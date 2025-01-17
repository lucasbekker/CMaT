#!/bin/bash
#
# This script builds and runs all the tests, specified in FILES, located in the "tests" directory.

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

# Combine compiler flags.
FLAGS0="$CUDA_NATIVE $GPP_NATIVE $THRUST_DEFINE"
FLAGS1="$WARNINGS $MKL_INCLUDE $MKL_LINKER $CUDA_LINKER $GPP_LINKER"

# Create "bin" directory if it doesn't exist.
if [ ! -d "tests/bin" ]; then
    mkdir tests/bin
fi

# Tests to run.
FILES="
Matrix_vector_product_test
Inner_product_test
Scalar_product_test
Scalar_addition_test
Transpose_test
Matio_test
Clone_test
Convert_test
AMGX_test
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
    if [ -f tests/bin/$TEST ]
    then
        echo "Running" $TEST
        tests/bin/$TEST
    fi
done