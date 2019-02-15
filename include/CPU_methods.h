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

        // Sparse double matrix transpose. (Thrust)
        void spdtrans ( const thrust::host_vector<double> & V, const thrust::host_vector<int> & i, 
                        const thrust::host_vector<int> & jpb, const thrust::host_vector<int> & jpe,
                        thrust::host_vector<double> & V_new, thrust::host_vector<int> & j_new,
                        thrust::host_vector<int> & ipb_new, thrust::host_vector<int> & ipe_new ) {

            // Create temporary data vector.
            thrust::host_vector<int> i_temp(i.size());

            // Copy data to the new and temporary vectors.
            thrust::copy(V.begin(), V.end(), V_new.begin());
            thrust::copy(i.begin(), i.end(), i_temp.begin());
    
            // Fill j_new using COO layout.
            for ( int k = 0; k < jpb.size(); k++ ) {

                thrust::fill_n((j_new.begin() + jpb[k]), (jpe[k] - jpb[k]), k); 

            }

            // Typedefs for zip iterator.
            typedef thrust::host_vector<double>::iterator DoubleIt;
            typedef thrust::host_vector<int>::iterator IntIt;
            typedef thrust::tuple<DoubleIt,IntIt> TupleIt;
            typedef thrust::zip_iterator<TupleIt> ZipIt;

            // Create the zip iterator
            ZipIt zip_iterator(thrust::make_tuple(V_new.begin(), j_new.begin()));

            // Reorder V, i and j such that V and j conform to the CSR layout.
            thrust::stable_sort_by_key(i_temp.begin(), i_temp.end(), zip_iterator);

            // Fill the first value of ipb_new.
            ipb_new[0] = 0;

            // Fill ipb_new using the CSR layout.
            for ( int k = 0; k < (ipb_new.size() - 1); k++ ) {
        
                ipb_new[k + 1] = ipb_new[k] + thrust::count(i.begin(), i.end(), k);

            }

            // Fill ipe_new using the CSR layout.
            thrust::copy(ipb_new.begin() + 1, ipb_new.end(), ipe_new.begin());
            ipe_new[(ipe_new.size() - 1)] = jpe[(jpe.size() - 1)];

        }

        // Sparse float matrix transpose. (Thrust)
        void spftrans ( const thrust::host_vector<float> & V, const thrust::host_vector<int> & i, 
                        const thrust::host_vector<int> & jpb, const thrust::host_vector<int> & jpe,
                        thrust::host_vector<float> & V_new, thrust::host_vector<int> & j_new,
                        thrust::host_vector<int> & ipb_new, thrust::host_vector<int> & ipe_new ) {

            // Create temporary data vector.
            thrust::host_vector<int> i_temp(i.size());

            // Copy data to the new and temporary vectors.
            thrust::copy(V.begin(), V.end(), V_new.begin());
            thrust::copy(i.begin(), i.end(), i_temp.begin());
    
            // Fill j_new using COO layout.
            for ( int k = 0; k < jpb.size(); k++ ) {

                thrust::fill_n((j_new.begin() + jpb[k]), (jpe[k] - jpb[k]), k); 

            }

            // Typedefs for zip iterator.
            typedef thrust::host_vector<float>::iterator FloatIt;
            typedef thrust::host_vector<int>::iterator IntIt;
            typedef thrust::tuple<FloatIt,IntIt> TupleIt;
            typedef thrust::zip_iterator<TupleIt> ZipIt;

            // Create the zip iterator
            ZipIt zip_iterator(thrust::make_tuple(V_new.begin(), j_new.begin()));

            // Reorder V, i and j such that V and j conform to the CSR layout.
            thrust::stable_sort_by_key(i_temp.begin(), i_temp.end(), zip_iterator);

            // Fill the first value of ipb_new.
            ipb_new[0] = 0;

            // Fill ipb_new using the CSR layout.
            for ( int k = 0; k < (ipb_new.size() - 1); k++ ) {
        
                ipb_new[k + 1] = ipb_new[k] + thrust::count(i.begin(), i.end(), k);

            }

            // Fill ipe_new using the CSR layout.
            thrust::copy(ipb_new.begin() + 1, ipb_new.end(), ipe_new.begin());
            ipe_new[(ipe_new.size() - 1)] = jpe[(jpe.size() - 1)];

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