#include "thread_pool_manager.h"
#include "utils/logging.h"

ThreadPoolManager::ThreadPoolManager(size_t thread_count) : stop_(false)
{
    for (size_t i = 0; i < thread_count; ++i)
    {
        workers_.emplace_back(&ThreadPoolManager::workerThread, this);
    }
}

ThreadPoolManager::~ThreadPoolManager()
{
    shutdown();
}

void ThreadPoolManager::enqueueTask(std::function<void()> task, int priority)
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        tasks_.push({task, priority});
    }
    condition_.notify_one();
}

void ThreadPoolManager::shutdown()
{
    stop_ = true;
    condition_.notify_all();
    for (std::thread &worker : workers_)
    {
        if (worker.joinable())
            worker.join();
    }
}

void ThreadPoolManager::workerThread()
{
    while (true)
    {
        Task task;
        {
            std::unique_lock<std::mutex> lock(queue_mutex_);
            condition_.wait(lock, [this]()
                            { return stop_ || !tasks_.empty(); });
            if (stop_ && tasks_.empty())
                return;
            task = tasks_.top();
            tasks_.pop();
        }
        task.func();
    }
}