#include "../include/CMaT.h"

// Test GPU_Dense.mv()
int main (  ) {

    // Create the handles.
    HANDLES handles = createHandles();

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    GPU_Dense A1(4,3,&handles);
    GPU_Dense A2(3,3,&handles);
    GPU_Dense A3(3,4,&handles);
    GPU_Dense b1(3,1,&handles);
    GPU_Dense b2(4,1,&handles);
    
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

    // Perform the calculation.
    GPU_Dense r1 = A1.mv(b1);
    GPU_Dense r2 = A2.mv(b1);
    GPU_Dense r3 = A3.mv(b2);

    // Check for errors.
    if ((r1.Values[0] == 6.0) && (r1.Values[1] == 6.0) && (r1.Values[2] == 6.0) && (r1.Values[3] == 9.0)) {
        std::cout << "No errors in A1*b1" << std::endl;
    } 
    if ((r2.Values[0] == 6.0) && (r2.Values[1] == 6.0) && (r2.Values[2] == 6.0)) {
        std::cout << "No errors in A2*b1" << std::endl;
    } 
    if ((r3.Values[0] == 9.0) && (r3.Values[1] == 9.0) && (r3.Values[2] == 9.0)) {
        std::cout << "No errors in A3*b2" << std::endl;
    } 

    // Print test result.
    if (pass == 1) {
        std::cout << "Test of GPU_Dense.mv() passed" << std::endl;
    } else {
        std::cout << "Test of GPU_Dense.mv() FAILED" << std::endl;
    }

    destroyHandles(handles);

    return 0;

}