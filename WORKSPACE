# Bazel MSP430 rules workspace

workspace(name = "msp430_rules")

new_http_archive(
    name = "msp430_toolchain",
    build_file = "BUILD.msp430_toolchain",
    sha256 = "528a8504a41c16bab23f4c0ab0332cfd852ca415e8836455810a496d477b96b0",
    strip_prefix = "msp430-gcc-7.3.1.24_macos",
    urls = [
        "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/msp430-gcc-7.3.1.24_macos.tar.bz2",
    ],
)

new_http_archive(
    name = "msp430_include",
    build_file = "BUILD.msp430_include",
    sha256 = "1d1d6231bd6571b0470dd298692f1b58ad262e83079ed042d368313270bf4a0c",
    strip_prefix = "msp430-gcc-support-files",
    urls = [
        "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/msp430-gcc-support-files-1.205.zip",
    ],
)
