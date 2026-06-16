#include "Header.h"
#include <iostream>
#include <string>
#include <cstdlib>

Character::~Character() 
{
    std::cout << "\n\nCharacter destructor called.  In character.cpp" << std::endl;
}





//=============================Main functions=============================
void Character::DisplayStats() 
{
    std::cout << "\n\n" << std::endl;
    std::cout <<"============================================="<< std::endl;
    std::cout << "Character Stats:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Race: " << race << std::endl;
    std::cout << "Profession: " << profession << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout <<"=================Self Stats=================="<< std::endl;
    std::cout << "Strength: " << strength << std::endl;
    std::cout << "Agility: " << agility << std::endl;
    std::cout << "Intelligence: " << intelligence << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Gold: " << gold << std::endl;
    std::cout <<"============================================="<< std::endl;
    std::cout << "\n\n" << std::endl;
}


void Character::RandomizeStats()
{
    race = (rand() % 5 == 0) ? "Human" : (rand() % 4 == 0) ? "Elf" : (rand() % 3 == 0) ? "Dwarf" : (rand() % 2 == 0) ? "Orc" : "Goblin";        // Random race
    

//=============================Professions base===============================================
std::string professions_h[] = {"Warrior", "Mage", "Rogue", "Peasant"}; //For_Human
std::string professions_e[] = { "Archer", "Druid", "Ranger"}; //For_Elf
std::string professions_d[] = {"Blacksmith", "Miner", "Berserker"}; //For_Dwarf
std::string professions_o[] = {"Shaman", "Warlord", "Berserker"}; //For_Orc
std::string professions_g[] = {"Thief", "Assassin", "Scavenger"}; //For_Goblin

//=============================Randomize stats based on profession=============================
   if(race == "Human") profession = professions_h[rand() % 4];
   else if (race == "Elf") profession = professions_e[rand() % 3];
   else if (race == "Dwarf") profession = professions_d[rand() % 3];
   else if (race == "Orc") profession = professions_o[rand() % 3];
   else if (race == "Goblin") profession = professions_g[rand() % 3];
    
//=============================Stats randomizer================================================
if(profession == "Warrior") {
    health = 120;
    level = 1;
    description = "A strong and resilient fighter, skilled in melee combat.";
}
else if (profession == "Mage") {
    health = 70;
    level = 1;
    description = "A master of arcane arts, capable of casting powerful spells.";
}
else if (profession == "Rogue") {
    health = 80;
    level = 1;
    description = "A stealthy and agile character, excelling in sneaking and critical strikes.";
}
else if (profession == "Peasant") {
    health = 70;
    level = 1;
    description = "A simple villager with basic survival skills, but untapped potential.";
}
else if (profession == "Archer") {
    health = 100;
    level = 1;
    description = "A skilled marksman, proficient with bows and ranged attacks.";
}
else if (profession == "Druid") {
    health = 110;
    level = 1;
    description = "A nature-based spellcaster, able to heal allies and summon creatures.";
}
else if (profession == "Ranger") {
    health = 100;
    level = 1;
    description = "A versatile hunter, adept at tracking and surviving in the wilderness.";
}
else if (profession == "Blacksmith") {
    health = 120;
    level = 1;
    description = "A master craftsman, able to forge powerful weapons and armor.";
}
else if (profession == "Miner") {
    health = 140;
    level = 1;
    description = "A hardy worker, skilled in extracting valuable resources from the earth.";
}
else if (profession == "Berserker") {
    health = 130;
    level = 1;
    description = "A fierce warrior who thrives in the heat of battle, gaining strength as they fight.";
}
else if (profession == "Shaman") {
    health = 120;
    level = 1;
    description = "A spiritual guide, able to commune with spirits and harness elemental powers.";
}
else if (profession == "Warlord") {
    health = 140;
    level = 1;
    description = "A strategic leader, commanding troops and inspiring allies on the battlefield.";
}
else if (profession == "Thief") {
    health = 80;
    level = 1;
    description = "A cunning and resourceful character, skilled in stealing and deception.";
}
else if (profession == "Assassin") {
    health = 90;
    level = 1;
    description = "A deadly and silent killer, specializing in eliminating targets quickly and efficiently.";
}
else if (profession == "Scavenger") {
    health = 100;
    level = 1;
    description = "A resourceful survivor, adept at finding valuable items and making the most of limited resources.";
}

//=============================Name randomizer=================================================

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
//=============================Age randomizer=================================================              &&&&&&&&&&&&&&&&&&&
    age = 18 + rand() % 83; // Random age between 18 and 100  



//=============================Stats randomizer based on profession=============================
    if(profession == "Warrior") {
        strength = 25+ rand() % 11; // Random strength between 25 and 35
        agility = 15 + rand() % 11; // Random agility between 15 and 25
        intelligence = 5 + rand() % 6; // Random intelligence between 5 and 10
        defense = 20 + rand() %11; // Random defense between 20 and 28
        gold = 40 + rand() % 21; // Random gold between 40 and 60
    }
    else if (profession == "Mage") {
        strength = 15 + rand() % 6; // Random strength between 15 and 20
        agility = 10 + rand() % 6; // Random agility between 10 and 15
        intelligence =20 + rand() %11; // Random intelligence between 20 and 30
        defense = 8 + rand() % 7; // Random defense between 8 and 15
        gold = 25 + rand() % 21; // Random gold between 25 and 45
    }
    else if (profession == "Rogue") {
        strength = 10 + rand() % 11; // Random strength between 10 and 15
        agility = 15 + rand() % 6; // Random agility between 15 and 20
        intelligence = 10 + rand() % 6; // Random intelligence between 10 and 15
        defense = 10 + rand() % 6; // Random defense between 10 and 15
        gold = 80 + rand() % 21; // Random gold between 80 and 100
    }
    else if (profession == "Peasant") {
        strength = 5 + rand() % 6; // Random strength between 5 and 10
        agility = 8 + rand() % 8; // Random agility between 8 and 15
        intelligence = 8 + rand() % 8; // Random intelligence between 8 and 15
        defense = 5 + rand() % 6; // Random defense between 5 and 10
        gold = 20 + rand() % 11; // Random gold between 20 and 30
    }
    else if (profession == "Archer") {
        strength = 15 + rand() % 11; // Random strength between 15 and 25
        agility = 20 + rand() % 11; // Random agility between 20 and 30
        intelligence = 20 + rand() % 6; // Random intelligence between 20 and 25
        defense = 10 + rand() % 6; // Random defense between 10 and 15
        gold = 50 + rand() % 21; // Random gold between 50 and 70
    }
    else if (profession == "Druid") {
        strength = 5 + rand() % 6; // Random strength between 5 and 10
        agility = 5 + rand() % 5; // Random agility between 5 and 10
        intelligence = 30 + rand() %11; // Random intelligence between 30 and 40
        defense = 12 + rand() % 4; // Random defense between 12 and 15
        gold = 50 + rand() % 21; // Random gold between 50 and 70
    }

    else if (profession == "Ranger") {
        strength = rand() % 15 + 10; // Random strength between 10 and 25
        agility = 20 + rand() % 11; // Random agility between 20 and 30
        intelligence = 15 + rand() % 11; // Random intelligence between 15 and 25
        defense = 15 + rand() % 11; // Random defense between 15 and 25
        gold = 50 + rand() % 21; // Random gold between 50 and 70
    }
    else if (profession == "Blacksmith") {
        strength = 15 + rand() % 11; // Random strength between 15 and 25
        agility = 8 + rand() % 6; // Random agility between 8 and 14
        intelligence = 20 + rand() % 6; // Random intelligence between 20 and 25
        defense = 10 + rand() % 11; // Random defense between 10 and 20
        gold =50 + rand() % 21; // Random gold between 50 and 70
    }
    else if (profession == "Miner") {
        strength = 20 + rand() % 11; // Random strength between 20 and 30
        agility = 5 + rand() % 6; // Random agility between 5 and 10
        intelligence = 15 + rand() % 6; // Random intelligence between 10 and 15
        defense = 15 + rand() % 11; // Random defense between 15 and 25
        gold = 70 + rand() % 21; // Random gold between 70 and 90
    }
    else if (profession == "Berserker") {
        strength = 20 + rand() % 11; // Increased strength for Berserker
        agility = 10 + rand() % 6; // Balanced agility
        intelligence = 5 + rand() % 11; // Lower intelligence for Berserker
        defense = 15 + rand() % 11; // Increased defense for Berserker
        gold = 30 + rand() % 21; // Starting gold for Berserker
    }
    else if (profession == "Shaman") {
        strength = 10 + rand() % 6; // Random strength between 10 and 15
        agility = 8 + rand() % 7; // Random agility between 8 and 15
        intelligence = 25 + rand() % 6; // Random intelligence between 25 and 30
        defense = 12 + rand() % 4; // Random defense between 12 and 15
        gold = 50 + rand() % 21; // Random gold between 50 and 70
    }
    else if (profession == "Warlord") {
        strength = 20 + rand() % 11; // Random strength between 20 and 30
        agility = 15 + rand() % 6; // Random agility between 15 and 20
        intelligence = 15 + rand() % 11; // Random intelligence between 15 and 20
        defense = 15 + rand() % 11; // Random defense between 15 and 25
        gold = 20 + rand() % 21; // Random gold between 20 and 40
    }
    else if (profession == "Thief") {
        strength = 10+ rand() % 6; // Random strength between 10 and 15
        agility = 15 + rand() % 11; // Random agility between 15 and 25
        intelligence = 10 + rand() % 6; // Random intelligence between 10 and 15
        defense = 8 + rand() % 8; // Random defense between 8 and 15
        gold = 80 + rand() % 21; // Random gold between 80 and 100
    }
    else if (profession == "Assassin") {
        strength = 15 + rand() % 6; // Random strength between 12 and 20
        agility = 18 + rand() % 7; // Random agility between 18 and 24
        intelligence = 8 + rand() % 6; // Random intelligence between 8 and 13
        defense = 15 + rand() % 6; // Random defense between 10 and 15
        gold = 70 + rand() % 21; // Random gold between 70 and 90
        age = 18 + rand() % 27; // Random age between 18 and 45 for Assassin
    }
    else if (profession == "Scavenger") {
        strength = 10 + rand() % 6; // Random strength between 10 and 15
        agility = 12 + rand() % 6; // Random agility between 12 and 17
        intelligence = 8 + rand() % 6; // Random intelligence between 8 and 13
        defense = 10 + rand() % 6; // Random defense between 10 and 15
        gold = 80 + rand() % 21; // Random gold between 80 and 100
    }

    //=============================End of randomization=============================
}

void Usage(Weapon *weapon)
{
    weapon -> Use();
}

void GetProfession(Character *profession)
{
    return profession;
}
