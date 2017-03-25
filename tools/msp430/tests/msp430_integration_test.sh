#!/bin/bash -e

echo "Installing bazel..."
brew update
brew install bazel

echo "Running test..."
bazel build //tools/msp430/tests:test_bin

echo "Test successful!"

