#include "hero_class.h"

Heroclass::Heroclass(int lvl, int advantage)  // TODO check for max_level
{
	alive = true;
	width = 25;
	length = 8;
	level = lvl;
	strength = advantage + lvl;
	endurance = advantage + lvl;
	regeneration = advantage + lvl;
	agility = advantage + lvl;
	luck = advantage + lvl;
	health = 90 + (endurance * 10);
	damage_dealed = 0;
	name = "You";
}

void Heroclass::level_up()
{
	level++;
	strength++;
	endurance++;
	regeneration++;
	agility++;
	luck++;
}

void Heroclass::regen(){
	add_health(regeneration);
}

void Heroclass::add_health(int value){
	health += value;
	if (health > 90 + (endurance * 10)){
		health = 90 + (endurance * 10);
	};
	if (health <= 0){
		health = 0;
		alive = false;
	}
}

void Heroclass::set_alive(bool bl){
	alive = bl;
}

bool Heroclass::is_alive() const{
	return alive;
}


void Heroclass::set_name(std::string str){
	name = str;
}

const std::string Heroclass::get_name() const{
	return name;
}



void Heroclass::strike( Heroclass* defence){
	int Critical = 1;
	int Dodge = 1;
	if ((rand() % 10 + 1) <= luck){  // check for critical strike
		Critical = 2;
	}
	if ((rand() % 10 + 1) <= defence->agility){ //check for dodge
		Dodge = 0;
	}
	damage_dealed =  5 * strength
						* Critical
						* Dodge;
	defence->add_health(-damage_dealed);
}

void Heroclass::set_width (int w) { width = w; }
int Heroclass::get_width () const { return width; }
void Heroclass::increase_width (int n) { width += n; }
void Heroclass::decrease_width (int n) { width -= n; }

void Heroclass::set_length (int w) { length = w; }
int Heroclass::get_length () const { return length; }
void Heroclass::increase_length (int n) { length += n; }
void Heroclass::decrease_length (int n) { length -= n; }

int Heroclass::get_level() const{ return level; }
int Heroclass::get_health() const {return health; }
int Heroclass::get_strength() const {return strength; }
int Heroclass::get_endurance() const {return endurance; }
int Heroclass::get_regeneration() const {return regeneration; }
int Heroclass::get_agility() const {return agility; }
int Heroclass::get_luck() const {return luck; }

void Heroclass::set_damage_dealed(int dam){ damage_dealed = dam; }
int Heroclass::get_damage_dealed() const { return damage_dealed; }

Enemyclass::Enemyclass(){
	set_name("Enemy");
}
