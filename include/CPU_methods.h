class CPU_methods {
    public:        
        // Dense float matrix vector product. (MKL)
        thrust::host_vector<float> dfgemv ( const int m, const int n, 
                                            thrust::host_vector<float> Av, 
                                            thrust::host_vector<float> xv ) {

            // Initiate result vector.
            thrust::host_vector<float> yv(m);

            // Generate raw pointers.
            float * A = thrust::raw_pointer_cast(&Av[0]);
            float * x = thrust::raw_pointer_cast(&xv[0]);
            float * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values.
            float alpha = 1.0;
            float beta  = 0.0;

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-cblas-gemv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            cblas_sgemv ( CblasColMajor, CblasNoTrans, m, n, alpha, A, m, x, 1, beta, y, 1 );

            return yv;
            // test using "tests/CPU_dfgemv_test.cu"
        }

        // Dense double matrix vector product. (MKL)
        thrust::host_vector<double> ddgemv ( const int m, const int n, 
                                             thrust::host_vector<double> Av, 
                                             thrust::host_vector<double> xv ) {

            // Initiate result vector.
            thrust::host_vector<double> yv(m);

            // Generate raw pointers.
            double * A = thrust::raw_pointer_cast(&Av[0]);
            double * x = thrust::raw_pointer_cast(&xv[0]);
            double * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values.
            double alpha = 1.0;
            double beta  = 0.0;

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-cblas-gemv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            cblas_dgemv ( CblasColMajor, CblasNoTrans, m, n, alpha, A, m, x, 1, beta, y, 1 );

            return yv;
            // test using "tests/CPU_ddgemv_test.cu"
        }

        // Dense float matrix matrix product. (MKL)
        void dfgemm (  ) { std::cout << "empty" << std::endl; }

        // Dense double matrix matrix product. (MKL)
        void ddgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse float matrix vector product. (MKL)
        void spfgemv (  ) { std::cout << "empty" << std::endl; }

        // Sparse double matrix vector product. (MKL)
        void spdgemv (  ) { std::cout << "empty" << std::endl; }

        // Sparse float matrix matrix product. (MKL)
        void spfgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse double matrix matrix product. (MKL)
        void spdgemm (  ) { std::cout << "empty" << std::endl; }

        // Float vector dot product. (Thrust)
        void fdot (  ) { std::cout << "empty" << std::endl; }

        // Double vector dot product. (Thrust)
        void ddot (  ) { std::cout << "empty" << std::endl; }

        // Float scalar multiplication. (Thrust)
        void fscp (  ) { std::cout << "empty" << std::endl; }

        // Double scalar multiplication. (Thrust)
        void dscp (  ) { std::cout << "empty" << std::endl; }

        // Float scalar addition. (Thrust)
        void fadd (  ) { std::cout << "empty" << std::endl; }

        // Double scalar addition. (Thrust)
        void dadd (  ) { std::cout << "empty" << std::endl; }

        // Float sparse matrix addition. (MKL)
        void spfadd (  ) { std::cout << "empty" << std::endl; }

        // Double sparse matrix addition. (MKL)
        void spdadd (  ) { std::cout << "empty" << std::endl; }
};