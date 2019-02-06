#include "../include/CMaT.h"

// Test CPU_Dense.dot()
int CPU_Dense_dot_test (  ) {

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

    // Perform the calculation.
    double r = x.dot(y);

    // Check for errors.
    if (r != 32) { std::cout << "The result is not correct." << std::endl; pass = 0; }
    
    return pass;

}

int CPU_Dense_f_dot_test (  ) {

    // Check.
    int pass = 1;

    // Initialize vectors.
    CPU_Dense_f x(3,1);
    CPU_Dense_f y(3,1);

    // Fill vector x.
    x.Values[0] = 1;
    x.Values[1] = 2;
    x.Values[2] = 3;

    // Fill vector y.
    y.Values[0] = 4;
    y.Values[1] = 5;
    y.Values[2] = 6;

    // Perform the calculation.
    float r = x.dot(y);

    // Check for errors.
    if (r != 32) { std::cout << "The result is not correct." << std::endl; pass = 0; }
    
    return pass;

}

// Test GPU_Dense.dot()
int GPU_Dense_dot_test (  ) {

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
    if (r != 32) { std::cout << "The result is not correct." << std::endl; pass = 0; }
    
    return pass;

}

// Test GPU_Dense_f.dot()
int GPU_Dense_f_dot_test (  ) {

    // Check.
    int pass = 1;

    // Initialize vectors.
    GPU_Dense_f x(3,1);
    GPU_Dense_f y(3,1);

    // Fill vector x.
    x.Values[0] = 1;
    x.Values[1] = 2;
    x.Values[2] = 3;

    // Fill vector y.
    y.Values[0] = 4;
    y.Values[1] = 5;
    y.Values[2] = 6;

    // Perform the calculation.
    float r = x.dot(y);

    // Check for errors.
    if (r != 32) { std::cout << "The result is not correct." << std::endl; pass = 0; }
    
    return pass;

}

int main (  ) {

    int pass1 = CPU_Dense_dot_test();
    int pass2 = CPU_Dense_f_dot_test();
    int pass3 = GPU_Dense_dot_test();
    int pass4 = GPU_Dense_f_dot_test();
    
    int pass_global = 1;

    if (pass1 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_dot_test" << std::endl; }
    if (pass2 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_f_dot_test" << std::endl; }
    if (pass3 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_dot_test" << std::endl; }
    if (pass4 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_f_dot_test" << std::endl; }
    
    if (pass_global == 1) { std::cout << "PASSED" << std::endl; } else { std::cout << "FAILED" << std::endl; }

    return 0;
}