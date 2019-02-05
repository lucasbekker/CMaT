#include "../include/CMaT.h"

// Test CPU_methods.dscp()
int main () {

    // Check.
    int pass = 1;

    // Initialize vectors and scalar.
    CPU_Dense x(3,1);
    thrust::host_vector<double> r(3);
    double a = 4.0;

    // Fill vector x.
    x.Values[0] = 1;
    x.Values[1] = 2;
    x.Values[2] = 3;

    // Create pointers.
    thrust::host_vector<double> * xp = &x.Values;

    // Perform the calculation.
    r = x.dscp(a,xp);

    // Check for errors.
    if ((r[0] == 4.0) && (r[1] == 8.0) && (r[2] == 12.0)) {
        std::cout << "No errors in 4.0 * [1;2;3]" << std::endl;
    } else { pass = 0; }
    
    // Print test result.
    if (pass == 1) {
        std::cout << "Test of CPU_methods.dscp() passed" << std::endl;
    } else {
        std::cout << "Test of CPU_methods.dscp() FAILED" << std::endl;
    }

    return 0;

}