#include <iostream>
#include "Header.h"


void Chest::ChestCreate(Type type) {
    Chest chest;
    this->chestType = type;
    this->isOpen = false;
    this->capacity =0;
    items.clear();                                          // Clear any existing items in the chest
    chest.RandomizeChest(type);
}
 


void Chest::RandomizeChest(Type type)
{
                // Randomly select a chest type (0 to 3)
    switch (type) {
        case COMMON:
            // Add common items to the chest
            items.push_back(new Weapon("Common Sword", 5));     // Add a common weapon to the chest and int is an attack value
            items.push_back(new Potion("Health Potion", Potion::HEALTH, 20, "Restores health", 10));
            break;
        case RARE:
            // Add rare items to the chest
            items.push_back(new Weapon("Rare Sword", 10));
            items.push_back(new Potion("Strength Potion", Potion::STRENGTH, 5, "Increases strength", 15));
            break;
        case EPIC:
            // Add epic items to the chest
            items.push_back(new Weapon("Epic Sword", 15));
            items.push_back(new Potion("Intelligence Potion", Potion::INTELLIGENCE, 5, "Increases intelligence", 20));
            break;
        case LEGENDARY:
            // Add legendary items to the chest
            items.push_back(new Weapon("Legendary Sword", 20));
            items.push_back(new Potion("Defense Potion", Potion::DEFENSE, 5, "Increases defense", 25));
            break;
    }
}
