#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
//This file is for saving game progress

void Saver(Character& hero, MyInventory& inv)
{
CreateDirectoryA("Saves", NULL);
std::string path = "Saves.txt";
std::fstream fs;

fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);

if (!fs.is_open()) {
        std::cout << "Failed to save game!" << std::endl;
        return;
    }


fs << hero.GetName() << std::endl;
fs << hero.GetProfession() << std::endl;
fs << hero.GetHealthValue() << std::endl;
fs << hero.GetGold() << std::endl;
fs << hero.GetIntelligence() << std::endl;
fs << hero.GetEquippedArmor() << hero.GetEquippedWeapon() << std::endl;


    fs.close();
    std::cout << "Game saved successfully!" << std::endl;
}