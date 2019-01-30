class GPU_methods {
    public:
        // Dense float matrix vector product. (cuBLAS)
        thrust::device_vector<float> dfgemv ( const int m, const int n, const float * A, const float * x ) {

            // Initiate result vector and pointer.
            thrust::device_vector<float> yv(m);
            float * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values and pointers.
            float Alfa = 1.0; float * alpha = &Alfa;
            float Beta = 0.0; float * beta = &Beta;
            
            // Create a handle for cuBLAS.
            cublasHandle_t handle;
            cublasStatus_t status;
            status = cublasCreate(&handle);

            // cuBLAS function, documentation:
            // https://docs.nvidia.com/cuda/cublas/index.html#cublas-lt-t-gt-gemv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            status = cublasSgemv( handle, CUBLAS_OP_N, m, n, alpha, A, m, x, 1, beta, y, 1 );

            // check the status.
            if (status != CUBLAS_STATUS_SUCCESS) {
                std::cout << "cuBLAS status is not ok. " << std::endl;
            }

            // Destroy the handle
            cublasDestroy(handle);

            return yv;
            // test using "tests/GPU_dfgemv_test.cu"
        }

        // Dense double matrix vector product. (cuBLAS)
        thrust::device_vector<double> ddgemv ( const int m, const int n, const double * A, const double * x ) {

            // Initiate result vector and pointer.
            thrust::device_vector<double> yv(m);
            double * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values and pointers.
            double Alfa = 1.0; double * alpha = &Alfa;
            double Beta = 0.0; double * beta = &Beta;

            // Create a handle for cuBLAS.
            cublasHandle_t handle;
            cublasStatus_t status;
            status = cublasCreate(&handle);

            // cuBLAS function, documentation:
            // https://docs.nvidia.com/cuda/cublas/index.html#cublas-lt-t-gt-gemv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            status = cublasDgemv( handle, CUBLAS_OP_N, m, n, alpha, A, m, x, 1, beta, y, 1 );

            // check the status.
            if (status != CUBLAS_STATUS_SUCCESS) {
                std::cout << "cuBLAS status is not ok. " << std::endl;
            }

            // Destroy the handle
            cublasDestroy(handle);

            return yv;
            // test using "tests/GPU_ddgemv_test.cu"
        }

        // Dense float matrix matrix product. (cuBLAS)
        void dfgemm (  ) { std::cout << "empty" << std::endl; }

        // Dense double matrix matrix product. (cuBLAS)
        void ddgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse float matrix vector product. (cuSPARSE)
        thrust::device_vector<float> spfgemv ( const int m, const int n, const int numnz, const float * Values,
                                               const int * I, const int * J, const float * x ) {

            // Initiate result vector and pointer.
            thrust::device_vector<float> yv(m);
            float * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values and pointers.
            float Alfa = 1.0; float * alpha = &Alfa;
            float Beta = 0.0; float * beta = &Beta;
            
            // Create a handle for cuSPARSE.
            cusparseHandle_t handle;
            cusparseStatus_t status;
            cusparseMatDescr_t descrA = NULL;
            status = cusparseSetMatType(descrA,CUSPARSE_MATRIX_TYPE_GENERAL);
            status = cusparseSetMatIndexBase(descrA,CUSPARSE_INDEX_BASE_ZERO);
            status = cusparseCreate(&handle);
            
            // cuSPARSE function, documentation:
            // https://docs.nvidia.com/cuda/cusparse/index.html#cusparse-lt-t-gt-csrmv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            status = cusparseScsrmv( handle, CUSPARSE_OPERATION_NON_TRANSPOSE, m, n, numnz, alpha, 
                                     descrA, Values, I, J, x, beta, y );

            // check the status.
            if (status != CUSPARSE_STATUS_SUCCESS) {
                std::cout << "cuSPARSE status is not ok. " << std::endl;
            }

            // Destroy the handle
            cusparseDestroy(handle);

            return yv;
            // test using "tests/GPU_spfgemv_test.cu"
        }

        // Sparse double matrix vector product. (cuSPARSE)
        thrust::device_vector<double> spdgemv ( int m, int n, int numnz, const double * Values,
                                                const int * I, const int * J, const double * x ) {

            // Initiate result vector and pointer.
            thrust::device_vector<double> yv(m);
            double * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values and pointers.
            double Alfa = 1.0; double * alpha = &Alfa;
            double Beta = 0; double * beta = &Beta;
            
            // Create a handle for cuSPARSE.
            cusparseHandle_t handle;
            cusparseStatus_t status;
            cusparseMatDescr_t descrA = NULL;
            status = cusparseSetMatType(descrA,CUSPARSE_MATRIX_TYPE_GENERAL);
            status = cusparseSetMatIndexBase(descrA,CUSPARSE_INDEX_BASE_ZERO);
            status = cusparseCreate(&handle);
           
            // cuSPARSE function, documentation:
            // https://docs.nvidia.com/cuda/cusparse/index.html#cusparse-lt-t-gt-csrmv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            status = cusparseDcsrmv( handle, CUSPARSE_OPERATION_NON_TRANSPOSE, m, n, numnz, alpha, 
                                     descrA, Values, I, J, x, beta, y );

            // check the status.
            if (status != CUSPARSE_STATUS_SUCCESS) {
                std::cout << "cuSPARSE status is not ok. " << std::endl;
            }

            // Destroy the handle
            cusparseDestroy(handle);

            return yv;
            // test using "tests/GPU_spdgemv_test.cu"
        }

        // Sparse float matrix matrix product. (cuSPARSE)
        void spfgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse double matrix matrix product. (cuSPARSE)
        void spdgemm (  ) { std::cout << "empty" << std::endl; }

        // Float vector dot product. (Thrust)
        void fdot (  ) { std::cout << "empty" << std::endl; }

        // Double vector dot product. (Thrust)
        void ddot (  ) { std::cout << "empty" << std::endl; }

        // Float scalar multiplication. (Thrust)
        void fscp (  ) { std::cout << "empty" << std::endl; }

        // Double scalar multiplication. (Thrust)
        void dscp (  ) { std::cout << "empty" << std::endl; }

        // Float addition. (Thrust)
        void fadd (  ) { std::cout << "empty" << std::endl; }

        // Double addition. (Thrust)
        void dadd (  ) { std::cout << "empty" << std::endl; }

        // Float sparse matrix addition. (cuSPARSE)
        void spfadd (  ) { std::cout << "empty" << std::endl; }

        // Double sparse matrix addition. (cuSPARSE)
        void spdadd (  ) { std::cout << "empty" << std::endl; }
};