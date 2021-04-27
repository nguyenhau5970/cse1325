#ifndef __TEACHER_H
#define __TEACHER_H

#include <iostream>

class Teacher {
  public:
    Teacher(std::string name, std::string email);
    Teacher(std::istream& ist);
    virtual void save(std::ostream& ost);
    std::string full_info() const override;
  protected:
    std::string _name;
    std::string _email;
};

#endif
