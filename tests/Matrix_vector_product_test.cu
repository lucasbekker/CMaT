#include "../include/CMaT.h"

int CPU_Dense_f_mv_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    CPU_Dense_f A1(4,3);
    CPU_Dense_f A2(3,3);
    CPU_Dense_f A3(3,4);
    CPU_Dense_f b1(3,1);
    CPU_Dense_f b2(4,1);
    
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
    CPU_Dense_f r1 = A1.mv(b1);
    CPU_Dense_f r2 = A2.mv(b1);
    CPU_Dense_f r3 = A3.mv(b2);

    // Check for errors.
    if ((r1.Values[0] != 6.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 6.0) || (r1.Values[3] != 9.0)) {
        std::cout << "Errors in A1*b1" << std::endl;
        pass = 0; }
    if ((r2.Values[0] != 6.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 6.0)) {
        std::cout << "Errors in A2*b1" << std::endl;
        pass = 0; }
    if ((r3.Values[0] != 9.0) || (r3.Values[1] != 9.0) || (r3.Values[2] != 9.0)) {
        std::cout << "Errors in A3*b2" << std::endl;
        pass = 0; } 

    return pass;

}

int CPU_Dense_mv_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    CPU_Dense A1(4,3);
    CPU_Dense A2(3,3);
    CPU_Dense A3(3,4);
    CPU_Dense b1(3,1);
    CPU_Dense b2(4,1);
    
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
    CPU_Dense r1 = A1.mv(b1);
    CPU_Dense r2 = A2.mv(b1);
    CPU_Dense r3 = A3.mv(b2);

    // Check for errors.
    if ((r1.Values[0] != 6.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 6.0) || (r1.Values[3] != 9.0)) {
        std::cout << "Errors in A1*b1" << std::endl;
        pass = 0; }
    if ((r2.Values[0] != 6.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 6.0)) {
        std::cout << "Errors in A2*b1" << std::endl;
        pass = 0; }
    if ((r3.Values[0] != 9.0) || (r3.Values[1] != 9.0) || (r3.Values[2] != 9.0)) {
        std::cout << "Errors in A3*b2" << std::endl;
        pass = 0; }

    return pass;

}

int CPU_Sparse_f_mv_test (  ) {

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
    if ((r1.Values[0] != 6.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 6.0) || (r1.Values[3] != 9.0)) {
        std::cout << "Errors in A1*b1" << std::endl;
        pass = 0; }
    if ((r2.Values[0] != 6.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 6.0)) {
        std::cout << "Errors in A2*b1" << std::endl;
        pass = 0; }
    if ((r3.Values[0] != 9.0) || (r3.Values[1] != 9.0) || (r3.Values[2] != 9.0)) {
        std::cout << "Errors in A3*b2" << std::endl;
        pass = 0; }

    return pass;

}

int CPU_Sparse_mv_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    CPU_Sparse A1(4,3,6);
    CPU_Sparse A2(3,3,3);
    CPU_Sparse A3(3,4,6);
    CPU_Dense b1(3,1);
    CPU_Dense b2(4,1);
    
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
    CPU_Dense r1 = A1.mv(b1);
    CPU_Dense r2 = A2.mv(b1);
    CPU_Dense r3 = A3.mv(b2);

    // Check for errors.
    if ((r1.Values[0] != 6.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 6.0) || (r1.Values[3] != 9.0)) {
        std::cout << "Errors in A1*b1" << std::endl;
        pass = 0; }
    if ((r2.Values[0] != 6.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 6.0)) {
        std::cout << "Errors in A2*b1" << std::endl;
        pass = 0; }
    if ((r3.Values[0] != 9.0) || (r3.Values[1] != 9.0) || (r3.Values[2] != 9.0)) {
        std::cout << "Errors in A3*b2" << std::endl;
        pass = 0; }

    return pass;

}

int GPU_Dense_f_mv_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    GPU_Dense_f A1(4,3);
    GPU_Dense_f A2(3,3);
    GPU_Dense_f A3(3,4);
    GPU_Dense_f b1(3,1);
    GPU_Dense_f b2(4,1);
    
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
    GPU_Dense_f r1 = A1.mv(b1);
    GPU_Dense_f r2 = A2.mv(b1);
    GPU_Dense_f r3 = A3.mv(b2);

    // Check for errors.
    if ((r1.Values[0] != 6.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 6.0) || (r1.Values[3] != 9.0)) {
        std::cout << "Errors in A1*b1" << std::endl;
        pass = 0; }
    if ((r2.Values[0] != 6.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 6.0)) {
        std::cout << "Errors in A2*b1" << std::endl;
        pass = 0; }
    if ((r3.Values[0] != 9.0) || (r3.Values[1] != 9.0) || (r3.Values[2] != 9.0)) {
        std::cout << "Errors in A3*b2" << std::endl;
        pass = 0; } 

    return pass;

}

int GPU_Dense_mv_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    GPU_Dense A1(4,3);
    GPU_Dense A2(3,3);
    GPU_Dense A3(3,4);
    GPU_Dense b1(3,1);
    GPU_Dense b2(4,1);
    
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
    if ((r1.Values[0] != 6.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 6.0) || (r1.Values[3] != 9.0)) {
        std::cout << "Errors in A1*b1" << std::endl;
        pass = 0; }
    if ((r2.Values[0] != 6.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 6.0)) {
        std::cout << "Errors in A2*b1" << std::endl;
        pass = 0; }
    if ((r3.Values[0] != 9.0) || (r3.Values[1] != 9.0) || (r3.Values[2] != 9.0)) {
        std::cout << "Errors in A3*b2" << std::endl;
        pass = 0; }

    return pass;

}

int GPU_Sparse_f_mv_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    GPU_Sparse_f A1(4,3,6);
    GPU_Sparse_f A2(3,3,3);
    GPU_Sparse_f A3(3,4,6);
    GPU_Dense_f b1(3,1);
    GPU_Dense_f b2(4,1);

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

        // Perform the calculation.
    GPU_Dense_f r1 = A1.mv(b1);
    GPU_Dense_f r2 = A2.mv(b1);
    GPU_Dense_f r3 = A3.mv(b2);

    // Check for errors.
    if ((r1.Values[0] != 6.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 6.0) || (r1.Values[3] != 9.0)) {
        std::cout << "Errors in A1*b1" << std::endl;
        pass = 0; }
    if ((r2.Values[0] != 6.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 6.0)) {
        std::cout << "Errors in A2*b1" << std::endl;
        pass = 0; }
    if ((r3.Values[0] != 9.0) || (r3.Values[1] != 9.0) || (r3.Values[2] != 9.0)) {
        std::cout << "Errors in A3*b2" << std::endl;
        pass = 0; }

    return pass;

}

int GPU_Sparse_mv_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrices and vectors.
    GPU_Sparse A1(4,3,6);
    GPU_Sparse A2(3,3,3);
    GPU_Sparse A3(3,4,6);
    GPU_Dense b1(3,1);
    GPU_Dense b2(4,1);

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

    // Perform the calculation.
    GPU_Dense r1 = A1.mv(b1);
    GPU_Dense r2 = A2.mv(b1);
    GPU_Dense r3 = A3.mv(b2);

    // Check for errors.
    if ((r1.Values[0] != 6.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 6.0) || (r1.Values[3] != 9.0)) {
        std::cout << "Errors in A1*b1" << std::endl;
        pass = 0; }
    if ((r2.Values[0] != 6.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 6.0)) {
        std::cout << "Errors in A2*b1" << std::endl;
        pass = 0; }
    if ((r3.Values[0] != 9.0) || (r3.Values[1] != 9.0) || (r3.Values[2] != 9.0)) {
        std::cout << "Errors in A3*b2" << std::endl;
        pass = 0; }

    return pass;

}

int main (  ) {

    int pass1 = CPU_Dense_mv_test();
    int pass2 = CPU_Dense_f_mv_test();
    int pass3 = GPU_Dense_mv_test();
    int pass4 = GPU_Dense_f_mv_test();
    int pass5 = CPU_Sparse_mv_test();
    int pass6 = CPU_Sparse_f_mv_test();
    int pass7 = GPU_Sparse_mv_test();
    int pass8 = GPU_Sparse_f_mv_test();

    int pass_global = 1;

    if (pass1 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_mv_test" << std::endl; }
    if (pass2 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_f_mv_test" << std::endl; }
    if (pass3 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_mv_test" << std::endl; }
    if (pass4 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_f_mv_test" << std::endl; }
    if (pass5 == 0) { pass_global = 0; std::cout << "Error in: CPU_Sparse_mv_test" << std::endl; }
    if (pass6 == 0) { pass_global = 0; std::cout << "Error in: CPU_Sparse_f_mv_test" << std::endl; }
    if (pass7 == 0) { pass_global = 0; std::cout << "Error in: GPU_Sparse_mv_test" << std::endl; }
    if (pass8 == 0) { pass_global = 0; std::cout << "Error in: GPU_Sparse_f_mv_test" << std::endl; }

    if (pass_global == 1) { std::cout << "PASSED" << std::endl; } else { std::cout << "FAILED" << std::endl; }

    return 0;
}