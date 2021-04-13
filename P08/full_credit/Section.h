#ifndef __Section_H
#define __Section_H

#include <Course.h>
#include <Semester.h>
#include <iostream>

class Section{
    private:
        Course course;
        Semester semester;
        int year;
    public:
        Section(Course course, Semester semester, int year)
        Section(std::istream& ist);
        virtual void save(std::ostream& ost)
        friend ostream& operator<<(ostream& ost, const Section& section);

}

#endif