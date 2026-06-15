#include "Header.h"

void Inventory() 
{
    std::cout << "This is the inventory function where players can manage their items and equipment." << std::endl;
}


//=====================================================Weapom_Randomize=========================================================================================================
void Weapon::RandomizeWeapon()
{
std::string professions_h[] = {"Warrior", "Mage", "Rogue", "Peasant"}; //For_Human
std::string professions_e[] = { "Archer", "Druid", "Ranger"}; //For_Elf
std::string professions_d[] = {"Blacksmith", "Miner", "Berserker"}; //For_Dwarf
std::string professions_o[] = {"Shaman", "Warlord", "Berserker"}; //For_Orc
std::string professions_g[] = {"Thief", "Assassin", "Scavenger"}; //For_Goblin
}

void Weapon::BrokenWeapon()
{
    Weapon::~Weapon();
}