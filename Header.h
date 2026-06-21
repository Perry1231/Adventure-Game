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
    
void DisplayStats();
void RandomizeStats();
void Usage();
std::string GetProfession() const { return profession; };

~Character(){}
};


//============================================================================Weapon_structure=============================================================================
class Weapon                                     
{
    protected:
    bool isEquipped_w;
    bool isBroken_w;
    bool isEnchanted_w;
int attack_w;
int defend_w;
float durability_w;
int value_w;
std::string name_w;

    public :
Weapon() : attack_w(), defend_w(), durability_w(), value_w(), name_w(), isEnchanted_w(), isEquipped_w(), isBroken_w() {}
Weapon(std::string name_)
{
    this->name_w = name_;
    this->attack_w = 0;
    this->defend_w = 0;   
    this->durability_w = 100; // Default durability
    this->value_w = 0; 
    this->isEquipped_w = false;
    this->isBroken_w = false;
    this->isEnchanted_w = false;
}
Weapon(std::string name_, int attack_) : Weapon(name_)
{
    this->attack_w = attack_;
}
Weapon(std::string name_, int attack_, int defend_) : Weapon(name_, attack_)
{
    this->defend_w = defend_;
}
Weapon(std::string name_, int attack_, int defend_, float durability_) : Weapon(name_, attack_, defend_)
{
    this->durability_w = durability_; 
}
Weapon(std::string name_, int attack_, int defend_, float durability_, int value_) : Weapon(name_, attack_, defend_, durability_)
{
    this->value_w = value_;
}
Weapon(std::string name_, int attack_, int defend_, float durability_, int value_, bool isEquipped_) : Weapon(name_, attack_, defend_, durability_, value_)
{
    this->isEquipped_w = isEquipped_;
}
Weapon(std::string name_, int attack_, int defend_, float durability_, int value_, bool isEquipped_, bool isBroken_) : Weapon(name_, attack_, defend_, durability_, value_, isEquipped_)
{
    this->isBroken_w = isBroken_;
}
Weapon(std::string name_, int attack_, int defend_, float durability_, int value_, bool isEquipped_, bool isBroken_, bool isEnchanted_) : Weapon(name_, attack_, defend_, durability_, value_, isEquipped_, isBroken_)
{
    this->isEnchanted_w = isEnchanted_;
}
   


    virtual void Use()  { }                                             
    virtual void Reset()  { }  //NoUse

    int GetAttack() const { return attack_w; };                                                      
    int GetDurability() const{ return durability_w; };  
    int GetValue() const { return value_w; };
    bool IsBroken() const { return isBroken_w; };
    bool IsEnchanted() const { return isEnchanted_w; };
    std::string RandomizeWeaponStart(const std::string& profession);
    void BrokenWeapon();
    void RandomizeWeaponSpeacial(const std::string& profession);
    bool IsUsable() const { return !isBroken_w && durability_w > 0; }
    void ShowCharacteristicWeapon();
    ~Weapon(){}
};


//=======================================================================Inventory_structure===========================================================================
class Inventory
{
private:
 int size=0;
 int *my_inv_mass = new int [size];                         //Player inventory
 int *ot_inv_mass = new int [size];                         //Other character inventory (trader , ...)
public:
Inventory() : size() {}

~Inventory(){}

void DisplayInventory();
void DeleteItem();
int GetSpace(int& size);
int AddSpace(int *&my_inv_mass,int& size, const int value);
int DelSpace(int *&my_inv_mass,int& size);
void InventoryFunctions();
};


void HelpFunction() ;
#endif