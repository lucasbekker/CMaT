#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/sort.h>
#include <thrust/iterator/zip_iterator.h>
#include <thrust/tuple.h>

#include <iostream>

// This code converts a CSC layout matrix to the CSR layout. 
int main (  ) {

// A = 1 0 0 0
//     2 3 5 6
//     0 0 0 7
//     0 4 0 0

// Declaration of vectors.
thrust::host_vector<double> V(7);
thrust::host_vector<int> i(7);
thrust::host_vector<int> jp(5);
thrust::host_vector<int> j(7);

// Fill V using CSC layout.
V[0] = 1; V[1] = 2;
V[2] = 3; V[3] = 4;
V[4] = 5; 
V[5] = 6; V[6] = 7;

// Fill i using CSC layout.
i[0] = 1; i[1] = 2;
i[2] = 2; i[3] = 4;
i[4] = 2; 
i[5] = 2; i[6] = 3;

// Fill jp using CSC layout.
jp[0] = 1; jp[1] = 3; jp[2] = 5; jp[3] = 6; jp[4] = 8;

// Fill j using COO layout and jp using CSR layout of ip.
thrust::fill_n(j.begin(), jp[1], 1);
for ( int k = 1; k < (jp.size() - 1); k++ ) {
    thrust::fill_n((j.begin() + jp[k] - 1), (jp[k + 1] - jp[k]), (k + 1));
    jp[k] = jp[k - 1] + thrust::count(i.begin(), i.end(), k);
}

// Typedefs for zip iterator.
typedef thrust::host_vector<double>::iterator DoubleIt;
typedef thrust::host_vector<int>::iterator IntIt;
typedef thrust::tuple<DoubleIt,IntIt> TupleIt;
typedef thrust::zip_iterator<TupleIt> ZipIt;

// Create the zip iterator
ZipIt zip_iterator(thrust::make_tuple(V.begin(),j.begin()));

// Reorder V, i and j such that V and j conform to the CSR layout.
thrust::stable_sort_by_key(i.begin(), i.end(), zip_iterator);

// Print V.
for ( int k = 0; k < V.size(); k++ ) { std::cout << "V[" << k << "] = " << V[k] << std::endl; }

// Print j.
for ( int k = 0; k < j.size(); k++ ) { std::cout << "j[" << k << "] = " << j[k] << std::endl; }

// Print ip.
for ( int k = 0; k < jp.size(); k++ ) { std::cout << "ip[" << k << "] = " << jp[k] << std::endl; }

}