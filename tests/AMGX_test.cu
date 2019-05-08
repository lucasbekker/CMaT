#include "../include/CMaT.h"

int CPU_AMGX_test ( std::string config_spec ) {

    // Check.
    int pass = 1;
    double tol = 0.0001;

    // Initialize problem data.
    CPU_Sparse A(4,4,10);
    CPU_Dense  b(1,4);
    CPU_Dense  x_0(1,4);

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

    // Fill x with data. (initial guess)
    x_0.Values[0] = 1; x_0.Values[1] = 1; x_0.Values[2] = 1;
    x_0.Values[3] = 1;

    // Copy x_0 to x;
    CPU_Dense x = x_0.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_c = &A;
    Axb.b_c = &b;
    Axb.x_c = &x;
    Axb.n = A.Size[0];
    Axb.nnz = A.Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_hDDI;
    
    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Check for errors.
    if ( abs(x.Values[0] - 0.4) > tol ||
         abs(x.Values[1] - 0.2) > tol ||
         abs(x.Values[2] - 0.2) > tol ||
         abs(x.Values[3] - 0.4) > tol ) {
         pass = 0; }

    // Return the result.
    return pass;

}

int CPU_f_AMGX_test ( std::string config_spec ) {

    // Check.
    int pass = 1;
    float tol = 0.0001;

    // Initialize problem data.
    CPU_Sparse_f A(4,4,10);
    CPU_Dense_f  b(1,4);
    CPU_Dense_f  x_0(1,4);

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

    // Fill x with data. (initial guess)
    x_0.Values[0] = 1; x_0.Values[1] = 1; x_0.Values[2] = 1;
    x_0.Values[3] = 1;

    // Copy x_0 to x;
    CPU_Dense_f x = x_0.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_cf = &A;
    Axb.b_cf = &b;
    Axb.x_cf = &x;
    Axb.n = A.Size[0];
    Axb.nnz = A.Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_hFFI;
    
    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Check for errors.
    if ( abs(x.Values[0] - 0.4) > tol ||
         abs(x.Values[1] - 0.2) > tol ||
         abs(x.Values[2] - 0.2) > tol ||
         abs(x.Values[3] - 0.4) > tol ) {
         pass = 0; }

    // Return the result.
    return pass;

}

int GPU_AMGX_test ( std::string config_spec ) {

    // Check.
    int pass = 1;
    double tol = 0.0001;

    // Initialize problem data.
    GPU_Sparse A(4,4,10);
    GPU_Dense  b(1,4);
    GPU_Dense  x_0(1,4);

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

    // Fill x with data. (initial guess)
    x_0.Values[0] = 1; x_0.Values[1] = 1; x_0.Values[2] = 1;
    x_0.Values[3] = 1;

    // Copy x_0 to x;
    GPU_Dense x = x_0.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_g = &A;
    Axb.b_g = &b;
    Axb.x_g = &x;
    Axb.n = A.Size[0];
    Axb.nnz = A.Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_dDDI;
    
    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Check for errors.
    if ( abs(x.Values[0] - 0.4) > tol ||
         abs(x.Values[1] - 0.2) > tol ||
         abs(x.Values[2] - 0.2) > tol ||
         abs(x.Values[3] - 0.4) > tol ) {
         pass = 0; }

    // Return the result.
    return pass;

}

int GPU_f_AMGX_test ( std::string config_spec ) {

    // Check.
    int pass = 1;
    float tol = 0.0001;

    // Initialize problem data.
    GPU_Sparse_f A(4,4,10);
    GPU_Dense_f  b(1,4);
    GPU_Dense_f  x_0(1,4);

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

    // Fill x with data. (initial guess)
    x_0.Values[0] = 1; x_0.Values[1] = 1; x_0.Values[2] = 1;
    x_0.Values[3] = 1;

    // Copy x_0 to x;
    GPU_Dense_f x = x_0.clone();

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_gf = &A;
    Axb.b_gf = &b;
    Axb.x_gf = &x;
    Axb.n = A.Size[0];
    Axb.nnz = A.Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_dFFI;
    
    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

    // Check for errors.
    if ( abs(x.Values[0] - 0.4) > tol ||
         abs(x.Values[1] - 0.2) > tol ||
         abs(x.Values[2] - 0.2) > tol ||
         abs(x.Values[3] - 0.4) > tol ) {
         pass = 0; }

    // Return the result.
    return pass;

}

int main (  ) {

    std::string config_spec = "config_version=2, \
                               solver(fgmres)=FGMRES, \
                               fgmres:tolerance=0.01, \
                               fgmres:max_iters=40, \
                               fgmres:gmres_n_restart=10, \
                               fgmres:preconditioner=NOSOLVER";

    int pass1 = CPU_AMGX_test(config_spec);
    int pass2 = CPU_f_AMGX_test(config_spec);
    int pass3 = GPU_AMGX_test(config_spec);
    int pass4 = GPU_f_AMGX_test(config_spec);
    
    int pass_global = 1;

    if (pass1 == 0) { pass_global = 0; std::cout << "Error in: CPU_AMGX_test" << std::endl; }
    if (pass2 == 0) { pass_global = 0; std::cout << "Error in: CPU_f_AMGX_test" << std::endl; }
    if (pass3 == 0) { pass_global = 0; std::cout << "Error in: GPU_AMGX_test" << std::endl; }
    if (pass4 == 0) { pass_global = 0; std::cout << "Error in: GPU_f_AMGX_test" << std::endl; }
        
    if (pass_global == 1) { std::cout << "PASSED" << std::endl; } else { std::cout << "FAILED" << std::endl; }

    return 0;

}