#include "Header.h"

void Inventory() 
{
    std::cout << "This is the inventory function where players can manage their items and equipment." << std::endl;
    std::cout ;
}

enum class WeaponCategory { Melee, Ranged, Magic };
enum class WeaponType { Sword, Bow, Staff, Dagger};

class Weapon {
protected:
    int attack;
    float durability;
    int value;
    WeaponCategory category;
    WeaponType type;
    bool isEquipped = false;
    bool isBroken = false;
    bool isEnchanted = false;

public:
    Weapon(std::string name, int attack, float durability, int value,
           WeaponCategory cat, WeaponType type);
    virtual ~Weapon() = default;
    
    virtual void Use() = 0;                                                     //Abstract method
    virtual void Reset() = 0;  //NoUse
    
    int GetAttack() const;                                                      //No changes in all
    int GetDurability() const;  
    int GetValue() const;
    bool IsBroken() const;
    bool IsEnchanted() const;
};


