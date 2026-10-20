#include <iostream>
#include <string>
#include <map>
#include "Header.h"

// void Task_1_CollectThings();
// void Task_2_Rescue();
// void Task_3_Explore();
// void Task_4_Eliminate();
// void Task_5_Deliver();
// void Task_6_Escort();
// void Task_7_Puzzle();

struct QuestStructBasic
{
    int gold_task;
    int difficulty_task;
    float experience_task;
};

// name + gold
// name -> {gold, difficulty}
static std::map<std::string, QuestStructBasic>& GetQuestTaskDB() {                       //Basic tasks
    static std::map<std::string, QuestStructBasic> yar;
    if (yar.empty()) {
        yar = {
            {"Collect Magic Sticks", {25, 2, 0.01}}, // 25 gold, 2 difficulty
            {"Collect Magic Stones", {25, 2, 0.01}},
            {"ColLect Magic Items", {18,1, 0.01}},
            {"ColLect Magic Grass",{15, 2, 0.01}},
            {"Collect Magic Flowers", {18, 2, 0.01}},
            {"Collect Rare Ores",{23, 2, 0.01}},
            {"Collect Broken Portal Fragments",{39, 2, 0.01}},
            {"Collect Festival Ingredients",{20, 1, 0.01}},
            {"Collect Magic White moss",{15,1, 0.01}},
            {"Collect Mandragora",{22, 2, 0.01}},
            {"Collect Magic Mirror",{20, 1, 0.01}},
            {"Collect Magic Pages from Book",{25, 5, 0.01}},
            {"Collect Magic Pages from Evil Book",{32, 2, 0.01}},
            {"Collect Magical Herb for village",{25, 2, 0.01}},
            {"Collect pinocones for magic squirrel",{12, 1, 0.01}},
            {"Collect leaves for small dwarf's house",{20, 1, 0.01}}
            
        };
    }
    return yar;
}



//Task for magic stranger
static std::map<std::string, QuestStructBasic>& GetQuestTaskMagicDB() {                  //Magic tasks for magicians
static std::map<std::string, QuestStructBasic> yar;
    if (yar.empty()) {
        yar = {
            {"",{}},
            {"",{}}
        };
    }
    return yar;
}




//Task for evil stranger
static std::map<std::string, QuestStructBasic>& GetQuestTaskEvilDB() {                   //Basic evil tasks
static std::map<std::string, QuestStructBasic> yar;
    if (yar.empty()) {
        yar = {
            {"",{}},
            {"",{}}
        };
    }
    return yar;
}



static std::map<std::string, QuestStructBasic>& GetQuestTaskDwarfDB() {                  //Basic dwarf tasks
static std::map<std::string, QuestStructBasic> yar;
    if (yar.empty()) {
        yar = {
            {"",{}},
            {"",{}}
        };
    }
    return yar;
}



std::string Quest::RandomizeQuest(GameHard& difficulty) {
    auto& yar = GetQuestTaskDB();

    std::string task_ar[] = {   //List of tasks
       "Collect Magic Sticks" , "Collect Magic Stones", "ColLect Magic Items", "ColLect Magic Grass", "Collect Magic Flowers",
        "Collect Rare Ores", "Collect Broken Portal Fragments", "Collect Festival Ingredients"
    };

    std::string chosen_name_t;
    chosen_name_t = task_ar[rand() % std::size(task_ar)];    //Change number of tasks
    questDifficulty = rand() + 3;
    auto it = yar.find(chosen_name_t);
    if (it != yar.end()) {
        reward = it->second.gold_task;                      //get reward
        questDifficulty = it->second.difficulty_task;       //get diffilculty
        int exp = it->second.experience_task;               //get experience
        
        reward = reward / difficulty.GetDifficultyLevel();
    }

    questName = chosen_name_t;
    return questName;
}



void Quest::DisplayQuestInfo() const {
    std::cout << "\n┌───────────────────────────────────────────────────┐\n";
    std::cout << "│                 QUEST DETAILS                     │\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
    std::cout << "│  Title       : " << questName << "\n";
    std::cout << "│  Difficulty  : " << questDifficulty << "\n";
    std::cout << "│  Reward      : " << reward << " gold\n";
    std::cout << "│  Status      : " << (isCompleted ? "Completed" : "In Progress") << "\n";
    std::cout << "└───────────────────────────────────────────────────┘\n\n";
}



void Character::Talk_About_Life()
{
std::cout << "Not implemented yet" << std::endl;
}