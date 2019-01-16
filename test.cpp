#include <iostream>
#include "Classes/Backend_class.h"
#include "Classes/Matrix_class.h"
#include "Classes/Sparse_class.h"
#include "Classes/User_class.h"

int main() {
    
    CPU_COO A;

    A.size = 3;

    std::cout << "the size of A: " << A.size << std::endl;

    CPU_Vector B;

    int test;

    test = B.dot(3);
    
    B.add();

    std::cout << "B.dot: " << test << std::endl;

    return 0;
}