#include <iostream>

class test {
public:
void testfn ( float & type ) { type = 1.0; std::cout << "float: " << type << std::endl; }

void testfn ( double & type ) { type = 2.0; std::cout << "double: " << type << std::endl; }

};

int main () {

test TEST;

TEST.testfn(float type1);
TEST.testfn(double type2);

std::cout << type1 << std::endl;
std::cout << type2 << std::endl;

return 0;

}
