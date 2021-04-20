#include "teacher.h" 


Teacher::Teacher(std::string name, std::string email)
    :   _name {name}, _email{email} { }

Teacher::Teacher(std::istream& ist) {
    std::getline(ist, _name);
    std::getline(ist, _email);
}

void Teacher::save(std::ostream& ost) {
    ost << _name << '\n' << _email << '\n';
}

std::string Person::full_info() const {
    return _name + " (" + _email + ")";
}
