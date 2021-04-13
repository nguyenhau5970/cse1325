#include "Semester.h"

#include <iostream>
#include <fstream>
#include <string>

std::ostream& operator<<(std::ostream& ost, const Semester& semester) {
    ost << ((semester == Semester::FALL) ? "fall" : (semester == Semester::SPRING) ? "spring" : (semester == Semester::SUMMER) ? "summer");
    return ost;
}

Semester load_semester(std::istream& ist) {
    std::string name;
    std::getline(ist, name);

    if(name == "Fall ")
        return Semester::FALL;

    if(name == "Spring ") 
        return Semester::SPRING;

    if(name == "Summer ") 
        return Semester::SUMMER;
}
