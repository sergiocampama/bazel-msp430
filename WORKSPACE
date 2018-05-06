# Bazel MSP430 rules workspace

workspace(name = "msp430_rules")

new_http_archive(
    name = "msp430_toolchain",
    build_file = "BUILD.msp430_toolchain",
    sha256 = "b2b393c852ea51bc153bde896b84fec8fea375a8d5bb4cab7edef789916ab3da",
    strip_prefix = "msp430-gcc-6.4.0.32_osx",
    urls = [
        "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/msp430-gcc-6.4.0.32_osx.tar.bz2",
    ],
)

new_http_archive(
    name = "msp430_include",
    build_file = "BUILD.msp430_include",
    sha256 = "401630dbaad23db17ad2edfba31a16f4a1fd1588e131140b5ca3a416b7534e11",
    strip_prefix = "msp430-gcc-support-files",
    urls = [
        "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/msp430-gcc-support-files-1.204.zip",
    ],
)
