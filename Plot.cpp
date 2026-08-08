#include "Header.h"
#include <iostream>
//For main events and plot

void StartGame(Enemy& enemy)
{
    std::cout << "\n\n" ;
    std::cout <<"\n=== START GAME ===\n\n\n" << std::endl;


    ChoiceHard(enemy);
    //Additional will be soon
    std::cout << "Welcome to the game! Your adventure begins now." << std::endl;

    //Continue
    //Plot cont
}


void Story()
{

}

void Turn(Character& hero)
{
    std::cout << "\n\n" ;
    std::cout <<"\n=== TURN ===\n\n\n" << std::endl;
    std::cout <<"----------------"<< std::endl;
    std::cout <<"Make turn - 1" << std::endl;
    std::cout <<"Look in inventory - 2" << std::endl;
    std::cout <<"Go to main menu - 3" << std::endl;
    std::cout <<"----------------"<< std::endl;

    std::cout << "Enter choice : " ;
    int choice = 0;
    std::cin >> choice;
    switch(choice)
    {
        case 1:
            std::cout << "You have chosen to make a turn." << std::endl;
            // Implement turn logic here
            break;
        case 2:
            std::cout << "You have chosen to look in your inventory." << std::endl;
            hero.GetInventory()->DisplayInventory(); {
            break;
        case 3:
            std::cout << "Returning to main menu." << std::endl;
            MainFunction(); 
            break;
        default:
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
            break;
    }
    //events % randomizer
    std::cout << "\n\n" ;
}
}

void TurnRandomizer()
{
   std::cout << "Make move"<< std::endl;
    
}