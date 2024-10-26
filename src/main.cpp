// src/main.cpp
#include "thread_pool_manager.h"
#include <iostream>

int main()
{
    ThreadPoolManager manager(4, 20); // Initialize with 4 threads, can scale to 20
    manager.enqueueTask([]()
                        { std::cout << "Task 1 running.\n"; });
    manager.enqueueTask([]()
                        { std::cout << "Task 2 running.\n"; });

    manager.shutdown();
    return 0;
}
