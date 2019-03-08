#!/bin/bash
#
# This script builds the code provided by the argument.

# Activate the environment variables of MKL.
source /opt/intel/compilers_and_libraries/linux/mkl/bin/mklvars.sh intel64

# Compiler flags.
MKL_INCLUDE="-I${MKLROOT}/include -I/opt/intel/tbb/include"
MKL_LINKER="-L${MKLROOT}/lib/intel64 -lmkl_intel_lp64 -lmkl_tbb_thread -lmkl_core -ltbb -lstdc++ -lpthread -lm -ldl"
CUDA_LINKER="-lcublas -lcusparse"
CUDA_NATIVE="--ptxas-options -O3"
THRUST_DEFINE="-DTHRUST_HOST_SYSTEM=THRUST_HOST_SYSTEM_TBB -DTHRUST_DEVICE_SYSTEM=THRUST_DEVICE_SYSTEM_CUDA"
GPP_LINKER="-lmatio"
GPP_NATIVE="--compiler-options -march=native,-O3,-std=c++11,-m64"
WARNINGS="-Wno-deprecated-gpu-targets -Wno-deprecated-declarations"

# Combine compiler flags.
FLAGS0="$CUDA_NATIVE $GPP_NATIVE $THRUST_DEFINE"
FLAGS1="$WARNINGS $MKL_INCLUDE $MKL_LINKER $CUDA_LINKER $GPP_LINKER"

# Input argument.
file=$1

# Build.
echo "Building" $file
nvcc $FLAGS0 $file.cu -o $file $FLAGS1