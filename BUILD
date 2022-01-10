load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "partition",
    hdrs = ["partition.h"],
)

cc_test(
    name = "partition_test",
    size = "small",
    srcs = ["partition_test.cc"],
    deps = [
        ":partition",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "quicksort",
    hdrs = ["quicksort.h"],
)

cc_test(
    name = "quicksort_test",
    size = "small",
    srcs = ["quicksort_test.cc"],
    deps = [
        ":quicksort",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "qs-median",
    hdrs = ["qs-median.h"],
)

cc_test(
    name = "qs-median_test",
    size = "small",
    srcs = ["qs-median_test.cc"],
    deps = [
        ":qs-median",
        "@com_google_googletest//:gtest_main",
    ],
)

#cc_binary(
#    name = "part1-main",
#    srcs = ["part1-main.cc"],
#    deps = [":navigation"],
#)
