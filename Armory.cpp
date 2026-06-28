#include <iostream>
#include "Header.h"
#include <map>          //-> for map function 
#include <string>
#include <utility> 


std::string Armory::RandomizeArmorStart(const std::string& profession_get)                                  //Starter pack armor
{
//              suit name defense cost
    std::map<std::string, std::pair<int, int>> SuitLightName = {
        {"Padded suit", {11 ,5}}, 
        {"Leather suit", {11, 10}}, 
        {"Studded suit", {12, 22}}};

    std::map<std::string, std::pair<int, int>> SuitMediumName = {
        {"Hide suit", {12, 10}},
        {"Chain shirt",{ 13, 30}}, 
        {"Scale male", {13, 43}},
        {"Spaiked armor", {15 , 50}},
        {"Breastplate",{17, 70}},
        {"Halfplate",  {19, 110}}};

    std::map<std::string, std::pair<int, int>> SuitHeavyName = {
        {"Ring mail", {14, 40 }}, 
        {"Chain mail", {15, 55}},
        {"Splint", {20, 140}}, 
        {"Plate", {26, 250}}};

    std::map<std::string, std::pair<int, int>> AddictionName  = {{"Shield", {6, 70}}};

name_a = "Padded suit";
defend_a = 11;
value_a = 5;
return name_a;
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


std::string Armory::RandomizeArmorSpeacial(const std::string& profession)       
{                                                 
name_a = "Dragon suit";
    defend_a = 25;
    value_a = 500;
    return name_a;
}