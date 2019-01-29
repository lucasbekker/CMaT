# CMat
## Cuda, Mkl and Thrust based C++ matrix library

This repository contains C++ class definitions for data types commonly encountered in Linear Algebra problems, namely: **Vector** and **Matrix**.

## Sparse

One of the main design goals of this project is to facilitate sparse matrices. Support for the following sparse matrix layout types has been considered:

* [COO, coordinate list](https://en.wikipedia.org/wiki/Sparse_matrix#Coordinate_list_(COO))
* [CSC, compressed sparse column](https://en.wikipedia.org/wiki/Sparse_matrix#Compressed_sparse_column_(CSC_or_CCS))
* [CSR, compressed sparse row](https://en.wikipedia.org/wiki/Sparse_matrix#Compressed_sparse_row_(CSR,_CRS_or_Yale_format))

The choice was made to only support the CRS layout for a number of reasons:

* CSC is equivalent to transposed CSR.
* CSR has the best support in cuSPARSE.
* CSR is the default layout in Scipy.

Sparse vectors are not supported.

## CPU and GPU

The second main design goal is to facilitate calculations on both the CPU ([MKL](https://software.intel.com/en-us/mkl)), and GPU ([cuBLAS/cuSPARSE](https://developer.nvidia.com/gpu-accelerated-libraries)).

## Thrust

The [Thrust](https://docs.nvidia.com/cuda/thrust/index.html) template library is used for memory allocation on either **host** or **device** memory. Blas level 1 and element-wise operations are also implemented using Thrust.

Thrust exposes a lot of other useful functionality that can be employed by numerical algorithms. The [API documentation](http://thrust.github.io/doc/modules.html) is very helpful.

### Dependencies

This project depends on Thrust, cuSPARSE, cuBLAS and MKL. These can be obtained by installing the CUDA toolkit and MKL.

cuSPARSE, cuBLAS and MKL provide the required BLAS implementations. Thrust provides memory management and other mathematical functionality.

Everything must be compiled using the NVCC compiler provided by NVIDIA. This is a (hard) requirement of Thrust. The target platform is Linux and the target host compiler (of NVCC) is GCC.