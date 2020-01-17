#include "Student.hpp"
#include <iostream>
using std::cout;

void Student::Student(const Student &original)
:_age(original._age),
_gpa(original._gpa)
{
    cout << "Copied thing!";
}