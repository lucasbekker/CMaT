#!/bin/bash
#
# This script builds and runs all the tests, specified in FILES, located in the "tests" directory.

# Activate the environment variables of MKL.
source /opt/intel/compilers_and_libraries/linux/mkl/bin/mklvars.sh intel64

# Compiler flags.
MKL_INCLUDE="-I${MKLROOT}/include"
MKL_LINKER="-L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_tbb_thread -lmkl_core -ltbb -lstdc++ -lpthread -lm -ldl"
CUDA_LINKER="-lcublas -lcusparse"
CUDA_NATIVE="--ptxas-options -O3"
GPP_NATIVE="--compiler-options -march=native,-O3,-std=c++11,-m64"
WARNINGS="-Wno-deprecated-gpu-targets -Wno-deprecated-declarations"

# Combine compiler flags.
FLAGS0="$CUDA_NATIVE $GPP_NATIVE"
FLAGS1="$WARNINGS $MKL_INCLUDE $MKL_LINKER $CUDA_LINKER"

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
GPU_Sparse_mv_test
GPU_Sparse_f_mv_test
CPU_Dense_dot_test
CPU_Dense_f_dot_test
GPU_Dense_dot_test
GPU_Dense_f_dot_test
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
    nvcc $FLAGS0 tests/$TEST.cu -o tests/bin/$TEST $FLAGS1
    # Run the test.
    echo "Running" $TEST
    tests/bin/$TEST
done