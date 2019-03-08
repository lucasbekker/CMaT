#include "include/CMaT.h"

int main (  ) {

    matfile_load matfile("matlab.mat");
    tic();
    GPU_Sparse A(matfile,"A");
    toc();
tic();
    GPU_Dense b(matfile,"b");toc();

    GPU_Dense ans = A.mv(b);

    
    //ans.print();

    return 0;


}