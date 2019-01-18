#include <iostream>
#include "Classes/Backend_class.h"
#include "Classes/Matrix_class.h"
#include "Classes/Sparse_class.h"
#include "Classes/User_class.h"

int main() {
    
    CPU_CSC A;
    CPU_CSC B;

    A.size[0] = 1;
    A.size[1] = 1;
    A.type = 'f';
    A.nnz = 1;
    A.base = 1;
    A.i = 1;
    A.j = 1;
    A.values = 1;

    B = A.clone();

    std::cout << B.i << std::endl;

    return 0;
}