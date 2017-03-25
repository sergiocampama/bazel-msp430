# Bazel MSP430 rules workspace

workspace(name = "msp430_rules")

new_http_archive(
    name = "msp430_toolchain",
    build_file = "BUILD.msp430_toolchain",
    sha256 = "7e6b9fb94885e566777312bfcd0c1d1d583e37898a080210a4adebced1116f86",
    strip_prefix = "msp430-gcc-6.2.1.16_osx",
    urls = [
        "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/msp430-gcc-6.2.1.16_osx.tar.bz2",
    ],
)

new_http_archive(
    name = "msp430_include",
    build_file = "BUILD.msp430_include",
    sha256 = "8d411d61eebf794d4f786f77c901223c931146ba2dfe2ae0798433c7ddb15137",
    strip_prefix = "msp430-gcc-support-files",
    urls = [
        "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/msp430-gcc-support-files-1.198.zip",
    ],
)
