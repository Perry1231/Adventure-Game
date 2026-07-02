//тут додаткова механіка до гри
#include "Header.h"

void HelpFunction() 
{
    std::cout << "This is a helper function that can be used for various purposes in the game." << std::endl;
    std::cout << "You can use this function to display help information and game instructions." << std::endl;
    std::cout << "This program shows how to structure a simple adventure game using C++." << std::endl;
    std::cout << "This program is written by Vladyslav Vytrykush to show the knowledge of C++ programming." << std::endl;
}



void ChoiceHard()
{
    int difil = 0;
    std::cout << "Choose difficulty level first" << std::endl;
    std::cout << "Be prepared for tougher enemies and more challenging puzzles." << std::endl;
    std::cout << "Good luck on your adventure!" << std::endl;
    std::cout << "Enter dificulty level : "  ;
    std::cin >> difil;
    if (difil == 1) {
        std::cout << "You have chosen the easy difficulty level!" << std::endl;
        std::cout << "Enemies will be weaker and puzzles will be simpler." << std::endl;
        std::cout << "Enjoy your adventure!" << std::endl;
    } else if (difil == 2) {
        std::cout << "You have chosen the medium difficulty level!" << std::endl;
        std::cout << "Enemies will be moderately challenging and puzzles will require some thought." << std::endl;
        std::cout << "Have fun on your adventure!" << std::endl;
    } else if (difil == 3) {
        std::cout << "You have chosen the hard difficulty level!" << std::endl;
        std::cout << "Enemies will be tough and puzzles will require careful planning." << std::endl;
        std::cout << "Good luck on your adventure!" << std::endl;
    } else {
        std::cout << "Invalid choice. Please select a valid difficulty level." << std::endl;
    }
              

    // Increase enemy health and damage
    // Decrease item drop rates
    // Add additional obstacles or enemies
}


void StartGame()
{
    ChoiceHard();
    //Additional will be soon
    std::cout << "Welcome to the game! Your adventure begins now." << std::endl;
}