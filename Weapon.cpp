#include "Header.h"

void Inventory() 
{
    std::cout << "This is the inventory function where players can manage their items and equipment." << std::endl;
    std::cout ;
}
Weapon::~Weapon() {}



class BasicSword : public Weapon {                                                                                                  //NotReady
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

class BasicBow : public Weapon {
    void Use() override {
    this->attack = attack + 2; 
    this->durability = durability - 7; 
    this->value = value + 10;
    if (durability <= 0) {
        std::cout << "The bow has broken!" << std::endl;
        durability = 0; 
    }
}
};


class BasicRod : public Weapon {
    void Use() override {}

};

class BasicDagger : public Weapon {
    void Use() override {}

};

class BasicShield : public Weapon {
    void Use() override {}

};