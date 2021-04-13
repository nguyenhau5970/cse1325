#include "Course.h"

#include <fstream>
#include <iostream>

Course::Course(std::istream ist){
    std::getline(ist,_subject);
    std::getline(ist,_grade;
}

void Course::save(std::ostream& ost) {
    ost << _subject << "\n" << _grade << "\n";
}

std::ostream& operator<<(std::ostream& ost, const Course& course) {
    ost << course._subject << " (grade " << course._grade << ")";
    return ost;
}
