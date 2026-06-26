#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Character hero;                                                     //Hero create test
    hero.RandomizeStats();
    hero.DisplayStats();



    Weapon* weapon_1 = new Weapon();                                    //Weapon create test
    Weapon* weapon_2 = new Weapon();  
    weapon_1->RandomizeWeaponStart(hero.GetProfession());
    weapon_2->RandomizeWeaponStart(hero.GetProfession());

    MyInventory inv1; 
    inv1.AddItem(weapon_1);
    inv1.AddItem(weapon_2);
    inv1.DisplayInventory();
    inv1.InventoryFunctions();


    Armory* armor_1 = new Armory();                                       //Weapon create test
    armor_1->RandomizeArmorStart(hero.GetProfession());
    MyInventory inv2;
    inv2.AddItem(armor_1);
    inv2.DisplayInventory();
    

    hero.EquipWeapon(weapon_1);
    std::cout << "Total attack: " << hero.GetTotalAttack() << std::endl;  // strength + attack_w

    hero.EquipArmor(armor_1);
    std::cout << "Total defense: " << hero.GetTotalDefense() << std::endl;
    return 0;             
}