#ifndef __PERSON_H
#define __PERSON_H
#include <ostream>

class Person
{
protected:
    std::string name;
    std::string email;
public:
    Person(std::string name, std::string email);
    std::string to_string();
    virtual std::string full_info();
    friend std::ostream& operator<<(std::ostream& ost, const Person& person);
};

#endif