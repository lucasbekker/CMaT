#include "../include/CMaT.h"

// Test CPU_methods.dfgemv()
int main (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    CPU_Dense_f A1(4,3);
    CPU_Dense_f A2(3,3);
    CPU_Dense_f A3(3,4);
    CPU_Dense_f b1(3,1);
    CPU_Dense_f b2(4,1);
    thrust::host_vector<float> r1;
    thrust::host_vector<float> r2;
    thrust::host_vector<float> r3;

    // Fill matrix A1.
    A1.Values[0] = 2;       // A1 = 2 0 0
    A1.Values[1] = 0;       //      0 2 0
    A1.Values[2] = 0;       //      0 0 2
    A1.Values[3] = 1;       //      1 1 1
    A1.Values[4] = 0;
    A1.Values[5] = 2;
    A1.Values[6] = 0;
    A1.Values[7] = 1;
    A1.Values[8] = 0;
    A1.Values[9] = 0;
    A1.Values[10] = 2;
    A1.Values[11] = 1;

    // Fill matrix A2.
    A2.Values[0] = 2;       // A2 = 2 0 0
    A2.Values[1] = 0;       //      0 2 0
    A2.Values[2] = 0;       //      0 0 2
    A2.Values[3] = 0;
    A2.Values[4] = 2;
    A2.Values[5] = 0;
    A2.Values[6] = 0;
    A2.Values[7] = 0;
    A2.Values[8] = 2;

    // Fill matrix A3.
    A3.Values[0] = 2;       // A3 = 2 0 0 1
    A3.Values[1] = 0;       //      0 2 0 1
    A3.Values[2] = 0;       //      0 0 2 1
    A3.Values[3] = 0;
    A3.Values[4] = 2;
    A3.Values[5] = 0;
    A3.Values[6] = 0;
    A3.Values[7] = 0;
    A3.Values[8] = 2;
    A3.Values[9] = 1;
    A3.Values[10] = 1;
    A3.Values[11] = 1;

    // Fill vector b1.
    b1.Values[0] = 3;
    b1.Values[1] = 3;
    b1.Values[2] = 3;

    // Fill vector b2.
    b2.Values[0] = 3;
    b2.Values[1] = 3;
    b2.Values[2] = 3;
    b2.Values[3] = 3;

    // Create pointers.
    float * A1p = thrust::raw_pointer_cast(&A1.Values[0]);
    float * A2p = thrust::raw_pointer_cast(&A2.Values[0]);
    float * A3p = thrust::raw_pointer_cast(&A3.Values[0]);
    float * b1p = thrust::raw_pointer_cast(&b1.Values[0]);
    float * b2p = thrust::raw_pointer_cast(&b2.Values[0]);

    // Perform the calculation.
    r1 = A1.dfgemv(4,3,A1p,b1p);
    r2 = A2.dfgemv(3,3,A2p,b1p);
    r3 = A3.dfgemv(3,4,A3p,b2p);

    // Check for errors.
    if ((r1[0] == 6.0) && (r1[1] == 6.0) && (r1[2] == 6.0) && (r1[3] == 9.0)) {
        std::cout << "No errors in A1*b1" << std::endl;
    } else {
        std::cout << "!!! Errors in A1*b1 !!!" << std::endl;
        std::cout << r1[0] << std::endl << r1[1] << std::endl << r1[2] << std::endl << r1[3] << std::endl;
        pass = 0;
    }
    if ((r2[0] == 6.0) && (r2[1] == 6.0) && (r2[2] == 6.0)) {
        std::cout << "No errors in A2*b1" << std::endl;
    } else {
        std::cout << "!!! Errors in A2*b1 !!!" << std::endl;
        std::cout << r2[0] << std::endl << r2[1] << std::endl << r2[2] << std::endl;
        pass = 0;
    }
    if ((r3[0] == 9.0) && (r3[1] == 9.0) && (r3[2] == 9.0)) {
        std::cout << "No errors in A3*b2" << std::endl;
    } else {
        std::cout << "!!! Errors in A3*b2 !!!" << std::endl;
        std::cout << r3[0] << std::endl << r3[1] << std::endl << r3[2] << std::endl;
        pass = 0;
    }

    // Print test result.
    if (pass == 1) {
        std::cout << "Test of CPU_methods.dfgemv() passed" << std::endl;
    } else {
        std::cout << "Test of CPU_methods.dfgemv() FAILED" << std::endl;
    }

    return 0;

}