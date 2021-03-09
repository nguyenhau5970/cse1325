#ifndef __STUDENT_H
#define __STUDENT_H
#include <ostream>
#include <vector>

class Parent;

class Student
{
protected:
    int grade;
    std::vector<Parent*> parents;
public:
    Student(std::string name, std::string email, int grade)
    void add_parent(Parent& parent);
    int parents();
    Parent& parent(int index);
    std::string full_info() override;

};

#endif
