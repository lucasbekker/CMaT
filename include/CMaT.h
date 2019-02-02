#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// Included for printing to screen.
#include <iostream>

// Include the MKL header files.
#include "mkl.h"
#include "mkl_spblas.h"

// Include the Thrust header files.
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

// Include the CUDA header files.
#include <cuda_runtime.h>
#include "cublas_v2.h"
#include "cusparse_v2.h"

// Include the CMaT project header files.
#include "Handles.h"
#include "CPU_methods.h"
#include "GPU_methods.h"
#include "CPU_Dense.h"
#include "GPU_Dense.h"
#include "CPU_Sparse.h"
#include "GPU_Sparse.h"