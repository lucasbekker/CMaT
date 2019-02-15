#include "../include/CMaT.h"

int main (  ) {

// A = 1 0 0 0 0
//     2 3 5 6 0
//     0 0 0 7 8
//     0 4 0 0 0

// Load the functions.
CPU_methods cpu_m;

// Declaration of vectors.
thrust::host_vector<double> V(8);
thrust::host_vector<int> i(8);
thrust::host_vector<int> jpb(5);
thrust::host_vector<int> jpe(5);
thrust::host_vector<double> V_new(8);
thrust::host_vector<int> j_new(8);
thrust::host_vector<int> ipb_new(4);
thrust::host_vector<int> ipe_new(4);

// Fill V using CSC layout.
V[0] = 1; V[1] = 2;
V[2] = 3; V[3] = 4;
V[4] = 5; 
V[5] = 6; V[6] = 7;
V[7] = 8;

// Fill i using CSC layout.
i[0] = 0; i[1] = 1;
i[2] = 1; i[3] = 3;
i[4] = 1; 
i[5] = 1; i[6] = 2;
i[7] = 2;

// Fill jpb and jpe using CSC layout.
jpb[0] = 0; jpb[1] = 2; jpb[2] = 4; jpb[3] = 5; jpb[4] = 7;
jpe[0] = 2; jpe[1] = 4; jpe[2] = 5; jpe[3] = 7; jpe[4] = 8;

// Perform the transpose operation.
cpu_m.spdtrans(V, i, jpb, jpe, V_new, j_new, ipb_new, ipe_new);

// Print V_new.
for ( int k = 0; k < V_new.size(); k++ ) {
    std::cout << "V_new [" << k << "] = " << V_new[k] << std::endl;
}
    
// Print j_new.
for ( int k = 0; k < j_new.size(); k++ ) {
    std::cout << "j_new [" << k << "] = " << j_new[k] << std::endl;
}

// Print ipb_new.
for ( int k = 0; k < ipb_new.size(); k++ ) {
    std::cout << "ipb_new [" << k << "] = " << ipb_new[k] << std::endl;
}

// Print ipe_new.
for ( int k = 0; k < ipe_new.size(); k++ ) {
    std::cout << "ipe_new [" << k << "] = " << ipe_new[k] << std::endl;
}

}