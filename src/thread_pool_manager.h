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
    void enqueueTask(std::function<void()> task, int priority = 0);
    void shutdown();

private:
    void workerThread();

    struct Task
    {
        std::function<void()> func;
        int priority;

        bool operator<(const Task &other) const
        {
            return priority < other.priority;
        }
    };

    std::vector<std::thread> workers_;
    std::priority_queue<Task> tasks_;
    std::mutex queue_mutex_;
    std::condition_variable condition_;
    std::atomic<bool> stop_;
};

#endif // THREAD_POOL_MANAGER_H