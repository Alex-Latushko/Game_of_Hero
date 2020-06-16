#include "game_engine.h"

using namespace std;

void fight(Heroclass* pH, Enemyclass* pE)
{
	pH->strike(pE);
	if (!pE->is_alive()){
		pH->level_up();
		if ((rand() % pE->AliveEnemies) < 1){  // check for Grail
			Graal_IsFound = true;
		}
		pE->AliveEnemies--;
	} else {
		pE->strike(pH);
	}
}

void place_Enemies(){  // generate positions of Enemies
	bool theSameCoordinats;
	for (int i = 0; i < Enemyclass::AliveEnemies; i++) {
		do {
			theSameCoordinats = false;
			Enemies[i].set_width(rand() % MapWidth);
			Enemies[i].set_length(rand() % MapLength);
			for (int ii = 0; ii < i; ii++) {
				if (Enemies[i].get_width() == Enemies[ii].get_width() &&
					Enemies[i].get_length() == Enemies[ii].get_length() ){ // check for the same coordinates
					theSameCoordinats = true;
				}
			}
		} while (theSameCoordinats == true);
	}
}

void level_up_enemies(Enemyclass Enemies[]){
	for (int i = 0; i < EnemiesNumber; i++){
		//if (Enemies[i].alive){
			Enemies[i].level_up();
		//}
	}
}

void show_enemies_on_map(char map[MapWidth][MapLength], Enemyclass Enemies[]){
	for (int i = 0; i < EnemiesNumber; i++){
		if (Enemies[i].is_alive()){
			map[Enemies[i].get_width()][Enemies[i].get_length()] = 'E';
		}
	}
}

void fill_map(char map[MapWidth][MapLength]){//fill map with blank cells
	for (int i = 0; i < MapLength; ++i){
		for (int j = 0; j < MapWidth; ++j){
			map[j][i] = '-';
		}
	}
}

char processing_action(Heroclass* pHero){
	char action;
	bool is_right_action;
	show_str("What is your next action, Hero? (enter 'h' for help)\n");
	do {
		is_right_action = true;
		action = get_action();
		switch (action)
		{
		case 'w':
			if (pHero->get_length() > 0) {
				pHero->decrease_length();
			} else {
				show_str("End of the World! Go another way!\n");
				is_right_action = false;
			}
			break;

		case 's':
			if (pHero->get_length() < (MapLength - 1)) {
				pHero->increase_length();
			} else {
				show_str("End of the World! Go another way!\n");
				is_right_action = false;
			}
			break;

		case 'd':
			if (pHero->get_width() < (MapWidth - 1)) {
				pHero->increase_width();
			} else {
				show_str("End of the World! Go another way!\n");
				is_right_action = false;
			}
			break;

		case 'a':
			if (pHero->get_width() > 0) {
				pHero->decrease_width();
			} else {
				show_str( "End of the World! Go another way!\n");
				is_right_action = false;
			}
			break;
		case 'h':
			show_help();
			break;
		case 'i':
			show_inf(pHero);
			break;
		case 'q':
			// quit from game
			break;
		case 'f':
			if (inBattle == true){
			} else {
				show_str("You are not in battle! Choose another action\n");
				is_right_action = false;
			}
			break;
		default:
			show_str("There is no such action! Enter 'h'for help\n");
			is_right_action = false;
		};
	} while (is_right_action == false);
	return action;
}
