#include "Header.h"

//====================================================Inventory_functions=======================================================================================================
int Inventory::AddSpace(int *&my_inv_mass, int &size, const int value)            //Add  njew space fow new items
{
int *newArray = new int [size++];
for(int i=0; i<size; i++)
{
    newArray[i] =my_inv_mass[i];
}
newArray[size++]= value;
delete[] my_inv_mass;
my_inv_mass = newArray;
size++;
return size;
}



int Inventory::GetSpace(int &size)                                                //Show number of items
{
return size;
}


int Inventory::DelSpace(int *& my_inv_mass, int &size)                            //Delete sapce 
{
size--;
int *newArray = new int [size];
for(int i =0; i<size; i++)
{
    newArray[i]= my_inv_mass[i];
}
delete[] my_inv_mass;
my_inv_mass = newArray;\

return size;
}


void Inventory::DisplayInventory()                                               //Shows items in inventory
{
    //for 
}

void Inventory::DeleteItem()                                                    //Deleet item ferom inventory
{

}


void Inventory::InventoryFunctions()                                                         //For displaying functions , like : show items , delete items; (MENU)
{
    int choice=0;
    std::cout << "\n\n" << std::endl;
    std::cout <<"============================================="<< std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout <<"=================Functions=================="<< std::endl;
    std::cout <<"Disaply all items in : 1 \nDelete item : 2 " << std::endl;
    std::cout <<"============================================="<< std::endl;
    std::cout << "\n\n" << std::endl;
    while(true)
    {
        if(choice == '1') DisplayInventory();
        else if (choice == '2') DeleteItem();
        else break;
    }

}