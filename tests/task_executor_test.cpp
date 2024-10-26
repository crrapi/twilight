// tests/task_executor_test.cpp
#include "src/task_executor.h"
#include <gtest/gtest.h>

TEST(TaskExecutorTest, ExecuteTask)
{
    bool executed = false;
    TaskExecutor executor([&]()
                          { executed = true; });
    executor.execute();
    ASSERT_TRUE(executed);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
