#include "Header.h"


//=====================================================Weapom_Randomize=========================================================================================================
void Weapon::RandomizeWeapon(const std::string& profession)
{
std::string weapon_me[] = {"Sword", "Dagger", "Spear", "Mace", "Longsword", "War Hammer", "Axe", "Club", "Mace", "Knife", "Katana", "Rapier", "Sabre"}; //For_Melee
std::string weapon_ra[] = {"Crossbow", "Longbow", "Nand Cannon"}; //For_range
std::string weapon_ma[] = {"Rod", "Wands", "Staffs"}; //For_magic

/*if (profession == "")
{

}

else if (profession == "")
{

}
}
*/
}

void Weapon::BrokenWeapon()
{
     isBroken = true;
    durability = 0;
}