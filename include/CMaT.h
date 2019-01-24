#include <iostream>

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

#include "mkl.h"

class CPU_methods {
    public:        
        // Dense float matrix vector product. (MKL)
        thrust::host_vector<double> dfgemv ( int m, int n ) {
                        
            // MKL function.
            // y := alpha*A*x + beta*y
            // alpha and beta are scalars.
            // x and y are vectors.
            // A is an m-by-n matrix.
            //cblas_dgemv ( CblasRowMajor, CblasNoTrans, m, n, alpha, const double *a, const int lda, *x, const int incx, beta, *y, const int incy);

        }

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

class CPU_Dense: public CPU_methods {
    public:
        // Data
        thrust::host_vector<double> Values;    // Host vector of length Size[2] storing type double.
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

        // Constructor
        CPU_Dense ( int m, int n ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( Size[1] == 1 ) {
                isVector = 1;
            }
            else {
                isVector = 0;
            }

        }

        // Overloaded constructor for manual isVector manipulation.
        CPU_Dense ( int m, int n, int isv ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( isv == 0 ) {
                isVector = 0;
            }
            else {
                isVector = 1;
            }

        }
};

class CPU_Dense_f: public CPU_methods {
    public:
        // Data
        thrust::host_vector<float> Values;   // Host vector of length Size[2] storing type float.
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

        // Constructor
        CPU_Dense_f ( int m, int n ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( Size[1] == 1 ) {
                isVector = 1;
            }
            else {
                isVector = 0;
            }

        }

        // Overloaded constructor for manual isVector manipulation.
        CPU_Dense_f ( int m, int n, int isv ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( isv == 0 ) {
                isVector = 0;
            }
            else {
                isVector = 1;
            }

        }
};

class GPU_Dense: public GPU_methods {
    public:
        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[2] storing type double.
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

        // Constructor
        GPU_Dense ( int m, int n ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( Size[1] == 1 ) {
                isVector = 1;
            }
            else {
                isVector = 0;
            }

        }

        // Overloaded constructor for manual isVector manipulation.
        GPU_Dense ( int m, int n, int isv ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( isv == 0 ) {
                isVector = 0;
            }
            else {
                isVector = 1;
            }

        }
};

class GPU_Dense_f: public GPU_methods {
    public:
        // Data
        thrust::device_vector<float> Values;   // Device vector of length Size[2] storing type float.
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

        // Constructor
        GPU_Dense_f ( int m, int n ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( Size[1] == 1 ) {
                isVector = 1;
            }
            else {
                isVector = 0;
            }

        }

        // Overloaded constructor for manual isVector manipulation.
        GPU_Dense_f ( int m, int n, int isv ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = m*n;

            // Allocate sufficient memory.
            Values.resize(Size[2]);

            // Check if it is a Vector.
            if ( isv == 0 ) {
                isVector = 0;
            }
            else {
                isVector = 1;
            }

        }
};

class CPU_Sparse: public CPU_methods {
    public:
        // Data
        thrust::host_vector<double> Values;  // Host vector of length Size[2] storing type double.
        int Size[3];                         // Array containing [ n, m, nnz ]
        thrust::host_vector<int> I;          // Host vector of length Size[1] + 1 storing pointer list type int.
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
        void mv (  ) { std::cout << "empty" << std::endl; }

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
            I.resize(Size[1] + 1);
            J.resize(Size[2]);

        }
};

class CPU_Sparse_f: public CPU_methods {
    public:
        // Data
        thrust::host_vector<float> Values;   // Host vector of length Size[2] storing type float.
        int Size[3];                         // Array containing [ n, m, nnz ]
        thrust::host_vector<int> I;          // Host vector of length Size[1] + 1 storing pointer list type int.
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
        void mv (  ) { std::cout << "empty" << std::endl; }

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
            I.resize(Size[1] + 1);
            J.resize(Size[2]);

        }
};

class GPU_Sparse: public GPU_methods {
    public:
        // Data
        thrust::device_vector<double> Values;  // Device vector of length Size[2] storing type double.
        int Size[3];                           // Array containing [ n, m, nnz ]
        thrust::device_vector<int> I;          // Device vector of length Size[1] + 1 storing pointer list type int.
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
        GPU_Sparse ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[1] + 1);
            J.resize(Size[2]);

        }
};

class GPU_Sparse_f: public GPU_methods {
    public:
        // Data
        thrust::device_vector<float> Values;  // Device vector of length Size[2] storing type float.
        int Size[3];                          // Array containing [ n, m, nnz ]
        thrust::device_vector<int> I;         // Device vector of length Size[1] + 1 storing pointer list type int.
        thrust::device_vector<int> J;         // Device vector of length Size[2] storing type int.

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
        GPU_Sparse_f ( int m, int n, int nnz ) {
            
            // Fill Size array.
            Size[0] = m;
            Size[1] = n;
            Size[2] = nnz;

            // Allocate sufficient memory.
            Values.resize(Size[2]);
            I.resize(Size[1] + 1);
            J.resize(Size[2]);

        }
};