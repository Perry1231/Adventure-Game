#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>
#include <cstdlib>

//========================================================================Item+structure==========================================
class Item {
private:
    int itemId;
public:
    virtual ~Item() {}
    virtual void ShowInfo() const = 0;
    virtual std::string GetName() const = 0;
    virtual std::string GetType() const = 0;
    int GetItemId() const { return itemId; }
    void SetItemId(int id) { itemId = id; }
};

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
class Weapon : public Item  
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
Weapon() : isEquipped_w(false), isBroken_w(false), 
           isEnchanted_w(false), attack_w(0), defend_w(0), durability_w(100), value_w(0), name_w("") {}Weapon(std::string name_)
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

    void ShowInfo() const override ;
    std::string GetName() const override { return name_w; }
    std::string GetType() const override { return "Weapon"; }


    ~Weapon() {}
};


//=======================================================================Armory_strucuture==========================================================================
class Armory : public Item
{
    protected :
bool isEquipped_a;
bool isBroken_a;
bool isEnchanted_a;
int defend_a;
float durability_a;
int value_a;
std::string name_a;


    public:
Armory() : isEquipped_a(false), isBroken_a(false), 
           isEnchanted_a(false), defend_a(0), durability_a(100), value_a(0), name_a("") {}Armory(std::string name_a)
{
    this->name_a = name_a;
    this->defend_a = 0;   
    this->durability_a = 100; // Default durability
    this->value_a = 0; 
    this->isEquipped_a = false;
    this->isBroken_a = false;
    this->isEnchanted_a = false;
}
Armory(std::string name_a, int defend_) : Armory(name_a)
{
    this->defend_a = defend_;
}
Armory(std::string name_a, int defend_, float durability_) : Armory(name_a,  defend_)
{
    this->durability_a = durability_; 
}
Armory(std::string name_a,  int defend_, float durability_, int value_) : Armory(name_a,  defend_, durability_)
{
    this->value_a = value_;
}
Armory(std::string name_a,  int defend_, float durability_, int value_, bool isEquipped_) : Armory(name_a,  defend_, durability_, value_)
{
    this->isEquipped_a = isEquipped_;
}
Armory(std::string name_a,  int defend_, float durability_, int value_, bool isEquipped_, bool isBroken_) : Armory(name_a, defend_, durability_, value_, isEquipped_)
{
    this->isBroken_a = isBroken_;
}
Armory(std::string name_a,  int defend_, float durability_, int value_, bool isEquipped_, bool isBroken_, bool isEnchanted_) : Armory(name_a,  defend_, durability_, value_, isEquipped_, isBroken_)
{
    this->isEnchanted_a = isEnchanted_;
}

virtual void Use() { }
virtual void Reset() { }
int GetDefense() const { return defend_a; }
int GetDurability() const { return durability_a; }
int GetValue() const { return value_a; }
bool IsBroken() const { return isBroken_a; }
bool IsEnchanted() const { return isEnchanted_a; }


std::string RandomizeArmorStart(const std::string& profession);
void BrokenArmor();
void RandomizeArmorSpeacial(const std::string& profession);
bool IsUsable() const { return !isBroken_a && durability_a > 0; }

void ShowInfo() const override;



~Armory() {};
};





//=======================================================================Inventory_structure===========================================================================
class MyInventory
{
private:
Item** items;
int capacity;   //Capacity of inventory given
int count;      //How many items now
int id;


public:
MyInventory() :  items(nullptr) , count(0) , capacity(0), id(1) {}

~MyInventory(){for (int i = 0; i < count; i++)
        delete items[i];
    delete[] items;}


void DisplayInventory() const;
int GetCount() const { return count; }
int AddItem(Item* item);
int DelItem(int id);
int ResizeInventoryBig();
void InventoryFunctions();
};
void HelpFunction() ;





class OtInventory
{
private:
    int size;
     int *ot_inv_mass = new int [size];                         //Other character inventory (trader , ...)

public:
OtInventory() : size() {}

~OtInventory(){delete[] ot_inv_mass;}
};





#endif