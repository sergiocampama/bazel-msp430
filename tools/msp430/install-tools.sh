#!/bin/bash

TOOLS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SYMLINK_FOLDER=msp430-gcc

COMPILER_FILES=msp430-gcc-5.3.0.224_osx
SUPPORT_FILES=msp430-gcc-support-files-1.194.zip

TMP_MSP430_GCC=/tmp/mspgcc.tar.bz2
TMP_MSP430_SUPPORT=/tmp/mspgcc-support.zip

echo Removing current files...
rm -rf "${TOOLS_DIR}/${SYMLINK_FOLDER}"
rm -rf "${TOOLS_DIR}/${COMPILER_FILES}"
rm -rf "${TOOLS_DIR}/msp430-gcc-support-files"

echo Downloading msp430-gcc...
curl -L -s -o "${TMP_MSP430_GCC}" \
    "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/${COMPILER_FILES}.tar.bz2"

echo Downloading msp430-gcc support files...
curl -L -s -o "${TMP_MSP430_SUPPORT}" \
    "http://software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSPGCC/latest/exports/${SUPPORT_FILES}"

echo Decompressing msp430-gcc...
tar -xzf "${TMP_MSP430_GCC}" -C "${TOOLS_DIR}"

echo Decompressing msp430-gcc support files...
unzip -qq "${TMP_MSP430_SUPPORT}" -d "${TOOLS_DIR}"

echo Creating symlink for "${SYMLINK_FOLDER}"...
ln -s "${TOOLS_DIR}/${COMPILER_FILES}" "${TOOLS_DIR}/${SYMLINK_FOLDER}"

echo Removing temporary files...
rm -f "${TMP_MSP430_GCC}"
rm -f "${TMP_MSP430_SUPPORT}"

echo Done!
