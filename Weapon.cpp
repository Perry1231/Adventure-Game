#include "Header.h"
#include <iostream>
#include <map>      //-> for map function for all weapon


//=====================================================Weapom_Randomize=========================================================================================================
void Weapon::WeaponList()                                                                   //Need cos and attack adjustment
{    //              name attack cost
std::map<std::string, std::pair<int, int>> WeaponMeleeLightName = {
        {"Club", {3 ,2}}, 
        {"Dagger", {5, 3}}, 
        {"Greatclub", {6, 5}},
        {"Handaxe", {5, 5}},
        {"Javelin", {6, 5}},
        {"Light hammer", {6, 5}},
        {"Mace", {6, 5}},
        {"Sickle", {6, 5}},
        {"Quarterstaff", {6, 5}},
        {"Scimitar", {6, 5}},
        {"Shortsword",{17, 70}},
        {"Unarmed strike", {6, 5}}};


std::map<std::string, std::pair<int, int>> WeaponRangedName = {
        {"Light crossbow", {12, 10}},
        {"Dart",{ 13, 30}}, 
        {"Shortbow", {13, 43}},
        {"Blowgun",{17, 70}},
        {"Longbow",{17, 70}},
        {"Greatsword",{17, 70}},
        {"Net",{17, 70}}};

std::map<std::string, std::pair<int, int>> WeaponMeleeHeavyName = {
        {"Battleaxe", {12, 10}},
        {"Flail",{ 13, 30}}, 
        {"Glaive", {13, 43}},
        {"Greataxe", {15 , 50}},
        {"Greatsword",{17, 70}},
        {"Lance",{17, 70}},
        {"Longsword",{17, 70}},
        {"Maul",{17, 70}},
        {"Morningstar",{17, 70}},
        {"Pike",{17, 70}},
        {"Rapier",{17, 70}},
        {"Greatsword",{17, 70}},
        {"Greatsword",{17, 70}},
        {"Warhammer",{17, 70}},
        {"Halberd",  {19, 110}}};
}


std::string Weapon::RandomizeWeaponStart(const std::string& profession_get)                                  //Starter pack weapon
{
std::string weapon_me[] = {"Sword", "Dagger", "Spear", "Mace", "Longsword", "War Hammer", "Axe", "Club", "Mace", "Knife", "Katana", "Rapier", "Sabre"}; //For_Melee == 13
std::string weapon_ra[] = {"Crossbow", "Longbow", "Nand Cannon", "Bow"}; //For_range == 4
std::string weapon_ma[] = {"Rod", "Wand", "Staff"}; //For_magic == 3

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
void Weapon::ShowInfo() const                                                                                          //Show weapon characteristics
{
std::cout << "\n===Your weapon characteristic=== "<< std::endl;
std::cout << "Name : " << name_w << "\nAttack : " << attack_w << "\nDefend : " << defend_w << "\nDurability : " 
            << durability_w << "\nValue : " << value_w <<"\nIs enchanted : " << isEnchanted_w <<"\n"<< std::endl;
}


void Weapon::BrokenWeapon()                                                                                                   //Count is weapon broken
{
    isBroken_w = true;
    durability_w = 0;
    std::cout << (IsUsable() ? "Usable" : "Broken") << std::endl;
}


void Weapon::Use()
{
    isEquipped_w = true;
    std::cout << name_w << " equipped! Attack +" << attack_w << std::endl;
}

void Weapon::Reset()
{
    isEquipped_w = false;
        std::cout << name_w << " equipped! Attack -" << attack_w << std::endl;
}

//=================================================================Special_weapon=================================================================================

std::string  Weapon::RandomizeWeaponSpeacial(const std::string& profession)                                                             //for chests 
{
std::string weapon_sp[] = {"Guandao", "Poleaxe", "Super Bow", "Super Sword", "Super Rod"}; //Special_weapon
std::string weapon_se[] = {"Health potion", "Power potion", "Poison cure", "experience potion", "Agilitty potion", "Inteligents potion", }; //For_spells
std::string weapon_ar[] = {"Midas arm", ""}; //For_artifacts

return 0;
}




//НОВЕ: задаємо атаку за назвою зброї