#include "Header.h"
//Here is additional functions for game / settings

void HelpFunction() 
{
    std::cout << "\n\n" ;
    std::cout << "This is a helper function that can be used for various purposes in the game." << std::endl;
    std::cout << "You can use this function to display help information and game instructions." << std::endl;
    std::cout << "This program shows how to structure a simple adventure game using C++." << std::endl;
    std::cout << "This program is written by Vladyslav Vytrykush to show the knowledge of C++ programming." << std::endl;
    std::cout << "\n\n" ;
}



void ChoiceHard(Enemy& enemy)
{
    std::cout <<"\n\n" ;
    int difil = 0;
    std::cout << "Choose difficulty level first" << std::endl;
    std::cout << "Be prepared for tougher enemies and more challenging puzzles." << std::endl;
    std::cout << "Good luck on your adventure!" << std::endl;
    std::cout << "1. Easy" << std::endl;
    std::cout << "2. Medium" << std::endl;
    std::cout << "3. Hard" << std::endl;
    std::cout << "Enter dificulty level : "  ;
    std::cin >> difil;
    std::cout << "\n\n" ;
    if (difil == 1) {
        std::cout << "You have chosen the easy difficulty level!" << std::endl;
        std::cout << "Enemies will be weaker and puzzles will be simpler." << std::endl;
        enemy.SetHealth(enemy.GetHealth()); 
        enemy.SetStrength(enemy.GetStrength());

    } else if (difil == 2) {
        std::cout << "You have chosen the medium difficulty level!" << std::endl;
        std::cout << "Enemies will be moderately challenging and puzzles will require some thought." << std::endl;
        enemy.SetHealth(enemy.GetHealth() + (enemy.GetHealth() / 2)); 
        enemy.SetStrength(enemy.GetStrength() + (enemy.GetStrength() / 2)); 
    } else if (difil == 3) {
        std::cout << "You have chosen the hard difficulty level!" << std::endl;
        std::cout << "Enemies will be tough and puzzles will require careful planning." << std::endl;
        enemy.SetHealth(enemy.GetHealth() + enemy.GetHealth()); 
        enemy.SetStrength(enemy.GetStrength() + enemy.GetStrength()); 

    } else {
        std::cout << "Invalid choice. Please select a valid difficulty level." << std::endl;
    }
}



void GetInfo()
{
        std::cout << "\n\n" ;
        std::cout << "\n=== INFO ===" << std::endl;
        std::cout << "This is a simple adventure game written in C++." << std::endl;
        std::cout << "You can explore the world, fight enemies, and collect items." << std::endl;
        std::cout << "Use the main menu to navigate through the game." << std::endl;
        std::cout << "Have fun and enjoy your adventure!" << std::endl;
        std::cout << "PS. This program is written by Vladyslav Vytrykush." << std::endl;
        std::cout << "\n\n" ;
}


void Help()
{
            std::cout << "\n\n" ;
            std::cout << "\n=== HELP ===" << std::endl;
            std::cout << "1. Show character stats - Displays current character statistics" << std::endl;
            std::cout << "2. Show your inventory - Lists all items in your inventory" << std::endl;
            std::cout << "3. Manage your Inventory - Access inventory management functions" << std::endl;
            std::cout << "4. Get info - Display help information" << std::endl;
            std::cout << "5. Help - Shows this help menu" << std::endl;
            std::cout << "0. Exit - Quit the program" << std::endl;
            std::cout << "\n\n" ;
}

void Reseter(Character& hero, MyInventory& inv)
{
    hero = Character(); 
    
    
    hero.EquipWeapon(nullptr);
    hero.EquipArmor(nullptr);
    
    // Clear inventory
    inv.Clear();
    
    Weapon* weapon_1 = new Weapon();
    weapon_1->RandomizeWeaponStart(hero.GetProfession());
    
    Armory* armor_1 = new Armory();
    armor_1->RandomizeArmorStart();
    
    Weapon* weapon_2 = new Weapon();
    weapon_2->RandomizeWeaponSpeacial();
    
    Potion* p = new Potion();
    p->RandomizePotion();
    
    inv.AddItem(weapon_1);
    inv.AddItem(armor_1);
    inv.AddItem(weapon_2);
    inv.AddItem(p);
    
    std::cout << "Game reset! Your adventure starts anew." << std::endl;
}



void Settings(Character& hero, MyInventory& inv, Enemy& enemy)
{
    std::cout << "\n\n" ;
    std::cout << "\n=== SETTINGS ===" << std::endl;
    std::cout << "1. Change difficulty level" << std::endl;
    std::cout << "2. --------" << std::endl;                                //Not implemended     
    std::cout << "3. --------" << std::endl;                                //Not implemended     
    std::cout << "4. Reset game progress" << std::endl;
    std::cout << "0. Back to main menu" << std::endl;

    int choice=0;
    std::cout << "Enter choice : " ;
    std::cin>> choice;
    
    switch (choice)
    {
         case 1://Dificulty 
         ChoiceHard(enemy);
         break;
        case 2:

        break;
        case 3:

        break;
        case 4:
         std::cout << "\n=== RESET GAME ===" << std::endl;
    std::cout << "All progress will be lost. Continue? (y/n): ";
    char confirm;
    std::cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        Reseter(hero, inv);
    }
    break;
        case 0:

        break;

        default: std::cout<< "Invalid choice" << std::endl;
    }
    std::cout << "\n\n" ;
}


void BugReportFunction()
{
    std::cout << "\n\n" ;
    std::cout << "\n=== BUG REPORT ===" << std::endl;
    std::cout << "If you encounter any bugs or issues while playing the game, please report them." << std::endl;
    std::cout << "You can contact the developer at GitHub." << std::endl;
    std::cout << "\n\n" ;
}
