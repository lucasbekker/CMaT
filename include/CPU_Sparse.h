class CPU_Sparse: public CPU_methods {
    public:
        // Based on MKL CSR four array zero based indexing.
        // https://software.intel.com/en-us/mkl-developer-reference-c-sparse-blas-csr-matrix-storage-format

        // Data
        thrust::host_vector<double> Values;  // Host vector of length Size[2] storing type double.
        int Size[3];                         // Array containing [ m, n, nnz ]
        thrust::host_vector<int> Ib;         // Host vector of length Size[0] storing pointer list type int.
        thrust::host_vector<int> Ie;         // Host vector of length Size[0] storing pointer list type int.
        thrust::host_vector<int> J;          // Host vector of length Size[2] storing type int.

        // Methods
        // Links to CPU_methods.dadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.spdadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.dscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.spdgemv().
        CPU_Dense mv ( const CPU_Dense& x  ) {

            // Initialize result Vector.
            CPU_Dense y(Size[0],1);

            // Create pointers.
            const double * Vp = thrust::raw_pointer_cast(&Values[0]);
            const int * Ibp = thrust::raw_pointer_cast(&Ib[0]);
            const int * Iep = thrust::raw_pointer_cast(&Ie[0]);
            const int * Jp = thrust::raw_pointer_cast(&J[0]);
            const double * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.spdgemv().
            y.Values = this->spdgemv(Size[0],Size[1],Vp,Ibp,Iep,Jp,xp);

            // Return the result.
            return y;

        }

        // Links to CPU_methods.spdgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Constructor
        CPU_Sparse ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            Ib.resize(Size[0]);
            Ie.resize(Size[0]);
            J.resize(Size[2]);

        }
};

class CPU_Sparse_f: public CPU_methods {
    public:
        // Based on MKL CSR four array zero based indexing.
        // https://software.intel.com/en-us/mkl-developer-reference-c-sparse-blas-csr-matrix-storage-format

        // Data
        thrust::host_vector<float> Values;   // Host vector of length Size[2] storing type float.
        int Size[3];                         // Array containing [ m, n, nnz ]
        thrust::host_vector<int> Ib;         // Host vector of length Size[0] storing pointer list type int.
        thrust::host_vector<int> Ie;         // Host vector of length Size[0] storing pointer list type int.
        thrust::host_vector<int> J;          // Host vector of length Size[2] storing type int.

        // Methods
        // Links to CPU_methods.fadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.spfadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.fscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.spfgemv().
        CPU_Dense_f mv ( const CPU_Dense_f& x  ) {

            // Initialize result Vector.
            CPU_Dense_f y(Size[0],1);

            // Create pointers.
            const float * Vp = thrust::raw_pointer_cast(&Values[0]);
            const int * Ibp = thrust::raw_pointer_cast(&Ib[0]);
            const int * Iep = thrust::raw_pointer_cast(&Ie[0]);
            const int * Jp = thrust::raw_pointer_cast(&J[0]);
            const float * xp = thrust::raw_pointer_cast(&x.Values[0]);

            // Call CPU_methods.spfgemv().
            y.Values = this->spfgemv(Size[0],Size[1],Vp,Ibp,Iep,Jp,xp);

            // Return the result.
            return y;

        }
        // Links to CPU_methods.spfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Constructor
        CPU_Sparse_f ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            Ib.resize(Size[0]);
            Ie.resize(Size[0]);
            J.resize(Size[2]);

        }
};