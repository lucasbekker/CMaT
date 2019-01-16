// CPU backend base class.
class CPU {
    public:
        // Methods
        void conv (  ) {
            // This method converts from the CPU backend to the GPU backend.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.conv" << std::endl;
        }

        void ialloc (  ) {
            // This method allocates memory on the host for type int.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.ialloc" << std::endl;
        }

        void falloc (  ) {
            // This method allocates memory on the host for type float.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.falloc" << std::endl;
        }

        void dalloc (  ) {
            // This method allocates memory on the host for type double.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.dalloc" << std::endl;
        }

        void dt (  ) {
            // This method calculates the dot product using MKL.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.dt" << std::endl;
        }

        void spgemm (  ) {
            // This method calculates the sparse matrix-matrix product using MKL.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.spgemm" << std::endl;
        }

        void spgemv (  ) {
            // This method calculates the sparse matrix-vector product using MKL.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.spgemv" << std::endl;
        }

        void fgemm (  ) {
            // This method calculates the full matrix-matrix product using MKL.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.fgemm" << std::endl;
        }

        void fgemv (  ) {
            // This method calculates the full matrix-vector product using MKL.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.fgemv" << std::endl;
        }
    };

// GPU backend base class.
class GPU {
    public:
        // Methods
        void conv (  ) {
            // This method converts from the GPU backend to the GPU backend.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.conv" << std::endl;
        }

        void ialloc (  ) {
            // This method allocates memory on the host for type int.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.ialloc" << std::endl;
        }

        void falloc (  ) {
            // This method allocates memory on the host for type float.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.falloc" << std::endl;
        }

        void dalloc (  ) {
            // This method allocates memory on the host for type double.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.dalloc" << std::endl;
        }

        void dt (  ) {
            // This method calculates the dot product using cuBLAS.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.dt" << std::endl;
        }

        void spgemm (  ) {
            // This method calculates the sparse matrix-matrix product using cuSPARSE.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.spgemm" << std::endl;
        }

        void spgemv (  ) {
            // This method calculates the sparse matrix-vector product using cuSPARSE.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.spgemv" << std::endl;
        }

        void fgemm (  ) {
            // This method calculates the full matrix-matrix product using cuBLAS.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.fgemm" << std::endl;
        }

        void fgemv (  ) {
            // This method calculates the full matrix-vector product using cuBLAS.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.fgemv" << std::endl;
        }
    };