#include <iostream>
#include "Header.h"


void Chest::ChestCreate(ChestType type) {
    this->chestType = type;
    this->isOpen = false;
    this->capacity =0;
    items.clear();                                    
    RandomizeChest(type);
}
 


void Chest::RandomizeChest(ChestType type)
{
        int proc = rand() % 100 + 1;     
        if(proc <= 52)
        {
            capacity = rand() % 4 + 1; // Random capacity between 1 and 4
            this->chestType = COMMON;
            this->isOpen = false;
            this->capacity =capacity;
        }   
        else if (proc >52 && proc <=80)
        {
            this->chestType = RARE;
            this->isOpen = false;
            this->capacity =capacity;
            capacity = rand() % 6 + 1; 
        }
        else if (proc > 80 && proc <= 95)
        {
            this->chestType = EPIC;
            this->isOpen = false;
            this->capacity =capacity;
            capacity = rand() % 8 + 2;
        }
        else 
        {
            this->chestType = LEGENDARY;
            this->isOpen = false;
            this->capacity =capacity;
            capacity = rand() % 10 + 3;
        }
}



void Chest::Open(Character* target) {
    int action;
    if (!isOpen) {
        isOpen = true;
        std::cout << "Chest opened!" << std::endl;
        ShowItems();
        std::cout << "Select actions what to do next : " << std::endl;
        std::cout << "1. Take item" << std::endl;
        std::cout << "2. Take all" << std::endl;
        std::cout << "3. Close chest" << std::endl;
        std::cin >> action;
        switch(action) {
            case 1: 
                target->SetCurrentChest(this); target->Take(); break;
                target->Take(); 
                break;
            case 2: 
                target->SetCurrentChest(this); target->TakeAll(); break;
                target->TakeAll(); 
                break;
            case 3: 
                Close(); 
                break;
            default: 
                std::cout << "Bad Choice" << std::endl;
        }
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

bool Chest::IsOpen() const {
    return isOpen && capacity > 0;
}

void Chest::ShowInfo(ChestType type) const {
    std::cout << "Chest Type: ";
    switch (chestType) {
        case COMMON: std::cout << "Common"; break;
        case RARE: std::cout << "Rare"; break;
        case EPIC: std::cout << "Epic"; break;
        case LEGENDARY: std::cout << "Legendary"; break;
    }
    std::cout << "\nCapacity: " << capacity << "\nIs Open: " << (isOpen ? "Yes" : "No") << std::endl;
}



void Chest::ShowItems()
{
for(int i =0; i < items.size(); i++)
{
    std::cout << i+1 << ". ";
    items[i]->ShowInfo();
}
std::cout << std::endl;
}



void Chest::RemoveItem(int index) {
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
    }
}
