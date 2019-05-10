#include "../include/CMaT.h"

int main (  ) {

    // Specify AMGX configuration.
    std::string config_spec = "config_version=2, \
                               solver(fgmres)=FGMRES, \
                               fgmres:tolerance=0.00000001, \
                               fgmres:max_iters=2000, \
                               fgmres:gmres_n_restart=40, \
                               fgmres:preconditioner=NOSOLVER, \
                               fgmres:monitor_residual=1";

    // Open the MAT file.
    matfile_load mat_file_load("./tests/MAT_FILES","Poisson_10000.mat");

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