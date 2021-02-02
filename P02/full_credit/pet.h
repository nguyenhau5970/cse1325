#ifndef __PET_H
#define __PET_H
#include <iostream>

enum Animal {DOG, CAT, PEN, ELE};
std::string to_string(Animal animal);

class Pet 
{
    std::string name;
    Animal animal;
    double age;
  public:
    Pet(std::string n, Animal ani, double a);
    std::string to_string();
};

#endif 
