#ifndef __PARENT_H
#define __PARENT_H
#include <ostream>
#include <vector>
class Student;

class Parent
{
protected:
    std::vector<Student*> students;
public:
    Parent(std::string name, std::string email);
    void add_student(Student& student);
    int students();
    Student& student(int index);
    std::string full_info() override;
};

#endif
