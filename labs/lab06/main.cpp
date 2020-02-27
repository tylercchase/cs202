#include "names.hpp"
#include <iostream>

int cool_number = 19;

void foo(){
    std::cout << "Hey I was called from the global scope.\n" <<
    "My cool number is: " << cool_number << std::endl;
}

int main(){
    tyler::foo();
    foo();

    auto coolStudent = tyler::Student(1.4);
    std::cout << "The student's GPA is: " << coolStudent.gpa <<
    std::endl;
    return 0;
}