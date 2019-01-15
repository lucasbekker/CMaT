#include <iostream>
#include <Backend_class.cpp>
#include <Matrix_class.cpp>
#include <Sparse_class.cpp>
#include <User_class.cpp>

int main() {
    
    CPU_COO A;

    A.size = 3;

    std::cout << "the size of A: " << A.size << std::endl;
    
    return 0;
}