#include <iostream>
#include "Header.h"
#include <map> 
//Here will be functions for objects db and their abillities

static std::map<std::string, std::pair<int, int>>& GetObjectDB() {
    static std::map<std::string, std::pair<int, int>> gtodb;        //name of get object db
    if (gtodb.empty()) {
        gtodb = 
        {
            
            {"Amulet of Strength", {10, 100}}, 
            {"Ring of Agility", {5, 50}}, 
            {"Cloak of Invisibility", {0, 200}}, 
            {"Boots of Speed", {0, 75}}, 
            {"Staff of Wisdom", {15, 150}}, 
            {"Sword of Flames", {20, 250}}, 
            {"Shield of Protection", {0, 125}}, 
            {"Helmet of Insight", {0, 80}}, 
            {"Gloves of Dexterity", {0, 60}}, 
            {"Belt of Vitality", {0, 90}}
        };
    }
}

std::string Object::RandomizeObject()   //Ready or not = 
{
auto&  gtodb = GetObjectDB();
    int randomIndex = rand() % gtodb.size();
    auto it = gtodb.begin();
    std::advance(it, randomIndex);
    return it->first;
}


void Object::CreateObjectConstructor()
{

}




void Object::DisplayObjectStats()
{
std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│              OBJECT CHARACTERISTICS             │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│  Object : " << name_object << "\n";
    std::cout << "│  Description: " << describtion_object << "\n";
    std::cout << "│  Rarity   : " << rarityType_object << "\n";
    std::cout << "│  Value    : " << price_object << " gold\n";
    std::cout << "└───────────────────────────────────────────────────┘\n\n";
}



void Object::ShowInfo() const {
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│              ARTIFACT CHARACTERISTICS             │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│  Artifact : " << name_object << "\n";
    std::cout << "│  Description: " << describtion_object << "\n";
    std::cout << "│  Type     : " << GetType() << "\n";
    std::cout << "│  Value    : " << price_object << " gold\n";
    std::cout << "└───────────────────────────────────────────────────┘\n\n";
}


void Object::Use() {// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    if (!owner_p) {
        std::cout << "│  Artifact " << name_object << " has no owner!\n";
        std::cout << "└───────────────────────────────────────────────────┘\n";
        return;
    }

    std::cout << "│  Using artifact: " << name_object << "!\n";
    std::cout << "└───────────────────────────────────────────────────┘\n";
}

void Object::Reset() {// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│  Resetting artifact: " << name_object << "!\n";
    std::cout << "└───────────────────────────────────────────────────┘\n";
}

int Object::AddObject(MyInventory& inv1, Item* item) {
    return inv1.AddItem(objects[count_object] = dynamic_cast<Object*>(item));  
}


void Object::DeleteObject(MyInventory& inv1, int id) {
    inv1.DelItem(objects[id]->GetItemId());
}

