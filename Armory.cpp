#include <iostream>
#include "Header.h"


std::string Armory::RandomizeArmorStart(const std::string& profession_get)                                  //Starter pack armor
{
std::string weapon_me[] = {"Sword", "Dagger", "Spear", "Mace", "Longsword", "War Hammer", "Axe", "Club", "Mace", "Knife", "Katana", "Rapier", "Sabre"}; //For_Melee == 13
std::string weapon_ra[] = {"Crossbow", "Longbow", "Nand Cannon", "Bow"}; //For_range == 4
std::string weapon_ma[] = {"Rod", "Wand", "Staff"}; //For_magic == 3
}


void Armory::ShowInfo() const                                                                                          //Show armor characteristics
{
std::cout << "\n===Your weapon characteristic=== "<< std::endl;
std::cout << "Name : " << name_a << "\nDefend : " << defend_a << "\nDurability : " 
            << durability_a << "\nValue : " << value_a <<"\nIs enchanted : " << isEnchanted_a <<"\n"<< std::endl;
}


void Armory::BrokenArmory()                                                                                                   //Count is armor broken
{
    isBroken_a = true;
    durability_a = 0;
    std::cout << (IsUsable() ? "Usable" : "Broken") << std::endl;
}


//==================================================================Special_weapon=========================================================================


void Armory::RandomizeArmorSpeacial(const std::string& profession)                                                             //for chests 
{
std::string armor_sp[] = {}; //Special_weapon
std::string armor_se[] = {}; //For_spells
std::string armor_ar[] = {}; //For_artifacts


}
