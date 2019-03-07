#include "../include/CMaT.h"

int main(){

GPU_Dense_f A(3,2);

A.Values[0] = 1;
A.Values[1] = 3;
A.Values[2] = 5;
A.Values[3] = 2;
A.Values[4] = 4;
A.Values[5] = 6;

GPU_Dense_f B = A.trans();

for (int i = 0; i < B.Size[2]; i++) {
    std::cout << B.Values[i] << std::endl;
}

return 0;
}