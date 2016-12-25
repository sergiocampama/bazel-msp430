load(
    "//tools/msp430:build_defs/msp430.bzl",
    "msp430_library",
    "msp430_binary"
)

msp430_library(
    name = "main",
    srcs = ["main.c"],
    deps = [
        "//msp430/launchpad:led",
        "//msp430/launchpad:core",
        "//msp430/launchpad:watchdog",
    ],
)

msp430_binary(
    name = "timer_blink",
    deps = [":main"],
)
