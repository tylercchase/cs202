#include <iostream>
#include "complex.hpp"

int main(){
    std::cout << Complex(2,3) << std::endl;

    std::cout << Complex(4,5) + Complex(1,3) << std::endl;
    std::cout << 1.0 + Complex(1,3) << std::endl;
    std::cout << Complex(1,3) + 1  << std::endl;
}