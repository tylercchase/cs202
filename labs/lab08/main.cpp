#include <iostream>
#include "complex.hpp"

int main(){
    std::cout << Complex(2,3) << std::endl;

    std::cout << Complex(4,5) + Complex(1,3) << std::endl;
    std::cout << 1.0 + Complex(1,3) << std::endl;
    std::cout << Complex(1,3) + 1  << std::endl;

    Complex number1(5,4);
    Complex number2(5,6);
    std::cout << number1 << std::endl;
    std::cout << number2 << std::endl;
    number1 += number2;
    std::cout << number1 << std::endl;
}