#include "thread_pool_manager.h"
#include <iostream>

int main()
{
    ThreadPoolManager manager(4); // Initialize with 4 threads

    manager.enqueueTask([]()
                        { std::cout << "Low priority task.\n"; }, 1);
    manager.enqueueTask([]()
                        { std::cout << "High priority task.\n"; }, 10);

    manager.shutdown();
    return 0;
}