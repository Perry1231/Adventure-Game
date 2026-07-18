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
    std::cout << "Attitude: " << attitude << std::endl;
    std::cout << "Race: " << race << std::endl;
    std::cout << "Profession: " << profession << std::endl;
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
    attitude = 1 + rand() % 2;
    if (attitude == 1) // Bad
    {

    }
    else 
    {

    }
    
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



void Enemy::ApplyPotionEffect(int effectType, int potency)
{
switch (effectType) {
        case 0: // HEALTH
            health += potency;
            std::cout << name << " restored " << potency << " HP!" << std::endl;
            break;
        case 1: // DEFENSE
            defense += potency;
            std::cout << name << " defense increased by " << potency << std::endl;
            break;
        case 2: // GOLD
            gold += potency;
            std::cout << name << " got " << potency << " gold!" << std::endl;
              break;
             case 3: // STRENGTH
        strength += potency;
        std::cout << name << " strength increased by " << potency << std::endl;
        break;
        default:
            std::cout << "Unknown potion effect!" << std::endl;
    }
}


void Enemy::AddEffect(int type, int potency, bool debuff)
{
    ActiveEffect eff;
    eff.type = type;
    eff.potency = potency;
    eff.isDebuff = debuff;
    activeEffects.push_back(eff);
std::cout << name << " gained effect: " << ::GetEffectName(type);

}


void Enemy::ProcessEffects()
{
 for (auto it = activeEffects.begin(); it != activeEffects.end(); ) {
        switch (it->type) {
            case 0: 
                if (it->isDebuff) {
					if (health !=Shealth){
                    health += it->potency;
                    std::cout << name << " takes " << (-it->potency) << " poison damage! (HP: " << health << ")\n";
					}
					else std::cout << name << " is at full health.\n";
                } else {
                    // не afford health regen over time from potion (instant only)
                }
                break;
        case 1: defense += it->potency; break;
        case 2: gold += it->potency; break;
        case 3: strength += it->potency; break;;
        }
    }
}

void Enemy::Usage()
{

}