#include "Header.h"
#include <iostream>
//This file for tavern games

void DiceRoll(Character& hero)
{

int choice;
do{
std::cout << "Choose option "<<
             "1 - Play game" <<
             "2 - How to play" <<
             "3 - Quit" << std::endl; 
             std::cout <<"Your choice :" ;
             std::cin>> choice;
switch(choice)
{
case '1':{
    std::cout << "You sat near strangers to play DiceRoll game " << std::endl;
    std::cout << "You roll the die" << std::endl;
    int roll1 = rand() % 10 + 1; // Roll a ten-sided die 
    std::cout << "You rolled a " << roll1 << "!" << std::endl;

    std::cout << "Now roll again" << std::endl;
    std::cout << "You roll the die" << std::endl;
    int roll2 = rand() % 10 + 1; // Roll a ten-sided die 
    std::cout << "You rolled a " << roll2 << "!" << std::endl;

    if(roll1 <= roll2) hero.SetGold(hero.GetGold() + 10);
    break;
}
    case '2':
    HowToPlayRollDiceFunction();
    break;

    case '3': 
    return ;
    break;

    default : 
    std::cout << "You eneteed wrong choice. Enter again "<< std::endl;
}
}
while(choice != 2);

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




  void  HowToPlayRollDiceFunction()
{
std::cout << "\n\n===How to play RollDice game=== \n" ;
std::cout << "You throw 2 times dice "
<< "And if you hit second time more then first time or equal"
<< "You win 10 coins" << std::endl;
}
