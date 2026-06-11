#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

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


//For melee weapons like swords, daggers======================================================================================================================================================
class Weapon_hand                                                         
{
    protected:
    bool isEquipped;
    bool isBroken;
    bool isEnchanted;
int attack;
int durability;
int value;
std::string name;
   public:
Weapon_hand() : attack(), durability(), value(), name() {}
Weapon_hand(std::string name_)
{
    this->name = name_;
    this->attack = 0;
    this->durability = 100; // Default durability
    this->value = 0; 
    this->isEquipped = false;
    this->isBroken = false;
    this->isEnchanted = false;
}
Weapon_hand(std::string name_, int attack_) : Weapon_hand(name_)
{
    this->attack = attack_;
}
Weapon_hand(std::string name_, int attack_, int durability_) : Weapon_hand(name_, attack_ )
{
    this->durability = durability_; 
}
Weapon_hand(std::string name_, int attack_,  int durability_, int value_) : Weapon_hand(name_, attack_,  durability_)
{
    this->value = value_;
}
Weapon_hand(std::string name_, int attack_, int durability_, int value_, bool isEquipped_) : Weapon_hand(name_, attack_, durability_, value_)
{
    this->isEquipped = isEquipped_;
}
Weapon_hand(std::string name_, int attack_, int durability_, int value_, bool isEquipped_, bool isBroken_) : Weapon_hand(name_, attack_,  durability_, value_, isEquipped_)
{
    this->isBroken = isBroken_;
}
Weapon_hand(std::string name_, int attack_,  int durability_, int value_, bool isEquipped_, bool isBroken_, bool isEnchanted_) : Weapon_hand(name_, attack_, durability_, value_, isEquipped_, isBroken_)
{
    this->isEnchanted = isEnchanted_;
}

    virtual void Use() = 0; // Pure virtual function for using the weapon

    virtual ~Weapon_hand();
};



//For bowlers and crossbows=======================================================================================================================================================
class Weapon_shoter                               
{
    protected:
    bool isEquipped;
    bool isBroken;
    bool isEnchanted;
int attack;
int durability;
int value;
std::string name;

public :
Weapon_shoter() : attack(), durability(), value(), name() {}
Weapon_shoter(std::string name_)
{
    this->name = name_;
    this->attack = 0;
    this->durability = 100; // Default durability
    this->value = 0; 
    this->isEquipped = false;
    this->isBroken = false;
    this->isEnchanted = false;
}
Weapon_shoter(std::string name_, int attack_) : Weapon_shoter(name_)
{
    this->attack = attack_;
}
Weapon_shoter(std::string name_, int attack_, int durability_) : Weapon_shoter(name_, attack_ )
{
    this->durability = durability_; 
}
Weapon_shoter(std::string name_, int attack_,  int durability_, int value_) : Weapon_shoter(name_, attack_,  durability_)
{
    this->value = value_;
}
Weapon_shoter(std::string name_, int attack_, int durability_, int value_, bool isEquipped_) : Weapon_shoter(name_, attack_, durability_, value_)
{
    this->isEquipped = isEquipped_;
}
Weapon_shoter(std::string name_, int attack_, int durability_, int value_, bool isEquipped_, bool isBroken_) : Weapon_shoter(name_, attack_,  durability_, value_, isEquipped_)
{
    this->isBroken = isBroken_;
}
Weapon_shoter(std::string name_, int attack_,  int durability_, int value_, bool isEquipped_, bool isBroken_, bool isEnchanted_) : Weapon_shoter(name_, attack_, durability_, value_, isEquipped_, isBroken_)
{
    this->isEnchanted = isEnchanted_;
}
    virtual void Shoot() = 0; // Pure virtual function for shooting the weapon
    virtual ~Weapon_shoter();

};



//For magic staffs and rods===============================================================================================================================================
class Weapon_magic                                      
{
    protected:
    bool isEquipped;
    bool isBroken;
    bool isEnchanted;
int attack;
int defend;
int durability;
int value;
std::string name;

    public :
Weapon_magic() : attack(), defend(), durability(), value(), name() {}
Weapon_magic(std::string name_)
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
Weapon_magic(std::string name_, int attack_) : Weapon_magic(name_)
{
    this->attack = attack_;
}
Weapon_magic(std::string name_, int attack_, int defend_) : Weapon_magic(name_, attack_)
{
    this->defend = defend_;
}
Weapon_magic(std::string name_, int attack_, int defend_, int durability_) : Weapon_magic(name_, attack_, defend_)
{
    this->durability = durability_; 
}
Weapon_magic(std::string name_, int attack_, int defend_, int durability_, int value_) : Weapon_magic(name_, attack_, defend_, durability_)
{
    this->value = value_;
}
Weapon_magic(std::string name_, int attack_, int defend_, int durability_, int value_, bool isEquipped_) : Weapon_magic(name_, attack_, defend_, durability_, value_)
{
    this->isEquipped = isEquipped_;
}
Weapon_magic(std::string name_, int attack_, int defend_, int durability_, int value_, bool isEquipped_, bool isBroken_) : Weapon_magic(name_, attack_, defend_, durability_, value_, isEquipped_)
{
    this->isBroken = isBroken_;
}
Weapon_magic(std::string name_, int attack_, int defend_, int durability_, int value_, bool isEquipped_, bool isBroken_, bool isEnchanted_) : Weapon_magic(name_, attack_, defend_, durability_, value_, isEquipped_, isBroken_)
{
    this->isEnchanted = isEnchanted_;
}
   


      virtual void Use_m() = 0; // Pure virtual function for using the magic weapon
    virtual ~Weapon_magic();
};


void HelpFunction() ;
void Inventory();
#endif