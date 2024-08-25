cc_library(
    name = "cox",
    srcs = [
        "src/cox.cc",
        "src/token.cc"
    ],
    hdrs = [
        "src/cox.h",
        "src/scanner.h",
        "src/token.h"
        ],
    copts = [
        "-std=c++20",
    ]
)

cc_binary(
    name = "cox-entry",
    srcs = ["src/main.cc"],
    deps = [":cox"],
    copts = [
        "-std=c++20",
    ]
)

cc_test(
    name = "scanner_test",
    size = "small",
    srcs = ["test/scanner_test.cc"],
    copts = [
        "-std=c++20",
    ],
    deps = [
        ":cox",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
