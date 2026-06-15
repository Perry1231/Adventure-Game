#include "Header.h"

void Inventory() 
{
    std::cout << "This is the inventory function where players can manage their items and equipment." << std::endl;
    std::cout ;
}



void Weapon::RandomizeWeapon()
{
std::string professions_h[] = {"Warrior", "Mage", "Rogue", "Peasant"}; //For_Human
std::string professions_e[] = { "Archer", "Druid", "Ranger"}; //For_Elf
std::string professions_d[] = {"Blacksmith", "Miner", "Berserker"}; //For_Dwarf
std::string professions_o[] = {"Shaman", "Warlord", "Berserker"}; //For_Orc
std::string professions_g[] = {"Thief", "Assassin", "Scavenger"}; //For_Goblin
}

class Weapon                                     
{
    protected:
    bool isEquipped;
    bool isBroken;
    bool isEnchanted;
int attack;
int defend;
float durability;
int value;
std::string name;

    public :
Weapon() : attack(), defend(), durability(), value(), name() {}
Weapon(std::string name_)
{
    this->name = name_;
    this->attack = 0;
    this->defend = 0;   
    this->durability = 100; // Default durability
    this->value = 0; 
    this->isEquipped = false;
    this->isBroken = false;
    this->isEnchanted = false;
}
Weapon(std::string name_, int attack_) : Weapon(name_)
{
    this->attack = attack_;
}
Weapon(std::string name_, int attack_, int defend_) : Weapon(name_, attack_)
{
    this->defend = defend_;
}
Weapon(std::string name_, int attack_, int defend_, float durability_) : Weapon(name_, attack_, defend_)
{
    this->durability = durability_; 
}
Weapon(std::string name_, int attack_, int defend_, float durability_, int value_) : Weapon(name_, attack_, defend_, durability_)
{
    this->value = value_;
}
Weapon(std::string name_, int attack_, int defend_, float durability_, int value_, bool isEquipped_) : Weapon(name_, attack_, defend_, durability_, value_)
{
    this->isEquipped = isEquipped_;
}
Weapon(std::string name_, int attack_, int defend_, float durability_, int value_, bool isEquipped_, bool isBroken_) : Weapon(name_, attack_, defend_, durability_, value_, isEquipped_)
{
    this->isBroken = isBroken_;
}
Weapon(std::string name_, int attack_, int defend_, float durability_, int value_, bool isEquipped_, bool isBroken_, bool isEnchanted_) : Weapon(name_, attack_, defend_, durability_, value_, isEquipped_, isBroken_)
{
    this->isEnchanted = isEnchanted_;
}
   


    virtual void Use() = 0;                                                     //Abstract method
    virtual void Reset() = 0;  //NoUse
    
    int GetAttack() const;                                                      //No changes in all
    int GetDurability() const;  
    int GetValue() const;
    bool IsBroken() const;
    bool IsEnchanted() const;
    void RandomizeWeapon();
};
