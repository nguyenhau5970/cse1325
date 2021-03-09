#include<vector>
#include<iostream>
#include <stdexcept>
#include<parent.h>
#include<student.h>

using namespace std;

Student::Student(const std::string name, const std::string email, const int grade)
{
    Name(name), Email(email), Grade(grade);
}

void student::add_parent(Parent& parent)
{
    parents.push_back(Parent(name,email));
}

int parents()
{
    return "This student has " + parents::size + " parents\n";
}

Parent& parent(int index)
{
    if(std::parents::at(index)==empty)
    {
        throw std::out_of_range("No Parent or Parent out of range");
    }
    
    return std::parents::at(index);
}


std::string full_info() override
{
    return "Name: " + Name + "\nemail: (" + Email + ") \nGrade: " + Grade + "\nParents: " + parent(0) + " " + parent(1);
}
