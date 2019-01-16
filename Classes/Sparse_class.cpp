#include <iostream>
#include "Include/Matrix_class.h"

// COO derived class.
class COO: public Sparse {
    public:
        // Methods
        void mm (  ) {
            // This method calculates the matrix-matrix product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "COO.mm" << std::endl;
        }

        void mv (  ) {
            // This method calculates the matrix-vector product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "COO.mv" << std::endl;
        }

        void add (  ) {
            // This method adds (element wise) two matrices.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "COO.add" << std::endl;
        }

        void trans (  ) {
            // This method transposes the matrix.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "COO.trans" << std::endl;
        }
};

// CSC derived class.
class CSC: public Sparse {
    public:
        // Methods
        void mm (  ) {
            // This method calculates the matrix-matrix product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CSC.mm" << std::endl;
        }

        void mv (  ) {
            // This method calculates the matrix-vector product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CSC.mv" << std::endl;
        }

        void add (  ) {
            // This method adds (element wise) two matrices.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CSC.add" << std::endl;
        }

        void trans (  ) {
            // This method transposes the matrix.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CSC.trans" << std::endl;
        }
};

// CSR derived class.
class CSR: public Sparse {
    public:
        // Methods
        void mm (  ) {
            // This method calculates the matrix-matrix product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CSR.mm" << std::endl;
        }

        void mv (  ) {
            // This method calculates the matrix-vector product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CSR.mv" << std::endl;
        }

        void add (  ) {
            // This method adds (element wise) two matrices.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CSR.add" << std::endl;
        }

        void trans (  ) {
            // This method transposes the matrix.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "CSR.trans" << std::endl;
        }
};