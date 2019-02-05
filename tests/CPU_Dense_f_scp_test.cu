#include "../include/CMaT.h"

// Test CPU_Dense_f.scp()
int main () {

    // Check.
    int pass = 1;

    // Initialize vectors and scalar.
    CPU_Dense_f x(3,1);
    CPU_Dense_f y(3,2);
    float a = 4.0;

    // Fill vector x.
    x.Values[0] = 1;
    x.Values[1] = 2;
    x.Values[2] = 3;

    // Fill matrix y.
    y.Values[0] = 1;        // y = 1 4
    y.Values[1] = 2;        //     2 5
    y.Values[2] = 3;        //     3 6
    y.Values[3] = 4;
    y.Values[4] = 5;
    y.Values[5] = 6;

    // Perform the calculation.
    CPU_Dense_f r1 = x.scp(a);
    CPU_Dense_f r2 = y.scp(a);

    // Check for errors.
    if ((r1.Values[0] == 4.0) && (r1.Values[1] == 8.0) && (r1.Values[2] == 12.0)) {
        std::cout << "No errors in 4.0 * [1;2;3]" << std::endl;
    } else { pass = 0; }
    if ((r2.Values[0] == 4.0) && (r2.Values[1] == 8.0) && (r2.Values[2] == 12.0) &&
        (r2.Values[3] == 16.0) && (r2.Values[4] == 20.0) && (r2.Values[5] == 24.0)) {
        std::cout << "No errors in 4.0 * [1,4;2,5;3,6]" << std::endl;
    } else { pass = 0; }
    
    // Print test result.
    if (pass == 1) {
        std::cout << "Test of CPU_Dense_f.scp() passed" << std::endl;
    } else {
        std::cout << "Test of CPU_Dense_f.scp() FAILED" << std::endl;
    }

    return 0;

}