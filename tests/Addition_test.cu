#include "../include/CMaT.h"

int main () {

GPU_Dense_f A(3,2);
GPU_Dense_f B(3,2);

A.Values[0] = 1; A.Values[1] = 2; A.Values[2] = 3;
A.Values[3] = 4; A.Values[4] = 5; A.Values[5] = 6;
B.Values[0] = 1; B.Values[1] = 2; B.Values[2] = 3;
B.Values[3] = 4; B.Values[4] = 5; B.Values[5] = 6;

GPU_Dense_f C = A.add(B);

C.print();

return 0;

}