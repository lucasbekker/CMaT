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
            
            // cuBLAS function, documentation:
            // https://docs.nvidia.com/cuda/cublas/index.html#cublas-lt-t-gt-gemv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            _handles->cbstatus = cublasSgemv( _handles->cbhandle, CUBLAS_OP_N, m, n, alpha, A, m, x, 1, beta, y, 1 );

            // check the status.
            if (_handles->cbstatus != CUBLAS_STATUS_SUCCESS) {
                std::cout << "cuBLAS status is not ok. " << std::endl;
            }

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

            // cuBLAS function, documentation:
            // https://docs.nvidia.com/cuda/cublas/index.html#cublas-lt-t-gt-gemv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            _handles->cbstatus = cublasDgemv( _handles->cbhandle, CUBLAS_OP_N, m, n, alpha, A, m, x, 1, beta, y, 1 );

            // check the status.
            if (_handles->cbstatus != CUBLAS_STATUS_SUCCESS) {
                std::cout << "cuBLAS status is not ok. " << std::endl;
            }

            return yv;
            // test using "tests/GPU_ddgemv_test.cu"
        }

        // Dense float matrix matrix product. (cuBLAS)
        void dfgemm (  ) { std::cout << "empty" << std::endl; }

        // Dense double matrix matrix product. (cuBLAS)
        void ddgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse float matrix vector product. (cuSPARSE)
        thrust::device_vector<float> spfgemv ( const int m, const int n, const int numnz, const float * Values,
                                               const int * I, const int * J, const float * x, cusparseMatDescr_t descr ) {

            // Initiate result vector and pointer.
            thrust::device_vector<float> yv(m);
            float * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values and pointers.
            float Alfa = 1.0; float * alpha = &Alfa;
            float Beta = 0.0; float * beta = &Beta;
                                    
            // cuSPARSE function, documentation:
            // https://docs.nvidia.com/cuda/cusparse/index.html#cusparse-lt-t-gt-csrmv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            _handles->csstatus = cusparseScsrmv( _handles->cshandle, CUSPARSE_OPERATION_NON_TRANSPOSE, m, n,
                                                 numnz, alpha, descr, Values, I, J, x, beta, y );

            // check the status.
            if (_handles->csstatus != CUSPARSE_STATUS_SUCCESS) {
                std::cout << "cuSPARSE status is not ok. " << std::endl;
            }

            return yv;
            // test using "tests/GPU_spfgemv_test.cu"
        }

        // Sparse double matrix vector product. (cuSPARSE)
        thrust::device_vector<double> spdgemv ( const int m, const int n, const int numnz, const double * Values,
                                                const int * I, const int * J, const double * x, cusparseMatDescr_t descr ) {

            // Initiate result vector and pointer.
            thrust::device_vector<double> yv(m);
            double * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values and pointers.
            double Alfa = 1.0; double * alpha = &Alfa;
            double Beta = 0; double * beta = &Beta;
            
            // cuSPARSE function, documentation:
            // https://docs.nvidia.com/cuda/cusparse/index.html#cusparse-lt-t-gt-csrmv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            _handles->csstatus = cusparseDcsrmv( _handles->cshandle, CUSPARSE_OPERATION_NON_TRANSPOSE, m, n,
                                                 numnz, alpha, descr, Values, I, J, x, beta, y );

            // check the status.
            if (_handles->csstatus != CUSPARSE_STATUS_SUCCESS) {
                std::cout << "cuSPARSE status is not ok. " << std::endl;
            }

            return yv;
            // test using "tests/GPU_spdgemv_test.cu"
        }

        // Sparse float matrix matrix product. (cuSPARSE)
        void spfgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse double matrix matrix product. (cuSPARSE)
        void spdgemm (  ) { std::cout << "empty" << std::endl; }

        // Float vector dot product. (Thrust)
        float fdot ( const thrust::device_vector<float> * x, const thrust::device_vector<float> * y ) {
            
            // Perform the calculation.
            float result = thrust::inner_product(x->begin(),x->end(),y->begin(),0.0);

            // Return the result.
            return result;

        }

        // Double vector dot product. (Thrust)
        double ddot ( const thrust::device_vector<double> * x, const thrust::device_vector<double> * y ) {
            
            // Perform the calculation.
            double result = thrust::inner_product(x->begin(),x->end(),y->begin(),0.0);

            // Return the result.
            return result;

        }

        // Float scalar multiplication. (Thrust)
        thrust::device_vector<float> fscp ( const float a, const thrust::device_vector<float> * x ) {
            
            // Initiate the result vector.
            thrust::device_vector<float> y(x->size());

            // Call the transformation.
            thrust::transform(x->begin(),x->end(),y.begin(),fscp_functor(a));

            // Return the result.
            return y;

        }

        // Double scalar multiplication. (Thrust)
        thrust::device_vector<double> dscp ( const double a, const thrust::device_vector<double> * x ) {
            
            // Initiate the result vector.
            thrust::device_vector<double> y(x->size());

            // Call the transformation.
            thrust::transform(x->begin(),x->end(),y.begin(),dscp_functor(a));

            // Return the result.
            return y;
        }

        // Float scalar addition. (Thrust)
        thrust::device_vector<float> fadd ( const float a, const thrust::device_vector<float> * x ) {
            
            // Initiate the result vector.
            thrust::device_vector<float> y(x->size());

            // Call the transformation.
            thrust::transform(x->begin(),x->end(),y.begin(),fadd_functor(a));

            // Return the result.
            return y;
        }

        // Double scalar addition. (Thrust)
        thrust::device_vector<double> dadd ( const double a, const thrust::device_vector<double> * x ) {
            
            // Initiate the result vector.
            thrust::device_vector<double> y(x->size());

            // Call the transformation.
            thrust::transform(x->begin(),x->end(),y.begin(),dadd_functor(a));

            // Return the result.
            return y;
        }

        // Float sparse matrix addition. (cuSPARSE)
        void spfadd (  ) { std::cout << "empty" << std::endl; }

        // Double sparse matrix addition. (cuSPARSE)
        void spdadd (  ) { std::cout << "empty" << std::endl; }
};