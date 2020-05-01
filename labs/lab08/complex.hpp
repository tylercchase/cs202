
#include <iostream>
class Complex{
    public:
        double real() const { return _real; };
        double imaginary() const { return _imaginary; };
        Complex() {};
        Complex(double real, double imaginary=0):_real{real},_imaginary{imaginary}{

        };
    private:
        double _real{0};
        double _imaginary{0};
};
std::ostream& operator<<(std::ostream& os,const Complex& complex);

