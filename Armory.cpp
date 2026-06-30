#include <iostream>
#include "Header.h"
#include <map>          //-> for map function 
#include <string>
#include <utility> 

//Also make as is in weapon.cpp
 static std::map<std::string, std::pair<int, int>>& GetWeaponDB() {
    static std::map<std::string, std::pair<int, int>> db;
    if (db.empty()) {
        db = {
    //              suit name defense cost
 
        {"Padded suit", {11 ,5}}, 
        {"Leather suit", {11, 10}}, 
        {"Studded suit", {12, 22}},

  
        {"Hide suit", {12, 10}},
        {"Chain shirt",{ 13, 30}}, 
        {"Scale male", {13, 43}},
        {"Spaiked armor", {15 , 50}},
        {"Breastplate",{17, 70}},
        {"Halfplate",  {19, 110}},

    
        {"Ring mail", {14, 40 }}, 
        {"Chain mail", {15, 55}},
        {"Splint", {20, 140}}, 
        {"Plate", {26, 250}},

        {"Shield", {6, 70}}};
        }
         return db;
}


std::string Armory::RandomizeArmorStart(const std::string& profession_get)                                  //Starter pack armor
{
    auto& db = GetWeaponDB();
name_a = "Padded suit";
auto it = db.find(name_a);
    if (it != db.end()) {
        value_a  = it->second.second; 
    }
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