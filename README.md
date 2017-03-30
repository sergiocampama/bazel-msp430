MSP430 Bazel Workspace
======================

[![Build Status](https://travis-ci.org/sergiocampama/bazel-msp430.svg?branch=master)](https://travis-ci.org/sergiocampama/bazel-msp430)

Author: Sergio Campamá (kaipi)

Date: 12/25/2016

Introduction
------------

This project is an integration of the MSP430 toolchain into bazel, specifically
to be run on macOS.

Dependencies (macOS)
--------------------

1. mspdebug: This is very easy to install by just using `brew install mspdebug`.
1. MSP430LPCDC.kext: This kernel extension will configure correctly the port for
                     mspdebug to install the binary onto the platform. The
                     extension can be found
                     [here](https://code.google.com/archive/p/msp430lpcdc/downloads).
                     Download and put this file in `/System/Library/Extensions`
                     and reboot your computer.

Installation (macOS)
-------------------

On your `WORKSPACE` file, add the following:

```python
git_repository(
    name = "msp430_rules",
    remote = "https://github.com/sergiocampama/bazel-msp430.git",
    tag = "v1.0",
)

new_http_archive(
    name = "msp430_toolchain",
    build_file = "@msp430_rules//:BUILD.msp430_toolchain",
    sha256 = "7e6b9fb94885e566777312bfcd0c1d1d583e37898a080210a4adebced1116f86",
    strip_prefix = "msp430-gcc-6.2.1.16_osx",
    urls = [
        "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/msp430-gcc-6.2.1.16_osx.tar.bz2",
    ],
)

new_http_archive(
    name = "msp430_include",
    build_file = "@msp430_rules//:BUILD.msp430_include",
    sha256 = "8d411d61eebf794d4f786f77c901223c931146ba2dfe2ae0798433c7ddb15137",
    strip_prefix = "msp430-gcc-support-files",
    urls = [
        "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/msp430-gcc-support-files-1.198.zip",
    ],
)
```

Once that is set, you can load the Skylark files in your BUILD file using

```
load(
    "@msp430_rules//tools/msp430:build_defs/msp430.bzl",
    "msp430_library",
    "msp430_binary",
)
```

Usage
-----

To build a binary file, just use `bazel build //path/to/msp430_binary:target`.
To install onto a device, use `bazel run //path/to/msp430_binary:target`.
