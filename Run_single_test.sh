#!/bin/bash
#
# This script builds and runs the test provided by the argument.

# Activate the environment variables of MKL.
source /opt/intel/compilers_and_libraries/linux/mkl/bin/mklvars.sh intel64

# Compiler flags.
MKL_INCLUDE="-I${MKLROOT}/include"
MKL_COMPILER="-m64"
MKL_LINKER="-L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_tbb_thread -lmkl_core -ltbb -lstdc++ -lpthread -lm -ldl"
CUDA_LINKER="-lcublas -lcusparse"
CUDA_COMPILER="-Wno-deprecated-gpu-targets"
GPP_COMPILER="-O3 -std=c++11"
GPP_NATIVE="--compiler-options -march=native"

# Combine compiler flags.
FLAGS="$GPP_COMPILER $GPP_NATIVE $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_COMPILER $CUDA_LINKER"

# Check if "bin" directory exists.
if [ ! -d "tests/bin" ]; then
    mkdir tests/bin
fi

# Input argument.
called_test=$1

# Remove the test binary if it exists.
if [ -f tests/bin/$called_test ]
then
    rm tests/bin/$called_test
fi

# Build.
echo "Building" $called_test
nvcc tests/$called_test.cu -o tests/bin/$called_test $FLAGS

# Run.
echo "Running" $called_test
tests/bin/$called_test
