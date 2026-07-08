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

void GetInfo()
{
        std::cout << "\n=== INFO ===" << std::endl;
        std::cout << "This is a simple adventure game written in C++." << std::endl;
        std::cout << "You can explore the world, fight enemies, and collect items." << std::endl;
        std::cout << "Use the main menu to navigate through the game." << std::endl;
        std::cout << "Have fun and enjoy your adventure!" << std::endl;
        std::cout << "PS. This program is written by Vladyslav Vytrykush." << std::endl;
}


void Help()
{
            std::cout << "\n=== HELP ===" << std::endl;
            std::cout << "1. Show character stats - Displays current character statistics" << std::endl;
            std::cout << "2. Show your inventory - Lists all items in your inventory" << std::endl;
            std::cout << "3. Manage your Inventory - Access inventory management functions" << std::endl;
            std::cout << "4. Get info - Display help information" << std::endl;
            std::cout << "5. Help - Shows this help menu" << std::endl;
            std::cout << "0. Exit - Quit the program" << std::endl;
}