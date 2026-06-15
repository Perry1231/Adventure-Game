#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>
#include <cstdlib>


//=======================================================================Character_structure===================================================================================
class Character
{
    protected :
int health;
std::string name;
int age;
std::string race;
std::string profession;
int level;
std::string description;
int strength;
int agility;
int intelligence;
int defense;
int gold;


    public :
//Default constructor
Character() : health(100), name ("Hero"), age(20), race("Human"), profession("Adventurer"), level(1), 
description("A brave adventurer ready to explore the world."), strength(10), agility(10), intelligence(10), defense(10), gold(100)   {}
//Parameterized constructor
Character(int health_, std::string name_, int age_, std::string race_, std::string profession_, int level_, 
        std::string description_, int strength_, int agility_, int intelligence_, int defense_, int gold_) : health(health_), name(name_),
        age(age_), race(race_), profession(profession_), level(level_), description(description_), strength(strength_), agility(agility_),  
        intelligence(intelligence_), defense(defense_), gold(gold_) {}
    

~Character();

void DisplayStats();
void RandomizeStats();
};


//============================================================================Weapon_structure=============================================================================
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
Weapon() : attack(), defend(), durability(), value(), name(), isEnchanted(), isEquipped(), isBroken() {}
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
    



    //=========================Realizuwaty treba
    int GetAttack() const;                                                      //No changes in all
    int GetDurability() const;  
    int GetValue() const;
    bool IsBroken() const;
    bool IsEnchanted() const;
    void RandomizeWeapon();
};


/*void BrokenWeapon()
{
    ~Weapon();
}
*/


void HelpFunction() ;
void Inventory();
#endif