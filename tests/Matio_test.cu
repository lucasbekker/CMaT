#include "../include/CMaT.h"

int main (  ) {

    // Open the MAT file.
    matfile_load mat_file_load("./tests/MAT_FILES","abcd.mat");
    matfile_save mat_file_save("./tests/MAT_FILES/Matio_test_save.mat");

    CPU_Dense c_c(mat_file_load,"c");
    GPU_Dense c_g(mat_file_load,"c");

    CPU_Dense_f d_c(mat_file_load,"d");
    GPU_Dense_f d_g(mat_file_load,"d");

    double x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    float y[9] = {1,2,3,1,2,3,1,2,3};

    double V[6] = {1,2,3,4,5,6};
    int i[6] = {0,0,0,1,1,1};
    int j[7] = {0,1,2,3,4,5,6};

    matsparse_save z(V,i,j,6,6);

    mat_file_save.save("x","double",x,10,1);
    mat_file_save.save("y","float",y,3,3); 
    mat_file_save.save("z","sparsed",z.sparsestream,2,6);

    return 0;

}

