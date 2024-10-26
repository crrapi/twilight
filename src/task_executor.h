// src/task_executor.h
#ifndef TASK_EXECUTOR_H
#define TASK_EXECUTOR_H

#include <functional>

class TaskExecutor
{
public:
    TaskExecutor(std::function<void()> task);
    void execute();

private:
    std::function<void()> task_;
};

#endif // TASK_EXECUTOR_H
