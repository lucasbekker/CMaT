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
    AmgX AMGX(config_spec,mode); 
    
    // Fill A with data.
    double data[] = {2,1,1,2,1,1,2,1,1,2};
    int col_ind[] = {0,1,0,1,2,1,2,3,2,3};
    int row_ptr[] = {0,2,5,8,10};
    AMGX_matrix_upload_all(AMGX.A, 4, 10, 1, 1, row_ptr, col_ind, data, 0);

    // Fill b with data.
    double b_data[] = {1,1,1,1};
    AMGX_vector_upload(AMGX.b,4,1,b_data);

    // Fill x with b as initial guess.
    AMGX_vector_upload(AMGX.x,4,1,b_data);

    AMGX.solve();

    // Gather the solution.
    double solution[4];
    AMGX_vector_download(AMGX.x,solution);

    // Print the solution.
    std::cout << solution[0] << std::endl;
    std::cout << solution[1] << std::endl;
    std::cout << solution[2] << std::endl;
    std::cout << solution[3] << std::endl;

}

int main (  ) {

    GMRES();

    return 0;

}