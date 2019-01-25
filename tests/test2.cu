#include <iostream>

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

thrust::host_vector<double> function ( thrust::host_vector<double> in ) {

    thrust::host_vector<double> out(in.size());

    for(int i = 0; i < out.size(); i++) {
        out[i] = 1.0;
    }

    return out;
}

int main () {
    
    thrust::host_vector<double> test(10);
    
    thrust::host_vector<double> result;

    result = function(test);

    std::cout << result.size() << std::endl;

}