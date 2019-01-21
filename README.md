# CMat - Redesign branch
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

## Methods

The amount of methods available to each class is going to be limited, in order to keep the project manageable.

#### Matrix

* **scp**:   Scalar multiplication.
* **mm**: 	 Matrix Matrix multiplication.
* **mv**: 	 Matrix Vector multiplication.
* **add**: 	 Matrix addition.
* **trans**: Transpose.
* **clone**: Make a clone.
* **conv**:  Convert the backend type

#### Vector

* **scp**:   Scalar multiplication.
* **dot**:   Vector dot product.
* **add**: 	 Vector addition.
* **trans**: Transpose.
* **clone**: Make a clone.
* **conv**:  Convert the backend type

# Design

## User interfaceable classes:

* **CPU_Full**:		CPU backend full matrix or vector of type **double**.
* **CPU_Full_f**:	CPU backend full matrix or vector of type **float**.
* **CPU_Sparse**:	CPU backend sparse CSR matrix of type **double**.
* **CPU_Sparse_f**: CPU backend sparse CSR matrix of type **float**.
* **GPU_Full**:		GPU backend full matrix or vector of type **double**.
* **GPU_Full_f**:	GPU backend full matrix or vector of type **float**.
* **GPU_Sparse**:	GPU backend sparse CSR matrix of type **double**.
* **GPU_Sparse_f**: GPU backend sparse CSR matrix of type **float**.

## Backend classes:

#### CPU_Methods

* **ffgemv**:	Full float matrix vector product. (MKL)
* **fdgemv**:	Full double matrix vector product. (MKL)
* **ffgemm**:	Full float matrix matrix product. (MKL)
* **fdgemm**:	Full double matrix matrix product. (MKL)
* **spfgemv**:	Sparse float matrix vector product. (MKL)
* **spdgemv**:	Sparse double matrix vector product. (MKL)
* **spfgemm**:	Sparse float matrix matrix product. (MKL)
* **spdgemm**:	Sparse double matrix matrix product. (MKL)
* **fdot**:		Float vector dot product. (Thrust)
* **ddot**:		Double vector dot product. (Thrust)
* **fscp**:		Float scalar multiplication. (Thrust)
* **dscp**:		Double scalar multiplication. (Thrust)
* **fadd**:		Float addition. (Thrust)
* **dadd**:		Double addition. (Thrust)

#### GPU_Methods

* **ffgemv**:	Full float matrix vector product. (cuBLAS)
* **fdgemv**:	Full double matrix vector product. (cuBLAS)
* **ffgemm**:	Full float matrix matrix product. (cuBLAS)
* **fdgemm**:	Full double matrix matrix product. (cuBLAS)
* **spfgemv**:	Sparse float matrix vector product. (cuSPARSE)
* **spdgemv**:	Sparse double matrix vector product. (cuSPARSE)
* **spfgemm**:	Sparse float matrix matrix product. (cuSPARSE)
* **spdgemm**:	Sparse double matrix matrix product. (cuSPARSE)
* **fdot**:		Float vector dot product. (Thrust)
* **ddot**:		Double vector dot product. (Thrust)
* **fscp**:		Float scalar multiplication. (Thrust)
* **dscp**:		Double scalar multiplication. (Thrust)
* **fadd**:		Float addition. (Thrust)
* **dadd**:		Double addition. (Thrust)

## Class description

#### CPU_Full

* **(D) Values**:	Host vector of length Size[3] storing type double.
* **(D) Size**:		Array containing [ n, m, n*m ]
* **(D) isVector**: Zero if it is not a Vector and One if it is a Vector.
* **add**:			Links to CPU_methods.dadd().
* **trans**:		Transposes the Matrix or Vector.
* **scp**:			Links to CPU_methods.dscp().
* **dot**:			Links to CPU_methods.ddot().
* **mv**:			Links to CPU_methods.fdgemv().
* **mm**:			Links to CPU_methods.fdgemm().
* **clone**: 		Make a clone.
* **conv**:  		Convert the backend type

#### CPU_Full_f

* **(D) Values**:	Host vector of length Size[3] storing type float.
* **(D) Size**:		Array containing [ n, m, n*m ]
* **(D) isVector**: Zero if it is not a Vector and One if it is a Vector.
* **add**:			Links to CPU_methods.fadd().
* **trans**:		Transposes the Matrix or Vector.
* **scp**:			Links to CPU_methods.fscp().
* **dot**:			Links to CPU_methods.fdot().
* **mv**:			Links to CPU_methods.ffgemv().
* **mm**:			Links to CPU_methods.ffgemm().
* **clone**: 		Make a clone.
* **conv**:  		Convert the backend type

#### GPU_Full

* **(D) Values**:	Device vector of length Size[3] storing type double.
* **(D) Size**:		Array containing [ n, m, n*m ]
* **(D) isVector**: Zero if it is not a Vector and One if it is a Vector.
* **add**:			Links to GPU_methods.dadd().
* **trans**:		Transposes the Matrix or Vector.
* **scp**:			Links to GPU_methods.dscp().
* **dot**:			Links to GPU_methods.ddot().
* **mv**:			Links to GPU_methods.fdgemv().
* **mm**:			Links to GPU_methods.fdgemm().
* **clone**: 		Make a clone.
* **conv**:  		Convert the backend type

#### GPU_Full_f

* **(D) Values**:	Device vector of length Size[3] storing type float.
* **(D) Size**:		Array containing [ n, m, n*m ]
* **(D) isVector**: Zero if it is not a Vector and One if it is a Vector.
* **add**:			Links to GPU_methods.fadd().
* **trans**:		Transposes the Matrix or Vector.
* **scp**:			Links to GPU_methods.fscp().
* **dot**:			Links to GPU_methods.fdot().
* **mv**:			Links to GPU_methods.ffgemv().
* **mm**:			Links to GPU_methods.ffgemm().
* **clone**: 		Make a clone.
* **conv**:  		Convert the backend type

#### CPU_Sparse

* **(D) Values**:	Host vector of length Size[3] storing type double.
* **(D) Size**:		Array containing [ n, m, nnz ]
* **(D) I**:		Host vector of length Size[m] storing pointer list type int.
* **(D) J**:		Host vector of length Size[3] storing type int.
* **add**:			Links to CPU_methods.dadd().
* **trans**:		Transposes the Matrix.
* **scp**:			Links to CPU_methods.dscp().
* **mv**:			Links to CPU_methods.spdgemv().
* **mm**:			Links to CPU_methods.spdgemm().
* **clone**: 		Make a clone.
* **conv**:  		Convert the backend type

#### CPU_Sparse_f

* **(D) Values**:	Host vector of length Size[3] storing type float.
* **(D) Size**:		Array containing [ n, m, nnz ]
* **(D) I**:		Host vector of length Size[m] storing pointer list type int.
* **(D) J**:		Host vector of length Size[3] storing type int.
* **add**:			Links to CPU_methods.fadd().
* **trans**:		Transposes the Matrix.
* **scp**:			Links to CPU_methods.fscp().
* **mv**:			Links to CPU_methods.spfgemv().
* **mm**:			Links to CPU_methods.spfgemm().
* **clone**: 		Make a clone.
* **conv**:  		Convert the backend type

#### GPU_Sparse

* **(D) Values**:	Device vector of length Size[3] storing type double.
* **(D) Size**:		Array containing [ n, m, nnz ]
* **(D) I**:		Device vector of length Size[m] storing pointer list type int.
* **(D) J**:		Device vector of length Size[3] storing type int.
* **add**:			Links to GPU_methods.dadd().
* **trans**:		Transposes the Matrix.
* **scp**:			Links to GPU_methods.dscp().
* **mv**:			Links to GPU_methods.spdgemv().
* **mm**:			Links to GPU_methods.spdgemm().
* **clone**: 		Make a clone.
* **conv**:  		Convert the backend type

#### GPU_Sparse_f

* **(D) Values**:	Device vector of length Size[3] storing type float.
* **(D) Size**:		Array containing [ n, m, nnz ]
* **(D) I**:		Device vector of length Size[m] storing pointer list type int.
* **(D) J**:		Device vector of length Size[3] storing type int.
* **add**:			Links to GPU_methods.fadd().
* **trans**:		Transposes the Matrix.
* **scp**:			Links to GPU_methods.fscp().
* **mv**:			Links to GPU_methods.spfgemv().
* **mm**:			Links to GPU_methods.spfgemm().
* **clone**: 		Make a clone.
* **conv**:  		Convert the backend type