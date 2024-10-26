#include "thread_pool_manager.h"
#include <chrono>

ThreadPoolManager::ThreadPoolManager(size_t initialThreads, size_t maxThreads)
    : maxThreads(maxThreads), currentThreads(initialThreads), activeThreads(0)
{

    for (size_t i = 0; i < initialThreads; ++i)
    {
        threads.emplace_back(&ThreadPoolManager::worker, this);
    }

    // Start a background thread to adjust the pool size
    std::thread([this]()
                {
        while (!stop) {
            adjustThreadPoolSize();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        } })
        .detach();
}

ThreadPoolManager::~ThreadPoolManager()
{
    shutdown();
}

void ThreadPoolManager::enqueueTask(std::function<void()> task)
{
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        tasks.emplace(std::move(task));
    }
    condition.notify_one();
}

void ThreadPoolManager::worker()
{
    while (true)
    {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            condition.wait(lock, [this]()
                           { return stop || !tasks.empty(); });
            if (stop && tasks.empty())
                return;

            task = std::move(tasks.front());
            tasks.pop();
            ++activeThreads;
        }

        task();

        {
            std::unique_lock<std::mutex> lock(queueMutex);
            --activeThreads;
        }
    }
}

void ThreadPoolManager::shutdown()
{
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread &thread : threads)
    {
        if (thread.joinable())
            thread.join();
    }
}

// Dynamic adjustment function
void ThreadPoolManager::adjustThreadPoolSize()
{
    size_t taskCount;
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        taskCount = tasks.size();
    }

    if (taskCount > threads.size() && currentThreads < maxThreads)
    {
        // Scale up by adding a new thread
        threads.emplace_back(&ThreadPoolManager::worker, this);
        ++currentThreads;
    }
    else if (taskCount < threads.size() / 2 && currentThreads > 1)
    {
        // Scale down by stopping one thread
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        threads.back().join();
        threads.pop_back();
        --currentThreads;
        stop = false;
    }
}
