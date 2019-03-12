#include "include/CMaT.h"

int main (  ) {

    matfile_load matfile("matlab.mat");
    
    CPU_Sparse A(matfile,"A");
    CPU_Dense b(matfile,"b");
    GPU_Sparse AA(matfile,"A");
    GPU_Dense bb(matfile,"B");

    tic();
    CPU_Dense c = A.mv(b);
    toc();
    
    tic();
    GPU_Dense cc = AA.mv(bb);
    toc();

    return 0;

}