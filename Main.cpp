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
    weapon_1->RandomizeWeaponStart(hero.GetProfession());

    MyInventory inv1;
    inv1.AddItem(weapon_1);



/*Armory* armor_1 = new Armor();                                       //Weapon create test
armor_1->RandomizeArmorStart(hero.GetProfession());

MyInventory inv1;
inv1.AddItem(armor_1);
*/





    inv1.InventoryFunctions();

    system("pause");
    return 0;
}