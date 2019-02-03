#!/bin/bash
#
# This script builds and runs all the tests in the "tests" directory.

# Activate the environment variables of MKL.
source /opt/intel/compilers_and_libraries/linux/mkl/bin/mklvars.sh intel64

# Compiler flags.
MKL_INCLUDE="-I${MKLROOT}/include"
MKL_COMPILER="-m64"
MKL_LINKER="-L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_tbb_thread -lmkl_core -ltbb -lstdc++ -lpthread -lm -ldl"
CUDA_LINKER="-lcublas -lcusparse"
CUDA_COMPILER="-Wno-deprecated-gpu-targets"
GPP_COMPILER="-O3 -std=c++11"

# Combine compiler flags.
FLAGS="$GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_COMPILER $CUDA_LINKER"

# Message to user.
echo "Building with the following compiler flags:"
echo $FLAGS

# Removing old builds.
rm tests/bin/*

# Build and run.
NAME="CPU_Dense_mv_test"
echo "Building" $NAME
nvcc tests/$NAME.cu -o tests/bin/$NAME $FLAGS
echo "Running" $NAME
tests/bin/$NAME

NAME="CPU_Dense_f_mv_test" 
echo "Building" $NAME
nvcc tests/$NAME.cu -o tests/bin/$NAME $FLAGS
echo "Running" $NAME
tests/bin/$NAME

NAME="GPU_Dense_mv_test"
echo "Building" $NAME
nvcc tests/$NAME.cu -o tests/bin/$NAME $FLAGS
echo "Running" $NAME
tests/bin/$NAME

NAME="GPU_Dense_f_mv_test"
echo "Building" $NAME
nvcc tests/$NAME.cu -o tests/bin/$NAME $FLAGS
echo "Running" $NAME
tests/bin/$NAME

NAME="CPU_Sparse_mv_test"
echo "Building" $NAME
nvcc tests/$NAME.cu -o tests/bin/$NAME $FLAGS
echo "Running" $NAME
tests/bin/$NAME

NAME="CPU_Sparse_f_mv_test"
echo "Building" $NAME
nvcc tests/$NAME.cu -o tests/bin/$NAME $FLAGS
echo "Running" $NAME
tests/bin/$NAME
