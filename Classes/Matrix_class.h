// Matrix base class.
class Matrix {
    public:
        // Data
        int size[2];
        int values;
        char type;
};

// Vector derived class.
class Vector: public Matrix {
    public:
        // Methods
        void conv (  ) {
            // This method converts the backend.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Vector.conv" << std::endl;
        }

        void sc (  ) {
            // This method calculates the vector scalar product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Vector.sc" << std::endl;
        }

        void dot (  ) {
            // This method calculates the vector dot product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Vector.dot" << std::endl;
        }

        void add (  ) {
            // This method adds (element wise) two vectors.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Vector.add" << std::endl;
        }

        void trans (  ) {
            // This method transposes the vector.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Vector.trans" << std::endl;
        }
};

// Full derived class.
class Full: public Matrix {
    public:
        // Methods
        void conv (  ) {
            // This method converts the backend.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Full.conv" << std::endl;
        }

        void sc (  ) {
            // This method calculates the matrix scalar product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Full.sc" << std::endl;
        }

        void mm (  ) {
            // This method calculates the matrix-matrix product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Full.mm" << std::endl;
        }

        void mv (  ) {
            // This method calculates the matrix-vector product.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Full.mv" << std::endl;
        }

        void add (  ) {
            // This method adds (element wise) two matrix.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Full.add" << std::endl;
        }

        void trans (  ) {
            // This method transposes the matrix.
            std::cout << "Empty at the moment..." << std::endl;
            std::cout << "Full.trans" << std::endl;
        }
};

// Sparse derived class.
class Sparse: public Matrix {
    public:
        // Data
        int nnz;
        int base;
        int i;
        int j;
};
