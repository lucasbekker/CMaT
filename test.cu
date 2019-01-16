#include <iostream>
#include "Classes/Backend_class.h"
#include "Classes/Matrix_class.h"
#include "Classes/Sparse_class.h"
#include "Classes/User_class.h"

int main() {
    
    CPU_Vector A;

    thrust::host_vector<int> test = A.ialloc(10);

    test[0] = 1;

    std::cout << "element 1: " << test[0] << std::endl;

    return 0;
}