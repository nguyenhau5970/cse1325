#ifndef __SEMESTER_H
#define __SEMESTER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

enum class semester {FALL,SPRING,SUMMER};
const std::vector<std::string> to_string {
    "fall", "spring", "summer"
};

class Semester
{
public:
    virtual void outstream(std::ostream& ost)
    friend ostream& operator<<(ostream& ost, const Semester& sem);
    load_semester(std::istream& ist); 
    std::string name;
};
#endif