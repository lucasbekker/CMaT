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
GPP_COMPILER="-O3"

# Removing old builds.
rm tests/bin/*

# Build.
echo "Building CPU_Dense_mv_test.cu"
nvcc tests/CPU_Dense_mv_test.cu -o tests/bin/CPU_Dense_mv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building CPU_Dense_f_mv_test.cu"
nvcc tests/CPU_Dense_f_mv_test.cu -o tests/bin/CPU_Dense_f_mv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building GPU_Dense_mv_test.cu"
nvcc tests/GPU_Dense_mv_test.cu -o tests/bin/GPU_Dense_mv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building GPU_Dense_f_mv_test.cu"
nvcc tests/CPU_Dense_f_mv_test.cu -o tests/bin/GPU_Dense_f_mv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building CPU_Sparse_mv_test.cu"
nvcc tests/CPU_Sparse_mv_test.cu -o tests/bin/CPU_Sparse_mv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building CPU_Sparse_f_mv_test.cu"
nvcc tests/CPU_Sparse_f_mv_test.cu -o tests/bin/CPU_Sparse_f_mv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER


# Run.
echo "Running CPU_Dense_mv_test"
tests/bin/CPU_Dense_mv_test

echo "Running CPU_Dense_f_mv_test"
tests/bin/CPU_Dense_f_mv_test

echo "Running GPU_Dense_mv_test"
tests/bin/GPU_Dense_mv_test

echo "Running GPU_Dense_f_mv_test"
tests/bin/GPU_Dense_f_mv_test

echo "Running CPU_Sparse_mv_test"
tests/bin/CPU_Sparse_mv_test

echo "Running CPU_Sparse_f_mv_test"
tests/bin/CPU_Sparse_f_mv_test