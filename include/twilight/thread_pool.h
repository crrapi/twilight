#ifndef TWILIGHT_THREAD_POOL_H
#define TWILIGHT_THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>

class ThreadPool {
public:
    ThreadPool(size_t);
    template <class F, class... Args>
    void enqueue(F&&, Args&&...);
    ~ThreadPool();
    
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};

#endif // TWILIGHT_THREAD_POOL_H
