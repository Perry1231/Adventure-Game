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

    std::cout << "Enter save filename (e.g. MySave): ";
    std::string name;
    std::getline(std::cin, name);

    if (name.empty()) name = "Saves";

    std::string path = name + ".txt";

    std::ofstream fs(path);
    if (!fs.is_open()) {
        std::cout << "Error: failed to open/create save file!\n";
        return;
std::string path = "Saves.txt";
std::fstream fs;

fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);

if (!fs.is_open()) {
        std::cout << "Error: failed to open or create save file: " << path << std::endl;
        return; 
    }

    
time_t now = time(0);
    fs << "========================================\n";
    fs << "           GAME SAVE FILE              \n";
    fs << "========================================\n";
    fs << "Saved at: " << ctime(&now);
    fs << "========================================\n\n";
    fs << "save name: " << name << "\n";
    fs << "========================================\n\n";

 fs << "[HERO]\n";
 fs << "Name: " << hero.GetName() << "\n";
    fs << "Age: " << hero.GetAge() << "\n";
    fs << "Race: " << hero.GetRace() << "\n";
    fs << "Profession: " << hero.GetProfession() << "\n";
    fs << "Level: " << hero.GetLevel() << "\n";
    fs << "Description: " << hero.GetDescription() << "\n";
    fs << "Health: " << hero.GetHealth() << "\n";
    fs << "Strength: " << hero.GetStrength() << "\n";
    fs << "Agility: " << hero.GetAgility() << "\n";
    fs << "Intelligence: " << hero.GetIntelligence() << "\n";
    fs << "Defense: " << hero.GetDefense() << "\n";
    fs << "Gold: " << hero.GetGold() << "\n\n";

    // === ІНВЕНТАР ===
    fs << "[INVENTORY]\n";
    fs << "Items count: " << inv.GetCount() << "\n";
    fs << "Capacity: " << inv.GetCapacity() << "\n";
    fs << "----------------------------------------\n";
    
    for (int i = 0; i < inv.GetCount(); ++i) {
        Item* item = inv.GetItem(i);
        if (!item) continue;
        
        fs << "Item #" << (i + 1) << ":\n";
        fs << "  ID: " << item->GetItemId() << "\n";
        fs << "  Type: " << item->GetType() << "\n";
        fs << "  Name: " << item->GetName() << "\n";
        
        // Додаткові властивості залежно від типу
        if (item->GetType() == "Weapon") {
            Weapon* w = dynamic_cast<Weapon*>(item);
            if (w) {
                fs << "  Attack: " << w->GetAttack() << "\n";
                fs << "  Durability: " << w->GetDurability() << "\n";
                fs << "  Value: " << w->GetValue() << "\n";
            }
        }
        else if (item->GetType() == "Armor") {
            Armory* a = dynamic_cast<Armory*>(item);
            if (a) {
                fs << "  Defense: " << a->GetDefense() << "\n";
                fs << "  Durability: " << a->GetDurability() << "\n";
                fs << "  Value: " << a->GetValue() << "\n";
            }
        }
        else if (item->GetType() == "Potion") {
            Potion* p = dynamic_cast<Potion*>(item);
            if (p) {
                fs << "  Effect: " << p->GetEffectType() << "\n";
                fs << "  Potency: " << p->GetPotency() << "\n";
                fs << "  Value: " << p->GetValue() << "\n";
            }
        }
        fs << "----------------------------------------\n";
    }
    fs << "\n";




    fs << "[EQUIPMENT]\n";
    
    Weapon* w = hero.GetEquippedWeapon();
    if (w) {
        fs << "Weapon: " << w->GetName() << "\n";
        fs << "  Attack: " << w->GetAttack() << "\n";
        fs << "  Durability: " << w->GetDurability() << "\n";
        fs << "  Value: " << w->GetValue() << "\n";
    } else {
        fs << "Weapon: None\n";
    }
    
    Armory* a = hero.GetEquippedArmor();
    if (a) {
        fs << "Armor: " << a->GetName() << "\n";
        fs << "  Defense: " << a->GetDefense() << "\n";
        fs << "  Durability: " << a->GetDurability() << "\n";
        fs << "  Value: " << a->GetValue() << "\n";
    } else {
        fs << "Armor: None\n";
    }

    fs << "\n========================================\n";
    fs << "           END OF SAVE FILE            \n";
    fs << "========================================\n";


    //Add here potential saving data for enemies, quests, and other game states as needed.
    fs.close();
    std::cout << "Game saved successfully to Saves.txt!\n";
}
}