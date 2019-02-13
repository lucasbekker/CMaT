#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/sort.h>
#include <thrust/iterator/zip_iterator.h>
#include <thrust/tuple.h>

#include <iostream>

void spdtrans_CPU ( const thrust::host_vector<double> & V, const thrust::host_vector<int> & i, 
                    const thrust::host_vector<int> & jp, thrust::host_vector<double> & V_new,
                    thrust::host_vector<int> & j_new, thrust::host_vector<int> & ip_new ) {

    // Create temporary data vector.
    thrust::host_vector<int> i_temp(i.size());

    // Copy data to the new and temporary vectors.
    thrust::copy(V.begin(), V.end(), V_new.begin());
    thrust::copy(i.begin(), i.end(), i_temp.begin());
    
    // Fill j_new using COO layout.
    for ( int k = 0; k < (jp.size() - 1); k++ ) {

        thrust::fill_n((j_new.begin() + jp[k] - 1), (jp[k + 1] - jp[k]), (k + 1)); 

    }

    // Typedefs for zip iterator.
    typedef thrust::host_vector<double>::iterator DoubleIt;
    typedef thrust::host_vector<int>::iterator IntIt;
    typedef thrust::tuple<DoubleIt,IntIt> TupleIt;
    typedef thrust::zip_iterator<TupleIt> ZipIt;

    // Create the zip iterator
    ZipIt zip_iterator(thrust::make_tuple(V_new.begin(), j_new.begin()));

    // Reorder V, i and j such that V and j conform to the CSR layout.
    thrust::stable_sort_by_key(i_temp.begin(), i_temp.end(), zip_iterator);

    // Fill the first value of ip_new.
    ip_new[0] = 1;

    // Fill ip_new using the CSR layout.
    for ( int k = 0; k < (ip_new.size() - 1); k++ ) {
        
        ip_new[k + 1] = ip_new[k] + thrust::count(i.begin(), i.end(), (k + 1));

    }

}

int main (  ) {

// A = 1 0 0 0 0
//     2 3 5 6 0
//     0 0 0 7 8
//     0 4 0 0 0

// Declaration of vectors.
thrust::host_vector<double> V(8);
thrust::host_vector<int> i(8);
thrust::host_vector<int> jp(6);
thrust::host_vector<double> V_new(8);
thrust::host_vector<int> j_new(8);
thrust::host_vector<int> ip_new(5);

// Fill V using CSC layout.
V[0] = 1; V[1] = 2;
V[2] = 3; V[3] = 4;
V[4] = 5; 
V[5] = 6; V[6] = 7;
V[7] = 8;

// Fill i using CSC layout.
i[0] = 1; i[1] = 2;
i[2] = 2; i[3] = 4;
i[4] = 2; 
i[5] = 2; i[6] = 3;
i[7] = 3;

// Fill jp using CSC layout.
jp[0] = 1; jp[1] = 3; jp[2] = 5; jp[3] = 6; jp[4] = 8; jp[5] = 9;   

// Perform the transpose operation.
spdtrans_CPU(V, i, jp, V_new, j_new, ip_new);

// Print V_new.
for ( int k = 0; k < V_new.size(); k++ ) {
    std::cout << "V_new [" << k << "] = " << V_new[k] << std::endl;
}
    
// Print j_new.
for ( int k = 0; k < j_new.size(); k++ ) {
    std::cout << "j_new [" << k << "] = " << j_new[k] << std::endl;
}

// Print ip_new.
for ( int k = 0; k < ip_new.size(); k++ ) {
    std::cout << "ip_new [" << k << "] = " << ip_new[k] << std::endl;
}

}