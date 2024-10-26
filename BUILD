# BUILD
load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "thread_pool_manager",
    srcs = ["src/main.cpp"],
    deps = [
        "//src:task_executor",
        "//src:thread_pool_manager",
        "//src/utils:logging",
    ],
)
