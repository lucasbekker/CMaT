#pragma once

// STD libs.
#include <iostream>
#include <assert.h>
#include <string>
#include <list>
#include <chrono>
#include <cmath>

// Debug.
#define DEBUG std::cout<<"debug"<<std::endl;

// Included for .mat file support.
#include <matio.h>
#include "Matfile.h"

// Included for timer support.
#include "Timer.h"

// Include the MKL header files.
#include "mkl.h"
#include "mkl_spblas.h"

// Include the Thrust header files.
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/inner_product.h>
#include <thrust/transform.h>
#include <thrust/sort.h>
#include <thrust/iterator/zip_iterator.h>
#include <thrust/tuple.h>

// Include the CUDA header files.
#include <cuda_runtime.h>
#include "cublas_v2.h"
#include "cusparse_v2.h"

// Include the AMGX header files.
#include <amgx_c.h>

// Include the CMaT project header files.
#include "Handles.h"
#include "Thrust_functors.h"
#include "CPU_methods.h"
#include "GPU_methods.h"
#include "CPU_Dense.h"
#include "GPU_Dense.h"
#include "CPU_Sparse.h"
#include "GPU_Sparse.h"
#include "Convert.h"
#include "Solver.h"