#pragma once
#include "hero_class.h"
#include "screens.h"

extern const int EnemiesNumber;
extern Enemyclass Enemies[];
extern bool inBatlle;
extern bool Graal_IsFound;
extern const int MapWidth;
extern const int MapLength;

void place_Enemies();
void fight(Heroclass* pH, Enemyclass* pE);

void level_up_enemies(Enemyclass Enemies[]);
void show_enemies_on_map(char map[MapWidth][MapLength], Enemyclass Enemies[]);
void fill_map(char map[MapWidth][MapLength]);
char processing_action(Heroclass* pHero);
