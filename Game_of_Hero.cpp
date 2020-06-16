#include "vector"
#include "ctime"
#include "hero_class.h"
#include "screens.h"
#include "game_engine.h"

using namespace std;

const int EnemiesNumber = 10;
Enemyclass Enemies[EnemiesNumber];
int Enemyclass::AliveEnemies = EnemiesNumber;

Heroclass Hero (1, 1);
Heroclass* pHero = &Hero;

bool inBattle = false;
bool Graal_IsFound = false;

int main()
{
	srand(time(0));

	int turn = 1;
	char action =' ';
	char map[MapWidth][MapLength];
	int EnemyNumber = 0; // number of active enemy
	const int TurnNumberLevelup = 25; // frequency of enemies level up

	breefing();
	show_help();
	place_Enemies();

	do {
		fill_map(map);
		if ((turn / TurnNumberLevelup > Enemies[0].get_level() - 1) && (inBattle == false)){
			level_up_enemies(Enemies);
		}

		show_enemies_on_map(map, Enemies);

		map[Hero.get_width()][Hero.get_length()] = 'H'; // show Hero on the map

		if (inBattle == false && (Hero.is_alive())){  //regeneration if not in battle
			Hero.regen();
			for (int i = 0; i < EnemiesNumber; i++){
				if (Enemies[i].is_alive()){
					Enemies[i].regen();
				}
			}
		}
		show_map(map);
		show_status(pHero, &Enemies[EnemyNumber], turn, action);

		if (!Hero.is_alive()){
			show_str("You are defeated!\n");
			enter_q_to_quit();
		}

		if (Graal_IsFound){
			show_str("You found the Graal! You are the real HERO!\a\n");
			enter_q_to_quit();
		}

		if ((Hero.is_alive()) && (Graal_IsFound == false)){
			action = processing_action(pHero);
			if (action == 'f'){
				fight(pHero, &Enemies[EnemyNumber]);
			}

			// check for 'step on' enemy
			for (int i = 0; i < EnemiesNumber; i++) {
				if (Enemies[i].is_alive() &&
					Hero.get_width() == Enemies[i].get_width() &&
					Hero.get_length() == Enemies[i].get_length() ) {

					inBattle = true;
					EnemyNumber = i;
					break;
				} else {
					inBattle = false;
				}
			}
		}
		turn++;
	} while (action != 'q'); // quit from game
	return 0;
}


