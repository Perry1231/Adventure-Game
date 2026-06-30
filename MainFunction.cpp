#include <iostream>
#include "Header.h"
//This file is for adding main functions that wiil start my programm

void MainFunction() {

    Character hero;
    hero.RandomizeStats();
    hero.DisplayStats();

    Weapon* weapon_1 = new Weapon();
    weapon_1->RandomizeWeaponStart(hero.GetProfession());


    Armory* armor_1 = new Armory();
    armor_1->RandomizeArmorStart(hero.GetProfession());

    MyInventory inv1;
    inv1.SetOwner(&hero);
    inv1.AddItem(weapon_1);


    int mainChoice = 0;
    while (true) {
        std::cout << "\n=== MAIN MENU ===" << std::endl;
        std::cout << "1. Start game" << std::endl;
        std::cout << "2. Show character stats" << std::endl;
        std::cout << "3. Show your inventory" << std::endl;
        std::cout << "4. Manage your Inventory" << std::endl;
        std::cout << "5. Get info " << std::endl;
        std::cout << "6. Help" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> mainChoice;
        if (mainChoice == 1){
            //Start game();
        }else if (mainChoice == 2) {
            hero.DisplayStats();
        } else if (mainChoice == 3) {
            inv1.DisplayInventory();
        } else if (mainChoice == 4) {
            inv1.InventoryFunctions();
        } else if (mainChoice == 5) {
            
            std::cout << "1. Display inventory" << std::endl;
            std::cout << "2. Show weapon stats" << std::endl;
            std::cout << "3. Equip weapon" << std::endl;
            std::cout << "4. Unequip weapon" << std::endl;
            std::cout << "5. Show armor stats" << std::endl;
            std::cout << "6. Equip armor" << std::endl;
            std::cout << "7. Enquip armor" << std::endl;
            std::cout << "0. Back to main menu" << std::endl;
            std::cout << "Choice: ";
            std::cin >> mainChoice;
        if (mainChoice == 1) {
           inv1.DisplayInventory();
        } else if (mainChoice == 2) {
            weapon_1->ShowInfo();    
        } else if (mainChoice == 3) {
            weapon_1->Use();
        } else if (mainChoice == 4) {
            weapon_1->Reset();
        } else if (mainChoice == 5) {
           armor_1->ShowInfo();
        } else if (mainChoice == 6) {
            armor_1->Use();
        } else if (mainChoice == 7) {
            armor_1->Reset();
        } else if (mainChoice == 0) {
            break;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }

            
        }else if (mainChoice == 6) {
            std::cout << "\n=== HELP ===" << std::endl;
            std::cout << "1. Show character stats - Displays current character statistics" << std::endl;
            std::cout << "2. Show your inventory - Lists all items in your inventory" << std::endl;
            std::cout << "3. Manage your Inventory - Access inventory management functions" << std::endl;
            std::cout << "4. Get info - Display help information" << std::endl;
            std::cout << "5. Help - Shows this help menu" << std::endl;
            std::cout << "0. Exit - Quit the program" << std::endl;

        } else if (mainChoice == 0) {
            break;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }
}