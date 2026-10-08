#include <iostream>
#include <string>
#include "Header.h"
//Here will be realisation of quests


void Quest::SetQuestName(const std::string& name) {
    questName = name;
}

void Quest::SetQuestDescription(const std::string& description) {
    questDescription = description;
}

void Quest::SetQuestDifficulty(int difficulty) {
    questDifficulty = difficulty;
}

void Quest::DisplayQuestInfo() const {
    std::cout << "Quest Name: " << questName << std::endl;
    std::cout << "Description: " << questDescription << std::endl;
    std::cout << "Difficulty: " << questDifficulty << std::endl;
    std::cout << "Completed: " << (isCompleted ? "Yes" : "No") << std::endl;
}

void Quest::SetCompleted(bool completed) {
    isCompleted = completed;
}

int Quest::GetQuestDifficulty() const {
    return questDifficulty;
}


std::string Quest::GetQuestName() const {
    return questName;
}

std::string Quest::GetQuestDescription() const {
    return questDescription;
}