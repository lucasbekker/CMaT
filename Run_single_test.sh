#!/bin/bash
#
# This script builds and runs the test provided by the argument.

# Activate the environment variables of MKL.
source /opt/intel/compilers_and_libraries/linux/mkl/bin/mklvars.sh intel64

# Compiler flags.
MKL_INCLUDE="-I${MKLROOT}/include -I/opt/intel/tbb/include"
MKL_LINKER="-L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_tbb_thread -lmkl_core -ltbb -lstdc++ -lpthread -lm -ldl"
CUDA_LINKER="-lcublas -lcusparse -lcusolver -lamgx -lamgx_core -lmagma -lmagma_sparse"
CUDA_NATIVE="--ptxas-options -O3 --gpu-architecture=sm_35"
THRUST_DEFINE="-DTHRUST_HOST_SYSTEM=THRUST_HOST_SYSTEM_TBB -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_CUDA"
GPP_LINKER="-lmatio -lmpi"
GPP_NATIVE="--compiler-options -march=native,-O3,-std=c++11,-m64"
WARNINGS="-Wno-deprecated-gpu-targets -Wno-deprecated-declarations"

# Combine compiler flags.
FLAGS0="$CUDA_NATIVE $GPP_NATIVE $THRUST_DEFINE"
FLAGS1="$WARNINGS $MKL_INCLUDE $MKL_LINKER $CUDA_LINKER $GPP_LINKER"

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
nvcc $FLAGS0 tests/$called_test.cu -o tests/bin/$called_test $FLAGS1

# Run.
if [ -f tests/bin/$called_test ]
then
    echo "Running" $called_test
    tests/bin/$called_test
fi