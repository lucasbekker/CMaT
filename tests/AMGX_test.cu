#include "../include/CMaT.h"

void GMRES_GPU_test ( GPU_Sparse & A, GPU_Dense & b, GPU_Dense & x ) {

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_g = &A;
    Axb.b_g = &b;
    Axb.x_g = &x;
    Axb.n = A.Size[0];
    Axb.nnz = A.Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_dDDI;
    std::string config_spec = "config_version=2, \
                               solver(fgmres)=FGMRES, \
                               fgmres:tolerance=0.01, \
                               fgmres:max_iters=40, \
                               fgmres:gmres_n_restart=10, \
                               fgmres:preconditioner=NOSOLVER, \
                               fgmres:print_solve_stats=1, \
                               fgmres:monitor_residual=1";

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

}

void GMRES_GPU_f_test ( GPU_Sparse_f & A, GPU_Dense_f & b, GPU_Dense_f & x ) {

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_gf = &A;
    Axb.b_gf = &b;
    Axb.x_gf = &x;
    Axb.n = A.Size[0];
    Axb.nnz = A.Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_dFFI;
    std::string config_spec = "config_version=2, \
                               solver(fgmres)=FGMRES, \
                               fgmres:tolerance=0.01, \
                               fgmres:max_iters=40, \
                               fgmres:gmres_n_restart=10, \
                               fgmres:preconditioner=NOSOLVER, \
                               fgmres:print_solve_stats=1, \
                               fgmres:monitor_residual=1";

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

}

void GMRES_CPU_test ( CPU_Sparse & A, CPU_Dense & b, CPU_Dense & x ) {

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_c = &A;
    Axb.b_c = &b;
    Axb.x_c = &x;
    Axb.n = A.Size[0];
    Axb.nnz = A.Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_hDDI;
    std::string config_spec = "config_version=2, \
                               solver(fgmres)=FGMRES, \
                               fgmres:tolerance=0.01, \
                               fgmres:max_iters=40, \
                               fgmres:gmres_n_restart=10, \
                               fgmres:preconditioner=NOSOLVER, \
                               fgmres:print_solve_stats=1, \
                               fgmres:monitor_residual=1";

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

}

void GMRES_CPU_f_test ( CPU_Sparse_f & A, CPU_Dense_f & b, CPU_Dense_f & x ) {

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_cf = &A;
    Axb.b_cf = &b;
    Axb.x_cf = &x;
    Axb.n = A.Size[0];
    Axb.nnz = A.Size[2];

    // Specify AMGX configuration.
    AMGX_Mode mode = AMGX_mode_hFFI;
    std::string config_spec = "config_version=2, \
                               solver(fgmres)=FGMRES, \
                               fgmres:tolerance=0.01, \
                               fgmres:max_iters=40, \
                               fgmres:gmres_n_restart=10, \
                               fgmres:preconditioner=NOSOLVER, \
                               fgmres:print_solve_stats=1, \
                               fgmres:monitor_residual=1";

    // Start the solving procedure.
    SOLVER_AmgX AMGX(config_spec, mode, Axb);

}

int main (  ) {

    // GPU double
    // =====================================================================
    // Initialize A, b and x.
    GPU_Sparse A_g(4,4,10);
    GPU_Dense  b_g(1,4);
    GPU_Dense  x_0g(1,4);

    // Fill A with data.
    A_g.Values[0] = 2; A_g.Values[1] = 1; A_g.Values[2] = 1;
    A_g.Values[3] = 2; A_g.Values[4] = 1; A_g.Values[5] = 1;
    A_g.Values[6] = 2; A_g.Values[7] = 1; A_g.Values[8] = 1;
    A_g.Values[9] = 2;
    A_g.J[0] = 0; A_g.J[1] = 1; A_g.J[2] = 0; A_g.J[3] = 1; A_g.J[4] = 2;
    A_g.J[5] = 1; A_g.J[6] = 2; A_g.J[7] = 3; A_g.J[8] = 2; A_g.J[9] = 3;
    A_g.I[0] = 0; A_g.I[1] = 2; A_g.I[2] = 5; A_g.I[3] = 8; A_g.I[4] = 10;
    
    // Fill b with data.
    b_g.Values[0] = 1; b_g.Values[1] = 1; b_g.Values[2] = 1;
    b_g.Values[3] = 1;

    // Fill x with data. (initial guess)
    x_0g.Values[0] = 1; x_0g.Values[1] = 1; x_0g.Values[2] = 1;
    x_0g.Values[3] = 1;

    // Copy x_0 to x;
    GPU_Dense x_g = x_0g.clone();

    // Solve Ax=b.
    GMRES_GPU_test(A_g, b_g, x_g);

    // Print the result.    
    CPU_Dense result_g = convert(x_g);
    result_g.print();

    // GPU float
    // =====================================================================
    // Initialize A, b and x.
    GPU_Sparse_f A_gf(4,4,10);
    GPU_Dense_f  b_gf(1,4);
    GPU_Dense_f  x_0gf(1,4);

    // Fill A with data.
    A_gf.Values[0] = 2; A_gf.Values[1] = 1; A_gf.Values[2] = 1;
    A_gf.Values[3] = 2; A_gf.Values[4] = 1; A_gf.Values[5] = 1;
    A_gf.Values[6] = 2; A_gf.Values[7] = 1; A_gf.Values[8] = 1;
    A_gf.Values[9] = 2;
    A_gf.J[0] = 0; A_gf.J[1] = 1; A_gf.J[2] = 0; A_gf.J[3] = 1; A_gf.J[4] = 2;
    A_gf.J[5] = 1; A_gf.J[6] = 2; A_gf.J[7] = 3; A_gf.J[8] = 2; A_gf.J[9] = 3;
    A_gf.I[0] = 0; A_gf.I[1] = 2; A_gf.I[2] = 5; A_gf.I[3] = 8; A_gf.I[4] = 10;
    
    // Fill b with data.
    b_gf.Values[0] = 1; b_gf.Values[1] = 1; b_gf.Values[2] = 1;
    b_gf.Values[3] = 1;

    // Fill x with data. (initial guess)
    x_0gf.Values[0] = 1; x_0gf.Values[1] = 1; x_0gf.Values[2] = 1;
    x_0gf.Values[3] = 1;

    // Copy x_0 to x;
    GPU_Dense_f x_gf = x_0gf.clone();

    // Solve Ax=b.
    GMRES_GPU_f_test(A_gf, b_gf, x_gf);

    // Print the result.    
    CPU_Dense_f result_gf = convert(x_gf);
    result_gf.print();

    // CPU double
    // =====================================================================
    // Initialize A, b and x.
    CPU_Sparse A_c(4,4,10);
    CPU_Dense  b_c(1,4);
    CPU_Dense  x_0c(1,4);

    // Fill A with data.
    A_c.Values[0] = 2; A_c.Values[1] = 1; A_c.Values[2] = 1;
    A_c.Values[3] = 2; A_c.Values[4] = 1; A_c.Values[5] = 1;
    A_c.Values[6] = 2; A_c.Values[7] = 1; A_c.Values[8] = 1;
    A_c.Values[9] = 2;
    A_c.J[0] = 0; A_c.J[1] = 1; A_c.J[2] = 0; A_c.J[3] = 1; A_c.J[4] = 2;
    A_c.J[5] = 1; A_c.J[6] = 2; A_c.J[7] = 3; A_c.J[8] = 2; A_c.J[9] = 3;
    A_c.Ib[0] = 0; A_c.Ib[1] = 2; A_c.Ib[2] = 5; A_c.Ib[3] = 8;
    A_c.Ie[0] = 2; A_c.Ie[1] = 5; A_c.Ie[2] = 8; A_c.Ie[3] = 10;
    
    // Fill b with data.
    b_c.Values[0] = 1; b_c.Values[1] = 1; b_c.Values[2] = 1;
    b_c.Values[3] = 1;

    // Fill x with data. (initial guess)
    x_0c.Values[0] = 1; x_0c.Values[1] = 1; x_0c.Values[2] = 1;
    x_0c.Values[3] = 1;

    // Copy x_0 to x;
    CPU_Dense x_c = x_0c.clone();

    // Solve Ax=b.
    GMRES_CPU_test(A_c, b_c, x_c);

    // Print the result.    
    CPU_Dense result_c = x_c.clone();
    result_c.print();

    // CPU float
    // =====================================================================
    // Initialize A, b and x.
    CPU_Sparse_f A_cf(4,4,10);
    CPU_Dense_f  b_cf(1,4);
    CPU_Dense_f  x_0cf(1,4);

    // Fill A with data.
    A_cf.Values[0] = 2; A_cf.Values[1] = 1; A_cf.Values[2] = 1;
    A_cf.Values[3] = 2; A_cf.Values[4] = 1; A_cf.Values[5] = 1;
    A_cf.Values[6] = 2; A_cf.Values[7] = 1; A_cf.Values[8] = 1;
    A_cf.Values[9] = 2;
    A_cf.J[0] = 0; A_cf.J[1] = 1; A_cf.J[2] = 0; A_cf.J[3] = 1; A_cf.J[4] = 2;
    A_cf.J[5] = 1; A_cf.J[6] = 2; A_cf.J[7] = 3; A_cf.J[8] = 2; A_cf.J[9] = 3;
    A_cf.Ib[0] = 0; A_cf.Ib[1] = 2; A_cf.Ib[2] = 5; A_cf.Ib[3] = 8;
    A_cf.Ie[0] = 2; A_cf.Ie[1] = 5; A_cf.Ie[2] = 8; A_cf.Ie[3] = 10;
    
    // Fill b with data.
    b_cf.Values[0] = 1; b_cf.Values[1] = 1; b_cf.Values[2] = 1;
    b_cf.Values[3] = 1;

    // Fill x with data. (initial guess)
    x_0cf.Values[0] = 1; x_0cf.Values[1] = 1; x_0cf.Values[2] = 1;
    x_0cf.Values[3] = 1;

    // Copy x_0 to x;
    CPU_Dense_f x_cf = x_0cf.clone();

    // Solve Ax=b.
    GMRES_CPU_f_test(A_cf, b_cf, x_cf);

    // Print the result.    
    CPU_Dense_f result_cf = x_cf.clone();
    result_cf.print();

    return 0;

}