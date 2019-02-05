#include "../include/CMaT.h"

// Test GPU_Dense.dot()
int main (  ) {

    // Check.
    int pass = 1;

    // Initialize vectors.
    GPU_Dense x(3,1);
    GPU_Dense y(3,1);

    // Fill vector x.
    x.Values[0] = 1;
    x.Values[1] = 2;
    x.Values[2] = 3;

    // Fill vector y.
    y.Values[0] = 4;
    y.Values[1] = 5;
    y.Values[2] = 6;

    // Perform the calculation.
    double r = x.dot(y);

    // Check for errors.
    if (r == 32) { 
        std::cout << "The result is correct." << std::endl; 
    } else {
        std::cout << "The result is not correct." << std::endl;
        pass = 0;
    }
    
    // Print test result.
    if (pass == 1) {
        std::cout << "Test of GPU_Dense.dot() passed" << std::endl;
    } else {
        std::cout << "Test of GPU_Dense.dot() FAILED" << std::endl;
    }

    return 0;
}