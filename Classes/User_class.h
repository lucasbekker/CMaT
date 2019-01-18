// User accecible derived class.

// CPU backend classes.
class CPU_COO: public CPU, public COO {
    public:
        // Methods
        CPU_COO clone (  ) {
            // Initiate my_clone.
            CPU_COO my_clone;

            // Copy the attributes from Matrix.
            my_clone.size[0] = size[0];
            my_clone.size[1] = size[1];
            my_clone.values = values;
            my_clone.type = type;

            // Copy the attributes from Sparse.
            my_clone.nnz = nnz;
            my_clone.base = base;
            my_clone.i = i;
            my_clone.j = j;

            return my_clone;
        }
};

class CPU_CSC: public CPU, public CSC {
    public:
        // Methods
        CPU_CSC clone (  ) {
            // Initiate my_clone.
            CPU_CSC my_clone;

            // Copy the attributes from Matrix.
            my_clone.size[0] = size[0];
            my_clone.size[1] = size[1];
            my_clone.values = values;
            my_clone.type = type;

            // Copy the attributes from Sparse.
            my_clone.nnz = nnz;
            my_clone.base = base;
            my_clone.i = i;
            my_clone.j = j;

            return my_clone;
        }
};

class CPU_CSR: public CPU, public CSR {
    public:
        // Methods
        CPU_CSR clone (  ) {
            // Initiate my_clone.
            CPU_CSR my_clone;

            // Copy the attributes from Matrix.
            my_clone.size[0] = size[0];
            my_clone.size[1] = size[1];
            my_clone.values = values;
            my_clone.type = type;

            // Copy the attributes from Sparse.
            my_clone.nnz = nnz;
            my_clone.base = base;
            my_clone.i = i;
            my_clone.j = j;

            return my_clone;
        }
};

class CPU_Vector: public CPU, public Vector {};

class CPU_Full_Matrix: public CPU, public Full {};

// GPU backend classes.
class GPU_COO: public GPU, public COO {
    public:
        // Methods
        GPU_COO clone (  ) {
            // Initiate my_clone.
            GPU_COO my_clone;

            // Copy the attributes from Matrix.
            my_clone.size[0] = size[0];
            my_clone.size[1] = size[1];
            my_clone.values = values;
            my_clone.type = type;

            // Copy the attributes from Sparse.
            my_clone.nnz = nnz;
            my_clone.base = base;
            my_clone.i = i;
            my_clone.j = j;

            return my_clone;
        }
};

class GPU_CSC: public GPU, public CSC {
    public:
        // Methods
        GPU_CSC clone (  ) {
            // Initiate my_clone.
            GPU_CSC my_clone;

            // Copy the attributes from Matrix.
            my_clone.size[0] = size[0];
            my_clone.size[1] = size[1];
            my_clone.values = values;
            my_clone.type = type;

            // Copy the attributes from Sparse.
            my_clone.nnz = nnz;
            my_clone.base = base;
            my_clone.i = i;
            my_clone.j = j;

            return my_clone;
        }
};

class GPU_CSR: public GPU, public CSR {
    public:
        // Methods
        GPU_CSR clone (  ) {
            // Initiate my_clone.
            GPU_CSR my_clone;

            // Copy the attributes from Matrix.
            my_clone.size[0] = size[0];
            my_clone.size[1] = size[1];
            my_clone.values = values;
            my_clone.type = type;

            // Copy the attributes from Sparse.
            my_clone.nnz = nnz;
            my_clone.base = base;
            my_clone.i = i;
            my_clone.j = j;

            return my_clone;
        }
};

class GPU_Vector: public GPU, public Vector {};
class GPU_Full_Matrix: public GPU, public Full {};