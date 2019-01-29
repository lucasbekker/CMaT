class CPU_methods {
    public:        
        // Dense float matrix vector product. (MKL)
        thrust::host_vector<float> dfgemv ( const int m, const int n, const float * A, const float * x ) {

            // Initiate result vector and pointer.
            thrust::host_vector<float> yv(m);
            float * y = thrust::raw_pointer_cast(&yv[0]);

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-cblas-gemv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            cblas_sgemv ( CblasColMajor, CblasNoTrans, m, n, 1.0, A, m, x, 1, 0.0, y, 1 );

            return yv;
            // test using "tests/CPU_dfgemv_test.cu"
        }

        // Dense double matrix vector product. (MKL)
        thrust::host_vector<double> ddgemv ( const int m, const int n, const double * A, const double * x ) {

            // Initiate result vector and pointer.
            thrust::host_vector<double> yv(m);
            double * y = thrust::raw_pointer_cast(&yv[0]);

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-cblas-gemv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            cblas_dgemv ( CblasColMajor, CblasNoTrans, m, n, 1.0, A, m, x, 1, 0.0, y, 1 );

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