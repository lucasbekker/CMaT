#include "../include/CMaT.h"

void CPU_AMGX_test ( std::string config_spec ) {

    // Initialize A, b and x.
    CPU_Sparse A(4,4,10);
    CPU_Dense  b(1,4);
    
    // Fill A with data.
    A.Values[0] = 2; A.Values[1] = 1; A.Values[2] = 1;
    A.Values[3] = 2; A.Values[4] = 1; A.Values[5] = 1;
    A.Values[6] = 2; A.Values[7] = 1; A.Values[8] = 1;
    A.Values[9] = 2;
    A.J[0] = 0; A.J[1] = 1; A.J[2] = 0; A.J[3] = 1; A.J[4] = 2;
    A.J[5] = 1; A.J[6] = 2; A.J[7] = 3; A.J[8] = 2; A.J[9] = 3;
    A.Ib[0] = 0; A.Ib[1] = 2; A.Ib[2] = 5; A.Ib[3] = 8;
    A.Ie[0] = 2; A.Ie[1] = 5; A.Ie[2] = 8; A.Ie[3] = 10;
    
    // Fill b with data.
    b.Values[0] = 1; b.Values[1] = 1; b.Values[2] = 1;
    b.Values[3] = 1;

    // Start the solving procedure.
    CPU_Dense x = A.solve(b,config_spec);

    // Print the result.    
    x.print();

}

void CPU_f_AMGX_test ( std::string config_spec ) {

    // Initialize A, b and x.
    CPU_Sparse_f A(4,4,10);
    CPU_Dense_f  b(1,4);
   
    // Fill A with data.
    A.Values[0] = 2; A.Values[1] = 1; A.Values[2] = 1;
    A.Values[3] = 2; A.Values[4] = 1; A.Values[5] = 1;
    A.Values[6] = 2; A.Values[7] = 1; A.Values[8] = 1;
    A.Values[9] = 2;
    A.J[0] = 0; A.J[1] = 1; A.J[2] = 0; A.J[3] = 1; A.J[4] = 2;
    A.J[5] = 1; A.J[6] = 2; A.J[7] = 3; A.J[8] = 2; A.J[9] = 3;
    A.Ib[0] = 0; A.Ib[1] = 2; A.Ib[2] = 5; A.Ib[3] = 8;
    A.Ie[0] = 2; A.Ie[1] = 5; A.Ie[2] = 8; A.Ie[3] = 10;
    
    // Fill b with data.
    b.Values[0] = 1; b.Values[1] = 1; b.Values[2] = 1;
    b.Values[3] = 1;

    // Start the solving procedure.
    CPU_Dense_f x = A.solve(b,config_spec);

    // Print the result.    
    x.print();

}

void GPU_AMGX_test ( std::string config_spec ) {

    // Initialize A, b and x.
    GPU_Sparse A(4,4,10);
    GPU_Dense  b(1,4);
    
    // Fill A with data.
    A.Values[0] = 2; A.Values[1] = 1; A.Values[2] = 1;
    A.Values[3] = 2; A.Values[4] = 1; A.Values[5] = 1;
    A.Values[6] = 2; A.Values[7] = 1; A.Values[8] = 1;
    A.Values[9] = 2;
    A.J[0] = 0; A.J[1] = 1; A.J[2] = 0; A.J[3] = 1; A.J[4] = 2;
    A.J[5] = 1; A.J[6] = 2; A.J[7] = 3; A.J[8] = 2; A.J[9] = 3;
    A.I[0] = 0; A.I[1] = 2; A.I[2] = 5; A.I[3] = 8; A.I[4] = 10;
    
    // Fill b with data.
    b.Values[0] = 1; b.Values[1] = 1; b.Values[2] = 1;
    b.Values[3] = 1;

    // Start the solving procedure.
    GPU_Dense x = A.solve(b,config_spec);

    // Print the result.
    CPU_Dense xx = convert(x);      // WORKAROUND FOR BUG !!!
    xx.print();    

}

void GPU_f_AMGX_test ( std::string config_spec ) {

    // Initialize A, b and x.
    GPU_Sparse_f A(4,4,10);
    GPU_Dense_f  b(1,4);
    
    // Fill A with data.
    A.Values[0] = 2; A.Values[1] = 1; A.Values[2] = 1;
    A.Values[3] = 2; A.Values[4] = 1; A.Values[5] = 1;
    A.Values[6] = 2; A.Values[7] = 1; A.Values[8] = 1;
    A.Values[9] = 2;
    A.J[0] = 0; A.J[1] = 1; A.J[2] = 0; A.J[3] = 1; A.J[4] = 2;
    A.J[5] = 1; A.J[6] = 2; A.J[7] = 3; A.J[8] = 2; A.J[9] = 3;
    A.I[0] = 0; A.I[1] = 2; A.I[2] = 5; A.I[3] = 8; A.I[4] = 10;
    
    // Fill b with data.
    b.Values[0] = 1; b.Values[1] = 1; b.Values[2] = 1;
    b.Values[3] = 1;

    // Start the solving procedure.
    GPU_Dense_f x = A.solve(b,config_spec);

    // Print the result.    
    x.print();

}

int main (  ) {

    // Specify AMGX configuration.
    std::string config_spec = "./config/GMRES.json";

    CPU_AMGX_test(config_spec);
    CPU_f_AMGX_test(config_spec);
    GPU_AMGX_test(config_spec);
    GPU_f_AMGX_test(config_spec);

    return 0;

}