# tests/BUILD
load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "thread_pool_manager_test",
    srcs = ["thread_pool_manager_test.cpp"],
    deps = [
        "//src:thread_pool_manager",
        "@com_google_googletest//:gtest",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "task_executor_test",
    srcs = ["task_executor_test.cpp"],
    deps = [
        "//src:task_executor",
        "@com_google_googletest//:gtest",
        "@com_google_googletest//:gtest_main",
    ],
)
