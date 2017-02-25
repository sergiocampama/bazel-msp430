load(
    "//tools/msp430:build_defs/msp430.bzl",
    "msp430_library",
    "msp430_binary"
)

msp430_library(
    name = "test_main",
    srcs = ["test_main.c"],
    deps = [
        "//msp430/launchpad:button",
        "//msp430/launchpad:core",
        "//msp430/launchpad:led",
        "//msp430/launchpad:watchdog",
    ],
)

msp430_binary(
    name = "test_bin",
    deps = [":test_main"],
)
