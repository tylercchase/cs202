#include "complex.hpp"


std::ostream& operator<<(std::ostream& os,const  Complex & complex){
    os << complex.real();
    os << " + i ";
    os << complex.imaginary();
    return os;
}
