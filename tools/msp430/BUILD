exports_files(["build_defs/msp430.bzl"])

filegroup(
    name = "compiler",
    srcs = ["msp430-gcc/bin/msp430-elf-gcc"],
    visibility = ["//visibility:public"],
)

filegroup(
    name = "compiler_support",
    srcs = glob([
        "msp430-gcc/bin/**/*",
        "msp430-gcc/include/**/*",
        "msp430-gcc/lib/**/*",
        "msp430-gcc/libexec/**/*",
        "msp430-gcc/msp430-elf/**/*",
        "msp430-gcc-support-files/include/**/*",

    ]),
    visibility = ["//visibility:public"],
)

filegroup(
    name = "base_includes",
    srcs = glob([
        "include/*.h",
        "msp430-elf/include/**/*.h",
    ]),
    visibility = ["//visibility:public"],
)
