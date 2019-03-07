#include "../include/CMaT.h"

int CPU_Sparse_trans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Declaration of matrix.
    CPU_Sparse test(3,4,5);
    
    // Fill V.
    test.Values[0] = 1; test.Values[1] = 3; test.Values[2] = 5;
    test.Values[3] = 2; test.Values[4] = 4; 

    // Fill Ipb and Ipe.
    test.Ib[0] = 0; test.Ib[1] = 3; test.Ib[2] = 4;
    test.Ie[0] = 3; test.Ie[1] = 4; test.Ie[2] = 5;

    // Fill J.
    test.J[0] = 0; test.J[1] = 1; test.J[2] = 3; 
    test.J[3] = 0; test.J[4] = 1;
    
    // Perform the transpose operation.
    CPU_Sparse result = test.trans();

    // Check for errors.
    if ((result.Values[0] != 1.0) || (result.Values[1] != 2.0) ||
        (result.Values[2] != 3.0) || (result.Values[3] != 4.0) ||
        (result.Values[4] != 5.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((result.J[0] != 0) || (result.J[1] != 1) || (result.J[2] != 0) ||
        (result.J[3] != 2) || (result.J[4] != 0)) {
        std::cout << "Errors in J." << std::endl; pass = 0; }
    if ((result.Ib[0] != 0) || (result.Ib[1] != 2) || 
        (result.Ib[2] != 4) || (result.Ib[3] != 4)) {
        std::cout << "Errors in Ipb." << std::endl; pass = 0; }
    if ((result.Ie[0] != 2) || (result.Ie[1] != 4) || 
        (result.Ie[2] != 4) || (result.Ie[3] != 5)) {
        std::cout << "Errors in Ipe." << std::endl; pass = 0; }
    
    // Return the result.
    return pass;

}

int CPU_Sparse_f_trans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Declaration of matrix.
    CPU_Sparse_f test(3,4,5);
    
    // Fill V.
    test.Values[0] = 1; test.Values[1] = 3; test.Values[2] = 5;
    test.Values[3] = 2; test.Values[4] = 4; 

    // Fill Ipb and Ipe.
    test.Ib[0] = 0; test.Ib[1] = 3; test.Ib[2] = 4;
    test.Ie[0] = 3; test.Ie[1] = 4; test.Ie[2] = 5;

    // Fill J.
    test.J[0] = 0; test.J[1] = 1; test.J[2] = 3; 
    test.J[3] = 0; test.J[4] = 1;
    
    // Perform the transpose operation.
    CPU_Sparse_f result = test.trans();

    // Check for errors.
    if ((result.Values[0] != 1.0) || (result.Values[1] != 2.0) ||
        (result.Values[2] != 3.0) || (result.Values[3] != 4.0) ||
        (result.Values[4] != 5.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((result.J[0] != 0) || (result.J[1] != 1) || (result.J[2] != 0) ||
        (result.J[3] != 2) || (result.J[4] != 0)) {
        std::cout << "Errors in J." << std::endl; pass = 0; }
    if ((result.Ib[0] != 0) || (result.Ib[1] != 2) || 
        (result.Ib[2] != 4) || (result.Ib[3] != 4)) {
        std::cout << "Errors in Ipb." << std::endl; pass = 0; }
    if ((result.Ie[0] != 2) || (result.Ie[1] != 4) || 
        (result.Ie[2] != 4) || (result.Ie[3] != 5)) {
        std::cout << "Errors in Ipe." << std::endl; pass = 0; }
    
    // Return the result.
    return pass;

}

int GPU_Sparse_trans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Declaration of matrix.
    GPU_Sparse test(3,4,5);
    
    // Fill V.
    test.Values[0] = 1; test.Values[1] = 3; test.Values[2] = 5;
    test.Values[3] = 2; test.Values[4] = 4; 

    // Fill Ip.
    test.I[0] = 0; test.I[1] = 3; test.I[2] = 4; test.I[3] = 5;
    
    // Fill J.
    test.J[0] = 0; test.J[1] = 1; test.J[2] = 3; 
    test.J[3] = 0; test.J[4] = 1;
    
    // Perform the transpose operation.
    GPU_Sparse result = test.trans();

    // Check for errors.
    if ((result.Values[0] != 1.0) || (result.Values[1] != 2.0) ||
        (result.Values[2] != 3.0) || (result.Values[3] != 4.0) ||
        (result.Values[4] != 5.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((result.J[0] != 0) || (result.J[1] != 1) || (result.J[2] != 0) ||
        (result.J[3] != 2) || (result.J[4] != 0)) {
        std::cout << "Errors in J." << std::endl; pass = 0; }
    if ((result.I[0] != 0) || (result.I[1] != 2) || 
        (result.I[2] != 4) || (result.I[3] != 4)) {
        std::cout << "Errors in Ip." << std::endl; pass = 0; }
    
    // Return the result.
    return pass;

}

int GPU_Sparse_f_trans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Declaration of matrix.
    GPU_Sparse_f test(3,4,5);
    
    // Fill V.
    test.Values[0] = 1; test.Values[1] = 3; test.Values[2] = 5;
    test.Values[3] = 2; test.Values[4] = 4; 

    // Fill Ip.
    test.I[0] = 0; test.I[1] = 3; test.I[2] = 4; test.I[3] = 5;

    // Fill J.
    test.J[0] = 0; test.J[1] = 1; test.J[2] = 3; 
    test.J[3] = 0; test.J[4] = 1;
    
    // Perform the transpose operation.
    GPU_Sparse_f result = test.trans();

    // Check for errors.
    if ((result.Values[0] != 1.0) || (result.Values[1] != 2.0) ||
        (result.Values[2] != 3.0) || (result.Values[3] != 4.0) ||
        (result.Values[4] != 5.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((result.J[0] != 0) || (result.J[1] != 1) || (result.J[2] != 0) ||
        (result.J[3] != 2) || (result.J[4] != 0)) {
        std::cout << "Errors in J." << std::endl; pass = 0; }
    if ((result.I[0] != 0) || (result.I[1] != 2) || 
        (result.I[2] != 4) || (result.I[3] != 4)) {
        std::cout << "Errors in Ip." << std::endl; pass = 0; }
    
    // Return the result.
    return pass;

}

int CPU_Dense_trans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Declaration of matrix.
    CPU_Dense test(3,4);

    // Fill test.
    test.Values[0] = 1; test.Values[1] = 2; test.Values[2] = 0;
    test.Values[3] = 3; test.Values[4] = 0; test.Values[5] = 4;
    test.Values[6] = 0; test.Values[7] = 0; test.Values[8] = 0;
    test.Values[9] = 5; test.Values[10] = 0; test.Values[11] = 0; 

    // Perform the transpose operation.
    CPU_Dense result = test.trans();

    // Check for errors.
    if ((result.Values[0] != 1) || (result.Values[1] != 3) || (result.Values[2] != 0) ||
        (result.Values[3] != 5) || (result.Values[4] != 2) || (result.Values[5] != 0) ||
        (result.Values[6] != 0) || (result.Values[7] != 0) || (result.Values[8] != 0) ||
        (result.Values[9] != 4) || (result.Values[10] != 0) || (result.Values[11] != 0)) {
        pass = 0; }
    
    // Return the result.
    return pass;

}

int CPU_Dense_f_trans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Declaration of matrix.
    CPU_Dense_f test(3,4);

    // Fill test.
    test.Values[0] = 1; test.Values[1] = 2; test.Values[2] = 0;
    test.Values[3] = 3; test.Values[4] = 0; test.Values[5] = 4;
    test.Values[6] = 0; test.Values[7] = 0; test.Values[8] = 0;
    test.Values[9] = 5; test.Values[10] = 0; test.Values[11] = 0; 

    // Perform the transpose operation.
    CPU_Dense_f result = test.trans();

    // Check for errors.
    if ((result.Values[0] != 1) || (result.Values[1] != 3) || (result.Values[2] != 0) ||
        (result.Values[3] != 5) || (result.Values[4] != 2) || (result.Values[5] != 0) ||
        (result.Values[6] != 0) || (result.Values[7] != 0) || (result.Values[8] != 0) ||
        (result.Values[9] != 4) || (result.Values[10] != 0) || (result.Values[11] != 0)) {
        pass = 0; }
    
    // Return the result.
    return pass;

}

int GPU_Dense_trans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Declaration of matrix.
    GPU_Dense test(3,4);

    // Fill test.
    test.Values[0] = 1; test.Values[1] = 2; test.Values[2] = 0;
    test.Values[3] = 3; test.Values[4] = 0; test.Values[5] = 4;
    test.Values[6] = 0; test.Values[7] = 0; test.Values[8] = 0;
    test.Values[9] = 5; test.Values[10] = 0; test.Values[11] = 0; 

    // Perform the transpose operation.
    GPU_Dense result = test.trans();

    // Check for errors.
    if ((result.Values[0] != 1) || (result.Values[1] != 3) || (result.Values[2] != 0) ||
        (result.Values[3] != 5) || (result.Values[4] != 2) || (result.Values[5] != 0) ||
        (result.Values[6] != 0) || (result.Values[7] != 0) || (result.Values[8] != 0) ||
        (result.Values[9] != 4) || (result.Values[10] != 0) || (result.Values[11] != 0)) {
        pass = 0; }
    
    // Return the result.
    return pass;

}

int GPU_Dense_f_trans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Declaration of matrix.
    GPU_Dense_f test(3,4);

    // Fill test.
    test.Values[0] = 1; test.Values[1] = 2; test.Values[2] = 0;
    test.Values[3] = 3; test.Values[4] = 0; test.Values[5] = 4;
    test.Values[6] = 0; test.Values[7] = 0; test.Values[8] = 0;
    test.Values[9] = 5; test.Values[10] = 0; test.Values[11] = 0; 

    // Perform the transpose operation.
    GPU_Dense_f result = test.trans();

    // Check for errors.
    if ((result.Values[0] != 1) || (result.Values[1] != 3) || (result.Values[2] != 0) ||
        (result.Values[3] != 5) || (result.Values[4] != 2) || (result.Values[5] != 0) ||
        (result.Values[6] != 0) || (result.Values[7] != 0) || (result.Values[8] != 0) ||
        (result.Values[9] != 4) || (result.Values[10] != 0) || (result.Values[11] != 0)) {
        pass = 0; }
    
    // Return the result.
    return pass;

}

int main (  ) {

    int pass1 = CPU_Sparse_trans_test();
    int pass2 = CPU_Sparse_f_trans_test();
    int pass3 = GPU_Sparse_trans_test();
    int pass4 = GPU_Sparse_f_trans_test();
    int pass5 = CPU_Dense_trans_test();
    int pass6 = CPU_Dense_f_trans_test();
    int pass7 = GPU_Dense_trans_test();
    int pass8 = GPU_Dense_f_trans_test();
    
    int pass_global = 1;

    if (pass1 == 0) { pass_global = 0; std::cout << "Error in: CPU_Sparse_trans_test" << std::endl; }
    if (pass2 == 0) { pass_global = 0; std::cout << "Error in: PU_Sparse_f_trans_test" << std::endl; }
    if (pass3 == 0) { pass_global = 0; std::cout << "Error in: GPU_Sparse_trans_test" << std::endl; }
    if (pass4 == 0) { pass_global = 0; std::cout << "Error in: GPU_Sparse_f_trans_test" << std::endl; }
    if (pass5 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_trans_test" << std::endl; }
    if (pass6 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_f_trans_test" << std::endl; }
    if (pass7 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_trans_test" << std::endl; }
    if (pass8 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_f_trans_test" << std::endl; }
    
    if (pass_global == 1) { std::cout << "PASSED" << std::endl; } else { std::cout << "FAILED" << std::endl; }

    return 0;

}