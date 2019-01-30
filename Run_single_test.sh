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
GPP_COMPILER="-O3"

# Input argument.
called_test=$1
called_test_cu=$called_test.cu

# Removing old build.
rm tests/bin/$called_test

# Build.
echo "Building" $called_test
nvcc tests/$called_test_cu -o tests/bin/$called_test $GPP_COMPILER $MKL_INCLUDE $MKL_COMPILER $MKL_LINKER $CUDA_LINKER

# Run.
echo "Running" $called_test
tests/bin/$called_test