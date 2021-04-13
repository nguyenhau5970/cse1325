#include "Semester.h"

#include <iostream>
#include <fstream>
#include <string>

Semester::load_semester(std::istream& ist)
{
    std::getline(ist, name);
}

void Semester::outstream(std::ostream& ost)
{
    ost << name;

}