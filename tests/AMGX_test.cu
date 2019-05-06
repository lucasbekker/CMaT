#include "../include/CMaT.h"

void GMRES (  ) {

    // Specify AMGX mode and configuration.
    AMGX_Mode mode = AMGX_mode_dDDI;
    std::string config_spec = "config_version=2, \
                               solver(fgmres)=FGMRES, \
                               fgmres:tolerance=0.01, \
                               fgmres:max_iters=40, \
                               fgmres:gmres_n_restart=10, \
                               fgmres:preconditioner=NOSOLVER, \
                               fgmres:print_solve_stats=1, \
                               fgmres:monitor_residual=1";

    // Initialize AMGX.
    SOLVER_AmgX AMGX(config_spec,mode,4,10);

    // Initialize A, b and x.
    GPU_Sparse A(4,4,10);
    GPU_Dense  b(1,4);
    GPU_Dense  x(1,4);

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

    // Fill x with data.
    x.Values[0] = 1; x.Values[1] = 1; x.Values[2] = 1;
    x.Values[3] = 1;

    // Initialize solver data and fill with addresses.
    SOLVER_data Axb;
    Axb.A_g = &A;
    Axb.b_g = &b;
    Axb.x_g = &x;

    // Upload the data.
    AMGX.upload(Axb);

    // Solve.
    AMGX.solve();

    // Download the result.
    AMGX.download(Axb);

    // Print the result.    
    CPU_Dense result = convert(x);
    result.print();

}

int main (  ) {

    GMRES();

    return 0;

}