#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Character hero;
    hero.RandomizeStats();
    hero.DisplayStats();

    Weapon* weapon_1 = new Weapon();
    weapon_1->RandomizeWeaponStart(hero.GetProfession());

    MyInventory inv1;
    inv1.AddItem(weapon_1);

   

    inv1.InventoryFunctions();

    system("pause");
    return 0;
}