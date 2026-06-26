#include <iostream>
#include "Header.h"
#include <cstdlib>
#include <ctime>

void MainFunction() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Character hero;
    hero.RandomizeStats();
    hero.DisplayStats();

    Weapon* weapon_1 = new Weapon();
    Weapon* weapon_2 = new Weapon();
    weapon_1->RandomizeWeaponStart(hero.GetProfession());
    weapon_2->RandomizeWeaponStart(hero.GetProfession());

    Armory* armor_1 = new Armory();
    armor_1->RandomizeArmorStart(hero.GetProfession());

    MyInventory inv1;
    inv1.AddItem(weapon_1);
    inv1.AddItem(weapon_2);

    MyInventory inv2;
    inv2.AddItem(armor_1);

    int mainChoice = 0;
    while (true) {
        std::cout << "\n=== MAIN MENU ===" << std::endl;
        std::cout << "1. Show character stats" << std::endl;
        std::cout << "2. Show weapon inventory" << std::endl;
        std::cout << "3. Manage weapon inventory" << std::endl;
        std::cout << "4. Show armor inventory" << std::endl;
        std::cout << "5. Equip first weapon" << std::endl;
        std::cout << "6. Equip first armor" << std::endl;
        std::cout << "7. Unequip weapon" << std::endl;
        std::cout << "8. Unequip armor" << std::endl;
        std::cout << "9. Show equipped stats" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> mainChoice;

        if (mainChoice == 1) {
            hero.DisplayStats();
        } else if (mainChoice == 2) {
            inv1.DisplayInventory();
        } else if (mainChoice == 3) {
            inv1.InventoryFunctions(); // повертається сюди після виходу з інвентаря
        } else if (mainChoice == 4) {
            inv2.DisplayInventory();
        } else if (mainChoice == 5) {
            hero.EquipWeapon(weapon_1);
            std::cout << "Weapon equipped! Total Attack: " << hero.GetTotalAttack() << std::endl;
        } else if (mainChoice == 6) {
            hero.EquipArmor(armor_1);
            std::cout << "Armor equipped! Total Defense: " << hero.GetTotalDefense() << std::endl;
        } else if (mainChoice == 7) {
            hero.UnequipWeapon();
            std::cout << "Weapon unequipped!" << std::endl;
        } else if (mainChoice == 8) {
            hero.UnequipArmor();
            std::cout << "Armor unequipped!" << std::endl;
        } else if (mainChoice == 9) {
            std::cout << "Total Attack: " << hero.GetTotalAttack() << std::endl;
            std::cout << "Total Defense: " << hero.GetTotalDefense() << std::endl;
        } else if (mainChoice == 0) {
            break;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }

    delete weapon_1;
    delete weapon_2;
    delete armor_1;
}