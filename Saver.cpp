#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#include <chrono>
#endif
//This file is for saving game progress

inline void ListSaveFiles() {
    std::cout << "\n=== Existing saves ===\n";
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA("*.txt", &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        std::cout << "No saves found.\n";
        return;
    }
    bool found = false;
    int count = 0;
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::cout << " " << (++count) << ". " << findFileData.cFileName << "\n";
            found = true;
        }
    } while (FindNextFileA(hFind, &findFileData) != 0);
    FindClose(hFind);
    if (!found) std::cout << "No saves found.\n";
}

void Saver(Character& hero, MyInventory& inv) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    ListSaveFiles();
    
    std::cout << "\nEnter save filename (without .txt, default Saves): ";
    std::string name;
    std::getline(std::cin, name);
    
    if (name.empty()) {
        name = "Saves";
    }
    
    std::string path = name + ".txt";
    std::ofstream fs(path);
    
    Fail_To_Open_File(fs);//Checker

    std::cout << "\nSaving to '" << path << "'...\n";
    
    fs << "╔══════════════════════════════════════════════════════════════╗\n";
    fs << "║ GAME SAVE FILE ║\n";
    fs << "╚══════════════════════════════════════════════════════════════╝\n\n";
    
    fs << "┌──────────────────────────────────────────────────────────────┐\n";
    fs << "│ HERO │\n";
    fs << "└──────────────────────────────────────────────────────────────┘\n";
    fs << " Name        : " << std::left << std::setw(25) << hero.GetName() << "\n";
    fs << " Age         : " << std::left << std::setw(25) << hero.GetAge() << "\n";
    fs << " Race        : " << std::left << std::setw(25) << hero.GetRace() << "\n";
    fs << " Profession  : " << std::left << std::setw(25) << hero.GetProfession() << "\n";
    fs << " Level       : " << std::left << std::setw(25) << hero.GetLevel() << "\n";
    fs << " Description : " << hero.GetDescription() << "\n";
    fs << " ─────────────────────────────────────────────────────────────\n";
    fs << " Health      : " << std::left << std::setw(25) << hero.GetHealth() << "\n";
    fs << " Strength    : " << std::left << std::setw(25) << hero.GetStrength() << "\n";
    fs << " Agility     : " << std::left << std::setw(25) << hero.GetAgility() << "\n";
    fs << " Intelligence: " << std::left << std::setw(25) << hero.GetIntelligence() << "\n";
    fs << " Defense     : " << std::left << std::setw(25) << hero.GetDefense() << "\n";
    fs << " Gold        : " << std::left << std::setw(25) << hero.GetGold() << "\n\n";
    
    fs << "┌──────────────────────────────────────────────────────────────┐\n";
    fs << "│ INVENTORY (" << std::setw(3) << inv.GetCount() << " items) │\n";
    fs << "└──────────────────────────────────────────────────────────────┘\n";
    
    if (inv.GetCount() == 0) {
        fs << " (empty)\n";
    } else {
        for (int i = 0; i < inv.GetCount(); ++i) {
            Item* item = inv.GetItem(i);
            if (!item) continue;
            
            fs << " [" << std::setw(2) << (i + 1) << "] " << item->GetName() << "\n";
            fs << "      Type : " << item->GetType() << "\n";
            fs << "      ID   : " << item->GetItemId() << "\n";
            
            if (item->GetType() == "Weapon") {
                Weapon* w = dynamic_cast<Weapon*>(item);
                if (w) {
                    fs << "      Attack   : " << w->GetAttack() << "\n";
                    fs << "      Durability: " << w->GetDurability() << "\n";
                    fs << "      Value    : " << w->GetValue() << " gold\n";
                }
            } else if (item->GetType() == "Armor") {
                Armory* a = dynamic_cast<Armory*>(item);
                if (a) {
                    fs << "      Defense  : " << a->GetDefense() << "\n";
                    fs << "      Durability: " << a->GetDurability() << "\n";
                    fs << "      Value    : " << a->GetValue() << " gold\n";
                }
            } else if (item->GetType() == "Potion") {
                Potion* p = dynamic_cast<Potion*>(item);
                if (p) {
                    fs << "      Effect   : ";
                    switch(p->GetEffectType()) {
                        case 0: fs << "Health"; break;
                        case 1: fs << "Defense"; break;
                        case 2: fs << "Agility"; break;
                        case 3: fs << "Intelligence"; break;
                        case 4: fs << "Gold"; break;
                        case 5: fs << "Strength"; break;
                        default: fs << "Unknown";
                    }
                    fs << "\n      Potency  : " << p->GetPotency() << "\n";
                    fs << "      Value    : " << p->GetValue() << " gold\n";
                }
            }
            fs << "\n";
        }
    }
    
    fs << "┌──────────────────────────────────────────────────────────────┐\n";
    fs << "│ EQUIPPED GEAR │\n";
    fs << "└──────────────────────────────────────────────────────────────┘\n";
    
    Weapon* w = hero.GetEquippedWeapon();
    Armory* a = hero.GetEquippedArmor();
    
    fs << " Weapon : ";
    if (w) {
        fs << w->GetName() << " (ATK: " << w->GetAttack() << ", DUR: " << w->GetDurability() << ")\n";
    } else {
        fs << "None\n";
    }
    
    fs << " Armor  : ";
    if (a) {
        fs << a->GetName() << " (DEF: " << a->GetDefense() << ", DUR: " << a->GetDurability() << ")\n";
    } else {
        fs << "None\n";
    }
    
    fs << "\n╔══════════════════════════════════════════════════════════════╗\n";
    fs << "║ END OF SAVE ║\n";
    fs << "╚══════════════════════════════════════════════════════════════╝\n";
    
    fs.close();
    std::cout << "\nGame saved successfully to '" << path << "'!\n";

    All_Error_Detector_Check(fs);//Check for errors
}
