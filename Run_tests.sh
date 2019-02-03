#!/bin/bash
#
# This script builds and runs all the tests, specified in FILES, located in the "tests" directory.

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

# Create "bin" directory if it doesn't exist.
if [ ! -d "tests/bin" ]; then
    mkdir tests/bin
fi

# Tests to run.
FILES="
CPU_Dense_mv_test
CPU_Dense_f_mv_test
GPU_Dense_mv_test
GPU_Dense_f_mv_test
CPU_Sparse_mv_test
CPU_Sparse_f_mv_test
"

# Build and run.
for TEST in $FILES
do
    # Remove the test binary if it exists.
    if [ -f tests/bin/$TEST ]
    then
        rm tests/bin/$TEST
    fi
    # Build the test.
    echo "Building" $TEST
    nvcc tests/$TEST.cu -o tests/bin/$TEST $FLAGS
    # Run the test.
    echo "Running" $TEST
    tests/bin/$TEST
done