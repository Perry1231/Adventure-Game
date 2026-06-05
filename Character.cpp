// тту буде реалізація героя та його характеристик, таких як здоров'я, сила атаки, захист тощо
#include "Header.h"
#include <iostream>
#include <string>
#include <cstdlib>

Character::Character() : health(100), name ("Hero"), age(20), race("Human"), profession("Adventurer"), level(1), description("A brave adventurer ready to explore the world.")
{
    std::cout << "\n\nCharacter created: " << name << std::endl;
}

Character::~Character() 
{
    std::cout << "\n\nCharacter destructor called." << std::endl;
}





//=============================Main functions=============================
void Character::DisplayStats() 
{
    std::cout <<"====================================="<< std::endl;
    std::cout << "\n\nCharacter Stats:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Race: " << race << std::endl;
    std::cout << "Profession: " << profession << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout <<"====================================="<< std::endl;
}


void Character::RandomizeStats()
{
    race = (rand() % 5 == 0) ? "Human" : (rand() % 4 == 0) ? "Elf" : (rand() % 3 == 0) ? "Dwarf" : (rand() % 2 == 0) ? "Orc" : "Goblin";        // Random race
    
    //=============================Randomize stats based on profession=============================
    if (profession == "Warrior") {
        age = rand() % 31 + 20; // Random age between 20 and 50
        health = 120;
        level = 1;
        description = "A strong and resilient fighter, excelling in melee combat.";
    } else if (profession == "Mage") {
        age =  40 + rand() % 51; // Random age between 40 and 90
        health = 80;
        level = 1;
        description = "A master of arcane arts, wielding powerful spells to defeat enemies.";
    } else if (profession == "Rogue") {         //Злodій
        age = 16 + rand() % 25; // Random age between 16 and 40
        health = 100;
        level = 1;
        description = "A stealthy and agile character, skilled in sneaking and critical strikes.";
    } else if (profession == "Cleric") {       //Священник
        age = 40 + rand() % 31; // Random age between 40 and 70
        health = 120;
        level = 1;
        description = "A holy warrior, capable of healing allies and smiting foes with divine power.";
    } else {
        age = 18 + rand() % 31; // Random age between 20 and 50
        health = 90;
        level = 1;
        description = "A versatile adventurer, ready to take on any challenge that comes their way.";
    }
//=============================Name generation=============================


std::string firstNames_h[] = {"Arin", "Bryn", "Cora", "Dain", "Eira", "Finn", "Gwen", "Hale", "Iris", "Jax"};
    std::string lastNames_h[] = {"Stormwind", "Shadowbane", "Ironfist", "Silverleaf", "Darkwood", "Brightblade", "Stoneheart", "Moonshadow", "Fireforge", "Duskwhisper"};
   
   std::string firstNames_e[] = {"Elara", "Thalion", "Lirael", "Eldrin", "Sylvara", "Faelar", "Aeris", "Galadriel", "Riven", "Nimriel"};
   std::string lastNames_e[] = {"Starweaver", "Moonwhisper", "Sunblade", "Duskbloom", "Silvermoon", "Shadowdancer", "Windrider", "Nightshade", "Frostfall", "Lightbringer"};
    
   std::string firstNames_d[] = {"Thorin", "Balin", "Dwalin", "Gimli", "Oin", "Gloin", "Dori", "Nori", "Ori", "Bifur"};
   std::string lastNames_d[] = {"Ironforge", "Stonehelm", "Goldbeard", "Hammerfall", "Deepdelve", "Anvilmar", "Bronzebeard", "Fireforge", "Stormhammer", "Frostbeard"};
   

    std::string firstNames_o[] = {"Grommash", "Garrosh", "Thrall", "Durotan", "Orgrim", "Kargathia", "Zul'jin", "Kilrogg", "Nazgrel", "Mok'Nathal"};
    std::string lastNames_o[] = {"Hellscream", "Doomhammer", "Shadowmoon", "Warsong", "Blackrock", "Frostwolf", "Bleeding Hollow", "Shattered Hand", "Burning Blade", "Skullcrusher"};

    std::string firstNames_g[] = {"Grimtooth", "Snaggletooth", "Gobblesnort", "Snotgoblin", "Fizzlefink", "Muckwump", "Raggleflap", "Zogmug", "Blightfang", "Wartnose"};
    std::string lastNames_g[] = {"Rotfang", "Snotlicker", "Guttergrin", "Pusface", "Filthsnout", "Mucknose", "Raggleflap", "Zogmug", "Blightfang", "Wartnose"};
  
    if (race == "Human") {
        name = firstNames_h[rand() % 10] + " " + lastNames_h[rand() % 10];
    } 
    else if (race == "Elf") {
        name = firstNames_e[rand() % 10] + " " + lastNames_e[rand() % 10];
    }
    else if (race == "Dwarf") {
        name = firstNames_d[rand() % 10] + " " + lastNames_d[rand() % 10];
    }
    else if (race == "Orc") {
        name = firstNames_o[rand() % 10] + " " + lastNames_o[rand() % 10];
    }
    else if (race == "Goblin") {
        name = firstNames_g[rand() % 10] + " " + lastNames_g[rand() % 10];
    }

      

}