#include "../include/CMaT.h"

int CPU_Dense_f_add_test (  ) {

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
    CPU_Dense_f r1 = x.add(a);
    CPU_Dense_f r2 = y.add(a);

    // Check for errors.
    if ((r1.Values[0] != 5.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 7.0)) {
        std::cout << "Errors in 4.0 + [1;2;3]" << std::endl; pass = 0; }
    if ((r2.Values[0] != 5.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 7.0) ||
        (r2.Values[3] != 8.0) || (r2.Values[4] != 9.0) || (r2.Values[5] != 10.0)) {
        std::cout << "Errors in 4.0 + [1,4;2,5;3,6]" << std::endl; pass = 0; }
    
    return pass;

}

int CPU_Dense_add_test (  ) {

    // Check.
    int pass = 1;

    // Initialize vectors and scalar.
    CPU_Dense x(3,1);
    CPU_Dense y(3,2);
    double a = 4.0;

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
    CPU_Dense r1 = x.add(a);
    CPU_Dense r2 = y.add(a);

    // Check for errors.
    if ((r1.Values[0] != 5.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 7.0)) {
        std::cout << "Errors in 4.0 + [1;2;3]" << std::endl; pass = 0; }
    if ((r2.Values[0] != 5.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 7.0) ||
        (r2.Values[3] != 8.0) || (r2.Values[4] != 9.0) || (r2.Values[5] != 10.0)) {
        std::cout << "Errors in 4.0 + [1,4;2,5;3,6]" << std::endl; pass = 0; }
    
    return pass;

}

int CPU_Sparse_f_add_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrix and scalar.
    CPU_Sparse_f A(4,3,6);
    float a = 4.0;
        
    // Fill matrix A1.
    A.Values[0] = 2;       // A1 = 2 0 0
    A.Values[1] = 2;       //      0 2 0
    A.Values[2] = 2;       //      0 0 2
    A.Values[3] = 1;       //      1 1 1
    A.Values[4] = 1;
    A.Values[5] = 1;
    A.Ib[0] = 0;
    A.Ib[1] = 1;
    A.Ib[2] = 2;
    A.Ib[3] = 3;
    A.Ie[0] = 1;
    A.Ie[1] = 2;
    A.Ie[2] = 3;
    A.Ie[3] = 6;
    A.J[0] = 0;
    A.J[1] = 1;
    A.J[2] = 2;
    A.J[3] = 0;
    A.J[4] = 1;
    A.J[5] = 2;

    // Perform the calculation.
    CPU_Sparse_f r = A.add(a);
    
    // Check for errors.
    if ((r.Values[0] != 6.0) || (r.Values[1] != 6.0) || (r.Values[2] != 6.0) || 
        (r.Values[3] != 5.0) || (r.Values[4] != 5.0) || (r.Values[5] != 5.0)) {
        std::cout << "Errors in 4.0 + A" << std::endl;
        pass = 0; }
    
    return pass;

}

int CPU_Sparse_add_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrix and scalar.
    CPU_Sparse A(4,3,6);
    double a = 4.0;
        
    // Fill matrix A1.
    A.Values[0] = 2;       // A1 = 2 0 0
    A.Values[1] = 2;       //      0 2 0
    A.Values[2] = 2;       //      0 0 2
    A.Values[3] = 1;       //      1 1 1
    A.Values[4] = 1;
    A.Values[5] = 1;
    A.Ib[0] = 0;
    A.Ib[1] = 1;
    A.Ib[2] = 2;
    A.Ib[3] = 3;
    A.Ie[0] = 1;
    A.Ie[1] = 2;
    A.Ie[2] = 3;
    A.Ie[3] = 6;
    A.J[0] = 0;
    A.J[1] = 1;
    A.J[2] = 2;
    A.J[3] = 0;
    A.J[4] = 1;
    A.J[5] = 2;

    // Perform the calculation.
    CPU_Sparse r = A.add(a);
    
    // Check for errors.
    if ((r.Values[0] != 6.0) || (r.Values[1] != 6.0) || (r.Values[2] != 6.0) || 
        (r.Values[3] != 5.0) || (r.Values[4] != 5.0) || (r.Values[5] != 5.0)) {
        std::cout << "Errors in 4.0 + A" << std::endl;
        pass = 0; }
    
    return pass;

}

int GPU_Dense_f_add_test (  ) {

    // Check.
    int pass = 1;

    // Initialize vectors and scalar.
    GPU_Dense_f x(3,1);
    GPU_Dense_f y(3,2);
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
    GPU_Dense_f r1 = x.add(a);
    GPU_Dense_f r2 = y.add(a);

    // Check for errors.
    if ((r1.Values[0] != 5.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 7.0)) {
        std::cout << "Errors in 4.0 + [1;2;3]" << std::endl; pass = 0; }
    if ((r2.Values[0] != 5.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 7.0) ||
        (r2.Values[3] != 8.0) || (r2.Values[4] != 9.0) || (r2.Values[5] != 10.0)) {
        std::cout << "Errors in 4.0 + [1,4;2,5;3,6]" << std::endl; pass = 0; }
    
    return pass;

}

int GPU_Dense_add_test (  ) {

    // Check.
    int pass = 1;

    // Initialize vectors and scalar.
    GPU_Dense x(3,1);
    GPU_Dense y(3,2);
    double a = 4.0;

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
    GPU_Dense r1 = x.add(a);
    GPU_Dense r2 = y.add(a);

    // Check for errors.
    if ((r1.Values[0] != 5.0) || (r1.Values[1] != 6.0) || (r1.Values[2] != 7.0)) {
        std::cout << "Errors in 4.0 + [1;2;3]" << std::endl; pass = 0; }
    if ((r2.Values[0] != 5.0) || (r2.Values[1] != 6.0) || (r2.Values[2] != 7.0) ||
        (r2.Values[3] != 8.0) || (r2.Values[4] != 9.0) || (r2.Values[5] != 10.0)) {
        std::cout << "Errors in 4.0 + [1,4;2,5;3,6]" << std::endl; pass = 0; }
    
    return pass;

}

int GPU_Sparse_f_add_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrix and scalar.
    GPU_Sparse_f A(4,3,6);
    float a = 4.0;
        
    // Fill matrix A1.
    A.Values[0] = 2;       // A1 = 2 0 0
    A.Values[1] = 2;       //      0 2 0
    A.Values[2] = 2;       //      0 0 2
    A.Values[3] = 1;       //      1 1 1
    A.Values[4] = 1;
    A.Values[5] = 1;
    A.I[0] = 0;
    A.I[1] = 1;
    A.I[2] = 2;
    A.I[3] = 3;
    A.I[4] = 6;
    A.J[0] = 0;
    A.J[1] = 1;
    A.J[2] = 2;
    A.J[3] = 0;
    A.J[4] = 1;
    A.J[5] = 2;

    // Perform the calculation.
    GPU_Sparse_f r = A.add(a);
    
    // Check for errors.
    if ((r.Values[0] != 6.0) || (r.Values[1] != 6.0) || (r.Values[2] != 6.0) || 
        (r.Values[3] != 5.0) || (r.Values[4] != 5.0) || (r.Values[5] != 5.0)) {
        std::cout << "Errors in 4.0 + A" << std::endl;
        pass = 0; }
    
    return pass;

}

int GPU_Sparse_add_test (  ) {

    // Check.
    int pass = 1;

    // Initialize Matrix and scalar.
    GPU_Sparse A(4,3,6);
    double a = 4.0;
        
    // Fill matrix A1.
    A.Values[0] = 2;       // A1 = 2 0 0
    A.Values[1] = 2;       //      0 2 0
    A.Values[2] = 2;       //      0 0 2
    A.Values[3] = 1;       //      1 1 1
    A.Values[4] = 1;
    A.Values[5] = 1;
    A.I[0] = 0;
    A.I[1] = 1;
    A.I[2] = 2;
    A.I[3] = 3;
    A.I[4] = 6;
    A.J[0] = 0;
    A.J[1] = 1;
    A.J[2] = 2;
    A.J[3] = 0;
    A.J[4] = 1;
    A.J[5] = 2;

    // Perform the calculation.
    GPU_Sparse r = A.add(a);
    
    // Check for errors.
    if ((r.Values[0] != 6.0) || (r.Values[1] != 6.0) || (r.Values[2] != 6.0) || 
        (r.Values[3] != 5.0) || (r.Values[4] != 5.0) || (r.Values[5] != 5.0)) {
        std::cout << "Errors in 4.0 + A" << std::endl;
        pass = 0; }
    
    return pass;

}

int main (  ) {

    int pass1 = CPU_Dense_add_test();
    int pass2 = CPU_Dense_f_add_test();
    int pass3 = GPU_Dense_add_test();
    int pass4 = GPU_Dense_f_add_test();
    int pass5 = CPU_Sparse_add_test();
    int pass6 = CPU_Sparse_f_add_test();
    int pass7 = GPU_Sparse_add_test();
    int pass8 = GPU_Sparse_f_add_test();

    int pass_global = 1;

    if (pass1 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_add_test" << std::endl; }
    if (pass2 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_f_add_test" << std::endl; }
    if (pass3 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_add_test" << std::endl; }
    if (pass4 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_f_add_test" << std::endl; }
    if (pass5 == 0) { pass_global = 0; std::cout << "Error in: CPU_Sparse_add_test" << std::endl; }
    if (pass6 == 0) { pass_global = 0; std::cout << "Error in: CPU_Sparse_f_add_test" << std::endl; }
    if (pass7 == 0) { pass_global = 0; std::cout << "Error in: GPU_Sparse_add_test" << std::endl; }
    if (pass8 == 0) { pass_global = 0; std::cout << "Error in: GPU_Sparse_f_add_test" << std::endl; }

    if (pass_global == 1) { std::cout << "PASSED" << std::endl; } else { std::cout << "FAILED" << std::endl; }

    return 0;
}