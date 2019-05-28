#include "../include/CMaT.h"

int main (  ) {

    // Specify AMGX configuration.
    std::string config_spec = "config_version=2, \
                               solver(main)=FGMRES, \
                               main:max_iters=10000, \
                               main:convergence=RELATIVE_MAX, \
                               main:gmres_n_restart=100, \
                               main:tolerance=0.00000001, \
                               main:monitor_residual=1, \
                               main:preconditioner(ilu)=NOSOLVER, \
                               main:print_solve_stats=1, \
                               determinism_flag=1";

    // Open the MAT file.
    matfile_load mat_file_load("./tests/MAT_FILES","jacobi_daan_19801.mat");

    // Load the data (Ar=b).
    GPU_Sparse A(mat_file_load,"A");
    GPU_Dense  b(mat_file_load,"b");
    GPU_Dense  r(mat_file_load,"x");

    // Solve Ax=b.
    tic();
    GPU_Dense x = A.solve(b,config_spec);
    toc();

    // Subtract the r from x.
    GPU_Dense b_x = A.mv(x);
    GPU_Dense res = b_x.add(b.scp(-1));

    // Print the result.
    std::cout << "2-norm of the residual is: " << sqrt(res.dot(res)) << std::endl;

    return 0;

}