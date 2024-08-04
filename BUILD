cc_library(
    name = "cox",
    srcs = ["src/cox.cc"],
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