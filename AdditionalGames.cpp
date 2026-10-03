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
case 1:{
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
    case 2:
    HowToPlayRollDiceFunction();
    break;

    case 3: 
    return ;
    break;

    default : 
    std::cout << "You eneteed wrong choice. Enter again "<< std::endl;
}
}
while(choice != 3);

}



void MusicChallenge(Character& hero)
{
    std::cout << "You participate in a music challenge with the tavern patrons." << std::endl;
    
    std::cout << "Choose a music challenge:\n1. Singing Contest\n2. Instrumental Performance\n3. Dance Off\n";
    int musicChoice;
    std::cin >> musicChoice;
    switch (musicChoice) {
        case 1:
            std::cout << "You participate in a singing contest." << std::endl;
            if(hero.GetLevel() > 1.0 && hero.GetAgility() > 10) {
                std::cout << "You impress the crowd with your singing skills!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 15);
                std::cout << "\n[REWARD]: +15 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The crowd is not impressed with your singing." << std::endl;
            }
            break;
        case 2:
            std::cout << "You perform an instrumental piece." << std::endl;
            if(hero.GetLevel() > 1.0 && hero.GetIntelligence() > 10) {
                std::cout << "Your instrumental performance captivates the audience!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 20);
                std::cout << "\n[REWARD]: +20 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The audience is not impressed with your performance." << std::endl;
            }
            break;
        case 3:
            std::cout << "You engage in a dance-off." << std::endl;
            if(hero.GetLevel() > 1.0 && hero.GetAgility() > 10) {
                std::cout << "You impress the crowd with your dancing skills!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 25);
                std::cout << "\n[REWARD]: +25 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The crowd is not impressed with your dancing." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid choice. You leave the music challenge." << std::endl;
            break;
    }

}
void FistFight(Character& hero)
{
    std::cout << "You engage in a fist fight with the tavern patrons." << std::endl;
    std::cout << "Choose action:\n1. Play fist fight\n2. Leave the game\n";
    int actionChoice;
    std::cin >> actionChoice;
    if(actionChoice == 1) 
    {
    std::cout << "Choose an opponent:\n1. Weak Opponent\n2. Average Opponent\n3. Strong Opponent\n";
    int opponentChoice;

    switch(opponentChoice) {
        case 1:
            std::cout << "You fight a weak opponent." << std::endl;
            if(hero.GetStrength() > 10) {
                std::cout << "You easily defeat the weak opponent!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 10);
                std::cout << "\n[REWARD]: +10 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The weak opponent proves to be a challenge. You lose 5 health." << std::endl;
                hero.SetHealth(hero.GetHealth() - 5);
            }
            break;
        case 2:
            std::cout << "You fight an average opponent." << std::endl;
            if(hero.GetStrength() > 15) {
                std::cout << "You defeat the average opponent!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 15);
                std::cout << "\n[REWARD]: +15 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The average opponent proves to be a challenge. You lose 10 health." << std::endl;
                hero.SetHealth(hero.GetHealth() - 10);
            }
            break;
        case 3:
            std::cout << "You fight a strong opponent." << std::endl;
            if(hero.GetStrength() > 20) {
                std::cout << "You defeat the strong opponent!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 20);
                std::cout << "\n[REWARD]: +20 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The strong opponent proves to be a challenge. You lose 15 health." << std::endl;
                hero.SetHealth(hero.GetHealth() - 15);
            }
            break;
        default:
            std::cout << "Invalid choice. You leave the fist fight." << std::endl;
            break;
    }
}
else if (actionChoice == 2)
    {
        std::cout << "You leave the fist  fight." << std::endl;
        return;
    }
    else
    {
        std::cout << "Invalid choice. You leave the fist  fight." << std::endl;
        return;
    }
}

void DrinkingContest(Character& hero, GameHard& levelDificulty)
{
    std::cout << "You participate in a drinking contest with the tavern patrons." << std::endl;
    std::cout << "Choose action:\n1. Drink \n2. Leave the game\n";
    int actionChoice;
    std::cin >> actionChoice;
    if (actionChoice == 1) 
    {    
    
    std::cout << "Choose a drinking opponent:\n1. Light Drinker\n2. Average Drinker\n3. Heavy Drinker\n";
    int opponentChoice;
    switch(opponentChoice) 
    {
        case 1:
            std::cout << "You compete against a light drinker." << std::endl;
            if(hero.GetLevel() > 1.0 && hero.GetAgility() > 10) {
                std::cout << "You outdrink the light drinker!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 10);
                std::cout << "\n[REWARD]: +10 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The light drinker proves to be a challenge. You lose 5 health." << std::endl;
                hero.SetHealth(hero.GetHealth() - 2 * levelDificulty.GetDifficultyLevel());
            }
            break;
        case 2:
            std::cout << "You compete against an average drinker." << std::endl;
            if(hero.GetLevel() > 1.0 && hero.GetAgility() > 10) {
                std::cout << "You outdrink the average drinker!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 15);
                std::cout << "\n[REWARD]: +15 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The average drinker proves to be a challenge. You lose 10 health." << std::endl;
                hero.SetHealth(hero.GetHealth() - 5 * levelDificulty.GetDifficultyLevel());
            }
            break;
        case 3:
            std::cout << "You compete against a heavy drinker." << std::endl;
            if(hero.GetLevel() > 1.0 && hero.GetAgility() > 10) {
                std::cout << "You outdrink the heavy drinker!" << std::endl;
                hero.SetLevel(hero.GetLevel() + 0.05);
                hero.SetGold(hero.GetGold() + 20);
                std::cout << "\n[REWARD]: +20 Gold (Total: " << hero.GetGold() << ")" << std::endl;
            } else {
                std::cout << "The heavy drinker proves to be a challenge. You lose 15 health." << std::endl;
                hero.SetHealth(hero.GetHealth() - 6 * levelDificulty.GetDifficultyLevel());
            }
            break;
        default:
            std::cout << "Invalid choice. You leave the drinking contest." << std::endl;
            break;

            }
        }
    else if (actionChoice == 2)
    {
        std::cout << "You leave the drinking contest." << std::endl;
        return;
    }
    else
    {
        std::cout << "Invalid choice. You leave the drinking contest." << std::endl;
        return;
    }
}







  void  HowToPlayRollDiceFunction()
{
std::cout << "\n\n===How to play RollDice game=== \n" ;
std::cout << "You throw 2 times dice "
<< "And if you hit second time more then first time or equal"
<< "You win 10 coins" << std::endl;
}


void CardDraw()             //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    std::cout << "You play a card draw game with the tavern patrons." << std::endl;
    std::cout << "Choose action:\n1. Draw a card\n2. Leave the game\n";
    int actionChoice;
    std::cin >> actionChoice;


    int randomCardWeight = rand() % 13 + 1;
    if(actionChoice == 1 )
    {
      std::cout << "You draw a card from the deck." << std::endl;
      std::cout << "The card you drew is a " << randomCardWeight << "." << std::endl;
    }

    else if (actionChoice == 2)
    {
        std::cout << "You leave the card draw game." << std::endl;
        return;
    }
    else
    {
        std::cout << "Invalid choice. You leave the card draw game." << std::endl;
        return;
    }
}
