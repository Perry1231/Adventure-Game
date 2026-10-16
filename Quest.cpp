#include "Header.h"

void Quest::DisplayQuestInfo() const
{
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                  QUEST INFORMATION               │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│ Name: " << questName << "\n";
    std::cout << "│ Description: " << questDescription << "\n";
    std::cout << "│ Difficulty: " << questDifficulty << "\n";
    std::cout << "│ Status: " << (isCompleted ? "Completed" : "In Progress") << "\n";
    std::cout << "└───────────────────────────────────────────────────┘\n";
}