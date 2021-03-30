#ifndef __STUDENT_H
#define __STUDENT_H

#include "person.h"
#include <vector>
#include <iostream>
#include <fstream>

class Parent;

class Student : public Person {
  public:
    Student(std::string name, std::string email, int grade);
    void add_parent(Parent& parent);
    int parents();
    Parent& parent(int index);
    std::string full_info() const override;

    void save(std::ostream& ost);
    Student(std::istream& ist); 
  protected:
    int _grade;
    std::vector<Parent*> _parents;
};

#endif
