    #include "Header.h"
//Additional events for game
enum EventType { 
    TOXIC_RAIN =0, RAIN=1, VOLCANIC_ERUPTION=2, FLASH_FLOOD=3, MUDSLIDE=4, HUMID_HOT=5, CONSTRICTOR_VINES=6, WILD_MAGIC_WILDS=7, QUICK_FREEZING_GLAD=8,
    WILL_WISP_ATTRACTION=9, DEAD_MAGIC_ZONE=10, POLLEN_HALLUCINATIONS=11,
    ENEMY_PATROL=12, MONSTER_AMBUSH=13, CUNNING_SCAVENGERS=14, STAGED_ACCIDENT=15, FALSE_HOSPITABLE_HOST=16,
    THE_PROPHETIC_BEGGAR=17, THE_SHADOWING_KID=18, EXTORTION=19, THE_TURNCOAT_GUIDE=20,
    POACHER_TRAP_TRIGGER=21, FAKE_DISTRESS_CALL=22,
    MONEY_FIND=23, GOOD_STRANGER=24, GOOD_WEATHER=25, GOOD_REST=26
};


void RandomizerEvent(Character& hero)
{
    int eventType = rand() % 27; //From 0 to 26

    switch (eventType) {
        case TOXIC_RAIN:
            ToxicRain(hero);
            break;
        case RAIN:
            Rain(hero);
            break;
        case VOLCANIC_ERUPTION:
            VolcanicEruption(hero);
            break;
        case FLASH_FLOOD:
            FlashFlood(hero);
            break;
        case MUDSLIDE:
            Mudslide(hero);
            break;
        case HUMID_HOT:
            HumidHot(hero);
            break;
        case CONSTRICTOR_VINES:
            ConstrictorVines(hero);
            break;
        case WILD_MAGIC_WILDS:
            WildMagicWilds(hero);
            break;
        case QUICK_FREEZING_GLAD:
            QuickFreezingGlad(hero);
            break;
        case WILL_WISP_ATTRACTION:
            WillWispAttraction(hero);
            break;
        case DEAD_MAGIC_ZONE:
            DeadMagicZone(hero);
            break;
        case POLLEN_HALLUCINATIONS:
            PollenHallucinations(hero);
            break;
        case ENEMY_PATROL:
            EnemyPatrol(hero);
            break;
        case MONSTER_AMBUSH:
            MonsterAmbush(hero);
            break;
        case CUNNING_SCAVENGERS:
            CunningScavengers(hero);
            break;
        case STAGED_ACCIDENT:
            StagedAccident(hero);
            break;
        case FALSE_HOSPITABLE_HOST:
            FalseHospitableHost(hero);
            break;
        case THE_PROPHETIC_BEGGAR:
            ThePropheticBeggar(hero);
            break;
        case THE_SHADOWING_KID:
            TheShadowingKid(hero);
            break;
        case EXTORTION:
            Extortion(hero);
            break;  
        case THE_TURNCOAT_GUIDE:
            TheTurncoatGuide(hero);
            break;
        case POACHER_TRAP_TRIGGER:
            PoacherTrapTrigger(hero);
            break;
        case FAKE_DISTRESS_CALL:
            FakeDistressCal(hero);
            break;
        case MONEY_FIND:
            MoneyFind(hero);
            break;
        case GOOD_STRANGER:
            GoodStranger(hero);
            break;
        case GOOD_WEATHER:
            GoodWeather(hero);
            break;
        case GOOD_REST:
            GoodRest(hero);
            break;
        default:
            std::cout << "Unknown event type!" << std::endl;
            break;
    }
}
//Nature events========================================
void ToxicRain(Character& hero)
{
hero.GetDamage(hero , 10); 
}

void Rain(Character& hero) //Heavy + light
{
int rainType = rand() % 2; // 0 for light rain, 1 for heavy rain
if (rainType == 0) {
    
    std::cout << "Light rain is falling. It has a minor effect on your health." << std::endl;
    hero.GetDamage(hero, 2); 
} else {
    std::cout << "Heavy rain is falling. It has a significant effect on your health." << std::endl;
    hero.GetDamage(hero, 5); 
}
}

void VolcanicEruption(Character& hero)
{
int random = rand() % 2;
if (random == 0) {
    std::cout << "A volcanic eruption occurs! You run away safely." << std::endl;
} else {
    std::cout << "A volcanic eruption occurs! You take 10 damage." << std::endl;
    hero.GetDamage(hero, 10);
}
}

void FlashFlood(Character& hero)
{
int random = rand() % 2;
if (random == 0) {
    std::cout << "A flood occurs! You run away safely." << std::endl;
} else {
    std::cout << "A flood occurs! You take 10 damage." << std::endl;
    hero.GetDamage(hero, 10);
}
}

void Mudslide(Character& hero)
{
int random = rand() % 2;
if (random == 0) {
    std::cout << "A mudslide occurs! You run away safely." << std::endl;
} else {
    std::cout << "A mudslide occurs! You take 5 damage." << std::endl;
    hero.GetDamage(hero, 5);
}
}

void HumidHot(Character& hero)
{
int random = rand() % 2;
if (random == 0) {
    std::cout << "A hot occurs! You run away safely." << std::endl;
} else {
    std::cout << "All water dried up!" << std::endl;
    std::cout << "You take 5 damage." << std::endl;
    hero.GetDamage(hero, 5);
}}

void ConstrictorVines(Character& hero)
{

}

void WildMagicWilds(Character& hero)
{

}

void QuickFreezingGlad(Character& hero)
{

}

void WillWispAttraction(Character& hero)
{

}

void DeadMagicZone(Character& hero)
{

}

void PollenHallucinations (Character& hero)
{

}

void Earthquake(Character& hero)
{
    
}
//Man events===========================================
void EnemyPatrol(Character& hero)
{

} 

void MonsterAmbush(Character& hero)
{

}

void CunningScavengers(Character& hero)
{

}

void StagedAccident(Character& hero)
{

}

void FalseHospitableHost(Character& hero)
{

}

void ThePropheticBeggar(Character& hero)
{

}

void TheShadowingKid(Character& hero)
{

}

void Extortion(Character& hero)
{

}

void TheTurncoatGuide(Character& hero)
{

}
//NonLive events=================================
void PoacherTrapTrigger(Character& hero)
{

}

void FakeDistressCal(Character& hero)
{

}

//Successful events=================================

void MoneyFind(Character& hero)
{
    int gold = rand() % 100 + 1; // Random gold between 1 and 100
    hero.SetGold(hero.GetGold() + gold); // Increase the hero's gold by the
    std::cout << "You found some money! Your gold increases by " << gold << std::endl;
}

void GoodStranger(Character& hero)
{

}

void GoodWeather(Character& hero)
{
std::cout << "The weather is favorable! You feel rejuvenated." << std::endl;
}
void GoodRest(Character& hero)
{
    int health = rand () % 20 + 10; 
    std::cout << "You found a safe place to rest. "<< health <<"health  restored." << std::endl;
    hero.SetHealth(health + 10); 
}