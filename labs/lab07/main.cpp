#include <iostream>
#include "Student.hpp"

std::ostream & operator<<(std::ostream & os, const Student &student){
    // std::cout << student._gpa;
    os << "Student stats\nGPA:" << student._gpa << "\nAge: " << student._age;
    return os;
}
int main(){
    const Student student;
    std::cout << student << std::endl;
    return 0;
}