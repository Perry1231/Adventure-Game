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

return 0;
}

int MyInventory::ResizeInventorySma()
{
    capacity--;
    return 0;

}

void MyInventory::DisplayInventory() const                                            //Shows items in inventory
{
     if (count == 0)
    {
        std::cout << "\nInventory is empty!" << std::endl;
        return;
    }

    std::cout << "\n\n=== Your Inventory ===" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "\nID: " << items[i]->GetName() << " (Type: " << items[i]->GetType() << ")" << std::endl;
        items[i]->ShowInfo();
    }
    std::cout << "\n=======================" << std::endl;
}




int MyInventory::AddItem(Item* item)
{
    if (count >= capacity)
        ResizeInventoryBig();

    item->ShowInfo(); 

    items[count++] = item;
    
    return 0;
}



int MyInventory::DelItem(int id)
{
    if (id < 0 || id >= count)
    {
        std::cout << "Invalid ID!" << std::endl;
        return -1;
    }
    delete items[id];

    for (int i = id; i < count - 1; i++)
        items[i] = items[i + 1];

    count--;
    std::cout << "Item deleted." << std::endl;
    return 0;
}


void MyInventory::InventoryFunctions()                                                       //For displaying functions , like : show items , delete items; (MENU)
{
    int choice =0;
    std::cout << "\n\n" << std::endl;
    std::cout <<"==================Inventory================="<< std::endl;
    std::cout << "Size: " << count << std::endl;
    std::cout <<"=================Functions=================="<< std::endl;
    std::cout <<"Disaply all items in : 1 \nDelete item from id : 2" << std::endl;
    std::cout << "Exit: 0" << std::endl;
    std::cout <<"============================================="<< std::endl;
    std::cout << "\n\n" << std::endl;
    while (true)
    {
        std::cin >> choice;
        if (choice == 1) DisplayInventory();
        else if (choice == 2)
        {
            int choice_2;
            std::cout << "Eneter id of item to delete : " ;
            std::cin>> choice_2;
            DelItem(choice_2);
        }
        else if (choice == 0) break;
        else std::cout << "Invalid choice!" << std::endl;
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


