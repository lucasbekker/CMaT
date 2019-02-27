#include "../include/CMaT.h"

int main (  ) {

    // Open the MAT file.
    matfile_save mat_file_save("./tests/MAT_FILES/Matio_test_save.mat");

    // Declaration of matrix.
    CPU_Sparse_f test(3,4,5);
    
    // Fill V.
    test.Values[0] = 1; test.Values[1] = 3; test.Values[2] = 5;
    test.Values[3] = 2; test.Values[4] = 4; 

    // Fill Ipb and Ipe.
    test.Ib[0] = 0; test.Ib[1] = 3; test.Ib[2] = 4;
    test.Ie[0] = 3; test.Ie[1] = 4; test.Ie[2] = 5;

    // Fill J.
    test.J[0] = 0; test.J[1] = 1; test.J[2] = 3; 
    test.J[3] = 0; test.J[4] = 1;

    test.save(mat_file_save,"test");

    /*// Declaration of matrix.
    GPU_Sparse_f testf(3,4,5);
    
    // Fill V.
    testf.Values[0] = 1; testf.Values[1] = 3; testf.Values[2] = 5;
    testf.Values[3] = 2; testf.Values[4] = 4; 

    // Fill Ip.
    testf.I[0] = 0; testf.I[1] = 3; testf.I[2] = 4; testf.I[3] = 5;
    
    // Fill J.
    testf.J[0] = 0; testf.J[1] = 1; testf.J[2] = 3; 
    testf.J[3] = 0; testf.J[4] = 1;

    testf.save(mat_file_save,"testf");*/

    return 0;

}

