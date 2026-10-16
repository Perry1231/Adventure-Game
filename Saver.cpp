#include "Header.h"
#include <fstream>

void Saver(Character& hero, MyInventory& inv, GameHard& difficultyLevel)
{
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                  SAVE GAME                      │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    
    std::cout << "Enter save name (without extension): ";
    std::string saveName;
    std::cin >> saveName;
    
    std::ofstream saveFile("saves/" + saveName + ".txt");
    if (!saveFile) {
        std::cout << "Failed to create save file!\n";
        return;
    }
    
    saveFile << "Character:\n";
    saveFile << "Name: " << hero.GetName() << "\n";
    saveFile << "Health: " << hero.GetHealth() << "\n";
    saveFile << "Gold: " << hero.GetGold() << "\n";
    saveFile << "Level: " << hero.GetLevel() << "\n";
    
    saveFile << "\nInventory:\n";
    // TODO: Save inventory items
    
    saveFile << "\nDifficulty: " << difficultyLevel.GetDifficultyLevel() << "\n";
    
    saveFile.close();
    std::cout << "Game saved successfully!\n";
}

void Loader(Character& hero, MyInventory& inv)
{
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                  LOAD GAME                      │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    
    std::cout << "Available saves:\n";
    // TODO: List available save files
    
    std::cout << "\nEnter save name to load: ";
    std::string saveName;
    std::cin >> saveName;
    
    std::ifstream loadFile("saves/" + saveName + ".txt");
    if (!loadFile) {
        std::cout << "Failed to load save file!\n";
        return;
    }
    
    std::string line;
    while (std::getline(loadFile, line)) {
        std::cout << line << std::endl;
    }
    
    loadFile.close();
    std::cout << "Game loaded successfully!\n";
}