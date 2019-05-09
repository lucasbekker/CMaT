#include "../include/CMaT.h"

int main (  ) {

    // Specify AMGX configuration.
    std::string config_spec = "config_version=2, \
                               solver(main)=FGMRES, \
                               main:max_iters=300, \
                               main:convergence=RELATIVE_MAX, \
                               main:tolerance=0.00000001, \
                               main:monitor_residual=1, \
                               main:preconditioner(amg)=AMG, \
                               main:print_solve_stats=1, \
                               amg:algorithm=AGGREGATION, \
                               amg:selector=SIZE_8, \
                               amg:cycle=V, \
                               amg:max_iters=1, \
                               amg:max_levels=10, \
                               amg:smoother(amg_smoother)=BLOCK_JACOBI, \
                               amg:relaxation_factor=0.75, \
                               amg:presweeps=1, \
                               amg:postsweeps=2, \
                               amg:coarsest_sweeps=4, \
                               determinism_flag=1";

    // Open the MAT file.
    matfile_load mat_file_load("./tests/MAT_FILES","Poisson_1000000.mat");

    // Load the data (Ar=b).
    GPU_Sparse A(mat_file_load,"A");
    GPU_Dense  b(mat_file_load,"b");
    GPU_Dense  r(mat_file_load,"x");

    // Solve Ax=b.
    tic();
    GPU_Dense x = Solve(A,b,config_spec);
    toc();

    // Subtract the r from x.
    GPU_Dense b_x = A.mv(x);
    GPU_Dense res = b_x.add(b.scp(-1));

    // Print the result.
    std::cout << "2-norm of the residual is: " << sqrt(res.dot(res)) << std::endl;

    return 0;

}