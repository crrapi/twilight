// tests/thread_pool_manager_test.cpp
#include "src/thread_pool_manager.h"
#include <gtest/gtest.h>

TEST(ThreadPoolManagerTest, EnqueueTask)
{
    ThreadPoolManager manager(2);
    manager.enqueueTask([]() { /* task code */ });
    manager.shutdown();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
