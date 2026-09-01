#include "Header.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
//Additional events for game
enum EventType {
    TOXIC_RAIN =0, RAIN=1, VOLCANIC_ERUPTION=2, FLASH_FLOOD=3, MUDSLIDE=4, HUMID_HOT=5,
    CONSTRICTOR_VINES=6, WILD_MAGIC_WILDS=7, QUICK_FREEZING_GLAD=8,
    WILL_WISP_ATTRACTION=9, DEAD_MAGIC_ZONE=10, POLLEN_HALLUCINATIONS=11,
    ENEMY_PATROL=12, MONSTER_AMBUSH=13, CUNNING_SCAVENGERS=14, STAGED_ACCIDENT=15,
    FALSE_HOSPITABLE_HOST=16, THE_PROPHETIC_BEGGAR=17, THE_SHADOWING_KID=18,
    EXTORTION=19, THE_TURNCOAT_GUIDE=20, POACHER_TRAP_TRIGGER=21, FAKE_DISTRESS_CALL=22,
    MONEY_FIND=23, GOOD_STRANGER=24, GOOD_WEATHER=25, GOOD_REST=26 , TAVERN=27, HOSTEL=28, CASTLE=29, DUNGEON=30, CAVE=31, FOREST=32, DESERT=33,
    VILLAGE=34, BASTION=35, TOWERPLACE=36, SIMPLE_HOUSE=37, GOOD_PLACE=38 , FISHING_CHALLENGE=39, ARCHERY_CONTEST=40, STRANGE_STONE=41
    
};

void RandomizerEvent(Character& hero, GameHard& levelDificulty)
{
    int eventType = rand() % 27; //From 0 to 41

    switch (eventType) {
        case TOXIC_RAIN: ToxicRain(hero, levelDificulty); break;
        case RAIN: Rain(hero, levelDificulty); break;
        case VOLCANIC_ERUPTION: VolcanicEruption(hero, levelDificulty); break;
        case FLASH_FLOOD: FlashFlood(hero, levelDificulty); break;
        case MUDSLIDE: Mudslide(hero, levelDificulty); break;
        case HUMID_HOT: HumidHot(hero, levelDificulty); break;
        case CONSTRICTOR_VINES: ConstrictorVines(hero, levelDificulty); break;
        case WILD_MAGIC_WILDS: WildMagicWilds(hero, levelDificulty); break;
        case QUICK_FREEZING_GLAD: QuickFreezingGlad(hero, levelDificulty); break;
        case WILL_WISP_ATTRACTION: WillWispAttraction(hero, levelDificulty); break;
        case DEAD_MAGIC_ZONE: DeadMagicZone(hero, levelDificulty); break;
        case POLLEN_HALLUCINATIONS: PollenHallucinations(hero, levelDificulty); break;
        case ENEMY_PATROL: EnemyPatrol(hero, levelDificulty); break;
        case MONSTER_AMBUSH: MonsterAmbush(hero, levelDificulty); break;
        case CUNNING_SCAVENGERS: CunningScavengers(hero, levelDificulty); break;
        case STAGED_ACCIDENT: StagedAccident(hero, levelDificulty); break;
        case FALSE_HOSPITABLE_HOST: FalseHospitableHost(hero, levelDificulty); break;
        case THE_PROPHETIC_BEGGAR: ThePropheticBeggar(hero, levelDificulty); break;
        case THE_SHADOWING_KID: TheShadowingKid(hero, levelDificulty); break;
        case EXTORTION: Extortion(hero, levelDificulty); break;
        case THE_TURNCOAT_GUIDE: TheTurncoatGuide(hero, levelDificulty); break;
        case POACHER_TRAP_TRIGGER: PoacherTrapTrigger(hero, levelDificulty); break;
        case FAKE_DISTRESS_CALL: FakeDistressCal(hero, levelDificulty); break;
        case MONEY_FIND: MoneyFind(hero); break;
        case GOOD_STRANGER: GoodStranger(hero); break;
        case GOOD_WEATHER: GoodWeather(hero); break;
        case GOOD_REST: GoodRest(hero); break;
        case TAVERN: Tavern(hero); break;
        case HOSTEL: Hostel(hero); break;
        case CASTLE: Castle(hero); break;
        case DUNGEON: Dungeon(hero); break;
        case CAVE: Cave(hero); break;
        case FOREST: Forest(hero); break;
        case DESERT: Desert(hero); break;
        case VILLAGE: Village(hero); break;
        case BASTION: Bastion(hero); break;
        case TOWERPLACE: TowerPlace(hero); break;
        case SIMPLE_HOUSE: SimpleHouse(hero); break;
        case GOOD_PLACE: GoodPlace(hero); break;
        case FISHING_CHALLENGE: FishingChallenge(hero); break;
        case ARCHERY_CONTEST: ArcheryContest(hero); break;
        case STRANGE_STONE: StrangeStone(hero); break;
        default: std::cout << "Unknown event type!" << std::endl; break;
    }
}
// ANSI Colors for Console
namespace Color {
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
    const std::string BOLD    = "\033[1m";
}

// Helper function to render formatted Event Cards
void PrintEventCard(const std::string& icon, const std::string& title, const std::string& description, const std::string& effectColor = Color::RED) {
    std::cout << "\n" << Color::BOLD << Color::CYAN << "┌──────────────────────────────────────────────┐\n" << Color::RESET;
    std::cout << Color::BOLD << Color::CYAN << "│ " << Color::YELLOW << icon << "  " << title;
    
    // Padding spaces for border alignment
    int padding = 43 - (title.length() + 4); 
    for (int i = 0; i < padding; ++i) std::cout << " ";
    std::cout << Color::CYAN << "│\n" << Color::RESET;
    
    std::cout << Color::BOLD << Color::CYAN << "├──────────────────────────────────────────────┤\n" << Color::RESET;
    std::cout << Color::CYAN << "│ " << effectColor << description;
    
    std::cout << Color::RESET << "\n";
    std::cout << Color::BOLD << Color::CYAN << "└──────────────────────────────────────────────┘\n" << Color::RESET;

    // Short delay for better visual pacing
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
}

// Helper function for damage logging
void DamageHero(Character& hero, int amount) {
    hero.SetHealth(hero.GetHealth() - amount);
    std::cout << Color::RED << Color::BOLD << "   [ - " << amount << " HP ] " 
              << Color::RESET << "Current Health: " << Color::GREEN << hero.GetHealth() << Color::RESET << "\n";
}

// Helper function for gold loss logging
void LoseGold(Character& hero, int amount) {
    hero.SetGold(hero.GetGold() - amount);
    std::cout << Color::YELLOW << Color::BOLD << "   [ - " << amount << " Gold ] " 
              << Color::RESET << "Current Gold: " << Color::YELLOW << hero.GetGold() << Color::RESET << "\n";
}

// ---------------- EVENTS ----------------

void ToxicRain(Character& hero, GameHard& levelDificulty) {
    if (levelDificulty.GetDifficultyLevel() >= 2) {
        PrintEventCard("☣️", "TOXIC RAIN", "Acidic rain burns your skin! You take extra damage due to the high difficulty level.");
        DamageHero(hero, 10); // Increased damage for higher difficulty
    } else {
        PrintEventCard("☣️", "TOXIC RAIN", "Acidic rain burns your skin!");
        DamageHero(hero, 5);
    }
    PrintEventCard("☣️", "TOXIC RAIN", "Acidic rain burns your skin!");
    DamageHero(hero, 5);
}

void Rain(Character& hero, GameHard& levelDificulty) {
    int rainType = rand() % 2;
    if (rainType == 0) {
        PrintEventCard("🌧️", "LIGHT RAIN", "Light rain falls. It is chilly and uncomfortable.", Color::YELLOW);
        DamageHero(hero, 2);
    } else {
        PrintEventCard("⛈️", "HEAVY RAIN", "Heavy rain pours down! You take damage from exposure.");
        DamageHero(hero, 5);
    }
}

void VolcanicEruption(Character& hero, GameHard& levelDificulty) {
    if (rand() % 2 == 0) {
        PrintEventCard("🌋", "VOLCANIC ERUPTION", "The ground shakes! You manage to escape safely.", Color::GREEN);
    } else {
        PrintEventCard("🌋", "VOLCANIC ERUPTION", "Hot ash and lava burn you as you run!");
        DamageHero(hero, 10);
    }
}

void FlashFlood(Character& hero, GameHard& levelDificulty) {
    if(levelDificulty.GetDifficultyLevel()  ==3 ) 
    {
        PrintEventCard("🌊", "FLASH FLOOD", "A sudden wave sweeps you away into sharp rocks! You take extra damage due to the high difficulty level.");
        DamageHero(hero, 15); // Increased damage for higher difficulty
    } else
    if (rand() % 2 == 0) {
        PrintEventCard("🌊", "FLASH FLOOD", "Water rises fast, but you climb to high ground safely.", Color::GREEN);
    } else {
        PrintEventCard("🌊", "FLASH FLOOD", "A sudden wave sweeps you away into sharp rocks!");
        DamageHero(hero, 10);
    }

}

void Mudslide(Character& hero, GameHard& levelDificulty) {
    if(levelDificulty.GetDifficultyLevel()  ==3 ) 
    {
        PrintEventCard("⛰️", "MUDSLIDE", "A torrent of mud sweeps past you closely! You take extra damage due to the high difficulty level.");
        DamageHero(hero, 10); // Increased damage for higher difficulty
    } else
    if (rand() % 2 == 0) {
        PrintEventCard("⛰️", "MUDSLIDE", "A torrent of mud sweeps past you closely.", Color::GREEN);
    } else {
        PrintEventCard("⛰️", "MUDSLIDE", "You get caught in a dangerous mudslide!");
        DamageHero(hero, 5);
    }
}

void HumidHot(Character& hero, GameHard& levelDificulty) {
    if(levelDificulty.GetDifficultyLevel()  ==3 ) 
    {
        PrintEventCard("🏜️", "HUMID & HOT", "All water dried up! You suffer from severe heat exhaustion! Extra damage due to high difficulty level.");
        DamageHero(hero, 10); // Increased damage for higher difficulty
    } else
    if (rand() % 2 == 0) {
        PrintEventCard("☀️", "HUMID & HOT", "It's humid and hot, but you manage fine.", Color::YELLOW);
    } else {
        PrintEventCard("🏜️", "HUMID & HOT", "All water dried up! You suffer from severe heat exhaustion.");
        DamageHero(hero, 5);
    }
}

void ConstrictorVines(Character& hero, GameHard& levelDificulty) {
    if(levelDificulty.GetDifficultyLevel()  ==3 ) 
    {
        PrintEventCard("🌿", "CONSTRICTOR VINES", "Predatory vines squeeze tight around you! Extra damage due to high difficulty level.");
        DamageHero(hero, 6); // Increased damage for higher difficulty
    } else
    {
        PrintEventCard("🌿", "CONSTRICTOR VINES", "Predatory vines squeeze tight around you!");
        DamageHero(hero, 3);
    }
}


void QuickFreezingGlade(Character& hero, GameHard& levelDificulty) {
    if(levelDificulty.GetDifficultyLevel()  ==3 ) 
    {
        PrintEventCard("❄️", "QUICK FREEZING GLADE", "The temperature plummets. Frostbite sets in! Extra damage due to high difficulty level.");
        DamageHero(hero, 8); // Increased damage for higher difficulty
    } else
    {
    PrintEventCard("❄️", "QUICK FREEZING GLADE", "The temperature plummets. Frostbite sets in!");
    DamageHero(hero, 4);
    }
}















void Extortion(Character& hero, GameHard& levelDificulty) {
    PrintEventCard("💰", "EXTORTION", "Local bandits force you to hand over some coin!");
    LoseGold(hero, 10);
}

void PoacherTrapTrigger(Character& hero, GameHard& levelDificulty) {
    PrintEventCard("🪤", "POACHER TRAP", "Snap! You stepped into a sharp steel trap!");
    DamageHero(hero, 6);
}

// Narrative Events (No stat loss)
void WildMagicWilds(Character& hero, GameHard& levelDificulty)       { PrintEventCard("✨", "WILD MAGIC WILDS", "Raw magical energy crackles through the air.", Color::MAGENTA); }
void WillWispAttraction(Character& hero, GameHard& levelDificulty)   { PrintEventCard("👻", "WILL-O'-WISP", "Mysterious glowing lights attempt to lead you astray.", Color::MAGENTA); }
void DeadMagicZone(Character& hero, GameHard& levelDificulty)        { PrintEventCard("🚫", "DEAD MAGIC ZONE", "All magic in this area completely vanishes.", Color::CYAN); }
void PollenHallucinations(Character& hero, GameHard& levelDificulty) { PrintEventCard("🍄", "POLLEN HALLUCINATIONS", "Strange floral pollen fills the air, distorting your sight.", Color::MAGENTA); }
void EnemyPatrol(Character& hero, GameHard& levelDificulty)          { PrintEventCard("⚔️", "ENEMY PATROL", "You spot an armed patrol marching nearby!", Color::YELLOW); }
void MonsterAmbush(Character& hero, GameHard& levelDificulty)        { PrintEventCard("🐺", "MONSTER AMBUSH", "A wild beast leaps out from the shadows!", Color::RED); }
void CunningScavengers(Character& hero, GameHard& levelDificulty)    { PrintEventCard("🦅", "CUNNING SCAVENGERS", "Opportunists are watching your every step...", Color::YELLOW); }
void StagedAccident(Character& hero, GameHard& levelDificulty)       { PrintEventCard("🎭", "STAGED ACCIDENT", "A traveler cries for help, but it feels like a trap.", Color::YELLOW); }
void FalseHospitableHost(Character& hero, GameHard& levelDificulty)  { PrintEventCard("🏡", "FALSE HOSPITABLE HOST", "Your host offers food, but their smile feels unnatural.", Color::YELLOW); }
void ThePropheticBeggar(Character& hero, GameHard& levelDificulty)   { PrintEventCard("🔮", "PROPHETIC BEGGAR", "An old beggar whispers an ominous prophecy.", Color::CYAN); }
void TheShadowingKid(Character& hero, GameHard& levelDificulty)      { PrintEventCard("👀", "SHADOWING KID", "A young child stalks you quietly from behind.", Color::CYAN); }
void TheTurncoatGuide(Character& hero, GameHard& levelDificulty)     { PrintEventCard("🗺️", "TURNCOAT GUIDE", "Your guide seems to be leading you off course...", Color::YELLOW); }



void FakeDistressCal(Character& hero, GameHard& levelDificulty) {
    std::cout << "If want to check -- 1 \nIf you want pass --- 2" << std::endl;
    int choice=0;

    if(choice == 1)
    {

    
    std::cout << "Event: Fake Distress Call!\n";
    int event_fake_diss_call = rand() % 4 +1;

    switch(event_fake_diss_call)
    {
case 1:
std::cout << "It's only your tired imagination" << std::endl;

break;
case 2:
std::cout << "It's only tired old granny" << std::endl;

break;
case 3:
std::cout << "IT'S WENDIGO RUN !!!" << std::endl;

break;
case 4:
std::cout << "You enter big forest" << std::endl;

break;
    }
}


    else if (choice == 2)
    {
        std::cout << "You go away" << std::endl;
        exit;
    }
    else {std::cout << "You entere wrong answer !";}
}

void Earthquake(Character& hero, GameHard& levelDificulty)
{
    
}
void MoneyFind(Character& hero, GameHard& levelDificulty) {
    int gold = rand() % 100 + 1;
    hero.SetGold(hero.GetGold() + gold);
    std::cout << "You found " << gold << " gold!\n";
}
void GoodStranger(Character& hero) {
    std::cout << "Event: Good Stranger! You feel refreshed.\n";
    std::cout << "Your health + 5" << std::endl;
    hero.SetHealth(hero.GetHealth() + 5);
}
void GoodWeather(Character& hero) {
    std::cout << "Event: Good Weather! You feel rejuvenated.\n";
    hero.SetHealth(hero.GetHealth() + 5);
}
void GoodRest(Character& hero) {
    int health = rand() % 20 + 10;
    hero.SetHealth(hero.GetHealth() + health);
    std::cout << "You found a safe place to rest. " << health << " health restored.\n";
}


void Tavern(Character& hero)
{
std::cout << "You enter a cozy tavern. The smell of food and ale fills the air." << std::endl;
std::cout << "You can rest here and regain some health." << std::endl;
std::cout << "Or you can talk to the locals and gather information about your next adventure." << std::endl;
std::cout << "You can also play a game of chance with the tavern patrons." << std::endl;

std::cout << "What would you like to do?" << std::endl;
std::cout << "1. Rest and regain health" << std::endl;
std::cout << "2. Talk to the locals" << std::endl;
std::cout << "3. Play a game of chance" << std::endl;
std::cout << "4. Leave the tavern" << std::endl;

int choice;
std::cin>> choice;
switch (choice) {
    case 1:
        std::cout << "You rest and regain some health." << std::endl;
        hero.SetHealth(hero.GetHealth() + 20);
        break;
    case 2:
        std::cout << "You talk to the locals and gather information about your next adventure." << std::endl;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        break;
    case 3:
        std::cout << "You play a game of chance with the tavern patrons." << std::endl;
        
        DiceRoll(hero);
        break;
    case 4:
        std::cout << "You leave the tavern and continue your adventure." << std::endl;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        break;
    default:
        std::cout << "Invalid choice. You leave the tavern." << std::endl;
}
}

void Hostel(Character& hero)
{
std::cout << "You enter a small hostel. The atmosphere is quiet and peaceful." << std::endl;
std::cout << "You can rest here and regain some health." << std::endl;
std::cout << "Or you can talk to the other travelers and gather information about your next adventure." << std::endl;
std::cout << "What would you like to do?" << std::endl;

std::cout <<"1. Rest and regain health" << std::endl;
std::cout <<"2. Talk to the other travelers" << std::endl;
std::cout <<"3. Leave the hostel" << std::endl;

int choice;
std::cin>> choice;

switch (choice) {
    case 1:
        std::cout << "You rest and regain some health." << std::endl;
        hero.SetHealth(hero.GetHealth() + 15);
        break;
    case 2:
        std::cout << "You talk to the other travelers and gather information about your next adventure." << std::endl;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        std::cout << "1. Gain some info about tresures" << std::endl;
        std::cout << "2. What is going here ?" << std::endl;
        std::cout << "3. Where I can find job ?" << std::endl;
        std::cout << "4.                       " << std::endl;

        break;
    case 3:
        std::cout << "You leave the hostel and continue your adventure." << std::endl;
        break;
    default:
        std::cout << "Invalid choice. You leave the hostel." << std::endl;
        break;
}
}

void Castle(Character& hero)
{

}

void Dungeon(Character& hero)
{

}

void Cave(Character& hero)//goblin cave, dragon or simple cave
{

}

void Forest(Character& hero)
{

}

void Desert(Character& hero)
{

}

void Village(Character& hero)
{

}

void Bastion(Character& hero)
{

}

void TowerPlace(Character& hero)//evil TowerPlace , mage TowerPlace
{

}

void SimpleHouse(Character& hero)//evil mage , witch , friendly house
{

}


void GoodPlace(Character& hero)//good place for rest and food
{

}

void FishingChallenge(Character& hero)
{
    std::cout << "You participate in a fishing challenge with the locals." << std::endl;
    // Implement fishing challenge logic here
}

void ArcheryContest(Character& hero)
{
    std::cout << "You participate in an archery contest with the locals." << std::endl;
    // Implement archery contest logic here
}

void StrangeStone(Character& hero)
{
    std::cout << "You find a strange stone with mysterious markings." << std::endl;
    // Implement logic for interacting with the strange stone here
}