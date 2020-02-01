#include "Student.hpp"
#include <iostream>
using std::cout;

 Student::Student(const Student &orig)
{
    _age = orig._age;
    _gpa = orig._gpa;
    std::cout << "Make a copy" << std::endl;
}
Student::Student(){
    _age = 0;
    _gpa = 0;
    std::cout << "Construct with default params" << std::endl;
}
Student::Student(int age, double gpa){
    _age = age;
    _gpa = gpa;
    std::cout << "Construct with parameter" << std::endl;
}
Student::~Student(){
    std::cout << "Deconstruct woo" << std::endl;
}
int Student::getAge(){
    return _age;
}