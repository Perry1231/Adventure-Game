#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
int main() 
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));             

    Character hero;
    hero.RandomizeStats();
    hero.DisplayStats();

    system("pause");
    return 0;
}