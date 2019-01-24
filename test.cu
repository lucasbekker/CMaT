#include<iostream>

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

class matrix {
    public:
        thrust::host_vector<int> Values;
};

int main (  ) {

    matrix A;

    A.Values.resize(4);

    A.Values[0]=1;
    A.Values[1]=2;
    A.Values[2]=3;
    A.Values[3]=4;

    std::cout << A.Values[3] << std::endl;
    std::cout << A.Values[5] << std::endl;

    return 0;
}