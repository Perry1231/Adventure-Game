#include <string>
#include <iostream>
#include "Header.h"
//File for additional characters


void Enemy::DisplayStats()
{
    std::cout << "\n\n" << std::endl;
    std::cout <<"============================================="<< std::endl;
    std::cout << "Character Stats:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Race: " << race << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout <<"=================Self Stats=================="<< std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Gold: " << gold << std::endl;
    std::cout <<"============================================="<< std::endl;
    std::cout << "\n\n" << std::endl;
}

void Enemy::RandomizeStats()
{
     race = (rand() % 5 == 0) ? "Human" : (rand() % 4 == 0) ? "Elf" : (rand() % 3 == 0) ? "Dwarf" : (rand() % 2 == 0) ? "Orc" : "Goblin";        // Random race
    
}

void Enemy::EquipWeapon(Weapon* w)
{
if (equipped_weapon) {
        equipped_weapon->Reset(); 
    }
    equipped_weapon = w;
    if (equipped_weapon) {
        equipped_weapon->Use(); 
         GetTotalAttack();
        GetTotalDefense();  
    }
}

void Enemy::EquipArmor(Armory* a)
{
if (equipped_armor) {
        equipped_armor->Reset(); 
    }
    equipped_armor = a;
    if (equipped_armor) {
        equipped_armor->Use(); 
        GetTotalAttack();
        GetTotalDefense();  
    }
}


Weapon* Character::GetEquippedWeapon() const { return equipped_weapon; } 
Armory* Character::GetEquippedArmor() const { return equipped_armor; } 
int Character::GetTotalAttack() const { return strength + (equipped_weapon ? equipped_weapon->GetAttack() : 0); } 
int Character::GetTotalDefense() const { return defense + (equipped_armor ? equipped_armor->GetDefense() : 0); }


void Enemy::ApplyPotionEffect(int effectType, int potency)
{

}

void Enemy::ProcessEffects()
{

}

void Enemy::AddEffect(int type, int potency, bool debuff = false)
{

}

void Enemy::Usage()
{

}

