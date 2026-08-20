#include "Header.h"
#include <map> 
//File for artifacts

static std::string EffectTypeToString(int type) {
    switch (type) {
        case 0: return "Health"; break;
        case 1: return "Defense";break;
        case 2: return "Agility";break;
        case 3: return "Intelligence";break;
        case 4: return "Gold";break;
        case 5: return "Strength";break;
        default: return "Unknown";break;
    }
}

 static std::map<std::string, std::pair<int, int>>& GetWeaponArtifactDB() {                 //For artifacts list
    static std::map<std::string, std::pair<int, int>> ar;
    if (ar.empty()) {
        ar = {//Power + cost
            {"Midas arm", {10, 10}},
            {"Javelin of Backbiting", {10, 10}},
            {"Wand of Orcus", {10, 10}},
            {"Windvane", {10, 10}},
            {"Spear of Heliod", {10, 10}},
            {"Ephixis", {10, 10}},
            {"Two-Birds Sling", {10, 10}},
            {"Axe of the Dwarvish Lords", {10, 10}},
            {"Gambler’s Blade", {10, 10}},
            {"Orcsplitter ", {10, 10}},
            {"Sword of Sharpness", {10, 10}},
            {"Vorpal Sword", {10, 10}},
            {"Acheron Blade", {10, 10}},
            {"Luck Blade", {10, 10}},
            {"Sword of Life Stealing", {10, 10}},
            {"Mind Lash", {10, 10}},
            {"Dragon Slayer", {10, 10}}};
    }
    return ar;
}

std::string  Artifact::RandomizeArtifact()                                                            
{ 
    auto& ar = GetWeaponArtifactDB();
    
    std::string weapon_ar[] = {"Midas arm", "Javelin of Backbiting", "Wand of Orcus", 
                               "Windvane", "Spear of Heliod", "Ephixis", 
                               "Two-Birds Sling", "Axe of the Dwarvish Lords", 
                               "Gambler's Blade", "Orcsplitter ", "Sword of Sharpness", 
                               "Vorpal Sword", "Acheron Blade", "Luck Blade", 
                               "Sword of Life Stealing", "Mind Lash", "Dragon Slayer"};

    std::string chosen_name; 
    chosen_name = weapon_ar[rand() % 17];
    
    // Effect mapping: artifact_name -> {effectType, potency}
    static std::map<std::string, std::pair<int, int>> artifactEffects = {
        {"Midas arm", {GOLD, 500}},                    // +500 gold
        {"Javelin of Backbiting", {STRENGTH, 50}},     // +50 strength
        {"Wand of Orcus", {INTELLIGENCE, 40}},         // +40 intelligence
        {"Windvane", {AGILITY, 45}},                   // +45 agility
        {"Spear of Heliod", {STRENGTH, 35}},           // +35 strength
        {"Ephixis", {DEFENSE, 30}},                    // +30 defense
        {"Two-Birds Sling", {AGILITY, 25}},            // +25 agility
        {"Axe of the Dwarvish Lords", {STRENGTH, 60}}, // +60 strength
        {"Gambler's Blade", {GOLD, 1000}},             // +1000 gold (risk/reward)
        {"Orcsplitter ", {DEFENSE, 40}},               // +40 defense
        {"Sword of Sharpness", {STRENGTH, 45}},        // +45 strength
        {"Vorpal Sword", {STRENGTH, 55}},              // +55 strength
        {"Acheron Blade", {INTELLIGENCE, 35}},         // +35 intelligence
        {"Luck Blade", {GOLD, 750}},                   // +750 gold
        {"Sword of Life Stealing", {HEALTH, 100}},     // +100 health
        {"Mind Lash", {INTELLIGENCE, 50}},             // +50 intelligence
        {"Dragon Slayer", {STRENGTH, 70}}              // +70 strength
    };

    auto it = ar.find(chosen_name);
    if (it != ar.end()) {
        power = it->second.first;
        value = it->second.second;
    }  
    
    auto ef_it = artifactEffects.find(chosen_name);
    if (ef_it != artifactEffects.end()) {
        effectType = ef_it->second.first;
        power = ef_it->second.second;
    }
    
    name = chosen_name;
    return name;
}

void Artifact::ShowInfo() const 
{
    std::cout << "Artifact: " << name << std::endl;
    std::cout << "Type: " << GetType() << std::endl;
    std::cout << "Power: " << power << std::endl;
    std::cout << "Value: " << value << " gold" << std::endl;
    std::cout << "Effect: ";
    
    switch (effectType) {
        case 0: std::cout << "Health +" << power; break;
        case 1: std::cout << "Defense +" << power; break;
        case 2: std::cout << "Agility +" << power; break;
        case 3: std::cout << "Intelligence +" << power; break;
        case 4: std::cout << "Gold +" << power; break;
        case 5: std::cout << "Strength +" << power; break;
    }
    std::cout << std::endl;
}


void Artifact::Use() 
{
    if (!owner_p) {
        std::cout << "Artifact " << name << " has no owner!" << std::endl;
        return;
    }
    
    std::cout << "Using artifact: " << name << "!" << std::endl;
    owner_p->ApplyPotionEffect(effectType, power);
    std::cout << "Effect applied!" << std::endl;
}


void Artifact::Reset() 
{
    isEquipped = false;
    std::cout << name << " unequipped." << std::endl;
}