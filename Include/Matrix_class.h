// Matrix base class.
class Matrix {
    public:
        // Data
        int size;
        int values;
};

// Vector derived class.
class Vector: public Matrix {
    public:
        // Methods
        int dot ( int test ) {}

        void add (  ) {}

        void trans (  ) {}
};

// Full derived class.
class Full: public Matrix {
    public:
        // Methods
        void mm (  ) {}

        void mv (  ) {}

        void add (  ) {}

        void trans (  ) {}
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
