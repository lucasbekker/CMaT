mat_t * matio_open_file ( std::string file ) {

    // Open .mat file.
    mat_t * mat_file = Mat_Open(file.c_str(),MAT_ACC_RDONLY);

    // Check succesfull opening of .mat file.
    if (mat_file == NULL) {
        std::cout << "Error opening MAT file: '" << file << "'" << std::endl;
    }

    return mat_file;

}

matvar_t * matio_open_variable ( mat_t * mat_file, std::string variable ) {

    // Open variable in .mat file.
    matvar_t * mat_variable = Mat_VarRead(mat_file,variable.c_str());

    // Check succesfull opening of variable in .mat file.
    if (mat_variable == NULL) {
        std::cout << "Variable: '" << variable << "' not found." << std::endl; 
    }

    return mat_variable;

} 

mat_sparse_t * matio_prepare_sparse ( matvar_t * mat_variable ) {

    // Cast data field of variable to sparse type.
    mat_sparse_t * mat_sparse = (mat_sparse_t*) mat_variable->data;

    return mat_sparse;

}

void matio_close_file ( mat_t * mat_file ) { Mat_Close(mat_file); }

