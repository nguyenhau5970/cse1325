#include "Section.h"

#include <fstream>

Section::Section(std::istream ist){
    std::getline(ist, _course);
    std::getline(ist, _semester);
    std::getline(ist, _year);
}

void Course::save(std::ostream& ost) {
    ost << _course << " for " << _semester << " " <<_year << "\n";
}
