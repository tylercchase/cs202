#include "complex.hpp"

Complex Complex::operator+(const Complex complex){
    return Complex(_real + complex._real, _imaginary + complex._imaginary);
}
Complex& Complex::operator+=(const Complex complex){
    _real += complex._real;
    _imaginary += complex._imaginary;
    return *this;
}

std::ostream& operator<<(std::ostream& os,const  Complex & complex){
    os << complex.real();
    os << " + i ";
    os << complex.imaginary();
    return os;
}
