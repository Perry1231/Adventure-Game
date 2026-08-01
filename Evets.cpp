    #include "Header.h"
//Additional events for game


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