#include "screens.h"
using namespace std;

void show_help()  // list of possible actions
{
	system("cls");
	int i = 1;
	cout << i++ << ".Possible actions" << endl;
	cout << i++ << ".Movement:" << endl;
	cout << i++ << ".'w' - move up" << endl;
	cout << i++ << ".'s' - move down" << endl;
	cout << i++ << ".'a' - move left" << endl;
	cout << i++ << ".'d' - move right" << endl;
	cout << i++ << ".Different:" << endl;
	cout << i++ << ".'f' - fight with the Enemy" << endl;
	cout << i++ << ".'i' - info about the Hero" << endl;
	cout << i++ << ".'b' - back to the main screen" << endl;
	cout << i++ << ".'q' - quit" << endl;
	int Neededlines = 2; // 1 line for info and 1 line for enter of the player's action
	for (; i <= (ScreenLength - Neededlines); ++i){ // fill the empty part of the screen
		cout << endl;
	}
	cout << "Enter anykey to return to the main screen." << endl;
	char ch;
	cin >> ch;
}

void breefing()
{
	system("cls");
	int i = 1;
	for (; i <= 10; ++i){ // skip first 10 lines from the top
		cout << endl;
	}
	// width of letter: 5 chars, height 7 chars, space between letters: 2 chars;
	cout << string(40, ' ') << "*****  *   *  *****     *****    *    *   *  *****" << string(20, ' ') << endl;
	cout << string(40, ' ') << "  *    *   *  *         *       * *   ** **  *    " << string(20, ' ') << endl;
	cout << string(40, ' ') << "  *    *   *  *         *       * *   ** **  *    " << string(20, ' ') << endl;
	cout << string(40, ' ') << "  *    *****  *****     *  **   ***   * * *  *****" << string(20, ' ') << endl;
	cout << string(40, ' ') << "  *    *   *  *         *   *  *   *  *   *  *    " << string(20, ' ') << endl;
	cout << string(40, ' ') << "  *    *   *  *         *   *  *   *  *   *  *    " << string(20, ' ') << endl;
	cout << string(40, ' ') << "  *    *   *  *****     *****  *   *  *   *  *****" << string(20, ' ') << endl;

	int Neededlines = 10; //7 lines for title, 2 lines for description, 1 line for enter of the player's action
	for (; i <= (ScreenLength - Neededlines); ++i){ // fill the empty part of the screen
		cout << endl;
	}
	cout << "One from the evil Es stole the Grail! Find it and prove that you are the real HERO!" << endl;
	cout << "Enter anykey to continue" << endl;
	char ch;
	cin >> ch;
}

void show_inf(const Heroclass*pH)
{
	system("cls");
	int i = 1;
	cout << i++ << ". Level:" << pH->get_level() << endl;
	cout << i++ << ". Strength:" << pH->get_strength() << endl;
	cout << i++ << ". Endurance:" << pH->get_endurance() << endl;
	cout << i++ << ". Regeneration:" << pH->get_regeneration() << endl;
	cout << i++ << ". Agility:" << pH->get_agility() << endl;
	cout << i++ << ". Luck:" << pH->get_luck() << endl;
	cout << i++ << ". Health:" << pH->get_health() << endl;
	int Neededlines = 2; // 1 line for info and 1 line for enter of the player's action
	for (; i <= (ScreenLength - Neededlines); ++i){ // fill the empty part of the screen
		cout << endl;
	}
	cout << "Enter anykey to return to the main screen." << endl;
	char ch;
	cin >> ch;
}

void show_map(char array1[MapWidth][MapLength])
{
	system("cls");
	cout << string(56, '_') << "THE GAME" << string(55, '_') << endl;
	for (int i = 0; i < MapLength; ++i)
	{
		for (int j = 0; j < MapWidth; ++j)
		{
			cout << array1[j][i];
		}
		cout << endl;
	};
	cout << string(ScreenWidth, '*') << endl;
}

void show_status(const Heroclass* pH, const Heroclass* pE, int turn, char act)
{
	std::string battle_message = "";
	int i = 1;
	cout << i++ << ". Hero status:" << endl;
	cout << i++ << ". Health: " << pH->get_health() << endl;
	cout << i++ << ". Turn number: " << turn << endl;
	if (inBattle == true)
	{
		battle_message += "You are in BATTLE!";
		cout << i++ << ". Enemy level: " << pE->get_level() << endl;
		cout << i++ << ". Enemy Health:" << pE->get_health() << endl;
	}
	i++;
	cout << string(ScreenWidth,'*') << endl;
	if ( act == 'f'){
		if (pH->get_damage_dealed() == 0){
			battle_message += pE->get_name() + " dodge! ";
		} else if (pH->get_damage_dealed() == pH->get_strength() * 5 * 2){   //TO DO after level up you cannot see Critical strike
			battle_message +=pH->get_name() + " made critical strike! ";
		}

		if (pE->get_damage_dealed() == 0){
			battle_message += pH->get_name() + " dodge! ";
		} else if (pE->get_damage_dealed() == pE->get_strength() * 5 *2){
			battle_message +=pE->get_name()+ " made critical strike! ";
		}

		if (!pE->is_alive()){
			battle_message += "Enemy defeated! ";
		}
		if (!pH->is_alive()){
			battle_message += "You lose!!! ";
		}
	}

	cout << i++ << ". Battle Message:" << battle_message << endl;
	if  ((act == 'f') ) // show damage, if Hero choose to fight
	{
		i++;
		cout << "You deal " << pH->get_damage_dealed() << " damage!\n";
		i++;
		cout << "Enemy deal " << pE->get_damage_dealed() << " damage!\n";
	}
	int Neededlines = 5; // 2 lines for map borders, 1 line for border between Message and player's info,
						 // 1 line for info, 1 line for enter of the player's action
	for (; i <= ScreenLength - MapLength - Neededlines; ++i){ // fill the empty part of the screen
		cout << endl;
	}
	cout << string(ScreenWidth, '*') << endl;
}

void show_str(std::string const& str){
	show_str_cout(str);
}

void show_str_cout(std::string const& str){
	std::cout << str;
}

void enter_q_to_quit(){
	char action;
	do {
		show_str("Enter 'q' to quit.\n");
		cin >> action;
	} while (action != 'q');
	exit(0);
}

char get_action(){
	return get_action_cin();
}

char get_action_cin(){
	char action;
	cin >> action;
	cin.ignore(100, '\n');
	return action;
}
