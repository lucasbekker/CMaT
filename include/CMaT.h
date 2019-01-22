#include<iostream>

class CPU_methods {
    public:        
        // Full float matrix vector product. (MKL)
        void ffgemv (  ) { std::cout << "empty" << std::endl; }

        // Full double matrix vector product. (MKL)
        void fdgemv (  ) { std::cout << "empty" << std::endl; }

        // Full float matrix matrix product. (MKL)
        void ffgemm (  ) { std::cout << "empty" << std::endl; }

        // Full double matrix matrix product. (MKL)
        void fdgemm (  ) { std::cout << "empty" << std::endl; }

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
        // Full float matrix vector product. (cuBLAS)
        void ffgemv (  ) { std::cout << "empty" << std::endl; }

        // Full double matrix vector product. (cuBLAS)
        void fdgemv (  ) { std::cout << "empty" << std::endl; }

        // Full float matrix matrix product. (cuBLAS)
        void ffgemm (  ) { std::cout << "empty" << std::endl; }

        // Full double matrix matrix product. (cuBLAS)
        void fdgemm (  ) { std::cout << "empty" << std::endl; }

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

class CPU_Full: public CPU_Methods {
    public:
        // Data
        double Values;  // Host vector of length Size[3] storing type double.
        int Size[3];    // Array containing [ n, m, n*m ]
        int isVector;   // Zero if it is not a Vector and One if it is a Vector.

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

        // Links to CPU_methods.fdgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.fdgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class CPU_Full_f: public CPU_Methods {
    public:
        // Data
        float Values;   // Host vector of length Size[3] storing type float.
        int Size[3];    // Array containing [ n, m, n*m ]
        int isVector;   // Zero if it is not a Vector and One if it is a Vector.

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

        // Links to CPU_methods.ffgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to CPU_methods.ffgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class GPU_Full: public GPU_Methods {
    public:
        // Data
        double Values;  // Device vector of length Size[3] storing type double.
        int Size[3];    // Array containing [ n, m, n*m ]
        int isVector;   // Zero if it is not a Vector and One if it is a Vector.

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

        // Links to GPU_methods.fdgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.fdgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class GPU_Full_f: public GPU_Methods {
    public:
        // Data
        float Values;   // Device vector of length Size[3] storing type float.
        int Size[3];    // Array containing [ n, m, n*m ]
        int isVector;   // Zero if it is not a Vector and One if it is a Vector.

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

        // Links to GPU_methods.ffgemv().
        void mv (  ) { std::cout << "empty" << std::endl; }

        // Links to GPU_methods.ffgemm().
        void mm (  ) { std::cout << "empty" << std::endl; }

        // Make a clone.
        void clone (  ) { std::cout << "empty" << std::endl; }

        // Convert the backend type
        void conv (  ) { std::cout << "empty" << std::endl; }
};

class CPU_Sparse: public CPU_Methods {
    public:
        // Data
        double Values;  // Host vector of length Size[3] storing type double.
        int Size[3];    // Array containing [ n, m, nnz ]
        int I;          // Host vector of length Size[m] storing pointer list type int.
        int J;          // Host vector of length Size[m] storing type int.

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
        float Values;   // Host vector of length Size[3] storing type float.
        int Size[3];    // Array containing [ n, m, nnz ]
        int I;          // Host vector of length Size[m] storing pointer list type int.
        int J;          // Host vector of length Size[m] storing type int.

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
        double Values;  // Device vector of length Size[3] storing type double.
        int Size[3];    // Array containing [ n, m, nnz ]
        int I;          // Device vector of length Size[m] storing pointer list type int.
        int J;          // Device vector of length Size[m] storing type int.

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
        double Values;  // Device vector of length Size[3] storing type float.
        int Size[3];    // Array containing [ n, m, nnz ]
        int I;          // Device vector of length Size[m] storing pointer list type int.
        int J;          // Device vector of length Size[m] storing type int.

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