#include<iostream>

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

class CPU_methods {
    public:        
        // Dense float matrix vector product. (MKL)
        void dfgemv (  ) { std::cout << "empty" << std::endl; }

        // Dense double matrix vector product. (MKL)
        void ddgemv (  ) { std::cout << "empty" << std::endl; }

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

class GPU_methods {
    public:
        // Dense float matrix vector product. (cuBLAS)
        void dfgemv (  ) { std::cout << "empty" << std::endl; }

        // Dense double matrix vector product. (cuBLAS)
        void ddgemv (  ) { std::cout << "empty" << std::endl; }

        // Dense float matrix matrix product. (cuBLAS)
        void dfgemm (  ) { std::cout << "empty" << std::endl; }

        // Dense double matrix matrix product. (cuBLAS)
        void ddgemm (  ) { std::cout << "empty" << std::endl; }

        // Sparse float matrix vector product. (cuSPARSE)
        void spfgemv (  ) { std::cout << "empty" << std::endl; }

        // Sparse double matrix vector product. (cuSPARSE)
        void spdgemv (  ) { std::cout << "empty" << std::endl; }

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

class CPU_Dense: public CPU_Methods {
    public:
        // Data
        thrust::host_vector<double> Values;    // Host vector of length Size[3] storing type double. (MISSING SIZE)
        int Size[3];                           // Array containing [ n, m, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to CPU_methods.dadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.dadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.dscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.ddot().
        void dot (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.ddgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.ddgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class CPU_Dense_f: public CPU_Methods {
    public:
        // Data
        thrust::host_vector<float> Values;   // Host vector of length Size[3] storing type float. (MISSING SIZE)
        int Size[3];                         // Array containing [ n, m, n*m ]
        int isVector;                        // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to CPU_methods.fadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.fadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.fscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.fdot().
        void dot (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.dfgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.dfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class GPU_Dense: public GPU_Methods {
    public:
        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[3] storing type double. (MISSING SIZE)
        int Size[3];                           // Array containing [ n, m, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to GPU_methods.dadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.ddot().
        void dot (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.ddgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.ddgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class GPU_Dense_f: public GPU_Methods {
    public:
        // Data
        thrust::device_vector<float> Values;   // Device vector of length Size[3] storing type float. (MISSING SIZE)
        int Size[3];                           // Array containing [ n, m, n*m ]
        int isVector;                          // Zero if it is not a Vector and One if it is a Vector.

        // Methods
        // Links to GPU_methods.fadd().
        void add (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fadd().
        void madd (  ) { std::cout << "empty" << std::endl; }

        // Transposes the Matrix or Vector.
        void trans (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fscp().
        void scp (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fdot().
        void dot (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dfgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.dfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class CPU_Sparse: public CPU_Methods {
    public:
        // Data
        thrust::host_vector<double> Values;  // Host vector of length Size[3] storing type double. (MISSING SIZE)
        int Size[3];                         // Array containing [ n, m, nnz ]
        thrust::host_vector<int> I;          // Host vector of length Size[m] storing pointer list type int. (MISSING SIZE)
        thrust::host_vector<int> J;          // Host vector of length Size[3] storing type int. (MISSING SIZE)

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
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.spdgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class CPU_Sparse_f: public CPU_Methods {
    public:
        // Data
        thrust::host_vector<float> Values;   // Host vector of length Size[3] storing type float. (MISSING SIZE)
        int Size[3];                         // Array containing [ n, m, nnz ]
        thrust::host_vector<int> I;          // Host vector of length Size[m] storing pointer list type int. (MISSING SIZE)
        thrust::host_vector<int> J;          // Host vector of length Size[3] storing type int. (MISSING SIZE)

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
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.spfgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class GPU_Sparse: public GPU_Methods {
    public:
        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[3] storing type double. (MISSING SIZE)
        int Size[3];                           // Array containing [ n, m, nnz ]
        thrust::device_vector<int> I;          // Device vector of length Size[m] storing pointer list type int. (MISSING SIZE)
        thrust::device_vector<int> J;          // Device vector of length Size[3] storing type int. (MISSING SIZE)

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
};

class GPU_Sparse_f: public GPU_Methods {
    public:
        // Data
        thrust::device_vector<float> Values;  // Device vector of length Size[3] storing type float. (MISSING SIZE)
        int Size[3];                          // Array containing [ n, m, nnz ]
        thrust::device_vector<int> I;         // Device vector of length Size[m] storing pointer list type int. (MISSING SIZE)
        thrust::device_vector<int> J;         // Device vector of length Size[3] storing type int. (MISSING SIZE)

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
};