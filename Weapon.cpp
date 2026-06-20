#include "Header.h"
#include <iostream>


//=====================================================Weapom_Randomize=========================================================================================================
std::string Weapon::RandomizeWeaponStart(const std::string& profession_get)                                  //Starter pack weapon
{
std::string weapon_me[] = {"Sword", "Dagger", "Spear", "Mace", "Longsword", "War Hammer", "Axe", "Club", "Mace", "Knife", "Katana", "Rapier", "Sabre"}; //For_Melee == 13
std::string weapon_ra[] = {"Crossbow", "Longbow", "Nand Cannon", "Bow"}; //For_range == 4
std::string weapon_ma[] = {"Rod", "Wands", "Staffs"}; //For_magic == 3

if (profession_get == "Warrior")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}

else if (profession_get == "Mage")
{
this -> name_w = weapon_ma[rand() % 3];
return name_w;
}
else if (profession_get == "Rogue")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else if (profession_get == "Peasant")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else if (profession_get == "Archer")
{
this -> name_w = weapon_ra[rand() % 4];
return name_w;
}
else if (profession_get == "Druid")
{
this -> name_w = weapon_ma[rand() % 3];
return name_w;
}
else if (profession_get == "Ranger")
{
this -> name_w = weapon_ra[rand() % 4];
return name_w;
}
else if (profession_get == "Blacksmith")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else if (profession_get == "Miner")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else if (profession_get == "Berserker")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else if (profession_get == "Shaman")
{
this -> name_w = weapon_ma[rand() % 3];
return name_w;
}
else if (profession_get == "Warlord")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else if (profession_get == "Thief")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else if (profession_get == "Assassin")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else if (profession_get == "Scavenger")
{
this -> name_w = weapon_me[rand() % 13];
return name_w;
}
else {this -> name_w = "Sword"; return name_w;}
}

//================================================================Other_functions=============================================================================
void Weapon::ShowCharacteristicWeapon()                                                                                          //Show weapon characteristics
{
std::cout << "\n\n ===Your weapon characteristic=== "<< std::endl;
std::cout << "Name : " << name_w << "\nAttack : " << attack_w << "\nDefend : " << defend_w << "\nDurability : " 
            << durability_w << "\nValue : " << value_w <<"\n Is enchanted : " << isEnchanted_w << std::endl;
}


void Weapon::BrokenWeapon()                                                                                                     //Count is weapon broken
{
    isBroken_w = true;
    durability_w = 0;
    std::cout << (IsUsable() ? "Usable" : "Broken") << std::endl;
}