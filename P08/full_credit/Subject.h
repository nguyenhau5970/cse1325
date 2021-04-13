#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

enum class subject {READING,WRITING,MATH,SCIENCE,HISTORY};
const std::vector<std::string> to_string {
    "reading", "wring", "math", "science", "history"
};

class Subject
{
public:
    virtual void outstream(std::ostream& ost)
    friend ostream& operator<<(ostream& ost, const Subject& sbj);
    load_subject(std::istream& ist);
    std::string name;
};

#endif 