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
            
            {"Amulet of Strength", {"Amulet of Strength", "A powerful amulet that enhances strength.", 50, 3, 10, 10, 10, 10}}, 
            {"Ring of Agility", {"Ring of Agility", "A ring that increases agility.", 70, 3, 5, 5, 5, 5}}, 
            {"Cloak of Invisibility", {"Cloak of Invisibility", "A cloak that makes the wearer invisible.", 100, 3, 0, 0, 0, 0}}, 
            {"Boots of Speed", {"Boots of Speed", "Boots that increase movement speed.", 50, 3, 0, 0, 0, 0}}, 
            {"Staff of Wisdom", {"Staff of Wisdom", "A staff that enhances wisdom.", 200, 3, 15, 15, 15, 15}}, 
            {"Sword of Flames", {"Sword of Flames", "A sword that deals fire damage.", 50, 2, 20, 20, 20, 20}},
            {"Shield of Protection", {"Shield of Protection", "A shield that provides protection.", 40, 2, 0, 0, 0, 0}}, 
            {"Helmet of Insight", {"Helmet of Insight", "A helmet that grants insight.", 40, 3, 0, 0, 0, 0}}, 
            {"Gloves of Dexterity", {"Gloves of Dexterity", "Gloves that enhance dexterity.", 50, 3, 0, 0, 0, 0}}, 
            {"Belt of Vitality", {"Belt of Vitality", "A belt that boosts vitality.", 40, 3, 0, 0, 0, 0}},

            //name + description + gold + rarity + health + strength + agility + intelligence + defense
            {"Apple", {"Basic apple", "A simple apple that restores health.", 1, 1, 5, 0, 0, 0}},
            {"Bread", {"Basic bread", "A simple bread.", 2, 1, 2, 0, 0, 0}},
            {"Banana", {"Simple banana", "A simple banana from warm counties", 3, 1, 4, 0, 0, 0}},
            {"Orrange", {"Simple orange", "A simple orange from warm counties", 4, 1, 6, 0, 0, 0}},
            {"Sausage", {"Simple sausage", "A simple sausage.", 5, 1, 3, 0, 0, 0}},
            {"Meat of deer", {"Meat of deer", "A simple meat from a deer.", 10, 1, 10, 0, 0, 0}},
            {"Meat of boar", {"Meat of boar", "A simple meat from a boar.", 15, 1, 15, 0, 0, 0}}
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

