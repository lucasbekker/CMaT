#include "include/CMaT.h"

int main (  ) {
    
    CPU_Dense A(4,1);

    A.Values[0]=1;
    A.Values[1]=2;
    A.Values[2]=3;
    A.Values[3]=4;

    std::cout << A.Values[3] << std::endl;
    std::cout << A.Values[5] << std::endl;
    std::cout << A.Size[0] << std::endl;
    std::cout << A.isVector << std::endl;

    CPU_Dense B(4,1,0);

    std::cout << B.isVector << std::endl;
    
    return 0;
}