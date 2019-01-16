#include "Include/Backend_class.h"
#include "Include/Matrix_class.h"
#include "Include/Sparse_class.h"

// User accecible derived class.

// CPU backend classes.
class CPU_COO: public CPU, public COO {};
class CPU_CSC: public CPU, public CSC {};
class CPU_CSR: public CPU, public CSR {};
class CPU_Vector: public CPU, public Vector {};
class CPU_Full_Matrix: public CPU, public Full {};

// GPU backend classes.
class GPU_COO: public GPU, public COO {};
class GPU_CSC: public GPU, public CSC {};
class GPU_CSR: public GPU, public CSR {};
class GPU_Vector: public GPU, public Vector {};
class GPU_Full_Matrix: public GPU, public Full {};