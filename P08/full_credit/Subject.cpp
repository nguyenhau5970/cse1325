#include "Subject.h"

#include <iostream>
#include <fstream>
#include <string>

Subject::load_subject(std::istream& ist)
{
    std::getline(ist, name);
}

void Semester::outstream(std::ostream& ost)
{
    ost << name;
}