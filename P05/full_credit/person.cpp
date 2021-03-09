#include <ostream>
#include <stdio.h>
#include <person.h>


Person::Person(std::string name, std::string email)
{
    Name(name), Email(email);
}

virtual std::string full_info()
{
    return Name + " (" + Email + ") ";
}

std::string to_string()
{
    return name + " \n" + full_info();
}

std::ostream& operator<<(std::ostream& ost, const Person& person)
{
    ost << person.name;
    return ost;
}

