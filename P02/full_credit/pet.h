#ifndef __PET_H
#define __PET_H
#include <iostream>
#include <vector>

enum Animal {DOG, CAT, PEN, ELE};
std::vector<std::string>to_string = {"Dog", "Cat", "Penguin", "Elephant"};

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
