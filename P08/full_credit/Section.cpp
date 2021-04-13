#include "Section.h"

#include <fstream>

Section::Section(std::istream ist){
    std::getline(ist, _course);
    std::getline(ist, _semester);
    std::getline(ist, _year);
}

void Course::save(std::ostream& ost) {
    ost << _course << "\n" << _semester << "\n" <<_year << "\n";
}

std::ostream& operator<<(std::ostream& ost, const Section& Section) {
    ost << section._course << " for " << section._semester << " " << section._year;
    return ost;
}
