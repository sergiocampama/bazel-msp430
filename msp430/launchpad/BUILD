load("//tools/msp430:build_defs/msp430.bzl", "msp430_library")

package(default_visibility = ["//visibility:public"])

msp430_library(
    name = "core",
    hdrs = ["core.h"],
)

msp430_library(
    name = "led",
    hdrs = ["led.h"],
    deps = [":core"],
)

msp430_library(
    name = "watchdog",
    hdrs = ["watchdog.h"],
    deps = [":core"],
)

msp430_library(
    name = "button",
    hdrs = ["button.h"],
    deps = [":core"],
)
