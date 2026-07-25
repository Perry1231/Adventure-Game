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
fs << hero.GetAge() << std:: endl;
fs << hero.GetRace() << std::endl;
fs << hero.GetProfession() << std::endl;
fs << hero.GetLevel() << std::endl;
fs << hero.GetDescription() << std::endl;

fs << hero.GetDescription() << std::endl;
fs << hero.GetHealth() << std::endl;
fs << hero.GetStrength() << std::endl;
fs << hero.GetAgility() << std::endl;
fs << hero.GetIntelligence() << std::endl;
fs << hero.GetDefense() << std::endl;
fs << hero.GetDescription() << std::endl;
fs << hero.GetGold() << std::endl;


fs << inv.GetCount() << std::endl;
fs << inv.GetCapacity() << std::endl;


for(int i=0; i<)



 Item** items;
 int capacity;                  //Capacity of inventory given
 int count;                     //How many items now
 int id;
 Character* owner;
    fs.close();
    std::cout << "Game saved successfully!" << std::endl;
}