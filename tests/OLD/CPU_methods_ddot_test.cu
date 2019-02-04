#include "../include/CMaT.h"

// Test CPU_methods.ddot()
int main (  ) {

    // Check.
    int pass = 1;

    // Initialize vectors.
    CPU_Dense x(3,1);
    CPU_Dense y(3,1);

    // Fill vector x.
    x.Values[0] = 1;
    x.Values[1] = 2;
    x.Values[2] = 3;

    // Fill vector y.
    y.Values[0] = 4;
    y.Values[1] = 5;
    y.Values[2] = 6;

    // Create pointers.
    thrust::host_vector<double> * xp = &x.Values;
    thrust::host_vector<double> * yp = &y.Values;

    // Perform calculations.
    double r = x.ddot(xp,yp);

    // Check for errors.
    if (r == 32) { 
        std::cout << "The result is correct." << std::endl; 
    } else {
        std::cout << "The result is not correct." << std::endl;
        pass = 0;
    }
    
    // Print test result.
    if (pass == 1) {
        std::cout << "Test of CPU_methods.ddot() passed" << std::endl;
    } else {
        std::cout << "Test of CPU_methods.ddot() FAILED" << std::endl;
    }

    return 0;
}