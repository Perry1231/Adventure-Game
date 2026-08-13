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



void ListSaveFilesLoader() {
    std::cout << "\n=== Available saves ===\n";
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
    if (!found) {
        std::cout << "No saves found.\n";
    }
}

void Loader(Character& hero, MyInventory& inv) {
   
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    ListSaveFilesLoader();
    
    std::cout << "\nEnter save filename to load (without .txt, default Saves): ";
    std::string name;
    std::getline(std::cin, name);
    if (name.empty()) {
        name = "Saves";
    }
    std::string path = name + ".txt";
    
    std::ifstream fs(path);
    Fail_To_Open_File(fs);

    
    std::cout << "Loading from '" << path << "'...\n";
    std::string line;
    std::string currentSection;
    
    
    inv.Clear();
    
    while (std::getline(fs, line)) {
        
        if (line.empty()) continue;
        
        char first = line[0];
        if (first == '=' || first == '╔' || first == '╚' || first == '┌' || 
            first == '│' || first == '└' || first == '─' || first == '┐' || 
            first == '║') continue;
        
        
        if (line.find("[HERO]") != std::string::npos) {
            currentSection = "HERO";
            continue;
        }
        if (line.find("[INVENTORY]") != std::string::npos) {
            currentSection = "INVENTORY";
            continue;
        }
        if (line.find("[EQUIPMENT]") != std::string::npos) {
            currentSection = "EQUIPMENT";
            continue;
        }
        if (line.find("[WEAPON]") != std::string::npos) {
            currentSection = "WEAPON";
            continue;
        }
        if (line.find("[ARMOR]") != std::string::npos) {
            currentSection = "ARMOR";
            continue;
        }
        
        
        size_t colonPos = line.find(":");
        if (colonPos == std::string::npos) continue;
        
        std::string key = line.substr(0, colonPos);
        std::string value = line.substr(colonPos + 1);
        
        // Прибираємо пробіли
        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        
       
        if (currentSection == "HERO") {
            if (key == "Name") hero.SetName(value);
            else if (key == "Age") hero.SetAge(std::stoi(value));
            else if (key == "Race") hero.SetRace(value);
            else if (key == "Profession") hero.SetProfession(value);
            else if (key == "Level") hero.SetLevel(std::stoi(value));
            else if (key == "Description") hero.SetDescription(value);
            else if (key == "Health") hero.SetHealth(std::stoi(value));
            else if (key == "Strength") hero.SetStrength(std::stoi(value));
            else if (key == "Agility") hero.SetAgility(std::stoi(value));
            else if (key == "Intelligence") hero.SetIntelligence(std::stoi(value));
            else if (key == "Defense") hero.SetDefense(std::stoi(value));
            else if (key == "Gold") hero.SetGold(std::stoi(value));
        }
        
        else if (currentSection == "INVENTORY") {
            if (key == "Items count" || key == "InventorySize") {
                std::cout << " Inventory loaded: " << value << " items\n";
            }
            
        }
        
        else if (currentSection == "EQUIPMENT" || currentSection == "WEAPON") {
            if (key == "Weapon") {
                if (value != "None" && !value.empty()) {
                    std::cout << " Equipped weapon: " << value << "\n";
                    
                } else {
                    std::cout << " No weapon equipped\n";
                }
            }
        }
        else if (currentSection == "EQUIPMENT" || currentSection == "ARMOR") {
            if (key == "Armor") {
                if (value != "None" && !value.empty()) {
                    std::cout << " Equipped armor: " << value << "\n";
                    
                } else {
                    std::cout << " No armor equipped\n";
                }
            }
        }
    }
    
    fs.close();
    
    Fail_To_Close_File(fs);
    std::cout << "\nGame loaded successfully!\n";
    hero.DisplayStats();
}