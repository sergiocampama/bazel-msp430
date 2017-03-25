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

```
git_repository(
    name = "msp430_rules",
    remote = "",
    tag = "",
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
