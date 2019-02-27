#include "../include/CMaT.h"

// Test CPU_Dense load.
int CPU_Dense_load_test ( matfile_load & mat_file ) {

    // Check.
    int pass = 1;

    // Load the variables.
    CPU_Dense test1(mat_file,"Dense_D");
    CPU_Dense_f test2(mat_file,"Dense_F");

    // Check for errors.
    if ((test1.Values[0] != 1) || (test1.Values[1] != 3) ||
        (test1.Values[2] != 2) || (test1.Values[3] != 4)) {
            std::cout << "Errors in CPU_Dense load" << std::endl;
            pass = 0; }
    if ((test2.Values[0] != 1) || (test2.Values[1] != 3) ||
        (test2.Values[2] != 2) || (test2.Values[3] != 4)) {
            std::cout << "Errors in CPU_Dense_f load" << std::endl;
            pass = 0; }

    return pass;

}

// Test GPU_Dense load.
int GPU_Dense_load_test ( matfile_load & mat_file ) {

    // Check.
    int pass = 1;

    // Load the variables.
    GPU_Dense test1(mat_file,"Dense_D");
    GPU_Dense_f test2(mat_file,"Dense_F");

    // Check for errors.
    if ((test1.Values[0] != 1) || (test1.Values[1] != 3) ||
        (test1.Values[2] != 2) || (test1.Values[3] != 4)) {
            std::cout << "Errors in GPU_Dense load" << std::endl;
            pass = 0; }
    if ((test2.Values[0] != 1) || (test2.Values[1] != 3) ||
        (test2.Values[2] != 2) || (test2.Values[3] != 4)) {
            std::cout << "Errors in GPU_Dense_f load" << std::endl;
            pass = 0; }

    return pass;
    
}

// Test CPU_Sparse load.
int CPU_Sparse_load_test ( matfile_load & mat_file ) {

    // Check.
    int pass = 1;
    std::cout << "debug" << std::endl;
    // Load the variables.
    CPU_Sparse test1(mat_file,"Sparse");
    std::cout << "debug" << std::endl;
    CPU_Sparse_f test2(mat_file,"Sparse");

    // Check for errors.
    if ((test1.Values[0] != 1) || (test1.Values[1] != 3) ||
        (test1.Values[2] != 2) || (test1.Values[3] != 4)) {
            std::cout << "Errors in CPU_Sparse load" << std::endl;
            pass = 0; }
    if ((test2.Values[0] != 1) || (test2.Values[1] != 3) ||
        (test2.Values[2] != 2) || (test2.Values[3] != 4)) {
            std::cout << "Errors in CPU_Sparse_f load" << std::endl;
            pass = 0; }

    return pass;
    
}

// Test GPU_Sparse load.
int GPU_Sparse_load_test ( matfile_load & mat_file ) {

    // Check.
    int pass = 1;



    return pass;
    
}

// Test CPU_Dense save.
int CPU_Dense_save_test ( matfile_save & mat_file ) {

    // Check.
    int pass = 1;



    return pass;

}

// Test GPU_Dense save.
int GPU_Dense_save_test ( matfile_save & mat_file ) {

    // Check.
    int pass = 1;



    return pass;
    
}

// Test CPU_Sparse save.
int CPU_Sparse_save_test ( matfile_save & mat_file ) {

    // Check.
    int pass = 1;



    return pass;
    
}

// Test GPU_Sparse save.
int GPU_Sparse_save_test ( matfile_save & mat_file ) {

    // Check.
    int pass = 1;



    return pass;
    
}

int main (  ) {

    // Open the MAT files.
    matfile_save mat_file_save("./tests/MAT_FILES","Matio_test_save.mat");
    matfile_load mat_file_load("./tests/MAT_FILES","Matio_test_load.mat");

    int pass1 = CPU_Dense_load_test(mat_file_load);
    int pass2 = GPU_Dense_load_test(mat_file_load);
    int pass3 = CPU_Sparse_load_test(mat_file_load);
    int pass4 = GPU_Sparse_load_test(mat_file_load);
    int pass5 = CPU_Dense_save_test(mat_file_save);
    int pass6 = GPU_Dense_save_test(mat_file_save);
    int pass7 = CPU_Sparse_save_test(mat_file_save);
    int pass8 = GPU_Sparse_save_test(mat_file_save);

    int pass_global = 1;

    if (pass1 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_load_test" << std::endl; }
    if (pass2 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_load_test" << std::endl; }
    if (pass3 == 0) { pass_global = 0; std::cout << "Error in: CPU_Sparse_load_test" << std::endl; }
    if (pass4 == 0) { pass_global = 0; std::cout << "Error in: GPU_Sparse_load_test" << std::endl; }
    if (pass5 == 0) { pass_global = 0; std::cout << "Error in: CPU_Dense_save_test" << std::endl; }
    if (pass6 == 0) { pass_global = 0; std::cout << "Error in: GPU_Dense_save_test" << std::endl; }
    if (pass7 == 0) { pass_global = 0; std::cout << "Error in: CPU_Sparse_save_test" << std::endl; }
    if (pass8 == 0) { pass_global = 0; std::cout << "Error in: GPU_Sparse_save_test" << std::endl; }

    if (pass_global == 1) { std::cout << "PASSED" << std::endl; } else { std::cout << "FAILED" << std::endl; }

    return 0;

}