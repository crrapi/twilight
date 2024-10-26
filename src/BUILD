# src/BUILD
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "thread_pool_manager",
    srcs = ["thread_pool_manager.cpp"],
    hdrs = ["thread_pool_manager.h"],
    visibility = ["//tests:__pkg__"],  # Allows access for tests
    deps = ["//src/utils:logging"],
)

cc_library(
    name = "task_executor",
    srcs = ["task_executor.cpp"],
    hdrs = ["task_executor.h"],
    visibility = ["//tests:__pkg__"],  # Same for task_executor if it’s accessed by tests
)

cc_binary(
    name = "thread_pool_manager_app",
    srcs = ["main.cpp"],
    deps = [
        ":task_executor",
        ":thread_pool_manager",
    ],
)
