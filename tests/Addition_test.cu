#include "../include/CMaT.h"

int main () {

GPU_Dense A(3,2);
GPU_Dense B(3,2);

A.Values[0] = 1; A.Values[1] = 2; A.Values[2] = 3;
A.Values[3] = 4; A.Values[4] = 5; A.Values[5] = 6;
B.Values[0] = 1; B.Values[1] = 2; B.Values[2] = 3;
B.Values[3] = 4; B.Values[4] = 5; B.Values[5] = 6;

GPU_Dense C = A.madd(B);

std::cout << C.Values[0] << std::endl;
std::cout << C.Values[1] << std::endl;
std::cout << C.Values[2] << std::endl;
std::cout << C.Values[3] << std::endl;
std::cout << C.Values[4] << std::endl;
std::cout << C.Values[5] << std::endl;

return 0;

}