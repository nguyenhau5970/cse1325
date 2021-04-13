#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

enum class Subject {READING,WRITING,MATH,SCIENCE,HISTORY};
const std::vector<std::string> to_string {
    "reading", "wring", "math", "science", "history"
};

std::ostream& operator<<(std::ostream& ost, const Subject& subject);
Subject load_subject(std::istream& ist);

#endif 
