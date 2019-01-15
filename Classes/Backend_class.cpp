// CPU backend base class.
class CPU {
    public:
        // Methods
        void conv (  ) {
            // This method converts from the CPU backend to the GPU backend.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.conv" << std::endl;
        }

        void alloc (  ) {
            // This method allocates memory on the host.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.alloc" << std::endl;
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

        void alloc (  ) {
            // This method allocates memory on the device.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "GPU.alloc" << std::endl;
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