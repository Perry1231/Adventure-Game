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
    inv1.GetCount();
    inv1.DisplayInventory();
    inv1.InventoryFunctions();

/*Armory* armor_1 = new Armor();                                       //Weapon create test
armor_1->RandomizeArmorStart(hero.GetProfession());

MyInventory inv1;
inv1.AddItem(armor_1);
*/





   

    system("pause");
    return 0;
}