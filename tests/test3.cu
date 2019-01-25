#include "include/CMaT.h"

int main () {

CPU_Dense_f A(4,3);
CPU_Dense_f B(3,1);

//A.Values[0] = 2;
//A.Values[1] = 0;
//A.Values[2] = 0;
//A.Values[3] = 0;
//A.Values[4] = 2;
//A.Values[5] = 0;
//A.Values[6] = 0;
//A.Values[7] = 0;
//A.Values[8] = 2;
//A.Values[9] = 1;
//A.Values[10] = 1;
//A.Values[11] = 1;

A.Values[0] = 2;
A.Values[1] = 0;
A.Values[2] = 0;
A.Values[3] = 1;
A.Values[4] = 0;
A.Values[5] = 2;
A.Values[6] = 0;
A.Values[7] = 1;
A.Values[8] = 0;
A.Values[9] = 0;
A.Values[10] = 2;
A.Values[11] = 1;

B.Values[0] = 3;
B.Values[1] = 3;
B.Values[2] = 3;

thrust::host_vector<float> result;

result = A.dfgemv(4,3,A.Values,B.Values);

std::cout << result.size() << std::endl;
std::cout << result[0] << std::endl;
std::cout << result[1] << std::endl;
std::cout << result[2] << std::endl;
std::cout << result[3] << std::endl;

}