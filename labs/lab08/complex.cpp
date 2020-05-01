#include "complex.hpp"

Complex Complex::operator+(const Complex complex){
    return Complex(_real + complex._real, _imaginary + complex._imaginary);
}

std::ostream& operator<<(std::ostream& os,const  Complex & complex){
    os << complex.real();
    os << " + i ";
    os << complex.imaginary();
    return os;
}
