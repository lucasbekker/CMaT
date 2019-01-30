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
rm tests/bin/CPU_ddgemv_test
rm tests/bin/CPU_dfgemv_test
rm tests/bin/GPU_ddgemv_test
rm tests/bin/GPU_dfgemv_test

# Build.
echo "Building CPU_ddgemv_test.cu"
nvcc tests/CPU_ddgemv_test.cu -o tests/bin/CPU_ddgemv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building CPU_dfgemv_test.cu"
nvcc tests/CPU_dfgemv_test.cu -o tests/bin/CPU_dfgemv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building GPU_ddgemv_test.cu"
nvcc tests/GPU_ddgemv_test.cu -o tests/bin/GPU_ddgemv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building GPU_dfgemv_test.cu"
nvcc tests/GPU_dfgemv_test.cu -o tests/bin/GPU_dfgemv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building CPU_spdgemv_test.cu"
nvcc tests/CPU_spdgemv_test.cu -o tests/bin/CPU_spdgemv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

echo "Building CPU_spfgemv_test.cu"
nvcc tests/CPU_spfgemv_test.cu -o tests/bin/CPU_spfgemv_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

# Run.
echo "Running CPU_ddgemv_test.cu"
tests/bin/CPU_ddgemv_test

echo "Running CPU_dfgemv_test.cu"
tests/bin/CPU_dfgemv_test

echo "Running GPU_ddgemv_test.cu"
tests/bin/GPU_ddgemv_test

echo "Running GPU_dfgemv_test.cu"
tests/bin/GPU_dfgemv_test

echo "Running CPU_spdgemv_test.cu"
tests/bin/CPU_spdgemv_test

echo "Running CPU_spfgemv_test.cu"
tests/bin/CPU_spfgemv_test