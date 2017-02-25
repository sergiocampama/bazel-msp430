#!/bin/bash -e

echo "Installing bazel..."
brew update
brew install bazel

echo "Installing msp430-gcc..."
WORKSPACE_ROOT=$(bazel info workspace)
"$WORKSPACE_ROOT/tools/msp430/install-tools.sh"

bazel build //tools/msp430/tests:test_bin

echo "Test successful!"

