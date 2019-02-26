#include "../include/CMaT.h"

int main (  ) {

    // Open the MAT file.
    matfile_save mat_file_save("./tests/MAT_FILES/Matio_test_save.mat");

    /*// Declaration of matrix.
    GPU_Sparse testd(3,4,5);
    
    // Fill V.
    testd.Values[0] = 1; testd.Values[1] = 3; testd.Values[2] = 5;
    testd.Values[3] = 2; testd.Values[4] = 4; 

    // Fill Ip.
    testd.I[0] = 0; testd.I[1] = 3; testd.I[2] = 4; testd.I[3] = 5;
    
    // Fill J.
    testd.J[0] = 0; testd.J[1] = 1; testd.J[2] = 3; 
    testd.J[3] = 0; testd.J[4] = 1;

    testd.save(mat_file_save,"testd");*/

    // Declaration of matrix.
    GPU_Sparse_f testf(3,4,5);
    
    // Fill V.
    testf.Values[0] = 1; testf.Values[1] = 3; testf.Values[2] = 5;
    testf.Values[3] = 2; testf.Values[4] = 4; 

    // Fill Ip.
    testf.I[0] = 0; testf.I[1] = 3; testf.I[2] = 4; testf.I[3] = 5;
    
    // Fill J.
    testf.J[0] = 0; testf.J[1] = 1; testf.J[2] = 3; 
    testf.J[3] = 0; testf.J[4] = 1;

    testf.save(mat_file_save,"testf");

    return 0;

}

