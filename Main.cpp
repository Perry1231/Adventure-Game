// головна програма, яка викликає всі функції та класи з інших файлів
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

    std::cin.sync_with_stdio(false);
    std::cin.ignore();
    std::cin.get();
    return 0;
}