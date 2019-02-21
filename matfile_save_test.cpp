#include "include/Matfile_save.h"

int main (  ) {

    std::string filename = "test.mat";
    std::string varname1 = "x";
    std::string varname2 = "y";

    matfile_save mat_file(filename);

    double x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    float y[9] = {1,2,3,1,2,3,1,2,3}; 

    mat_file.ddsave(varname1,x,10,1);
    mat_file.dfsave(varname2,y,3,3);

    return 0;
}