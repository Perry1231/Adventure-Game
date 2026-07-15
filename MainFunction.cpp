#include <iostream>
#include "Header.h"
void MainFunction() {
//TESTING=======================================  (For user : -> don't about this)
    Character hero;
    hero.RandomizeStats();

    Weapon* weapon_1 = new Weapon();
    weapon_1->RandomizeWeaponStart(hero.GetProfession());

    Armory* armor_1 = new Armory();
    armor_1->RandomizeArmorStart();

    Weapon* weapon_2 = new Weapon();
    weapon_2->RandomizeWeaponSpeacial();


    MyInventory inv1;
    inv1.SetOwner(&hero);
    hero.SetInventory(&inv1);

    inv1.AddItem(weapon_1);             //Added item with ID ---- will be written
    inv1.AddItem(armor_1);
    inv1.AddItem(weapon_2);

    Potion* p = new Potion();
    p->RandomizePotion();
    inv1.AddItem(p);
//====================================================================
    int mainChoice = 0;
    while (true) {
        std::cout << "\n=== MAIN MENU ===" << std::endl;                                            //Main functions (*Main menu*)
        std::cout << "1. Start game" << std::endl;

        std::cout << "2. Load game" << std::endl;
        std::cout << "3. Save game" << std::endl;

        std::cout << "4. Show character stats" << std::endl;
        std::cout << "5. Manage your Inventory" << std::endl;
        std::cout << "6. Settings " << std::endl;
        std::cout << "7. Help" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> mainChoice;                                                                     
        if (mainChoice == 1) {
            StartGame();
        } else if (mainChoice == 2) {
           Loader();                                                                              //Load game
        } else if (mainChoice == 3) {
            Saver();                                                                              //Save game
        } else if (mainChoice == 4) {
            hero.DisplayStats();                                                                     //Display stats
        } else if (mainChoice == 5) {
            std::cout << "1. Display inventory" << std::endl;                                        //Sub-main functions act1 (Manage inventory)
            std::cout << "2. Show weapon status" << std::endl;
            std::cout << "3. Equip weapon" << std::endl;
            std::cout << "4. Unequip weapon" << std::endl;
            std::cout << "5. Show armor stats" << std::endl;
            std::cout << "6. Equip armor" << std::endl;
            std::cout << "7. Unquip armor" << std::endl;
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
        } else if (mainChoice == 4) {
            Settings(hero , inv1);                                                                              //Settings
        } else if (mainChoice == 5) {
            Help();                                                                                             //Help
        } else if (mainChoice == 0) {
            break;
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }
}