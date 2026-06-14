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
    void Create()
    {
        this->value = value + 6;
        this->name = "This is basic Rod";
    }
    void Delete()
    {
        /*~Weapon()*/
    }
    void Use() override {
        this->attack = attack + 2;
        this->durability = durability -8;
        this-> value = value -0.5;
        if(durability <= 0){
            std::cout << "The bow has broken!" << std::endl;
            durability =0;
             Delete();
        }
    }
    void NoUse() 
    {
        this->attack =  Weapon_hand::attack;  
    }
};


class BasicBow : public Weapon_shoter {
   void Create()
    {
        this->value = value + 6;
        this->name = "This is basic Rod";
    }
    void Delete()
    {
        
    }
    void Shoot() override {
        this->attack = attack + 2;
        this->durability = durability -8;
        this-> value = value -0.5;
        if(durability <= 0){
            std::cout << "The bow has broken!" << std::endl;
            durability =0;
             Delete();
        }
    }
    void NoUse() 
    {
        this->attack =  Weapon_shoter::attack;  
    }
};


class BasicRod : public Weapon_magic {
    void Create()
    {
        this->value = value + 6;
        this->name = "This is basic Rod";
    }
    void Delete()
    {
        /*~Weapon()*/
    }
    void Use_m() override {
        this->attack = attack + 2;
        this->durability = durability -8;
        this-> value = value -0.5;
        if(durability <= 0){
            std::cout << "The bow has broken!" << std::endl;
            durability =0;
             Delete();
        }
    }
    void NoUse() 
    {
        this->attack =  Weapon_magic::attack;  
    }
};


class BasicDagger : public Weapon_hand {
 void Create()
    {
        this->value = value + 6;
        this->name = "This is basic Rod";
    }
    void Delete()
    {
        /*~Weapon()*/
    }
    void Use() override {
        this->attack = attack + 2;
        this->durability = durability -8;
        this-> value = value -0.5;
        if(durability <= 0){
            std::cout << "The bow has broken!" << std::endl;
            durability =0;
             Delete();
        }
    }
    void NoUse() 
    {
        this->attack =  Weapon_hand::attack;  
    }
};


class BasicStaff : public Weapon_magic {
   
void Create()
    {
        this->value = value + 6;
        this->name = "This is basic Rod";
    }
    void Delete()
    {
        /*~Weapon()*/
    }
    void Use_m() override {
        this->attack = attack + 2;
        this->durability = durability -8;
        this-> value = value -0.5;
        if(durability <= 0){
            std::cout << "The bow has broken!" << std::endl;
            durability =0;
             Delete();
        }
    }
    void NoUse() 
    {
        this->attack =  Weapon_magic::attack;  
    }
};


class BasicCrossbow : public Weapon_shoter {
   
void Create()
    {
        this->value = value + 6;
        this->name = "This is basic Rod";
    }
    void Delete()
    {
        /*~Weapon()*/
    }
    void Shoot() override {
        this->attack = attack + 2;
        this->durability = durability -8;
        this-> value = value -0.5;
        if(durability <= 0){
            std::cout << "The bow has broken!" << std::endl;
            durability =0;
             Delete();
        }
    }
    void NoUse() 
    {
        this->attack =  Weapon_shoter::attack;  
    }
};


class BasicWeaponOC : public Weapon_hand {

void Create()
    {
        this->value = value + 6;
        this->name = "This is basic Rod";
    }
    void Delete()
    {
        /*~Weapon()*/
    }
    void Use() override {
        this->attack = attack + 2;
        this->durability = durability -8;
        this-> value = value -0.5;
        if(durability <= 0){
            std::cout << "The bow has broken!" << std::endl;
            durability =0;
             Delete();
        }
    }
    void NoUse() 
    {
        this->attack = Weapon_hand::attack;  
    }
};