

class Student {
    public:
        int _age;
        float _gpa;
        Student(const Student &orig);
        Student();
        Student(int age, double gpa);
        ~Student();
};