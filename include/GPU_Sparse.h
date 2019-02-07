class GPU_Sparse: public GPU_methods {
    public:
        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[2] storing type double.
        int Size[3];                           // Array containing [ m, n, nnz ]
        thrust::device_vector<int> I;          // Device vector of length Size[0] + 1 storing pointer list type int.
        thrust::device_vector<int> J;          // Device vector of length Size[2] storing type int.
        cusparseMatDescr_t descr = NULL;       // Matrix description.
        
        // Methods
        // Links to GPU_methods.dadd().
        GPU_Sparse add ( const double a ) {
            
            // Initialize result Vector.
            GPU_Sparse y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::device_vector<double> * xp = &Values;

            // Call GPU_methods.dadd().
            y.Values = dadd(a,xp);

            // Fill the index arrays.
            y.I = I;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to GPU_methods.spdadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dscp().
        GPU_Sparse scp ( const double a ) {
            
            // Initialize result Vector.
            GPU_Sparse y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::device_vector<double> * xp = &Values;

            // Call GPU_methods.dscp().
            y.Values = dscp(a,xp);

            // Fill the index arrays.
            y.I = I;
            y.J = J;

            // Return the result.
            return y;

        }
        
        // Links to GPU_methods.spdgemv().
        GPU_Dense mv ( const GPU_Dense& x ) {

            // Initialize result Vector.
            GPU_Dense y(Size[0],1);

            // Check if the dimensions are correct.
            if ((Size[1] == x.Size[0]) && (x.isVector == 1)) {

                // Create pointers.
                const double * Vp = thrust::raw_pointer_cast(&Values[0]);
                const int * Ip = thrust::raw_pointer_cast(&I[0]);
                const int * Jp = thrust::raw_pointer_cast(&J[0]);
                const double * xp = thrust::raw_pointer_cast(&x.Values[0]);

                // Call GPU_methods.spdgemv().
                y.Values = spdgemv(Size[0],Size[1],Size[2],Vp,Ip,Jp,xp,descr);

            } else { std::cout << "ERROR: Input GPU_Sparse.mv()" << std::endl; }

            // Return the result.
            return y;

        }

        // Links to GPU_methods.spdgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Constructor
        GPU_Sparse ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[0] + 1);
            J.resize(Size[2]);

            // Fill matrix description.
            _handles->csstatus = cusparseCreateMatDescr(&descr);
            _handles->csstatus = cusparseSetMatType(descr,CUSPARSE_MATRIX_TYPE_GENERAL);
            _handles->csstatus = cusparseSetMatIndexBase(descr,CUSPARSE_INDEX_BASE_ZERO);

        }
};

class GPU_Sparse_f: public GPU_methods {
    public:
        // Data
        thrust::device_vector<float> Values;  // Device vector of length Size[2] storing type float.
        int Size[3];                          // Array containing [ m, n, nnz ]
        thrust::device_vector<int> I;         // Device vector of length Size[0] + 1 storing pointer list type int.
        thrust::device_vector<int> J;         // Device vector of length Size[2] storing type int.
        cusparseMatDescr_t descr = NULL;      // Matrix description.

        // Methods
        // Links to GPU_methods.fadd().
        GPU_Sparse_f add ( const float a ) {
            
            // Initialize result Vector.
            GPU_Sparse_f y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::device_vector<float> * xp = &Values;

            // Call GPU_methods.fadd().
            y.Values = fadd(a,xp);

            // Fill the index arrays.
            y.I = I;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to CPU_methods.spfadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fscp().
        GPU_Sparse_f scp ( const float a ) {
            
            // Initialize result Vector.
            GPU_Sparse_f y(Size[0],Size[1],Size[2]);

            // Create pointers.
            const thrust::device_vector<float> * xp = &Values;

            // Call GPU_methods.fscp().
            y.Values = fscp(a,xp);

            // Fill the index arrays.
            y.I = I;
            y.J = J;

            // Return the result.
            return y;

        }

        // Links to GPU_methods.spfgemv().
        GPU_Dense_f mv ( const GPU_Dense_f& x ) {

            // Initialize result Vector.
            GPU_Dense_f y(Size[0],1);

            if ((Size[1] == x.Size[0]) && (x.isVector == 1)) {

                // Create pointers.
                const float * Vp = thrust::raw_pointer_cast(&Values[0]);
                const int * Ip = thrust::raw_pointer_cast(&I[0]);
                const int * Jp = thrust::raw_pointer_cast(&J[0]);
                const float * xp = thrust::raw_pointer_cast(&x.Values[0]);

                // Call GPU_methods.spdgemv().
                y.Values = spfgemv(Size[0],Size[1],Size[2],Vp,Ip,Jp,xp,descr);

            } else { std::cout << "ERROR: Input GPU_Sparse_f.mv()" << std::endl; }

            // Return the result.
            return y;

        }

        // Links to GPU_methods.spfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Constructor
        GPU_Sparse_f ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[0] + 1);
            J.resize(Size[2]);

            // Fill matrix description.
            _handles->csstatus = cusparseCreateMatDescr(&descr);
            _handles->csstatus = cusparseSetMatType(descr,CUSPARSE_MATRIX_TYPE_GENERAL);
            _handles->csstatus = cusparseSetMatIndexBase(descr,CUSPARSE_INDEX_BASE_ZERO);

        }
};