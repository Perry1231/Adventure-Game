#include <iostream>
#include "Header.h"


void Chest::ChestCreate(ChestType type, Character& hero) {
    this->chestType = type;
    this->isOpen = false;
    this->capacity =0;
    items.clear();                                    
    RandomizeChest(hero);
}
 


void Chest::RandomizeChest(Character& hero)
{
        int proc = rand() % 100 + 1;     
        if(proc <= 52)
        {
            capacity = rand() % 4 + 1; // Random capacity between 1 and 4
            this->chestType = COMMON;
            this->isOpen = false;
            for(int i=0; i<capacity; i++)
            {
                int ite = rand() % 3 +1;
                if(ite == 1) 
                {
                Weapon* weapon_1 = new Weapon();
                weapon_1->RandomizeWeaponStart(hero.GetProfession());
                this->items.push_back(weapon_1);
                }
                else if(ite ==2)
                {
                Armory* armor_1 = new Armory();
                    armor_1->RandomizeArmorStart(); 
                    this->items.push_back(armor_1);
                }
                else
                {
                    Potion* potion = new Potion();
                    potion->RandomizePotion();
                    this->items.push_back(potion);
                }
                
            }
        }   
        else if (proc >52 && proc <=80)
        {
            this->chestType = RARE;
            this->isOpen = false;
            capacity = rand() % 6 + 1; 
            for(int i=0; i<capacity; i++)
            {
                int ite = rand() % 3 +1;
                if(ite == 1) 
                {
                Weapon* weapon_1 = new Weapon();
                weapon_1->RandomizeWeaponStart(hero.GetProfession());
                this->items.push_back(weapon_1);
                }
                else if(ite ==2)
                {
                Armory* armor_1 = new Armory();
                    armor_1->RandomizeArmorStart(); 
                    this->items.push_back(armor_1);
                }
                else
                {
                    Potion* potion = new Potion();
                    potion->RandomizePotion();
                    this->items.push_back(potion);
                }
                
            }
        }
        else if (proc > 80 && proc <= 95)
        {
            this->chestType = EPIC;
            this->isOpen = false;
            capacity = rand() % 8 + 2;
            for(int i=0; i<capacity; i++)
            {
                int ite = rand() % 3 +1;
                if(ite == 1) 
                {
                Weapon* weapon_1 = new Weapon();
                weapon_1->RandomizeWeaponStart(hero.GetProfession());
                this->items.push_back(weapon_1);
                }
                else if(ite ==2)
                {
                Armory* armor_1 = new Armory();
                    armor_1->RandomizeArmorStart(); 
                    this->items.push_back(armor_1);
                }
                else
                {
                    Potion* potion = new Potion();
                    potion->RandomizePotion();
                    this->items.push_back(potion);
                }
                
            }
        }
        else 
        {
            this->chestType = LEGENDARY;
            this->isOpen = false;
            capacity = rand() % 10 + 3;
            for(int i=0; i<capacity; i++)
            {
                int ite = rand() % 5 +1;
                if(ite == 1) 
                {
                Weapon* weapon_1 = new Weapon();
                weapon_1->RandomizeWeapon();
                this->items.push_back(weapon_1);
                }
                else if(ite ==2)
                {
                Armory* armor_1 = new Armory();
                    armor_1->RandomizeArmorStart(); 
                    this->items.push_back(armor_1);
                }
                else if(ite == 3)
                {
                    Potion* potion = new Potion();
                    potion->RandomizePotion();
                    this->items.push_back(potion);
                }
                else if(ite == 4)
                {
                    Weapon* weapon_2 = new Weapon();
                    weapon_2->RandomizeWeaponSpeacial();
                    this->items.push_back(weapon_2);
                }
                else 
                {
                    Armory* armor_2 = new Armory();
                    armor_2->RandomizeArmorSpecial();
                    this->items.push_back(armor_2);
                }
                
            }
        }
         for (auto item : items) {
        delete item;
        }
        items.clear();

         for (int i = 0; i < capacity; ++i) {
        int roll = rand() % 100;
        Item* newItem = nullptr;
        if (chestType == COMMON) {
           
            if (roll < 40) {
                Weapon* w = new Weapon();
                w->RandomizeWeaponStart("Warrior");
                newItem = w;
            } else if (roll < 70) {
                Armory* a = new Armory();
                a->RandomizeArmorStart();
                newItem = a;
            } else {
                Potion* p = new Potion();
                p->RandomizePotion();
                newItem = p;
            }
        }

         else if (chestType == RARE) {
            
            if (roll < 25) {
                Weapon* w = new Weapon();
                w->RandomizeWeaponStart("Warrior");
                newItem = w;
            } else if (roll < 50) {
                Armory* a = new Armory();
                a->RandomizeArmorStart();
                newItem = a;
            } else if (roll < 80) {
                Weapon* w = new Weapon();
                w->RandomizeWeaponSpeacial();
                newItem = w;
            } else {
                Potion* p = new Potion();
                p->RandomizePotion();
                newItem = p;
            }
        }
        else if (chestType == EPIC) {
            
            if (roll < 40) {
                Weapon* w = new Weapon();
                w->RandomizeWeaponSpeacial();
                newItem = w;
            } else if (roll < 70) {
                Armory* a = new Armory();
                a->RandomizeArmorSpecial();
                newItem = a;
            } else {
                Potion* p = new Potion();
                p->RandomizePotion();
                newItem = p;
            }
        }
        else { // LEGENDARY
            
            if (roll < 35) {
                Weapon* w = new Weapon();
                w->RandomizeWeaponSpeacial();
                newItem = w;
            } else if (roll < 70) {
                Armory* a = new Armory();
                a->RandomizeArmorSpecial();
                newItem = a;
            } else {
                Potion* p = new Potion();
                p->RandomizePotion();
                newItem = p;
            }
        }


if (newItem) {
            items.push_back(newItem);
}

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


void Chest::ShowInfo() const 
{
    std::string typeStr;
    std::string colorCode;

    switch (chestType) {
        case COMMON:    typeStr = "Common";    colorCode = "\033[37m"; break; // grey clr
        case RARE:      typeStr = "Rare";      colorCode = "\033[34m"; break; // blue clr
        case EPIC:      typeStr = "Epic";      colorCode = "\033[35m"; break; // violet clr
        case LEGENDARY: typeStr = "Legendary"; colorCode = "\033[33m"; break; // gold color
        default:        typeStr = "Unknown";   colorCode = "\033[0m";  break;
    }

    const std::string reset = "\033[0m";

    std::cout << colorCode
              << "==============================\n"
              << "          CHEST INFO          \n"
              << "==============================\n" << reset
              << " Type:     " << colorCode << typeStr << reset << "\n"
              << " Capacity: " << capacity << "\n"
              << " Status:   " << (isOpen ? "Open" : "Closed") << "\n"
              << colorCode << "==============================" << reset << "\n";
}



void Chest::ShowItems() const
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
        delete items[index];     
        items.erase(items.begin() + index);  
    }
}

