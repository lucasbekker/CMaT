#include "../include/CMaT.h"

// Test CPU_Sparse_f.mv()
int main (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    CPU_Sparse_f A1(4,3,6);
    CPU_Sparse_f A2(3,3,3);
    CPU_Sparse_f A3(3,4,6);
    CPU_Dense_f b1(3,1);
    CPU_Dense_f b2(4,1);
    
    // Fill matrix A1.
    A1.Values[0] = 2;       // A1 = 2 0 0
    A1.Values[1] = 2;       //      0 2 0
    A1.Values[2] = 2;       //      0 0 2
    A1.Values[3] = 1;       //      1 1 1
    A1.Values[4] = 1;
    A1.Values[5] = 1;
    A1.Ib[0] = 0;
    A1.Ib[1] = 1;
    A1.Ib[2] = 2;
    A1.Ib[3] = 3;
    A1.Ie[0] = 1;
    A1.Ie[1] = 2;
    A1.Ie[2] = 3;
    A1.Ie[3] = 6;
    A1.J[0] = 0;
    A1.J[1] = 1;
    A1.J[2] = 2;
    A1.J[3] = 0;
    A1.J[4] = 1;
    A1.J[5] = 2;

    // Fill matrix A2.
    A2.Values[0] = 2;       // A2 = 2 0 0
    A2.Values[1] = 2;       //      0 2 0
    A2.Values[2] = 2;       //      0 0 2
    A2.Ib[0] = 0;
    A2.Ib[1] = 1;
    A2.Ib[2] = 2;
    A2.Ie[0] = 1;
    A2.Ie[1] = 2;
    A2.Ie[2] = 3;
    A2.J[0] = 0;
    A2.J[1] = 1;
    A2.J[2] = 2;

    // Fill matrix A3.
    A3.Values[0] = 2;       // A3 = 2 0 0 1
    A3.Values[1] = 1;       //      0 2 0 1
    A3.Values[2] = 2;       //      0 0 2 1
    A3.Values[3] = 1;
    A3.Values[4] = 2;
    A3.Values[5] = 1;
    A3.Ib[0] = 0;
    A3.Ib[1] = 2;
    A3.Ib[2] = 4;
    A3.Ie[0] = 2;
    A3.Ie[1] = 4;
    A3.Ie[2] = 6;
    A3.J[0] = 0;
    A3.J[1] = 3;
    A3.J[2] = 1;
    A3.J[3] = 3;
    A3.J[4] = 2;
    A3.J[5] = 3;

    // Fill vector b1.
    b1.Values[0] = 3;
    b1.Values[1] = 3;
    b1.Values[2] = 3;

    // Fill vector b2.
    b2.Values[0] = 3;
    b2.Values[1] = 3;
    b2.Values[2] = 3;
    b2.Values[3] = 3;

    // Perform the calculation.
    CPU_Dense_f r1 = A1.mv(b1);
    CPU_Dense_f r2 = A2.mv(b1);
    CPU_Dense_f r3 = A3.mv(b2);

    // Check for errors.
    if ((r1.Values[0] == 6.0) && (r1.Values[1] == 6.0) && (r1.Values[2] == 6.0) && (r1.Values[3] == 9.0)) {
        std::cout << "No errors in A1*b1" << std::endl;
    } else { pass = 0; }
    if ((r2.Values[0] == 6.0) && (r2.Values[1] == 6.0) && (r2.Values[2] == 6.0)) {
        std::cout << "No errors in A2*b1" << std::endl;
    } else { pass = 0; }
    if ((r3.Values[0] == 9.0) && (r3.Values[1] == 9.0) && (r3.Values[2] == 9.0)) {
        std::cout << "No errors in A3*b2" << std::endl;
    } else { pass = 0; }

    // Print test result.
    if (pass == 1) {
        std::cout << "Test of CPU_Sparse_f.mv() passed" << std::endl;
    } else {
        std::cout << "Test of CPU_Sparse_f.mv() FAILED" << std::endl;
    }

    return 0;

}