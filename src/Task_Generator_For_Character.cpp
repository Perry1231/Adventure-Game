#include <iostream>
#include <string>
#include <map>
#include "Header.h"



constexpr const char* CYAN = "\033[36m";
constexpr const char* YELLOW = "\033[33m";
constexpr const char* GRAY = "\033[90m";
constexpr const char* RED = "\033[31m";
constexpr const char* RESET = "\033[0m";

// void Task_1_CollectThings();
// void Task_2_Rescue();
// void Task_3_Explore();
// void Task_4_Eliminate();
// void Task_5_Deliver();
// void Task_6_Escort();
// void Task_7_Puzzle();

struct QuestStructBasic
{
    std::string description_task;
    int gold_task;
    int difficulty_task;
    double experience_task;
};

int Quest::ResizeQuestBig()
{
   int new_capacity = capacity_quest + 1;
    Quest** temp = new Quest*[new_capacity];
    for (int i = 0; i < count_quest; i++)
        temp[i] = quests[i];
    delete[] quests;
    quests = temp;
    capacity_quest = new_capacity;
    return 0;
}


int Quest::AddQuest(Quest* quest1) {
    if (count_quest >= capacity_quest) ResizeQuestBig();
    quest1->SetQuestNumber(number_quest);   
    quests[count_quest++] = quest1;
    number_quest++;
    return 0;
}


// name + gold
// name -> {gold, difficulty}
static std::map<std::string, QuestStructBasic>& GetQuestTaskDB( GameHard&  difficultyLevel) {                       //Basic tasks
    static std::map<std::string, QuestStructBasic> yar;
    if (yar.empty()) {
        yar = { //Collect tasks
            // 25 gold, 2 difficulty , 0.01 exp
            {"Collect Magic Sticks", "Collect magic sticks.", {25/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}}, 
            {"Collect Magic Stones", "Collect magic stones.", {25/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"ColLect Magic Items", "Collect magic items.", {18/difficultyLevel.GetDifficultyLevel(),1, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"ColLect Magic Grass","Collect magic grass.", {15/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Magic Flowers", "Collect magic flowers.", {18/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Rare Ores","Collect rare ores.", {23/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Broken Portal Fragments","Collect broken portal fragments.", {39/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Festival Ingredients","Collect festival ingredients.", {20/difficultyLevel.GetDifficultyLevel(), 1, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Magic White moss","Collect magic white moss.", {15/difficultyLevel.GetDifficultyLevel(),1, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Mandragora","Collect mandragora.", {22/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Magic Mirror","Collect magic mirror.", {20/difficultyLevel.GetDifficultyLevel(), 1, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Magic Pages for Book","Collect magic pages.", {25/difficultyLevel.GetDifficultyLevel(), 5, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Magic Pages from Evil Book","Collect magic pages from evil book.", {32/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect Magical Herb for village","Collect magical herb for village.", {25/difficultyLevel.GetDifficultyLevel(), 2, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect pinocones for magic squirrel","Collect pinocones for magic squirrel.", {12/difficultyLevel.GetDifficultyLevel(), 1, 0.01*difficultyLevel.GetDifficultyLevel()}},
            {"Collect leaves for small dwarf's house","Collect leaves for small dwarf's house.", {20/difficultyLevel.GetDifficultyLevel(), 1, 0.01*difficultyLevel.GetDifficultyLevel()}},


            {"Rescue girl form goblin", "Rescue girl from goblin.", {40/difficultyLevel.GetDifficultyLevel(), 3, 0.3*difficultyLevel.GetDifficultyLevel()}},
            {"Rescue village form orks", "Rescue village from orks.", {50/difficultyLevel.GetDifficultyLevel(), 3, 0.3*difficultyLevel.GetDifficultyLevel()}},
            {"Rescue boy form orks camp", "Rescue boy from orks camp.", {35/difficultyLevel.GetDifficultyLevel(), 3, 0.25*difficultyLevel.GetDifficultyLevel()}},
            {"Rescue dog form misfortune", "Rescue dog from misfortune.", {15/difficultyLevel.GetDifficultyLevel(), 3, 0.09*difficultyLevel.GetDifficultyLevel()}},
            {"Rescue a herd pf pigs for farmer", "Rescue a herd of pigs for farmer.", {20/difficultyLevel.GetDifficultyLevel(), 3, 0.05*difficultyLevel.GetDifficultyLevel()}},

            {"Explore new lands for farmers", "Explore new lands for farmers to cultivate.", {15/difficultyLevel.GetDifficultyLevel(), 1, 0.03*difficultyLevel.GetDifficultyLevel()}},
            {"Explore new lands for king", "Explore new lands for king to rule.", {27/difficultyLevel.GetDifficultyLevel(), 1, 0.05*difficultyLevel.GetDifficultyLevel()}},
            {"Explore new lands for researchers", "Explore new lands for researchers.", {15/difficultyLevel.GetDifficultyLevel(), 1, 0.03*difficultyLevel.GetDifficultyLevel()}},
            {"Explore new lands for castle's knight", "Explore new lands for castle's knight.", {15/difficultyLevel.GetDifficultyLevel(), 1, 0.03*difficultyLevel.GetDifficultyLevel()}},


            {"Eliminate danger ork", "Eliminate danger ork in danger lands.", {25/difficultyLevel.GetDifficultyLevel(), 2, 0.08*difficultyLevel.GetDifficultyLevel()}},
            {"Kill big hog", "Kill big hog in the forest.", {15/difficultyLevel.GetDifficultyLevel(), 1, 0.04*difficultyLevel.GetDifficultyLevel()}},
            {"Eliminate danger bear", "Eliminate danger bear in the forest.", {17/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}},


            {"Escort rich man", "Escort rich man to the castle.", {17/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}},
            {"Eliminate pretty girl", "Eliminate pretty girl.", {20/difficultyLevel.GetDifficultyLevel(), 2, 0.06*difficultyLevel.GetDifficultyLevel()}},
            {"Escort princess", "Escort princess to the castle.", {40/difficultyLevel.GetDifficultyLevel(), 2, 0.3*difficultyLevel.GetDifficultyLevel()}},
            {"Escort old man", "Escort old man to the village.", {10/difficultyLevel.GetDifficultyLevel(), 1, 0.04*difficultyLevel.GetDifficultyLevel()}},
            {"Escort merchant", "Escort merchant to the market.", {17/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}},
            {"Escort child to home", "Escort child to home.", {5/difficultyLevel.GetDifficultyLevel(), 1, 0.04*difficultyLevel.GetDifficultyLevel()}},



            {"Deliver package to village", "Deliver package to village.", {10/difficultyLevel.GetDifficultyLevel(), 1, 0.03*difficultyLevel.GetDifficultyLevel()}},
            {"Deliver package to king", "Deliver package to king.", {20/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}},
            {"Deliver package to merchant", "Deliver package to merchant.", {15/difficultyLevel.GetDifficultyLevel(), 1, 0.04*difficultyLevel.GetDifficultyLevel()}},
            {"Deliver package to princess", "Deliver package to princess.", {30/difficultyLevel.GetDifficultyLevel(), 2, 0.06*difficultyLevel.GetDifficultyLevel()}},
            {"Deliver package to old man", "Deliver package to old man.", {5/difficultyLevel.GetDifficultyLevel(), 1, 0.02*difficultyLevel.GetDifficultyLevel()}},

            {"Solve puzzle in the cave", "Solve puzzle in the cave.", {25/difficultyLevel.GetDifficultyLevel(), 3, 0.08*difficultyLevel.GetDifficultyLevel()}},
            {"Solve puzzle in the forest", "Solve puzzle in the forest.", {15/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}},
            {"Solve puzzle in the castle", "Solve puzzle in the castle.", {35/difficultyLevel.GetDifficultyLevel(), 4, 0.1*difficultyLevel.GetDifficultyLevel()}},
            {"Solve puzzle in the dungeon", "Solve puzzle in the dungeon.", {20/difficultyLevel.GetDifficultyLevel(), 3, 0.07*difficultyLevel.GetDifficultyLevel()}},
            {"Eliminate danger bear", "Eliminate danger bear.", {17/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}},
            {"Eliminate danger bear", "Eliminate danger bear.", {17/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}},
            {"Eliminate danger bear", "Eliminate danger bear .", {17/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}},
            {"Eliminate danger bear", "Eliminate danger bear in the forest.", {17/difficultyLevel.GetDifficultyLevel(), 2, 0.05*difficultyLevel.GetDifficultyLevel()}}
            
        };
    }
    return yar;
}





std::string Quest::RandomizeQuest(GameHard& difficulty) {                       //====================================!!!!!!!!!!!!!!!!!=====
    auto& yar = GetQuestTaskDB(difficulty);

    std::string task_ar[] = {   //List of tasks
       "Collect Magic Sticks" , "Collect Magic Stones", "ColLect Magic Items", "ColLect Magic Grass", "Collect Magic Flowers",
        "Collect Rare Ores", "Collect Broken Portal Fragments", "Collect Festival Ingredients", "Collect Magic White moss", "Collect Mandragora", "Collect Magic Mirror", "Collect Magic Pages from Book",
        "Collect Magic Pages from Evil Book", "Collect Magical Herb for village", "Collect pinocones for magic squirrel", "Collect leaves for small dwarf's house",
        "Rescue girl form goblin", "Rescue village form orks", "Rescue boy form orks camp", "Rescue dog form misfortune", "Rescue a herd pf pigs for farmer",
        "Explore new lands for farmers", "Explore new lands for king", "Explore new lands for farmers", "Explore new lands for farmers",
        "Eliminate danger ork", "Kill big hog", "Eliminate danger bear",
        "Escort rich man", "Eliminate pretty girl", "Escort princess", "Escort old man", "Escort merchant", "Escort child to home",
        "Deliver package to village", "Deliver package to king", "Deliver package to merchant", "Deliver package to princess", "Deliver package to old man",
        "Solve puzzle in the cave", "Solve puzzle in the forest", "Solve puzzle in the castle", "Solve puzzle in the dungeon"
        
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


void Quest::DisplayAllQuestInfo() const 
{

    if (count_quest == 0)
    {
        std::cout << RED << "\n[!] Quest's list is completely empty.\n" << RESET;
        return;
    }

    std::cout << CYAN << "\n================ Quest's list (" << count_quest << " items) ================\n" << RESET;

    for (int i = 0; i < count_quest; ++i)
    {
        std::cout << YELLOW << "#" << (i + 1) << " " << RESET
                  << quests[i]->GetQuestName() 
                  << GRAY << " [ID: " << quests[i]->GetQuestNumber() 
                  << " | Type: " << quests[i]->GetQuestDifficulty() << "]" << RESET << "\n";

  
        quests[i]->DisplayQuestInfo();

        if (i < count_quest - 1) {
            std::cout << GRAY << "--------------------------------------------------\n" << RESET;
        }
    }

    std::cout << CYAN << "====================================================\n\n" << RESET;
}



void Character::Talk_About_Life(Quest& quest, GameHard& difficulty)
{
std::cout << "I've lived a long time and seen many things." << std::endl;
std::cout << "Life is full of challenges, but also moments of joy." << std::endl;
std::cout << "Remember to cherish the people around you and the experiences you have." << std::endl;
std::cout << "If you want to succeed, you must be brave and persistent." << std::endl;
std::cout << "And always remember, the journey is just as important as the destination." << std::endl;

std::cout << "Here is some quests you can do to earn gold and experience:\n";

quest.RandomizeQuest(difficulty);
quest.DisplayQuestInfo();
}




int Quest::Delete_Quest(int ) {
    for (int i = 0; i < count_quest; i++) {
        if (quests[i]->GetQuestNumber() == number_quest) {
            delete quests[i];
            for (int j = i; j < count_quest - 1; j++) {
                quests[j] = quests[j + 1];
            }
            count_quest--;
            std::cout << "Item with ID " << number_quest << " deleted." << std::endl;
            return 0;
        }
    }
    std::cout << "Item with ID " << number_quest << " not found!" << std::endl;
    return -1;
}