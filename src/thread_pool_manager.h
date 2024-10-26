#ifndef THREAD_POOL_MANAGER_H
#define THREAD_POOL_MANAGER_H

#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

class ThreadPoolManager
{
public:
    ThreadPoolManager(size_t initialThreads, size_t maxThreads);
    ~ThreadPoolManager();

    void enqueueTask(std::function<void()> task);
    void shutdown();

private:
    // New method to scale threads dynamically
    void adjustThreadPoolSize();

    // Worker function for threads
    void worker();

    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop = false;

    size_t maxThreads;
    std::atomic<size_t> currentThreads;
    std::atomic<size_t> activeThreads;
};

#endif // THREAD_POOL_MANAGER_H