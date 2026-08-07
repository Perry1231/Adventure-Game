#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>


#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#include <chrono>
#endif
//This file is for saving game progress


void Saver(Character& hero, MyInventory& inv)
{

std::string path = "Saves.txt";
std::fstream fs;

fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);

if (!fs.is_open()) {
        std::cout << "Error: failed to open or create save file: " << path << std::endl;
        return; 
    }


std::cout << "\n\n\n---------Hero----------" << std::endl;
std::cout << "Your hero saved successfully!" << std::endl;

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


std::cout << "\n---------Inventory----------" << std::endl;
fs << inv.GetCount() << std::endl;
    fs << inv.GetCapacity() << std::endl;

    
    for (int i = 0; i < inv.GetCount(); ++i) {
        Item* item = inv.GetItem(i); 
        if (item) {
            fs << item->GetType() << " " << item->GetName() << std::endl;
        }
    }
    std::cout << "Inventory saved successfully!" << std::endl;
    std::cout << "\n---------Potion----------" << std::endl;
    for (int i = 0; i < inv.GetCount(); ++i) {
        Item* item = inv.GetItem(i);
        if (item && item->GetType() == "Potion") {
            fs << item->GetName() << std::endl;
        }
    }
    std::cout << "Potions saved successfully!" << std::endl;

    std::cout << "\n---------Weapon----------" << std::endl;
    Weapon* w = hero.GetEquippedWeapon();
    if (w) {
        fs << w->GetName() << " " << w->GetAttack() << " " << w->GetDurability() << std::endl;
    } else {
        fs << "None" << std::endl;
    }
    std::cout << "Weapons saved successfully!" << std::endl;

    std::cout << "\n---------Armory----------" << std::endl;
    Armory* a = hero.GetEquippedArmor();
    if (a) {
        fs << a->GetName() << " " << a->GetDefense() << " " << a->GetDurability() << std::endl;
    } else {
        fs << "None" << std::endl;
    }
    std::cout << "Armory saved successfully!" << std::endl;

    fs.close();
    std::cout << "\nGame saved successfully!" << std::endl;
}
    