#include "Header.h"
#include <iostream>
//For main events and plot

void StartGame(Enemy& enemy, Character& hero)
{
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                    START GAME                     │\n";
    std::cout << "└───────────────────────────────────────────────────┘\n";

    ChoiceHard(enemy);

    std::cout << "┌───────────────────────────────────────────────────┐\n";
    std::cout << "│ Welcome to the game! Your adventure begins now.   │\n";
    std::cout << "└───────────────────────────────────────────────────┘\n\n";

    Turn(hero);
}

void Turn(Character& hero)
{
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                       TURN                        │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│  1. Make turn                                     │\n";
    std::cout << "│  2. Look in inventory                             │\n";
    std::cout << "│  3. Go to main menu                               │\n";
    std::cout << "└───────────────────────────────────────────────────┘\n";

    std::cout << "Enter choice : ";
    int choice = 0;
    std::cin >> choice;

    switch(choice)
    {
        case 1:
            std::cout << "\nYou make a turn.\n";
            RandomizerEvent(hero); 
            break;
        case 2:
            std::cout << "\nYou have chosen to look in your inventory.\n";
            hero.GetInventory()->DisplayInventory();
            break;
        case 3:
            std::cout << "\nReturning to main menu.\n";
            MainFunction(); 
            break;
        default:
            std::cout << "\nInvalid choice. Please select a valid option.\n";
            break;
    }
    std::cout << "\n\n";
}