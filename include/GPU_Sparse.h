class GPU_Sparse: public GPU_methods {
    public:
        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[2] storing type double.
        int Size[3];                           // Array containing [ m, n, nnz ]
        thrust::device_vector<int> I;          // Device vector of length Size[0] + 1 storing pointer list type int.
        thrust::device_vector<int> J;          // Device vector of length Size[2] storing type int.
        
        // Methods
        // Links to GPU_methods.dadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.spdadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dscp().
        void scp (  ) { std::cout << "empty" << std::endl; }
        
        // Links to GPU_methods.spdgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.spdgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Constructor
        GPU_Sparse ( int m, int n, int nnz, HANDLES * _handles ): GPU_methods(_handles) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[0] + 1);
            J.resize(Size[2]);

        }
};

class GPU_Sparse_f: public GPU_methods {
    public:
        // Data
        thrust::device_vector<float> Values;  // Device vector of length Size[2] storing type float.
        int Size[3];                          // Array containing [ m, n, nnz ]
        thrust::device_vector<int> I;         // Device vector of length Size[0] + 1 storing pointer list type int.
        thrust::device_vector<int> J;         // Device vector of length Size[2] storing type int.
        HANDLES * handles;                     // Handles to CUDA libraries.

        // Methods
        // Links to GPU_methods.fadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.spfadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.spfgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.spfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }

        // Constructor
        GPU_Sparse_f ( int m, int n, int nnz, HANDLES * _handles ): GPU_methods(_handles)  {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[0] + 1);
            J.resize(Size[2]);

        }
};