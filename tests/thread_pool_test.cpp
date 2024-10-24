#include "twilight/thread_pool.h"
#include <iostream>
#include <gtest/gtest.h>

void task(int i) {
    std::cout << "Task " << i << " is being processed." << std::endl;
}

TEST(ThreadPoolTest, BasicEnqueueTest) {
    ThreadPool pool(4);
    for (int i = 0; i < 10; ++i) {
        pool.enqueue(task, i);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
