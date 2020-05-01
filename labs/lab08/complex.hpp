
#include <iostream>
class Complex{
    public:
        double real() const { return _real; };
        double imaginary() const { return _imaginary; };
        Complex() {};
        Complex(double real, double imaginary=0):_real{real},_imaginary{imaginary}{

        };
        Complex operator+(const Complex complex);
        Complex& operator+=(const Complex complex);
    private:
        double _real{0};
        double _imaginary{0};
};
inline Complex operator+(double left, const Complex right){
    return Complex(left + right.real(), right.imaginary());
}
std::ostream& operator<<(std::ostream& os,const Complex& complex);

