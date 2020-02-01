#include <iostream>
#include "Student.hpp"
#include <vector>
#include <memory>
void printAllGpa(std::vector<Student> &students){
    for(const Student &student: students){
        std::cout << student._gpa << std::endl;
    }
}
void printAllAge(std::vector<Student> students){
    for(const Student &student: students){
        std::cout << student._age << std::endl;
    }
}
Student makeStudent(){
    return Student(19,4.0);
}

int main(){
    std::cout << "-----Create a raw pointer-----" << std::endl;
    Student *karl = new Student();

    std::cout << "-----Create a unique pointer-----" << std::endl;
    auto jim =  std::make_unique<Student>(1,4);
    
    std::cout << "-----Transfer a unique pointer-----" << std::endl;
    std::unique_ptr<Student> bob;
    bob = std::move(jim);
    
    std::cout << "-----Call a member function-----" << std::endl;
    std::cout << bob->getAge() <<std::endl;
    
    std::cout << "-----Make a shared pointer-----" << std::endl;
    auto viv = std::make_shared<Student>();
    
    std::cout << "-----Make a shared pointer pointing to same thing-----" << std::endl;

    for(int x=0;x< 5;x++){
        auto vivy = viv;
        std::cout << vivy->getAge() << std::endl;
    }

    std::cout << "-----Delete everything------" << std::endl;
    
    //karl is not destroyed unless deleted manually
    delete karl;
}