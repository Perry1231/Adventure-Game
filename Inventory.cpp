#include "Header.h"

//====================================================Inventory_functions=======================================================================================================

int MyInventory::ResizeInventoryBig()
{
    size ++;
return 0;
}

int MyInventory::ResizeInventorySma()
{
    size--;
    return 0;

}

void MyInventory::DisplayInventory()                                               //Shows items in inventory
{
    //for 
}



int MyInventory::AddItem(Item* item)
{
return 0;

}



int MyInventory::DelItem(int id)
{
return 0;
}



void MyInventory::InventoryFunctions()                                                         //For displaying functions , like : show items , delete items; (MENU)
{
    int choice =0;
    std::cout << "\n\n" << std::endl;
    std::cout <<"==================Inventory================="<< std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout <<"=================Functions=================="<< std::endl;
    std::cout <<"Disaply all items in : 1 \nDelete item from id : 2" << std::endl;
    std::cout <<"============================================="<< std::endl;
    std::cout << "\n\n" << std::endl;
    while(true)
    {
        std::cin >> choice;
        if(choice == 1) DisplayInventory();
        else if (choice == 2) DelItem(id);
        else if (choice == 0) break;
        else  std::cout << "Invalid choice!" ; continue;
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


