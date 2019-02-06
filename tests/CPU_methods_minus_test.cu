#include "../include/CMaT.h"

int main (  ) { 

GPU_Dense test(3,1);
thrust::device_vector<double> result1(3);
thrust::device_vector<double> result2(3);
const double a = 4.0;

test.Values[0] = 1;
test.Values[1] = 2;
test.Values[2] = 3;

// Create pointers.
const thrust::device_vector<double> * xp = &test.Values;

result1 = test.dadd(a,xp,0);
result2 = test.dadd(a,xp,1);

std::cout << result1[0] << std::endl;
std::cout << result2[0] << std::endl;

}