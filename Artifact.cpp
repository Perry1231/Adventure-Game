#include "Header.h"
#include <map>

static std::string EffectTypeToString(int type) {
    switch (type) {
        case HEALTH: return "Health"; break;
        case DEFENSE: return "Defense"; break;
        case AGILITY: return "Agility"; break;
        case INTELLIGENCE: return "Intelligence"; break;
        case GOLD: return "Gold"; break;
        case STRENGTH: return "Strength"; break;
        default: return "Unknown"; break;
    }
}

static std::map<std::string, std::pair<int, int>>& GetWeaponArtifactDB() {
    static std::map<std::string, std::pair<int, int>> ar;
    if (ar.empty()) {
        ar = {
            {"Midas arm", {10, 10}},
            {"Javelin of Backbiting", {10, 10}},
            {"Wand of Orcus", {10, 10}},
            {"Windvane", {10, 10}},
            {"Spear of Heliod", {10, 10}},
            {"Ephixis", {10, 10}},
            {"Two-Birds Sling", {10, 10}},
            {"Axe of the Dwarvish Lords", {10, 10}},
            {"Gambler's Blade", {10, 10}},
            {"Orcsplitter ", {10, 10}},
            {"Sword of Sharpness", {10, 10}},
            {"Vorpal Sword", {10, 10}},
            {"Acheron Blade", {10, 10}},
            {"Luck Blade", {10, 10}},
            {"Sword of Life Stealing", {10, 10}},
            {"Mind Lash", {10, 10}},
            {"Dragon Slayer", {10, 10}}
        };
    }
    return ar;
}

//Name + Effect -> 
static int GetArtifactEffectType(const std::string& name) {
    static std::map<std::string, int> effects = {
        {"Midas arm", GOLD},
        {"Javelin of Backbiting", STRENGTH},
        {"Wand of Orcus", INTELLIGENCE},
        {"Windvane", AGILITY},
        {"Spear of Heliod", STRENGTH},
        {"Ephixis", DEFENSE},
        {"Two-Birds Sling", AGILITY},
        {"Axe of the Dwarvish Lords", STRENGTH},
        {"Gambler's Blade", GOLD},
        {"Orcsplitter ", DEFENSE},
        {"Sword of Sharpness", STRENGTH},
        {"Vorpal Sword", STRENGTH},
        {"Acheron Blade", INTELLIGENCE},
        {"Luck Blade", GOLD},
        {"Sword of Life Stealing", HEALTH},
        {"Mind Lash", INTELLIGENCE},
        {"Dragon Slayer", STRENGTH}
    };
    auto it = effects.find(name);
    return (it != effects.end()) ? it->second : HEALTH;
}

std::string Artifact::RandomizeArtifact() {
    auto& ar = GetWeaponArtifactDB();

    std::string weapon_ar[] = {
        "Midas arm", "Javelin of Backbiting", "Wand of Orcus", "Windvane",
        "Spear of Heliod", "Ephixis", "Two-Birds Sling", "Axe of the Dwarvish Lords",
        "Gambler's Blade", "Orcsplitter ", "Sword of Sharpness", "Vorpal Sword",
        "Acheron Blade", "Luck Blade", "Sword of Life Stealing", "Mind Lash", "Dragon Slayer"
    };

    std::string chosen_name;
    chosen_name = weapon_ar[rand() % 17];
    auto it = ar.find(chosen_name);
    if (it != ar.end()) {
        power = it->second.first;
        value = it->second.second;
    }

    effectType = GetArtifactEffectType(chosen_name);

    name = chosen_name;
    return name;
}

void Artifact::ShowInfo() const {
    std::cout << "Artifact: " << name << std::endl;
    std::cout << "Type: " << GetType() << std::endl;
    std::cout << "Power: " << power << std::endl;
    std::cout << "Value: " << value << " gold" << std::endl;
    std::cout << "Effect: ";
    std::cout << EffectTypeToString(effectType) << " +" << power;
    std::cout << std::endl;
}

void Artifact::Use() {
    if (!owner_p) {
        std::cout << "Artifact " << name << " has no owner!" << std::endl;
        return;
    }

    std::cout << "Using artifact: " << name << "!" << std::endl;
    owner_p->ApplyPotionEffect(effectType, power);
    std::cout << "Effect applied!" << std::endl;
}

void Artifact::Reset() {
    isEquipped = false;
    owner_p = nullptr;
    std::cout << name << " unequipped." << std::endl;
}