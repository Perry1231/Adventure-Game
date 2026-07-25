#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
//This file is for saving game progress


void Saver(Character& hero, MyInventory& inv)
{

std::string path = "Saves.txt";
std::fstream fs;

fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);

if (!fs.is_open()) {
CreateDirectoryA("Saves.txt", NULL);     
}

fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);


std::cout << "\n\n\n---------Hero----------" << std::endl;
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


std::cout << "\n\n\n---------Inventory----------" << std::endl;
fs << inv.GetCount() << std::endl;
    fs << inv.GetCapacity() << std::endl;

    
    for (int i = 0; i < inv.GetCount(); ++i) {
        Item* item = inv.GetItem(i); 
        if (item) {
            fs << item->GetType() << " " << item->GetName() << std::endl;
        }
    }

    std::cout << "\n\n\n---------Weapon----------" << std::endl;
    Weapon* w = hero.GetEquippedWeapon();
    if (w) {
        fs << w->GetName() << " " << w->GetAttack() << " " << w->GetDurability() << std::endl;
    } else {
        fs << "None" << std::endl;
    }

    std::cout << "\n\n\n---------Armory----------" << std::endl;
    Armory* a = hero.GetEquippedArmor();
    if (a) {
        fs << a->GetName() << " " << a->GetDefense() << " " << a->GetDurability() << std::endl;
    } else {
        fs << "None" << std::endl;
    }
    fs.close();
    std::cout << "Game saved successfully!" << std::endl;
}
    