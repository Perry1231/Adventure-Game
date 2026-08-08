#include "Header.h"
#include <iostream>
//This file for tavern games

void DiceRoll()
{
    int roll = rand() % 10 + 1; // Roll a ten-sided die
    std::cout << "You rolled a " << roll << "!" << std::endl;
}

void BoardGame()
{
    std::cout << "You play a board game with the tavern patrons." << std::endl;
    // Implement board game logic here
}

void MusicChallenge()
{
    std::cout << "You participate in a music challenge with the tavern patrons." << std::endl;
    // Implement music challenge logic here
}
void FistFight()
{
    std::cout << "You engage in a fist fight with the tavern patrons." << std::endl;
    // Implement fist fight logic here
}

void DrinkingContest()
{
    std::cout << "You participate in a drinking contest with the tavern patrons." << std::endl;
    // Implement drinking contest logic here
}