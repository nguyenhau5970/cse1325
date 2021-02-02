#include <iostream>
#include "pet.h"

int main() 
{
    Pet P(Pluto,DOG,10);
    Pet F(Felicia,CAT,7);
    Pet E(Eliza,PEN,12);
    Pet M(Marth,ELE,23);
    std::cout << P.to_string() << std::endl;
    std::cout << F.to_string() << std::endl;
    std::cout << E.to_string() << std::endl;
    std::cout << M.to_string() << std::endl;
}
