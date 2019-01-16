#include "thrust/host_vector.h"
#include "thrust/device_vector.h"

// CPU backend base class.
class CPU {
    public:
        // Methods
        void conv (  ) {
            // This method converts from the CPU backend to the GPU backend.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CPU.conv" << std::endl;
        }

        thrust::host_vector<int> ialloc ( int length ) {
            // This method allocates memory on the host for type int.
            
            thrust::host_vector<int> h_vec( length );

            return h_vec;
        }

        thrust::host_vector<float> falloc ( int length ) {
            // This method allocates memory on the host for type float.
            
            thrust::host_vector<float> h_vec( length );

            return h_vec;
        }

        thrust::host_vector<double> dalloc ( int length ) {
            // This method allocates memory on the host for type double.
            
            thrust::host_vector<double> h_vec( length );

            return h_vec;
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

        thrust::device_vector<int> ialloc ( int length ) {
            // This method allocates memory on the device for type int.
            
            thrust::device_vector<int> d_vec( length );

            return d_vec;
        }

        thrust::device_vector<float> falloc ( int length ) {
            // This method allocates memory on the device for type float.
            
            thrust::device_vector<float> d_vec( length );

            return d_vec;
        }

        thrust::device_vector<double> dalloc ( int length ) {
            // This method allocates memory on the device for type double.
            
            thrust::device_vector<double> d_vec( length );

            return d_vec;
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
