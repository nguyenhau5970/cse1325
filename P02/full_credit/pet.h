#ifndef __PET_H
#define __PET_H
#include <iostream>

enum Animal {DOG, CAT, PEN, ELE};
std::string to_string(Animal ani);

class Pet 
{
    std::string _name;
    double _age;
    Animal _ani;
  public:
    Pet(std::string n, Animal ani, double a);
    std::string to_string();
};

#endif 
