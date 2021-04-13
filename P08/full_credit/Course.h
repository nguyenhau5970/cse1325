#ifndef __COURSE_H
#define __COURSE_H

#include <Subject.h>
#include <iostream>

class Course{
    private:
        int grade;
        Subject subject;
    public:
        Course(Subject subject, int grade);
        Course(std::istream& ist);
        virtual void save(std::ostream& ost)
        friend ostream& operator<<(ostream& ost, const Course& course);

}

#endif