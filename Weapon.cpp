#include "Header.h"

void Inventory() 
{
    std::cout << "This is the inventory function where players can manage their items and equipment." << std::endl;
    std::cout ;
}
Weapon_hand::~Weapon_hand() {}
Weapon_shoter::~Weapon_shoter() {}
Weapon_magic::~Weapon_magic() {}


class BasicSword : public Weapon_hand {                                                                                                  //NotReady
      void Use() override {

  
    this->attack = attack + 2; 
    this->durability = durability - 7; 
    this->value = value + 10;
    if (durability <= 0) {
        std::cout << "The sword has broken!" << std::endl;
        durability = 0; 
    }
}
};

class BasicBow : public Weapon_shoter {
    void Shoot() override {
    this->attack = attack + 2; 
    this->durability = durability - 7; 
    this->value = value + 10;
    if (durability <= 0) {
        std::cout << "The bow has broken!" << std::endl;
        durability = 0; 
    }
}
};


class BasicRod : public Weapon_magic {
    void Use_m() override {}

};

class BasicDagger : public Weapon_hand {
    void Use() override {}

};

