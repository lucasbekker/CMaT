#include "../include/CMaT.h"

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
    thrust::device_vector<int> J(5);
    thrust::device_vector<int> Ip(4);
    thrust::device_vector<double> V_new(5);
    thrust::device_vector<int> J_new(5);
    thrust::device_vector<int> Ip_new(5);

    // Fill V.
    V[0] = 1; V[1] = 3; V[2] = 5; V[3] = 2; V[4] = 4; 

    // Fill Ip.
    Ip[0] = 0; Ip[1] = 3; Ip[2] = 4; Ip[3] = 5;

    // Fill J.
    J[0] = 0; J[1] = 1; J[2] = 3; J[3] = 0; J[4] = 1;
    
    // Perform the transpose operation.
    gpu_m.spdtrans(V,Ip,J,V_new,Ip_new,J_new);

    // Check for errors.
    if ((V_new[0] != 1.0) || (V_new[1] != 2.0) || (V_new[2] != 3.0) ||
        (V_new[3] != 4.0) || (V_new[4] != 5.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((J_new[0] != 0) || (J_new[1] != 1) || (J_new[2] != 0) ||
        (J_new[3] != 2) || (J_new[4] != 0)) {
        std::cout << "Errors in J." << std::endl; pass = 0; }
    if ((Ip_new[0] != 0) || (Ip_new[1] != 2) || (Ip_new[2] != 4) || 
        (Ip_new[3] != 4) || (Ip_new[4] != 5)) {
        std::cout << "Errors in Ip." << std::endl; pass = 0; }
    
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
    thrust::device_vector<int> J(5);
    thrust::device_vector<int> Ip(4);
    thrust::device_vector<float> V_new(5);
    thrust::device_vector<int> J_new(5);
    thrust::device_vector<int> Ip_new(5);

    // Fill V.
    V[0] = 1; V[1] = 3; V[2] = 5; V[3] = 2; V[4] = 4; 

    // Fill Ip.
    Ip[0] = 0; Ip[1] = 3; Ip[2] = 4; Ip[3] = 5;

    // Fill J.
    J[0] = 0; J[1] = 1; J[2] = 3; J[3] = 0; J[4] = 1;
    
    // Perform the transpose operation.
    gpu_m.spftrans(V,Ip,J,V_new,Ip_new,J_new);
    
    // Check for errors.
    if ((V_new[0] != 1.0) || (V_new[1] != 2.0) || (V_new[2] != 3.0) ||
        (V_new[3] != 4.0) || (V_new[4] != 5.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((J_new[0] != 0) || (J_new[1] != 1) || (J_new[2] != 0) ||
        (J_new[3] != 2) || (J_new[4] != 0)) {
        std::cout << "Errors in J." << std::endl; pass = 0; }
    if ((Ip_new[0] != 0) || (Ip_new[1] != 2) || (Ip_new[2] != 4) || 
        (Ip_new[3] != 4) || (Ip_new[4] != 5)) {
        std::cout << "Errors in Ip." << std::endl; pass = 0; }
    
    // Return the result.
    return pass;

}

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
    thrust::host_vector<int> J(5);
    thrust::host_vector<int> Ipb(3);
    thrust::host_vector<int> Ipe(3);
    thrust::host_vector<double> V_new(5);
    thrust::host_vector<int> J_new(5);
    thrust::host_vector<int> Ipb_new(4);
    thrust::host_vector<int> Ipe_new(4);

    // Fill V.
    V[0] = 1; V[1] = 3; V[2] = 5; V[3] = 2; V[4] = 4; 

    // Fill Ipb and Ipe.
    Ipb[0] = 0; Ipb[1] = 3; Ipb[2] = 4;
    Ipe[0] = 3; Ipe[1] = 4; Ipe[2] = 5;

    // Fill J.
    J[0] = 0; J[1] = 1; J[2] = 3; J[3] = 0; J[4] = 1;
    
    // Perform the transpose operation.
    cpu_m.spdtrans(V,Ipb,Ipe,J,V_new,Ipb_new,Ipe_new,J_new);

    // Check for errors.
    if ((V_new[0] != 1.0) || (V_new[1] != 2.0) || (V_new[2] != 3.0) ||
        (V_new[3] != 4.0) || (V_new[4] != 5.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((J_new[0] != 0) || (J_new[1] != 1) || (J_new[2] != 0) ||
        (J_new[3] != 2) || (J_new[4] != 0)) {
        std::cout << "Errors in J." << std::endl; pass = 0; }
    if ((Ipb_new[0] != 0) || (Ipb_new[1] != 2) || 
        (Ipb_new[2] != 4) || (Ipb_new[3] != 4)) {
        std::cout << "Errors in Ipb." << std::endl; pass = 0; }
    if ((Ipe_new[0] != 2) || (Ipe_new[1] != 4) || 
        (Ipe_new[2] != 4) || (Ipe_new[3] != 5)) {
        std::cout << "Errors in Ipe." << std::endl; pass = 0; }
    
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
    thrust::host_vector<int> J(5);
    thrust::host_vector<int> Ipb(3);
    thrust::host_vector<int> Ipe(3);
    thrust::host_vector<float> V_new(5);
    thrust::host_vector<int> J_new(5);
    thrust::host_vector<int> Ipb_new(4);
    thrust::host_vector<int> Ipe_new(4);

    // Fill V.
    V[0] = 1; V[1] = 3; V[2] = 5; V[3] = 2; V[4] = 4; 

    // Fill Ipb and Ipe.
    Ipb[0] = 0; Ipb[1] = 3; Ipb[2] = 4;
    Ipe[0] = 3; Ipe[1] = 4; Ipe[2] = 5;

    // Fill J.
    J[0] = 0; J[1] = 1; J[2] = 3; J[3] = 0; J[4] = 1;
    
    // Perform the transpose operation.
    cpu_m.spftrans(V,Ipb,Ipe,J,V_new,Ipb_new,Ipe_new,J_new);

    // Check for errors.
    if ((V_new[0] != 1.0) || (V_new[1] != 2.0) || (V_new[2] != 3.0) ||
        (V_new[3] != 4.0) || (V_new[4] != 5.0)) {
        std::cout << "Errors in V." << std::endl; pass = 0; }
    if ((J_new[0] != 0) || (J_new[1] != 1) || (J_new[2] != 0) ||
        (J_new[3] != 2) || (J_new[4] != 0)) {
        std::cout << "Errors in J." << std::endl; pass = 0; }
    if ((Ipb_new[0] != 0) || (Ipb_new[1] != 2) || 
        (Ipb_new[2] != 4) || (Ipb_new[3] != 4)) {
        std::cout << "Errors in Ipb." << std::endl; pass = 0; }
    if ((Ipe_new[0] != 2) || (Ipe_new[1] != 4) || 
        (Ipe_new[2] != 4) || (Ipe_new[3] != 5)) {
        std::cout << "Errors in Ipe." << std::endl; pass = 0; }
    
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