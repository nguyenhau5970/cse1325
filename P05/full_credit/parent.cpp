#include<vector>
#include<iostream>
#include <stdexcept>
#include<parent.h>
#include<student.h>

using namespace std;

Parent::Parent(const std::string name, const std::string email)
{
    Name(name), Email(email);
}

void student::add_student(Student& student)
{
    students.push_back(Student(name,email));
}

int students()
{
    return "This parent has " + students::size + " students\n";
}

Student& student(int index)
{
    if(std::students::at(index)==empty)
    {
        throw std::out_of_range("No Student or student is out of range");
    }
    
    return std::students::at(index);
}


std::string full_info() override
{
    return "Name: " + Name + "\nemail: (" + Email + ") \nGrade: "; 
}
