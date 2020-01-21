#include "Student.hpp"
#include <iostream>
using std::cout;

 Student::Student(const Student &orig)
{
    _age = orig._age;
    _gpa = orig._gpa;
}
Student::Student(){
    _age = 0;
    _gpa = 0;
}
Student::Student(int age, double gpa){
    _age = age;
    _gpa = gpa;
}
Student::~Student(){
    std::cout << "Deconstruct woo" << std::endl;
}