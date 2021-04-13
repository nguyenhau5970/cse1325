#include "Subject.h"

#include <iostream>
#include <fstream>
#include <string>

std::ostream& operator<<(std::ostream& ost, const Subject& subject) {
    ost << subject_to_string.at(subject);
    return ost;
}

Subject load_subject(std::istream& ist) {
    std::string name;
    std::getline(ist, name);
}
