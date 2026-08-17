#include "Header.h"
#include <map> 
//File for artifacts




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
                                                                  //Special_weapon
std::string weapon_ar[] = {"Midas arm", "Javelin of Backbiting", "Wand of Orcus", "Windvane",  "Spear of Heliod",  "Ephixis",  "Two-Birds Sling",  "Axe of the Dwarvish Lords", 
                           "Gambler's Blade", "Orcsplitter ","Sword of Sharpness", "Vorpal Sword", "Acheron Blade","Luck Blade", "Sword of Life Stealing", "Mind Lash", "Dragon Slayer"}; //For_artifacts

 std::string chosen_name; 
        chosen_name = weapon_ar[rand() % 17];
        auto it = ar.find(chosen_name);
        if (it != ar.end()) {
            power = it->second.first;
            value = it->second.second;
        }  
    name = chosen_name;
    return name;
}


void ShowInfo() 
{

}


void Use() 
{

}


void Reset() 
{

}
