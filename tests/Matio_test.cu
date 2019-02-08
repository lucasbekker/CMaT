#include "../include/CMaT.h"

int matio_sparse_nnz ( std::string file, std::string variable ) {

    // Open .mat file.
    mat_t * mat_file = Mat_Open(file.c_str(),MAT_ACC_RDONLY);

    // Check succesfull opening of .mat file.
    if (mat_file == NULL) {

        std::cout << "Error opening MAT file: '" << file << "'" << std::endl;

        return 0;

    } 
    
    // Open variable in .mat file.
    matvar_t * mat_variable = Mat_VarRead(mat_file,variable.c_str());

    // Check succesfull opening of variable in .mat file.
    if (mat_variable == NULL) {
        
        std::cout << "Variable: '" << variable << "' not found." << std::endl;
        
        return 0;
        
    } 

    // Cast data field of variable to sparse type.
    mat_sparse_t * mat_sparse = (mat_sparse_t*) mat_variable->data;
    
    // Close the .mat file.
    Mat_Close(mat_file);
    
    // Return the number of non-zero elements.
    return mat_sparse->nzmax;

}

int main (  ) {

    // Provide file location and variable name.
    std::string filename = "./tests/MAT_FILES/x.mat";
    std::string variable = "x";

    // Get the number of non-zero elements.
    int result = matio_sparse_nnz(filename,variable);

    // Check the result.
    if (result == 10) { std::cout << "PASSED" << std::endl; }
    else { std::cout << "FAILED" << std::endl; }

}
