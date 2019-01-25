#include "include/CMaT.h"

int main () {

CPU_Dense A(3,3);
CPU_Dense B(3,1);

A.Values[0] = 2;
A.Values[1] = 0;
A.Values[2] = 0;
A.Values[3] = 0;
A.Values[4] = 2;
A.Values[5] = 0;
A.Values[6] = 0;
A.Values[7] = 0;
A.Values[8] = 2;

B.Values[0] = 3;
B.Values[1] = 3;
B.Values[2] = 3;

thrust::host_vector<double> result;

result = A.ddgemv(3,3,A.Values,B.Values);

std::cout << result[0] << std::endl;
std::cout << result[1] << std::endl;
std::cout << result[2] << std::endl;


}