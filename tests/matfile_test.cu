#include "../include/CMaT.h"

int main (  ) {

// Provide file location and variable name.
std::string name = "abcd.mat";
std::string path = "./tests/MAT_FILES";

// Open the MAT file.
matfile_load mat_file(path,name);

CPU_Dense c_c(mat_file,"c");
GPU_Dense c_g(mat_file,"c");

CPU_Dense_f d_c(mat_file,"d");
GPU_Dense_f d_g(mat_file,"d");

// Print the values.
std::cout << c_c.Values[0] << std::endl;
std::cout << c_c.Values[1] << std::endl;
std::cout << c_c.Values[2] << std::endl;
std::cout << c_c.Values[3] << std::endl;
std::cout << c_g.Values[0] << std::endl;
std::cout << c_g.Values[1] << std::endl;
std::cout << c_g.Values[2] << std::endl;
std::cout << c_g.Values[3] << std::endl;
std::cout << d_c.Values[0] << std::endl;
std::cout << d_c.Values[1] << std::endl;
std::cout << d_c.Values[2] << std::endl;
std::cout << d_c.Values[3] << std::endl;
std::cout << d_g.Values[0] << std::endl;
std::cout << d_g.Values[1] << std::endl;
std::cout << d_g.Values[2] << std::endl;
std::cout << d_g.Values[3] << std::endl;

CPU_Sparse a_c(mat_file,"a");

std::cout << "V: " << a_c.Values[0] << std::endl;
std::cout << "V: " << a_c.Values[1] << std::endl;
std::cout << "V: " << a_c.Values[2] << std::endl;
std::cout << "V: " << a_c.Values[3] << std::endl;
std::cout << "V: " << a_c.Values[4] << std::endl;
std::cout << "V: " << a_c.Values[5] << std::endl;

std::cout << "Ib: " << a_c.Ib[0] << std::endl;
std::cout << "Ib: " << a_c.Ib[1] << std::endl;
std::cout << "Ie: " << a_c.Ie[0] << std::endl;
std::cout << "Ie: " << a_c.Ie[1] << std::endl;

std::cout << "J: " << a_c.J[0] << std::endl;
std::cout << "J: " << a_c.J[1] << std::endl;
std::cout << "J: " << a_c.J[2] << std::endl;
std::cout << "J: " << a_c.J[3] << std::endl;
std::cout << "J: " << a_c.J[4] << std::endl;
std::cout << "J: " << a_c.J[5] << std::endl;

}