#include "../include/CMaT.h"

int CPU_spdtrans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Load the functions.
    CPU_methods cpu_m;

    // Declaration of vectors.
    thrust::host_vector<double> V(5);
    thrust::host_vector<int> i(5);
    thrust::host_vector<int> jpb(4);
    thrust::host_vector<int> jpe(4);
    thrust::host_vector<double> V_new(5);
    thrust::host_vector<int> j_new(5);
    thrust::host_vector<int> ipb_new(3);
    thrust::host_vector<int> ipe_new(3);

    // Fill V using CSC layout.
    V[0] = 1; V[1] = 2; V[2] = 3; V[3] = 4; V[4] = 5; 

    // Fill i using CSC layout.
    i[0] = 0; i[1] = 1; i[2] = 0; i[3] = 2; i[4] = 0; 

    // Fill jpb and jpe using CSC layout.
    jpb[0] = 0; jpb[1] = 2; jpb[2] = 4; jpb[3] = 4;
    jpe[0] = 2; jpe[1] = 4; jpe[2] = 4; jpe[3] = 5;

    // Perform the transpose operation.
    cpu_m.spdtrans(V, i, jpb, jpe, V_new, j_new, ipb_new, ipe_new);

    // Check for errors.
    if ((V_new[0] != 1.0) || (V_new[1] != 3.0) || (V_new[2] != 5.0) ||
        (V_new[3] != 2.0) || (V_new[4] != 4.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((j_new[0] != 0) || (j_new[1] != 1) || (j_new[2] != 3) ||
        (j_new[3] != 0) || (j_new[4] != 1)) {
        std::cout << "Errors in j." << std::endl; pass = 0; }
    if ((ipb_new[0] != 0) || (ipb_new[1] != 3) || (ipb_new[2] != 4)) {
        std::cout << "Errors in ipb." << std::endl; pass = 0; }
    if ((ipe_new[0] != 3) || (ipe_new[1] != 4) || (ipe_new[2] != 5)) {
        std::cout << "Errors in ipe." << std::endl; pass = 0; }

    // Return the result.
    return pass;

}

int CPU_spftrans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Load the functions.
    CPU_methods cpu_m;

    // Declaration of vectors.
    thrust::host_vector<float> V(5);
    thrust::host_vector<int> i(5);
    thrust::host_vector<int> jpb(4);
    thrust::host_vector<int> jpe(4);
    thrust::host_vector<float> V_new(5);
    thrust::host_vector<int> j_new(5);
    thrust::host_vector<int> ipb_new(3);
    thrust::host_vector<int> ipe_new(3);

    // Fill V using CSC layout.
    V[0] = 1; V[1] = 2; V[2] = 3; V[3] = 4; V[4] = 5; 

    // Fill i using CSC layout.
    i[0] = 0; i[1] = 1; i[2] = 0; i[3] = 2; i[4] = 0; 

    // Fill jpb and jpe using CSC layout.
    jpb[0] = 0; jpb[1] = 2; jpb[2] = 4; jpb[3] = 4;
    jpe[0] = 2; jpe[1] = 4; jpe[2] = 4; jpe[3] = 5;

    // Perform the transpose operation.
    cpu_m.spftrans(V, i, jpb, jpe, V_new, j_new, ipb_new, ipe_new);

    // Check for errors.
    if ((V_new[0] != 1.0) || (V_new[1] != 3.0) || (V_new[2] != 5.0) ||
        (V_new[3] != 2.0) || (V_new[4] != 4.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((j_new[0] != 0) || (j_new[1] != 1) || (j_new[2] != 3) ||
        (j_new[3] != 0) || (j_new[4] != 1)) {
        std::cout << "Errors in j." << std::endl; pass = 0; }
    if ((ipb_new[0] != 0) || (ipb_new[1] != 3) || (ipb_new[2] != 4)) {
        std::cout << "Errors in ipb." << std::endl; pass = 0; }
    if ((ipe_new[0] != 3) || (ipe_new[1] != 4) || (ipe_new[2] != 5)) {
        std::cout << "Errors in ipe." << std::endl; pass = 0; }

    // Return the result.
    return pass;

}

int GPU_spdtrans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Load the functions.
    GPU_methods gpu_m;

    // Declaration of vectors.
    thrust::device_vector<double> V(5);
    thrust::device_vector<int> i(5);
    thrust::device_vector<int> jp(5);
    thrust::device_vector<double> V_new(5);
    thrust::device_vector<int> j_new(5);
    thrust::device_vector<int> ip_new(4);

    // Fill V using CSC layout.
    V[0] = 1; V[1] = 2; V[2] = 3; V[3] = 4; V[4] = 5; 

    // Fill i using CSC layout.
    i[0] = 0; i[1] = 1; i[2] = 0; i[3] = 2; i[4] = 0; 

    // Fill jp using CSC layout.
    jp[0] = 0; jp[1] = 2; jp[2] = 4; jp[3] = 4; jp[4] = 5;
    
    // Perform the transpose operation.
    gpu_m.spdtrans(V, i, jp, V_new, j_new, ip_new);

    // Check for errors.
    if ((V_new[0] != 1.0) || (V_new[1] != 3.0) || (V_new[2] != 5.0) ||
        (V_new[3] != 2.0) || (V_new[4] != 4.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((j_new[0] != 0) || (j_new[1] != 1) || (j_new[2] != 3) ||
        (j_new[3] != 0) || (j_new[4] != 1)) {
        std::cout << "Errors in j." << std::endl; pass = 0; }
    if ((ip_new[0] != 0) || (ip_new[1] != 3) ||
        (ip_new[2] != 4) || (ip_new[3] != 5)) {
        std::cout << "Errors in ip." << std::endl; pass = 0; }
    
    // Return the result.
    return pass;

}

int GPU_spftrans_test (  ) {

    // A = 1 3 0 5
    //     2 0 0 0
    //     0 4 0 0

    // Check.
    int pass = 1;

    // Load the functions.
    GPU_methods gpu_m;

    // Declaration of vectors.
    thrust::device_vector<float> V(5);
    thrust::device_vector<int> i(5);
    thrust::device_vector<int> jp(5);
    thrust::device_vector<float> V_new(5);
    thrust::device_vector<int> j_new(5);
    thrust::device_vector<int> ip_new(4);

    // Fill V using CSC layout.
    V[0] = 1; V[1] = 2; V[2] = 3; V[3] = 4; V[4] = 5; 

    // Fill i using CSC layout.
    i[0] = 0; i[1] = 1; i[2] = 0; i[3] = 2; i[4] = 0; 

    // Fill jp using CSC layout.
    jp[0] = 0; jp[1] = 2; jp[2] = 4; jp[3] = 4; jp[4] = 5;
    
    // Perform the transpose operation.
    gpu_m.spftrans(V, i, jp, V_new, j_new, ip_new);

    // Check for errors.
    if ((V_new[0] != 1.0) || (V_new[1] != 3.0) || (V_new[2] != 5.0) ||
        (V_new[3] != 2.0) || (V_new[4] != 4.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((j_new[0] != 0) || (j_new[1] != 1) || (j_new[2] != 3) ||
        (j_new[3] != 0) || (j_new[4] != 1)) {
        std::cout << "Errors in j." << std::endl; pass = 0; }
    if ((ip_new[0] != 0) || (ip_new[1] != 3) ||
        (ip_new[2] != 4) || (ip_new[3] != 5)) {
        std::cout << "Errors in ip." << std::endl; pass = 0; }

    // Return the result.
    return pass;

}

int main (  ) {

    int pass1 = CPU_spdtrans_test();
    int pass2 = CPU_spftrans_test();
    int pass3 = GPU_spdtrans_test();
    int pass4 = GPU_spftrans_test();
    
    int pass_global = 1;

    if (pass1 == 0) { pass_global = 0; std::cout << "Error in: CPU_spdtrans_test" << std::endl; }
    if (pass2 == 0) { pass_global = 0; std::cout << "Error in: CPU_spftrans_test" << std::endl; }
    if (pass3 == 0) { pass_global = 0; std::cout << "Error in: GPU_spdtrans_test" << std::endl; }
    if (pass4 == 0) { pass_global = 0; std::cout << "Error in: GPU_spftrans_test" << std::endl; }
    
    if (pass_global == 1) { std::cout << "PASSED" << std::endl; } else { std::cout << "FAILED" << std::endl; }

    return 0;

}