#include "Header.h"
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

void RandomizerEvent(Character& hero)
{
    int eventType = rand() % 27; //From 0 to 26

    switch (eventType) {
        case TOXIC_RAIN: ToxicRain(hero); break;
        case RAIN: Rain(hero); break;
        case VOLCANIC_ERUPTION: VolcanicEruption(hero); break;
        case FLASH_FLOOD: FlashFlood(hero); break;
        case MUDSLIDE: Mudslide(hero); break;
        case HUMID_HOT: HumidHot(hero); break;
        case CONSTRICTOR_VINES: ConstrictorVines(hero); break;
        case WILD_MAGIC_WILDS: WildMagicWilds(hero); break;
        case QUICK_FREEZING_GLAD: QuickFreezingGlad(hero); break;
        case WILL_WISP_ATTRACTION: WillWispAttraction(hero); break;
        case DEAD_MAGIC_ZONE: DeadMagicZone(hero); break;
        case POLLEN_HALLUCINATIONS: PollenHallucinations(hero); break;
        case ENEMY_PATROL: EnemyPatrol(hero); break;
        case MONSTER_AMBUSH: MonsterAmbush(hero); break;
        case CUNNING_SCAVENGERS: CunningScavengers(hero); break;
        case STAGED_ACCIDENT: StagedAccident(hero); break;
        case FALSE_HOSPITABLE_HOST: FalseHospitableHost(hero); break;
        case THE_PROPHETIC_BEGGAR: ThePropheticBeggar(hero); break;
        case THE_SHADOWING_KID: TheShadowingKid(hero); break;
        case EXTORTION: Extortion(hero); break;
        case THE_TURNCOAT_GUIDE: TheTurncoatGuide(hero); break;
        case POACHER_TRAP_TRIGGER: PoacherTrapTrigger(hero); break;
        case FAKE_DISTRESS_CALL: FakeDistressCal(hero); break;
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


void ToxicRain(Character& hero) {
    std::cout << "Event: Toxic Rain! You take 5 damage.\n";
    hero.SetHealth(hero.GetHealth() - 5);
}
void Rain(Character& hero) {
    int rainType = rand() % 2;
    if (rainType == 0) {
        std::cout << "Light rain is falling.\n";
        hero.SetHealth(hero.GetHealth() - 2);
    } else {
        std::cout << "Heavy rain is falling! You take 5 damage.\n";
        hero.SetHealth(hero.GetHealth() - 5);
    }
}
void VolcanicEruption(Character& hero) {
    int random = rand() % 2;
    if (random == 0) {
        std::cout << "A volcanic eruption occurs! You run away safely.\n";
    } else {
        std::cout << "A volcanic eruption occurs! You take 10 damage.\n";
        hero.SetHealth(hero.GetHealth() - 10);
    }
}
void FlashFlood(Character& hero) {
    int random = rand() % 2;
    if (random == 0) {
        std::cout << "A flood occurs! You run away safely.\n";
    } else {
        std::cout << "A flood occurs! You take 10 damage.\n";
        hero.SetHealth(hero.GetHealth() - 10);
    }
}
void Mudslide(Character& hero) {
    int random = rand() % 2;
    if (random == 0) {
        std::cout << "A mudslide occurs! You run away safely.\n";
    } else {
        std::cout << "A mudslide occurs! You take 5 damage.\n";
        hero.SetHealth(hero.GetHealth() - 5);
    }
}
void HumidHot(Character& hero) {
    int random = rand() % 2;
    if (random == 0) {
        std::cout << "It's humid and hot, but you manage fine.\n";
    } else {
        std::cout << "All water dried up! You take 5 damage.\n";
        hero.SetHealth(hero.GetHealth() - 5);
    }
}
void ConstrictorVines(Character& hero) {
    std::cout << "Event: Constrictor Vines! You take 3 damage.\n";
    hero.SetHealth(hero.GetHealth() - 3);
}
void WildMagicWilds(Character& hero) {
    std::cout << "Event: Wild Magic in the Wilds!\n";
}
void QuickFreezingGlad(Character& hero) {
    std::cout << "Event: Quick Freezing Glad! You take 4 damage.\n";
    hero.SetHealth(hero.GetHealth() - 4);
}
void WillWispAttraction(Character& hero) {
    std::cout << "Event: Will-o'-Wisp Attraction!\n";
}
void DeadMagicZone(Character& hero) {
    std::cout << "Event: Dead Magic Zone!\n";
}
void PollenHallucinations(Character& hero) {
    std::cout << "Event: Pollen Hallucinations!\n";
}
void EnemyPatrol(Character& hero) {
    std::cout << "Event: Enemy Patrol!\n";
}
void MonsterAmbush(Character& hero) {
    std::cout << "Event: Monster Ambush!\n";
}
void CunningScavengers(Character& hero) {
    std::cout << "Event: Cunning Scavengers!\n";
}
void StagedAccident(Character& hero) {
    std::cout << "Event: Staged Accident!\n";
}
void FalseHospitableHost(Character& hero) {
    std::cout << "Event: False Hospitable Host!\n";
}
void ThePropheticBeggar(Character& hero) {
    std::cout << "Event: The Prophetic Beggar!\n";
}
void TheShadowingKid(Character& hero) {
    std::cout << "Event: The Shadowing Kid!\n";
}
void Extortion(Character& hero) {
    std::cout << "Event: Extortion! You lose 10 gold.\n";
    hero.SetGold(hero.GetGold() - 10);
}
void TheTurncoatGuide(Character& hero) {
    std::cout << "Event: The Turncoat Guide!\n";
}
void PoacherTrapTrigger(Character& hero) {
    std::cout << "Event: Poacher Trap Trigger! You take 6 damage.\n";
    hero.SetHealth(hero.GetHealth() - 6);
}
void FakeDistressCal(Character& hero) {
    std::cout << "Event: Fake Distress Call!\n";
}
void MoneyFind(Character& hero) {
    int gold = rand() % 100 + 1;
    hero.SetGold(hero.GetGold() + gold);
    std::cout << "You found " << gold << " gold!\n";
}
void GoodStranger(Character& hero) {
    std::cout << "Event: Good Stranger! You feel refreshed.\n";
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
        std::cout << "You talk to the locals and gather information about your next adventure." << std::endl;//!!!!!!
        break;
    case 3:
        std::cout << "You play a game of chance with the tavern patrons." << std::endl;//!!!!!!
        
        DiceRoll(hero);
        break;
    case 4:
        std::cout << "You leave the tavern and continue your adventure." << std::endl;//!!!!!!
        break;
    default:
        std::cout << "Invalid choice. You leave the tavern." << std::endl;
        break;
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
        std::cout << "You talk to the other travelers and gather information about your next adventure." << std::endl;//!!!!!!
        break;
    case 3:
        std::cout << "You leave the hostel and continue your adventure." << std::endl;//!!!!!!
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