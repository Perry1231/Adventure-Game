#include <iostream>
#include "Header.h"


std::string Armory::RandomizeArmorStart(const std::string& profession_get)                                  //Starter pack armor
{
std::string armor_me[] = {"Sword", "Dagger", "Spear", "Mace", "Longsword", "War Hammer", "Axe", "Club", "Mace", "Knife", "Katana", "Rapier", "Sabre"}; //For_Melee == 13
std::string armor_ra[] = {"Crossbow", "Longbow", "Nand Cannon", "Bow"}; //For_range == 4
std::string armor_ma[] = {"Rod", "Wand", "Staff"}; //For_magic == 3
if (profession_get == "Warrior")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}

else if (profession_get == "Mage")
{
this -> name_a = armor_ma[rand() % 3];
return name_a;
}
else if (profession_get == "Rogue")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else if (profession_get == "Peasant")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else if (profession_get == "Archer")
{
this -> name_a = armor_ra[rand() % 4];
return name_a;
}
else if (profession_get == "Druid")
{
this -> name_a = armor_ma[rand() % 3];
return name_a;
}
else if (profession_get == "Ranger")
{
this -> name_a = armor_ra[rand() % 4];
return name_a;
}
else if (profession_get == "Blacksmith")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else if (profession_get == "Miner")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else if (profession_get == "Berserker")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else if (profession_get == "Shaman")
{
this -> name_a = armor_ma[rand() % 3];
return name_a;
}
else if (profession_get == "Warlord")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else if (profession_get == "Thief")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else if (profession_get == "Assassin")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else if (profession_get == "Scavenger")
{
this -> name_a = armor_me[rand() % 13];
return name_a;
}
else {this -> name_a = "Sword"; return name_a;}
}


void Armory::ShowInfo() const                                                                                          //Show armor characteristics
{
std::cout << "\n===Your armor characteristic=== "<< std::endl;
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


std::string Armory::RandomizeArmorSpeacial(const std::string& profession)                                                             //for chests 
{
std::string armor_sp[] = {}; //Special_weapon
std::string armor_se[] = {}; //For_spells
std::string armor_ar[] = {}; //For_artifacts

return 0;
}
