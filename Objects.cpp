#include <iostream>
#include "Header.h"
#include <map> 
//Here will be functions for objects db and their abillities

struct ObjectStructBasic
{
    std::string name_object;
    std::string describtion_object;
    int gold_object;
    int rarityType_object;
    int health_object;
    int strength_object;
    int agility_object;
    int intelligence_object;
    int defense_object;
    
};

static std::map<std::string, ObjectStructBasic>& GetObjectDB() {
    static std::map<std::string, ObjectStructBasic> gtodb;        //name of get object db
    if (gtodb.empty()) {
        gtodb = 
        {
            
            {"Amulet of Strength", {"Amulet of Strength", "A powerful amulet that enhances strength.", 10, 100, 10, 10, 10, 10}}, 
            {"Ring of Agility", {"Ring of Agility", "A ring that increases agility.", 5, 50, 5, 5, 5, 5}}, 
            {"Cloak of Invisibility", {"Cloak of Invisibility", "A cloak that makes the wearer invisible.", 0, 200, 0, 0, 0, 0}}, 
            {"Boots of Speed", {"Boots of Speed", "Boots that increase movement speed.", 0, 75, 0, 0, 0, 0}}, 
            {"Staff of Wisdom", {"Staff of Wisdom", "A staff that enhances wisdom.", 15, 150, 15, 15, 15, 15}}, 
            {"Sword of Flames", {"Sword of Flames", "A sword that deals fire damage.", 20, 250, 20, 20, 20, 20}},
            {"Shield of Protection", {"Shield of Protection", "A shield that provides protection.", 0, 125, 0, 0, 0, 0}}, 
            {"Helmet of Insight", {"Helmet of Insight", "A helmet that grants insight.", 0, 80, 0, 0, 0, 0}}, 
            {"Gloves of Dexterity", {"Gloves of Dexterity", "Gloves that enhance dexterity.", 0, 60, 0, 0, 0, 0}}, 
            {"Belt of Vitality", {"Belt of Vitality", "A belt that boosts vitality.", 0, 90, 0, 0, 0, 0}}



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

