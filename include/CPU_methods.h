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
        thrust::host_vector<float> spfgemv ( const int m, const int n, const float * Values, 
                                             const int * Ib, const int * Ie, const int * J, const float * x ) { 
            
            // Initiate result vector and pointer.
            thrust::host_vector<float> yv(m);
            float * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values and pointers.
            const float Alfa = 1.0; const float * alpha = &Alfa;
            const float Beta = 0.0; const float * beta = &Beta;

            // See: https://software.intel.com/en-us/mkl-developer-reference-c-interface-consideration#TBL2-6
            const char matdescra[] = "GOOCOO";
            const char transa[] = "N";
            
            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-mkl-csrmv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            mkl_scsrmv ( transa, &m, &n, alpha, matdescra, Values, J, Ib, Ie, x, beta, y );
            
            return yv;
            // test using "tests/CPU_spfgemv_test.cu"
        }
       
        // Sparse double matrix vector product. (MKL)
        thrust::host_vector<double> spdgemv ( const int m, const int n, const double * Values, 
                                              const int * Ib, const int * Ie, const int * J, const double * x ) { 
            
            // Initiate result vector and pointer.
            thrust::host_vector<double> yv(m);
            double * y = thrust::raw_pointer_cast(&yv[0]);

            // Set scalar values and pointers.
            const double Alfa = 1.0; const double * alpha = &Alfa;
            const double Beta = 0.0; const double * beta = &Beta;

            // See: https://software.intel.com/en-us/mkl-developer-reference-c-interface-consideration#TBL2-6
            const char matdescra[] = "GOOCOO";
            const char transa[] = "N";

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-mkl-csrmv
            //
            // y := alpha*A*x + beta*y.
            // x and y are vectors.
            // A is an m-by-n matrix.
            mkl_dcsrmv ( transa, &m, &n, alpha, matdescra, Values, J, Ib, Ie, x, beta, y );
            
            return yv;
            // test using "tests/CPU_spdgemv_test.cu"
        }

        // Sparse float matrix matrix product. (MKL)
        void spfgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse double matrix matrix product. (MKL)
        void spdgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse double matrix transpose. (MKL)
        void spdtrans ( thrust::host_vector<double> & V, thrust::host_vector<int> & Ipb, 
                        thrust::host_vector<int> & Ipe, thrust::host_vector<int> & J,
                        thrust::host_vector<double> & V_new, thrust::host_vector<int> & Ipb_new,
                        thrust::host_vector<int> & Ipe_new, thrust::host_vector<int> & J_new, int m, int n ) {
            
            // Initiate status, index and MKL-sparse-matrix type with pointer.
            sparse_status_t status;
            sparse_matrix_t A_data;
            sparse_matrix_t * A_p = &A_data;
            sparse_index_base_t index = SPARSE_INDEX_BASE_ZERO;
            
            // Create pointers.            
            double * V_p = thrust::raw_pointer_cast(&V[0]);
            int * Ipb_p = thrust::raw_pointer_cast(&Ipb[0]);
            int * Ipe_p = thrust::raw_pointer_cast(&Ipe[0]);
            int * J_p = thrust::raw_pointer_cast(&J[0]);
                        
            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-mkl-sparse-create-csr
            //
            // Create a CSR layout sparse matrix.
            status = mkl_sparse_d_create_csr(A_p, index, m, n, Ipb_p, Ipe_p, J_p, V_p);

            // Initialize MKL-sparse-matrix and pointer. 
            sparse_matrix_t B_data;
            sparse_matrix_t * B_p = &B_data;

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-mkl-sparse-convert-csr
            //
            // Create a new MKL-sparse-matrix with transposed data.
            status = mkl_sparse_convert_csr(A_data, SPARSE_OPERATION_TRANSPOSE, B_p);

            // Create pointers.
            double * V_new_p; double ** V_new_pp = &V_new_p;
            int * Ipb_new_p; int ** Ipb_new_pp = &Ipb_new_p;
            int * Ipe_new_p; int ** Ipe_new_pp = &Ipe_new_p;
            int * J_new_p; int ** J_new_pp = &J_new_p;

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-mkl-sparse-export-csr
            //
            // Export pointers to the transposed matrix.
            status = mkl_sparse_d_export_csr(B_data, &index, &n, &m, Ipb_new_pp, Ipe_new_pp, J_new_pp, V_new_pp);

            // Copy the data to the thrust vectors.
            V_new.resize(0); Ipb_new.resize(0); Ipe_new.resize(0); J_new.resize(0);
            V_new.insert(V_new.begin(), V_new_p, (V_new_p + V.size()));
            Ipb_new.insert(Ipb_new.begin(), Ipb_new_p, (Ipb_new_p + m));
            Ipe_new.insert(Ipe_new.begin(), Ipe_new_p, (Ipe_new_p + m));
            J_new.insert(J_new.begin(), J_new_p, (J_new_p + J.size()));

            // Free memory.
            status = mkl_sparse_destroy(A_data);
            status = mkl_sparse_destroy(B_data);

            // Check status.
            if (status != SPARSE_STATUS_SUCCESS) { std::cout << "MKL sparse status not OK!" << std::endl; }

        }

        // Sparse float matrix transpose. (MKL)
        void spftrans ( thrust::host_vector<float> & V, thrust::host_vector<int> & Ipb, 
                        thrust::host_vector<int> & Ipe, thrust::host_vector<int> & J,
                        thrust::host_vector<float> & V_new, thrust::host_vector<int> & Ipb_new,
                        thrust::host_vector<int> & Ipe_new, thrust::host_vector<int> & J_new, int m, int n ) {
            
            // Initiate status, index and MKL-sparse-matrix type with pointer.
            sparse_status_t status;
            sparse_matrix_t A_data;
            sparse_matrix_t * A_p = &A_data;
            sparse_index_base_t index = SPARSE_INDEX_BASE_ZERO;
            
            // Create pointers.            
            float * V_p = thrust::raw_pointer_cast(&V[0]);
            int * Ipb_p = thrust::raw_pointer_cast(&Ipb[0]);
            int * Ipe_p = thrust::raw_pointer_cast(&Ipe[0]);
            int * J_p = thrust::raw_pointer_cast(&J[0]);
                        
            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-mkl-sparse-create-csr
            //
            // Create a CSR layout sparse matrix.
            status = mkl_sparse_s_create_csr(A_p, index, m, n, Ipb_p, Ipe_p, J_p, V_p);

            // Initialize MKL-sparse-matrix and pointer. 
            sparse_matrix_t B_data;
            sparse_matrix_t * B_p = &B_data;

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-mkl-sparse-convert-csr
            //
            // Create a new MKL-sparse-matrix with transposed data.
            status = mkl_sparse_convert_csr(A_data, SPARSE_OPERATION_TRANSPOSE, B_p);

            // Create pointers.
            float * V_new_p; float ** V_new_pp = &V_new_p;
            int * Ipb_new_p; int ** Ipb_new_pp = &Ipb_new_p;
            int * Ipe_new_p; int ** Ipe_new_pp = &Ipe_new_p;
            int * J_new_p; int ** J_new_pp = &J_new_p;

            // MKL function, documentation:
            // https://software.intel.com/en-us/mkl-developer-reference-c-mkl-sparse-export-csr
            //
            // Export pointers to the transposed matrix.
            status = mkl_sparse_s_export_csr(B_data, &index, &n, &m, Ipb_new_pp, Ipe_new_pp, J_new_pp, V_new_pp);

            // Copy the data to the thrust vectors.
            V_new.resize(0); Ipb_new.resize(0); Ipe_new.resize(0); J_new.resize(0);
            V_new.insert(V_new.begin(), V_new_p, (V_new_p + V.size()));
            Ipb_new.insert(Ipb_new.begin(), Ipb_new_p, (Ipb_new_p + m));
            Ipe_new.insert(Ipe_new.begin(), Ipe_new_p, (Ipe_new_p + m));
            J_new.insert(J_new.begin(), J_new_p, (J_new_p + J.size()));

            // Free memory.
            status = mkl_sparse_destroy(A_data);
            status = mkl_sparse_destroy(B_data);

            // Check status.
            if (status != SPARSE_STATUS_SUCCESS) { std::cout << "MKL sparse status not OK!" << std::endl; }

        }

        // Float vector dot product. (Thrust)
        float fdot ( const thrust::host_vector<float> * x, const thrust::host_vector<float> * y ) {
            
            // Perform the calculation.
            float result = thrust::inner_product(x->begin(),x->end(),y->begin(),0.0);

            // Return the result.
            return result;
        
        }

        // Double vector dot product. (Thrust)
        double ddot ( const thrust::host_vector<double> * x, const thrust::host_vector<double> * y ) { 
            
            // Perform the calculation.
            double result = thrust::inner_product(x->begin(),x->end(),y->begin(),0.0);

            // Return the result.
            return result;
        
        }

        // Float scalar multiplication. (Thrust)
        thrust::host_vector<float> fscp ( const float a, const thrust::host_vector<float> * x ) {
            
            // Initiate the result vector.
            thrust::host_vector<float> y(x->size());

            // Call the transformation.
            thrust::transform(x->begin(),x->end(),y.begin(),fscp_functor(a));

            // Return the result.
            return y;

        }

        // Double scalar multiplication. (Thrust)
        thrust::host_vector<double> dscp ( const double a, const thrust::host_vector<double> * x ) {
            
            // Initiate the result vector.
            thrust::host_vector<double> y(x->size());

            // Call the transformation.
            thrust::transform(x->begin(),x->end(),y.begin(),dscp_functor(a));

            // Return the result.
            return y;
        }

        // Float scalar addition. (Thrust)
        thrust::host_vector<float> fadd ( const float a, const thrust::host_vector<float> * x ) {
            
            // Initiate the result vector.
            thrust::host_vector<float> y(x->size());

            // Call the transformation.
            thrust::transform(x->begin(),x->end(),y.begin(),fadd_functor(a));

            // Return the result.
            return y;
        }

        // Double scalar addition. (Thrust)
        thrust::host_vector<double> dadd ( const double a, const thrust::host_vector<double> * x ) {
            
            // Initiate the result vector.
            thrust::host_vector<double> y(x->size());

            // Call the transformation.
            thrust::transform(x->begin(),x->end(),y.begin(),dadd_functor(a));

            // Return the result.
            return y;
        }

        // Double dense matrix addition. (Thrust)
        void ddmadd (  ) { std::cout << "empty" << std::endl; }

        // Float dense matrix addition. (Thrust)
        void dfmadd (  ) { std::cout << "empty" << std::endl; }

        // Float sparse matrix addition. (MKL)
        void spfadd (  ) { std::cout << "empty" << std::endl; }

        // Double sparse matrix addition. (MKL)
        void spdadd (  ) { std::cout << "empty" << std::endl; }
};