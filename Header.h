//підключ всі функції та класи з інших файлів

#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>

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



    public :
//Default constructor
Character() : health(100), name ("Hero"), age(20), race("Human"), profession("Adventurer"), level(1), description("A brave adventurer ready to explore the world.") {}
//Parameterized constructor
Character(int health_, std::string name_, int age_, std::string race_, std::string profession_, int level_, std::string description_) : health(health_), name(name_), age(age_), race(race_), profession(profession_), level(level_), description(description_) {}
    

Character();
~Character();

void DisplayStats();
void RandomizeStats();

};




#endif