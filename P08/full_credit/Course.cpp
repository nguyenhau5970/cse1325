#include "Course.h"

#include <fstream>

Course::Course(std::istream ist){
    std::getline(ist,_subject);
}

void Course::save(std::ostream& ost) {
    ost << _subject << ", (" << _grade << ")";
}
