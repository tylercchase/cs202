#include <iostream>
#include "Student.hpp"
#include <vector>

//Pass by reference #4
void printAllGpa(std::vector<Student> &students){
    for(const Student &student: students){
        std::cout << student._gpa << std::endl;
    }
}
//Pass by value #3
void printAllAge(std::vector<Student> students){
    //Pass by const reference #5
    for(const Student &student: students){
        std::cout << student._age << std::endl;
    }
}
//Return by value #6
Student makeStudent(){
    return Student(19,4.0);
}

int main(){
    //Create local variable #1
    Student student = Student();
    //Create vector of 5 #7
    std::vector<Student> vecotrOfStudent(5,Student());
    //Create a copy #2
    auto studentCopy = student;
    auto studentMade = makeStudent();
    printAllGpa(vecotrOfStudent);
    printAllAge(vecotrOfStudent);
}