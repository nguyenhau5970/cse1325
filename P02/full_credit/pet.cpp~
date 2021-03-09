 #include "pet.h"
 #include <vector>
 #include <iostream>

std::string Pet::to_string()
{
    return std::to_string(name) + " is a " 
           + ::to_string(animal) + " age " 
           + std::to_string(age);
}

std::string to_string(Animal animal)
{
    std::vector<std::string>v = {"Dog", "Cat", "Penguin", "Elephant"};
    
    return v[animal];
}
