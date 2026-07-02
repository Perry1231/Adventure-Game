#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>
#include <cstdlib>

class Weapon;
class Armory;
class Character;
class Inventory;
class Item;
class OtInventory;
class Potion;


//=====================================================Item_structure==========================================
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


    virtual void Use() = 0;
    virtual void Reset() = 0;

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


Weapon* equipped_weapon;                //For equipment
Armory* equipped_armor;


    public :
//Default constructo 
Character() : health(100), name ("Hero"), age(20), race("Human"), profession("Adventurer"), level(1), 
description("A brave adventurer ready to explore the world."), strength(10), agility(10), intelligence(10), 
defense(10), gold(100) , equipped_weapon(nullptr), equipped_armor(nullptr) {}

//Parameterized constructor
Character(int health_, std::string name_, int age_, std::string race_, std::string profession_, int level_, 
        std::string description_, int strength_, int agility_, int intelligence_, int defense_, int gold_) : health(health_), name(name_),
        age(age_), race(race_), profession(profession_), level(level_), description(description_), strength(strength_), agility(agility_),  
        intelligence(intelligence_), defense(defense_), gold(gold_) {}
    
    void DisplayStats();
    void RandomizeStats();
        
    void EquipWeapon(Weapon* w); 
    void EquipArmor(Armory* a); 
    Weapon* GetEquippedWeapon() const;
    Armory* GetEquippedArmor() const; 
    int GetTotalAttack() const; 
    int GetTotalDefense() const; 
    void UnequipWeapon(); 
    void UnequipArmor();

    void GetHealth() const { std::cout << "Health: " << health << std::endl; }
    void GetLevel() const { std::cout << "Level: " << level << std::endl; }
    void GetDefense() const { std::cout << "Defense: " << defense << std::endl; }
    void GetStrength() const { std::cout << "Strength: " << strength << std::endl; }
    void GetAgility() const { std::cout << "Agility: " << agility << std::endl; }
    void GetIntelligence() const { std::cout << "Intelligence: " << intelligence << std::endl; }

    void ApplyPotionEffect(int effectType, int potency, int duration);//===========-0=--=0-0-0-0-0-0000-0-0-0-0-0-0000 Realize cont

    std::string GetProfession() const { return profession; };
    void Usage();
    
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
   


    void Use() override;
    void Reset() override;

    int GetAttack() const { return attack_w; };                                                      
    int GetDurability() const{ return durability_w; };  
    int GetValue() const { return value_w; };
    bool IsBroken() const { return isBroken_w; };
    bool IsEnchanted() const { return isEnchanted_w; };
    std::string RandomizeWeaponStart(const std::string& profession);
    void BrokenWeapon();
    std::string  RandomizeWeaponSpeacial(const std::string& profession);
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

void Use();
void Reset();
int GetDefense() const { return defend_a; }
int GetDurability() const { return durability_a; }
int GetValue() const { return value_a; }
bool IsBroken() const { return isBroken_a; }
bool IsEnchanted() const { return isEnchanted_a; }


bool IsUsable() const { return !isBroken_a && durability_a > 0; }
void BrokenArmory();
void ShowInfo() const override;
std::string RandomizeArmorSpeacial(const std::string& profession);
std::string RandomizeArmorStart(const std::string& profession_get);
std::string GetName() const override { return name_a; }
std::string GetType() const override { return "Armor"; }


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
Character* owner;

public:
MyInventory() :  items(nullptr) , count(0) , capacity(0), id(1), owner(nullptr) {}

~MyInventory(){for (int i = 0; i < count; i++)
        delete items[i];
    delete[] items;}


void SetOwner(Character* c) { owner = c; }
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
    int size=1;
     int *ot_inv_mass = new int [size];                         //Other character inventory (trader , ...)

public:            
OtInventory() : size(0), ot_inv_mass(nullptr) {}



int GetSize() const { return size; }
int* GetInventory() const { return ot_inv_mass; }


~OtInventory(){delete[] ot_inv_mass;}
};
//==================================================================Potion_structure=========================================================================================

class Potion : public Item
{
public:
enum EffectType { HEALTH, DEFENSE, AGILITY, INTELLIGENCE, GOLD }; // Example effect types

protected:
    std::string name_p;
    int effectType; 
    int potency;                // How strong the potion is
    int duration;               // How long the effect lasts
    std::string description_p;
    bool isEquipped_p;
    int value_p; // Value of the potion in gold


public:
    Potion() : effectType(0),  potency(0) ,  duration(0) ,value_p(0) ,name_p("") , isEquipped_p(false) , description_p("")  {}

    Potion (std::string name_, int effectType_, int potency_, int duration_, std::string description_, int value_)
     : name_p(name_), effectType(effectType_), potency(potency_), duration(duration_), value_p(value_), isEquipped_p(false), description_p(description_) {}

    int GetValue() const { return value_p; }
    std::string GetName() const override { return name_p; }
    std::string GetType() const override { return "Potion"; }
    int GetEffectType() const { return effectType; }
    int GetPotency() const { return potency; }
    int GetDuration() const { return duration; }
    std::string GetDescription() const { return description_p; }

    bool IsEquipped() const { return isEquipped_p; }
    void SetEquipped(bool equipped) { isEquipped_p = equipped; }
     void SetValue(int val) { value_p = val; }

    void ApplyEffect(Character* target); // Apply the potion effect to the character

    void ShowInfo() const override ;
    void Use() override;
    void Reset() override;
};


//==================================================================Other_functions=============================================================================
void MainFunction();

#endif