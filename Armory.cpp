#include <iostream>
#include "Header.h"
#include <map>


std::string Armory::RandomizeArmorStart(const std::string& profession_get)                                  //Starter pack armor
{
std::string armor_li[] = {"Padded suit","Leather suit", "Studded suit"}; //For_light == 3
std::string armor_me[] = {"Hide suit", "Chain suit", "Scale suit", "Breathplate", "Halp plate"}; //For_medium == 5
std::string armor_we[] = {"Ring mail suit", "Splint suit", "Plated suit"}; //For_weight == 3
std::string armor_ot[] = {"Shield"};
if (profession_get == "Warrior")
{
this -> name_a = armor_me[rand() % 3];
return name_a;
} 

else if (profession_get == "Mage")
{ 
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Rogue")
{
this -> name_a = armor_li[rand() % 3];
return name_a; 
}
else if (profession_get == "Peasant")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Archer")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Druid")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Ranger")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Blacksmith")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Miner")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Berserker")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Shaman")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Warlord")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Thief")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Assassin")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else if (profession_get == "Scavenger")
{
this -> name_a = armor_li[rand() % 3];
return name_a;
}
else {this -> name_a = "Armor"; return name_a;}
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



void Armory::Use() {
    isEquipped_a = true;
    std::cout << name_a << " equipped! Defense: +" << defend_a << std::endl;
}

void Armory::Reset() {
    isEquipped_a = false;
    std::cout << name_a << " unequipped." << std::endl;
}

//==================================================================Special_weapon=========================================================================


std::string Armory::RandomizeArmorSpeacial(const std::string& profession)                                                             //for chests 
{
std::string armor_sp[] = {"Dragon suit", "shadow suit", "Death suit", "Void suit"}; //Special_armor
this -> name_a = armor_sp[rand() % 4];
return name_a;
}