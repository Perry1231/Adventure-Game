#include "Header.h"

void Chest::ChestCreate(ChestType type, Character& hero)
{
    chestType = type;
    capacity = 5; // Default capacity
    isOpen = false;
    
    // TODO: Add items based on chest type
    std::cout << "Chest created with type: " << type << "\n";
}

void Chest::RandomizeChest(Character& hero)
{
    int randType = rand() % 4;
    ChestType types[] = {COMMON, RARE, EPIC, LEGENDARY};
    chestType = types[randType];
    
    // TODO: Add items based on chest type
    capacity = 5 + randType; // Higher rarity = more capacity
    isOpen = false;
    
    std::cout << "Chest randomized with type: " << chestType << "\n";
}

void Chest::Open(Character* target)
{
    if (IsOpen()) {
        std::cout << "Chest is already open!\n";
        return;
    }
    
    isOpen = true;
    std::cout << "Chest opened!\n";
    
    chest.ShowInfo();
    
}

void Chest::Close()
{
    isOpen = false;
    std::cout << "Chest closed!\n";
}

void Chest::ShowInfo() const
{
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                  CHEST INFORMATION               │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│ Type: " << chestType << "\n";
    std::cout << "│ Capacity: " << capacity << "\n";
    std::cout << "│ Status: " << (isOpen ? "Open" : "Closed") << "\n";
    std::cout << "└───────────────────────────────────────────────────┘\n";
}

void Chest::ShowItems(const Inventory& items) const
{
    constexpr const char* CYAN = "\033[36m";
    constexpr const char* YELLOW = "\033[33m";
    constexpr const char* GRAY = "\033[90m";
    constexpr const char* RED = "\033[31m";
    constexpr const char* RESET = "\033[0m";
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                    CHEST ITEMS                   │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    if (capacity == 0)
    {
        std::cout << RED << "\n[!] Chest is completely empty.\n" << RESET;
        return;
    }

    for (int i = 0; i < capacity; ++i)
    {
        std::cout << YELLOW << "#" << (i + 1) << " " << RESET
                  << items[i]->GetName() 
                  << GRAY << " [ID: " << items[i]->GetItemId() 
                  << " | Type: " << items[i]->GetType() << "]" << RESET << "\n";

  
        items[i]->ShowInfo();

        if (i < capacity - 1) {
            std::cout << GRAY << "--------------------------------------------------\n" << RESET;
        }
    }
    
    std::cout << "└───────────────────────────────────────────────────┘\n";
}

