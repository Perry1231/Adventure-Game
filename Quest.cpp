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
    // Colors and Styles
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string CYAN = "\033[36m";
    const std::string YELLOW = "\033[33m";
    const std::string GREEN = "\033[32m";
    const std::string RED = "\033[31m";
    const std::string GRAY = "\033[90m";

    // Header Border
    std::cout << CYAN << "========================================\n";
    std::cout << "               QUEST INFO               \n";
    std::cout << "========================================\n" << RESET;

    // Quest Details with styling
    std::cout << BOLD << "Name        : " << RESET << YELLOW << questName << RESET << std::endl;
    std::cout << BOLD << "Description : " << RESET << GRAY << questDescription << RESET << std::endl;
    std::cout << BOLD << "Difficulty  : " << RESET << questDifficulty << std::endl;
    
    // Status with conditional coloring (Green for Yes, Red for No)
    std::cout << BOLD << "Completed   : " << RESET;
    if (isCompleted) {
        std::cout << GREEN << "[ Yes ]" << RESET << std::endl;
    } else {
        std::cout << RED << "[ No ]" << RESET << std::endl;
    }

    // Footer Border
    std::cout << CYAN << "========================================\n" << RESET;
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