#include "../include/CMaT.h"

int main (  ) {

    // Provide file location and variable name.
    std::string filename = "./tests/MAT_FILES/x.mat";
    std::string variable = "x";

    // Open the MAT file.
    mat_t * mat_file = matio_open_file(filename);

    // Open the variable in MAT file.
    matvar_t * mat_variable = matio_open_variable(mat_file,variable);

    // Cast to sparse.
    mat_sparse_t * mat_sparse = matio_prepare_sparse(mat_variable);

    // Get the number of non-zero elements.
    int result = mat_sparse->nzmax;

    // Check the result.
    if (result == 10) { std::cout << "PASSED" << std::endl; }
    else { std::cout << "FAILED" << std::endl; }

    // Close the MAT file.
    matio_close_file(mat_file);

    return 0;

}
