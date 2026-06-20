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
delete [] newArray;
}



int Inventory::GetSpace(int &size)             //Show number of items
{
return size;
}


int Inventory::DelSpace(int *& my_inv_mass, int &size)             //Delete sapce 
{
size--;
int *newArray = new int [size];
for(int i =0; i<size; i++)
{
    newArray[i]= my_inv_mass[i];
}
delete[] my_inv_mass;
my_inv_mass = newArray;
delete [] newArray;
}


void Inventory::DisplayInventory()
{
    //for 
}


void InventoryFunctions()                           //For displaying functions , like : show items , delete items;
{

}