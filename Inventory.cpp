#include "Header.h"

//====================================================Inventory_functions=======================================================================================================

int MyInventory::ResizeInventoryBig()
{
   int new_capacity = capacity + 1;
    Item** temp = new Item*[new_capacity];
    for (int i = 0; i < count; i++)
        temp[i] = items[i];
    delete[] items;
    items = temp;
    capacity = new_capacity;
    return 0;
}


void MyInventory::DisplayInventory() const                                            //Shows items in inventory
{
     if (count == 0)
    {
        std::cout << "\nInventory is empty!" << std::endl;
        return;
    }

    std::cout << "\n\n=== Your Inventory ================" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "\nID: " << items[i]->GetItemId() << "\nName: " <<items[i]->GetName() << " (Type: " << items[i]->GetType() << ")" << std::endl;
        items[i]->ShowInfo();
    }
    std::cout << "\n==================================" << std::endl;
}



int MyInventory::AddItem(Item* item) {
    if (count >= capacity) ResizeInventoryBig();
    item->SetItemId(id);   
    items[count++] = item;
    std::cout << "Added item with ID: " << id << std::endl;
    id++;
    return 0;
}



int MyInventory::DelItem(int itemId) {
    for (int i = 0; i < count; i++) {
        if (items[i]->GetItemId() == itemId) {
            delete items[i];
            for (int j = i; j < count - 1; j++) {
                items[j] = items[j + 1];
            }
            count--;
            std::cout << "Item with ID " << itemId << " deleted." << std::endl;
            return 0;
        }
    }
    std::cout << "Item with ID " << itemId << " not found!" << std::endl;
    return -1;
}

void MyInventory::InventoryFunctions()                                                       //For displaying functions , like : show items , delete items; (MENU)
{
    while(true)
    {
    int choice =0;
    std::cout << "\n\n" << std::endl;
    std::cout <<"==================Inventory================="<< std::endl;
    std::cout << "Size: " << count << std::endl;
    std::cout <<"=================Functions=================="<< std::endl;
    std::cout <<"Disaply all items in : 1 \nDelete item from id  : 2 \nEquip item from id   : 3 " << std::endl;
    std::cout << "Exit: 0" << std::endl;
    std::cout <<"============================================="<< std::endl;
                
    std::cout << "\n\n" << std::endl;
    while (true)
    {//Show inventory
        std::cout << "Choice: ";
        std::cin >>choice;
        if (choice == 1) DisplayInventory();

        else if (choice == 2)
        {//Display all items
            int choice_2;
            std::cout << "Eneter id of item to delete : " ;
            std::cin>> choice_2;
            DelItem(choice_2);
        }

        else if (choice == 3)         
{//Equip item
    int itemId;
    std::cout << "Enter item ID to equip: ";
    std::cin >> itemId;
    
    //Search items in inventory
    for (int i = 0; i < count; i++)
    {
        if (items[i]->GetItemId() == itemId)
        {
            if (items[i]->GetType() == "Weapon")
            {
                owner->EquipWeapon(dynamic_cast<Weapon*>(items[i]));
            }
            else if (items[i]->GetType() == "Armor")
            {
                owner->EquipArmor(dynamic_cast<Armory*>(items[i]));
            }
            else
            {
                std::cout << "This item cannot be equipped!" << std::endl;
            }
            continue;
        }
    }
    
} //Else if choice not good
        else if (choice == 0) continue;
        else std::cout << "Invalid choice!" << std::endl;   
    }
    }
}



//==============================================For_other_characters================================================================
int Take()                                         //Take from another character
{
return 0;

}

int AllTake()                                       //Take all from another character  
{
return 0;

}


