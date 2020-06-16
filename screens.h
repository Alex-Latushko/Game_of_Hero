#pragma once
#include <iostream>
#include "hero_class.h"

const int ScreenWidth = 119;
const int ScreenLength = 30;
const int MapWidth = 50;
const int MapLength = 15;

extern bool inBattle;

void show_help();
void breefing(); //start screen
void show_inf(const Heroclass* pH); //screen with info about hero
void show_map(char array1[MapWidth][ MapLength]);
void show_status(const Heroclass* pH, const Heroclass* pE, int turn, char act = ' ');
void show_str(std::string const& str);
void show_str_cout(std::string const& str);
char get_action();
char get_action_cin();
void enter_q_to_quit();




