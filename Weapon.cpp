#include "Header.h"

//====================================================Inventory_functions=======================================================================================================

void Inventory() 
{
    std::cout << "This is the inventory function where players can manage their items and equipment." << std::endl;
}

void Weapon::DisplayInventory()
{
    //for 
}

//=====================================================Weapom_Randomize=========================================================================================================
void Weapon::RandomizeWeapon()
{
std::string weapon_m[] = {"Sword", "Dagger", "Spear", "Mace", "Longsword", "War Hammer", "Axe", "Club", "Mace", "Knife", "Katana", "Rapier", "Sabre"}; //For_Melee
std::string weapon_r[] = {"Crossbow", "Longbow", "Nand Cannon"}; //For_range
std::string weapon_m[] = {"Rod", "Wands", "Staffs"}; //For_magic
std::string weapon_s[] = {"Guandao", "Poleaxe", ""}; //For_special

}

void Weapon::BrokenWeapon()
{
    Weapon::~Weapon();
}