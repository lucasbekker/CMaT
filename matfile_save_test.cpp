#include "include/Matfile_save.h"

int main (  ) {

    std::string filename = "test.mat";
    std::string varname1 = "x";
    std::string varname2 = "y";
    std::string varname3 = "z";

    matfile_save mat_file(filename);

    double x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    float y[9] = {1,2,3,1,2,3,1,2,3}; 

    double V[6] = {1,2,3,4,5,6};
    int i[6] = {0,0,0,1,1,1};
    int j[7] = {0,1,2,3,4,5,6};

    int m = 6;

    matsparse_save z;

    z.sparsestream->nzmax = 6;

    mat_file.ddsave(varname1,x,10,1);
    mat_file.dfsave(varname2,y,3,3);
    mat_file.spsave(varname3,z.sparsestream,MAT_T_DOUBLE,2,6);

    return 0;
}