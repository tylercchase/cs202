// names.h
#ifndef names_hpp
#define names_hpp

namespace tyler {
    void foo();
    class Student{
        public:
        float gpa;
        Student(){
            gpa = 2.4;
        }
        Student(float _gpa){
            gpa = _gpa;
        }
    };
}

#endif