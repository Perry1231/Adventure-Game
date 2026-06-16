#include "Header.h"


//=====================================================Weapom_Randomize=========================================================================================================
void Weapon::RandomizeWeapon()
{
std::string weapon_m[] = {"Sword", "Dagger", "Spear", "Mace", "Longsword", "War Hammer", "Axe", "Club", "Mace", "Knife", "Katana", "Rapier", "Sabre"}; //For_Melee
std::string weapon_r[] = {"Crossbow", "Longbow", "Nand Cannon"}; //For_range
std::string weapon_m[] = {"Rod", "Wands", "Staffs"}; //For_magic


}

void Weapon::BrokenWeapon()
{
    Weapon::~Weapon();
}