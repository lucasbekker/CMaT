#include "../include/CMaT.h"

// Test GPU_methods.spfgemv()
int main (  ) {

    // Create the handles.
    HANDLES handles = createHandles();

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    GPU_Sparse_f A1(4,3,6,&handles);
    GPU_Sparse_f A2(3,3,3,&handles);
    GPU_Sparse_f A3(3,4,6,&handles);
    GPU_Dense_f b1(3,1,&handles);
    GPU_Dense_f b2(4,1,&handles);
    thrust::device_vector<float> r1(4);
    thrust::device_vector<float> r2(3);
    thrust::device_vector<float> r3(3);

    // Fill matrix A1.
    A1.Values[0] = 2;       // A1 = 2 0 0
    A1.Values[1] = 2;       //      0 2 0
    A1.Values[2] = 2;       //      0 0 2
    A1.Values[3] = 1;       //      1 1 1
    A1.Values[4] = 1;
    A1.Values[5] = 1;
    A1.I[0] = 0;
    A1.I[1] = 1;
    A1.I[2] = 2;
    A1.I[3] = 3;
    A1.I[4] = 6;
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
    A2.I[0] = 0;
    A2.I[1] = 1;
    A2.I[2] = 2;
    A2.I[3] = 3;
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
    A3.I[0] = 0;
    A3.I[1] = 2;
    A3.I[2] = 4;
    A3.I[3] = 6;
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

    // Create pointers.
    float * A1vp = thrust::raw_pointer_cast(&A1.Values[0]);
    int * A1ip = thrust::raw_pointer_cast(&A1.I[0]);
    int * A1jp = thrust::raw_pointer_cast(&A1.J[0]);
    float * A2vp = thrust::raw_pointer_cast(&A2.Values[0]);
    int * A2ip = thrust::raw_pointer_cast(&A2.I[0]);
    int * A2jp = thrust::raw_pointer_cast(&A2.J[0]);
    float * A3vp = thrust::raw_pointer_cast(&A3.Values[0]);
    int * A3ip = thrust::raw_pointer_cast(&A3.I[0]);
    int * A3jp = thrust::raw_pointer_cast(&A3.J[0]);
    float * b1p = thrust::raw_pointer_cast(&b1.Values[0]);
    float * b2p = thrust::raw_pointer_cast(&b2.Values[0]);

    // Perform the calculation.
    r1 = A1.spfgemv(4,3,6,A1vp,A1ip,A1jp,b1p);
    r2 = A2.spfgemv(3,3,3,A2vp,A2ip,A2jp,b1p);
    r3 = A3.spfgemv(3,4,6,A3vp,A3ip,A3jp,b2p);

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
        std::cout << "Test of GPU_methods.spfgemv() passed" << std::endl;
    } else {
        std::cout << "Test of GPU_methods.spfgemv() FAILED" << std::endl;
    }

    destroyHandles(handles);

    return 0;

}