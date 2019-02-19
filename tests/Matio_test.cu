#include "../include/CMaT.h"

int main (  ) {

    // Provide file location and variable name.
    std::string name = "x.mat";
    std::string path = "./tests/MAT_FILES";
    std::string variable = "x";

    // Open the MAT file.
    matfile_load mat_file(path,name);

    // Open the variable in MAT file.
    matvar mat_var = mat_file.openvar(variable);
    
    // Get the number of non-zero elements.
    int result = mat_var.sparsestream->nzmax;

    // Check the result.
    if (result == 10) { std::cout << "PASSED" << std::endl; }
    else { std::cout << "FAILED" << std::endl; }

    return 0;

}
