#include "Header.h"
#include <map>
#include <string>

static std::map<std::string, std::tuple<int, int, int>>& GetPotionDB() {                 //For spell list
    static std::map<std::string, std::tuple<int, int, int>> pt;
    if (pt.empty()) {
        pt = {
        {"Health Potion", {0, 20, 0}},
        {"Strength Potion", {1, 5, 3}},
        {"Poison Potion", {0, -10, 0}},
        {"Weakness Potion", {1, -5, 3}},
        {"Slowness Potion", {2, -1, 3}},
        {"Agility Potion", {2, 5, 3}}};
    }
    return pt;
}



void Potion::ShowInfo() const                                                                                                  //Count is weapon broken
{
std::cout << "\n===Your potion characteristic=== "<< std::endl;
std::cout << "Name : " << name_p << "\nEffect Type : " << effectType << "\nPotency : " 
            << potency << std::endl;
}


void Potion::Use()
{
    isEquipped_p = true;
//continue
}

void Potion::Reset()
{
    isEquipped_p = false;
        std::cout << name_p << " equipped! Attack -" << potency << std::endl;
}

void Potion::ApplyEffect(Character* character) {
    isEquipped_p = true;
    if (!character) {
        std::cout << "No character to apply the potion effect!" << std::endl;
        return;
    }
    else
{
     }
    character->ApplyPotionEffect(GetEffectType(), GetPotency(), GetDuration());
    std::cout << "Used " << GetName() << "." << std::endl;
}
