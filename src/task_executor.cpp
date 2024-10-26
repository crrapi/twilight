// src/task_executor.cpp
#include "task_executor.h"

TaskExecutor::TaskExecutor(std::function<void()> task) : task_(task) {}

void TaskExecutor::execute()
{
    task_();
}
