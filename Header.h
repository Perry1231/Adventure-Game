//підключ всі функції та класи з інших файлів

#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Character
{
    private :
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

void HelpFunction() ;

#endif