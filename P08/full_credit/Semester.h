#ifndef __SEMESTER_H
#define __SEMESTER_H

#include <iostream>
#include <fstream>

enum class Semester {FALL,SPRING,SUMMER};

std::ostream& operator<<(std::ostream& ost, const Semester& semester);
Semester load_semester(std::istream& ist);

#endif
