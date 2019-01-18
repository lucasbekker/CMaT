# CMat
## Cuda, Mkl and Thrust based C++ matrix library

This repository contains C++ class definitions for data types commonly encountered in Linear Algebra problems, namely: **Vector** and **Matrix**.

## Sparse

One of the main design goals of this project is to facilitate sparse matrices:

* [COO, coordinate list](https://en.wikipedia.org/wiki/Sparse_matrix#Coordinate_list_(COO))
* [CSC, compressed sparse column](https://en.wikipedia.org/wiki/Sparse_matrix#Compressed_sparse_column_(CSC_or_CCS))
* [CSR, compressed sparse row](https://en.wikipedia.org/wiki/Sparse_matrix#Compressed_sparse_row_(CSR,_CRS_or_Yale_format))

Sparse vectors are not supported.

## CPU and GPU

The second main design goal is to facilitate calculations on both the CPU ([MKL](https://software.intel.com/en-us/mkl)), and GPU ([cuBLAS/cuSPARSE](https://developer.nvidia.com/gpu-accelerated-libraries)).

## Thrust

The [Thrust](https://docs.nvidia.com/cuda/thrust/index.html) template library is used for memory allocation on either **host** or **device** memory.

Thrust also exposes a lot of other useful functionality that can be employed by numerical algorithms. The [API documentation](http://thrust.github.io/doc/modules.html) is very helpful.

### Dependencies

This project depends on Thrust, cuSPARSE, cuBLAS and MKL. These can be obtained by installing the CUDA toolkit and MKL.

cuSPARSE, cuBLAS and MKL provide the required BLAS implementations. Thrust provides memory management and other mathematical functionality.

Everything must be compiled using the NVCC compiler provided by NVIDIA. This is a (hard) requirement of Thrust. The target platform is Linux and the target host compiler (of NVCC) is GCC.

## Methods

The amount of methods available to each class is going to be limited, in order to keep the project manageable.

#### Matrix

* **sc**:    Matrix scalar multiplication.
* **mm**: 	 Matrix Matrix multiplication.
* **mv**: 	 Matrix Vector multiplication.
* **add**: 	 Matrix addition.
* **trans**: Matrix transpose.
* **conv**:  Convert backend.
* **clone**: Make a clone.

#### Vector

* **sc**:    Vector scalar multiplication.
* **dot**:   Vector dot product.
* **add**: 	 Vector addition.
* **trans**: Vector transpose.
* **conv**:  Convert backend.
* **clone**: Make a clone.

# Design

## User accessible classes:

* **GPU_Vector**:      Composition of GPU and Vector.
* **CPU_Vector**:      Composition of CPU and Vector.
* **GPU_Full_matrix**: Composition of GPU and Full.
* **CPU_Full_matrix**: Composition of CPU and Full.
* **GPU_COO**:		   Composition of GPU and COO.
* **CPU_COO**:		   Composition of CPU and COO.
* **GPU_CSC**:		   Composition of GPU and CSC.
* **CPU_CSC**:		   Composition of CPU and CSC.
* **GPU_CSR**:		   Composition of GPU and CSR.
* **CPU_CSR**:		   Composition of CPU and CSR.

## Base classes:

#### CPU

* **(M) ialloc**: Thrust allocate memory on the **host** for type int.
* **(M) falloc**: Thrust allocate memory on the **host** for type float.
* **(M) dalloc**: Thrust allocate memory on the **host** for type double.
* **(M) dt**:	  MKL vector dot product.
* **(M) spgemm**: MKL sparse gemm operation.
* **(M) spgemv**: MKL sparse gemv operation.
* **(M) fgemm**:  MKL full gemm operation.
* **(M) fgemv**:  MKL full gemv operation.

#### GPU

* **(D) DeviceID**: Device ID of the GPU.
* **(M) ialloc**:   Thrust allocate memory on the **device** for type int.
* **(M) falloc**:   Thrust allocate memory on the **device** for type float.
* **(M) dalloc**:   Thrust allocate memory on the **device** for type double.
* **(M) dt**:	    cuBLAS vector dot product.
* **(M) spgemm**:   cuSPARSE sparse gemm operation.
* **(M) spgemv**:   cuSPARSE sparse gemv operation.
* **(M) fgemm**:    cuBLAS full gemm operation.
* **(M) fgemv**:    cuBLAS full gemv operation.

#### Matrix

* **(D) size**:   Int array containing size information [ m, n ].
* **(D) values**: Thrust *array*.
* **(D) type**:   Character indicating the type of values.

#### Vector <-- (Matrix)

* **(M) sc**:     Vector scalar multiplication.
* **(M) dot**:    Vector dot product.
* **(M) add**:    Vector addition.
* **(M) trans**:  Vector transpose.

#### Full <-- (Matrix)

* **(M) sc**:     Matrix scalar multiplication.
* **(M) mm**: 	  Matrix Matrix multiplication.
* **(M) mv**: 	  Matrix Vector multiplication.
* **(M) add**:    Matrix addition.
* **(M) trans**:  Matrix transpose.

#### Sparse <-- (Matrix)

* **(D) nnz**:    Number of non-zero elements.
* **(D) base**:   Zero or One based indexing.
* **(D) i**:      Thrust *array*.
* **(D) j**:      Thrust *array*.

#### COO <-- (Sparse)

* **(M) sc**:     Matrix scalar multiplication.
* **(M) mm**: 	  Matrix Matrix multiplication.
* **(M) mv**: 	  Matrix Vector multiplication.
* **(M) add**:    Matrix addition.
* **(M) trans**:  Matrix transpose.

#### CSC <-- (Sparse)

* **(M) sc**:     Matrix scalar multiplication.
* **(M) mm**: 	  Matrix Matrix multiplication.
* **(M) mv**: 	  Matrix Vector multiplication.
* **(M) add**:    Matrix addition.
* **(M) trans**:  Matrix transpose.

#### CSR <-- (Sparse)

* **(M) sc**:     Matrix scalar multiplication.
* **(M) mm**: 	  Matrix Matrix multiplication.
* **(M) mv**: 	  Matrix Vector multiplication.
* **(M) add**:    Matrix addition.
* **(M) trans**:  Matrix transpose.

