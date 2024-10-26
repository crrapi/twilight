// src/thread_pool_manager.h
#ifndef THREAD_POOL_MANAGER_H
#define THREAD_POOL_MANAGER_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <atomic>

class ThreadPoolManager
{
public:
    ThreadPoolManager(size_t thread_count);
    ~ThreadPoolManager();

    void enqueueTask(std::function<void()> task);
    void shutdown();

private:
    void workerThread();

    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> tasks_;
    std::mutex queue_mutex_;
    std::condition_variable condition_;
    std::atomic<bool> stop_;
};

#endif // THREAD_POOL_MANAGER_H
