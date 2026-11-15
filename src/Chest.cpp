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

void Chest::Open(Character* target, Chest& chest, Item* item)
{
    if (IsOpen()) {
        std::cout << "Chest is already open!\n";
        return;
    }
    
    isOpen = true;
    std::cout << "Chest opened!\n";
    
    ShowItems(*target, *target->GetInventory(), chest);
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

void Chest::ShowItems(Character& hero, MyInventory& inv1, Chest& chest) const
{
    constexpr const char* CYAN   = "\033[36m";
    constexpr const char* YELLOW = "\033[33m";
    constexpr const char* GRAY   = "\033[90m";
    constexpr const char* RED    = "\033[31m";
    constexpr const char* RESET  = "\033[0m";

    
    if (items.empty())
    {
        std::cout << RED << "\n[!] Chest is completely empty.\n" << RESET;
        return;
    }

    std::cout << CYAN << "\n================ CHEST ITEMS (" << items.size()
              << " items) ================\n" << RESET;

    for (size_t i = 0; i < items.size(); ++i)
    {
        std::cout << YELLOW << "#" << (i + 1) << " " << RESET
                  << items[i]->GetName()
                  << GRAY << " [ID: " << items[i]->GetItemId()
                  << " | Type: " << items[i]->GetType() << "]" << RESET << "\n";

        items[i]->ShowInfo();

        if (i + 1 < items.size())
            std::cout << GRAY << "--------------------------------------------------\n" << RESET;
    }

    std::cout << CYAN << "====================================================\n\n" << RESET;
    std::cout << "If you want to take an item, press 1 , if you want to close the chest, press 2\n";
    int choice = ChoiceInput_Number();
    if(choice == 1)
    {
        std::cout << "Enter the item number you want to take: ";
        int itemIndex = ChoiceInput_Number() - 1; // Convert to 0-based index
        if (itemIndex >= 0 && itemIndex < (int)items.size())
        {
            std::cout << "You have taken: " << items[itemIndex]->GetName() << "\n";
            
            chest.TakeFromChest(hero, itemIndex, inv1);
        }
        else
        {
            std::cout << "Invalid item number!\n";
        }
    }
    else if(choice == 2)
    {
        chest.Close();
    }
    else
    {
        std::cout << "Invalid choice! Closing chest.\n";
        chest.Close();
    }
}


void Chest::ChestRemoveItem(int index) {
    if (index < 0 || index >= capacity) {
        std::cout << "Invalid item index!\n";
        return;
    }
    items.erase(items.begin() + index);
    capacity--;
    std::cout << "Item removed from chest.\n";
}


void Chest::TakeFromChest(Character& hero, int itemIndex, MyInventory& inv1) {
    if (itemIndex < 0 || itemIndex >= (int)items.size()) {
        std::cout << "Invalid item index!\n";
        return;
    }
    
    Item* item = items[itemIndex];
    if (inv1.AddItem(item)) {
        std::cout << "You took " << item->GetName() << " from the chest.\n";
        ChestRemoveItem(itemIndex);
    } else {
        std::cout << "Your inventory is full! Cannot take the item.\n";
    }
}


