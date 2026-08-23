#include "Header.h"
#include <iostream>
#include <string>
//For all saves functions like save game , load game, delete save

void ManageGameSaves(Character& hero, MyInventory& inv1)
{
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                 MANAGE GAME SAVES                 │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│  1. Save Game                                     │\n";
    std::cout << "│  2. Load Game                                     │\n";
    std::cout << "│  3. Delete Game                                   │\n";
    std::cout << "└───────────────────────────────────────────────────┘\n";
    
    int choice = 0;
    std::cout << "Enter choice: ";
    std::cin >> choice;

    switch(choice)
    {
        case 1:
            Saver(hero, inv1);
            break;
        case 2:
            Loader(hero, inv1);
            break;
        case 3:
            Deleter();
            break;
        default:
            std::cout << "\n[!] No such function. Invalid choice.\n";
            break;
    }
}