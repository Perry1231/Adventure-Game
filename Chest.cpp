#include <iostream>
#include "Header.h"


void Chest::ChestCreate(ChestType type) {
    Chest chest;
    this->chestType = type;
    this->isOpen = false;
    this->capacity =0;
    items.clear();                                          // Clear any existing items in the chest
    chest.RandomizeChest(type);
}
 


void Chest::RandomizeChest(ChestType type)
{
                
    switch (type) {
        case COMMON:
            capacity = rand() % 4 + 1; // Random capacity between 1 and 4
            this->chestType = COMMON;
            this->isOpen = false;
            this->capacity =capacity;
            
            break;
        case RARE:
            this->chestType = RARE;
            this->isOpen = false;
            this->capacity =capacity;
            capacity = rand() % 6 + 1; 
            
            break;
        case EPIC:
            this->chestType = EPIC;
            this->isOpen = false;
            this->capacity =capacity;
            capacity = rand() % 8 + 2;
            
            break;
        case LEGENDARY:
            this->chestType = LEGENDARY;
            this->isOpen = false;
            this->capacity =capacity;
            capacity = rand() % 10 + 3;

            break;
    }
}



void Chest::Open(Character* target) {
    if (!isOpen) {
        isOpen = true;
        std::cout << "Chest opened!" << std::endl;
        // Here you can add logic to give items to the character
    } else {
        std::cout << "Chest is already open!" << std::endl;
    }
}


void Chest::Close() {
    if (isOpen) {
        isOpen = false;
        std::cout << "Chest closed!" << std::endl;
    } else {
        std::cout << "Chest is already closed!" << std::endl;
    }
}


void Chest::ShowInfo() const {
    std::cout << "Chest Type: ";
    switch (chestType) {
        case COMMON: std::cout << "Common"; break;
        case RARE: std::cout << "Rare"; break;
        case EPIC: std::cout << "Epic"; break;
        case LEGENDARY: std::cout << "Legendary"; break;
    }
    std::cout << "\nCapacity: " << capacity << "\nIs Open: " << (isOpen ? "Yes" : "No") << std::endl;
}