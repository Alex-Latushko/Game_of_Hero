#pragma once
#include <string>

class Heroclass{
private:
	bool alive;
	std::string name;
	int width, length;
	int level, health, strength, endurance, regeneration, agility, luck;
	int damage_dealed;

public:
	Heroclass(int lvl = 1, int advantage = 0);

	void regen();
	void add_health(int value);
	void strike(Heroclass* defence);

	void set_alive(bool bl);
	bool is_alive() const;

	void set_name(std::string str);
	const std::string get_name() const;

	void set_width (int w);
	int get_width () const;
	void increase_width (int n = 1);
	void decrease_width (int n = 1);

	void set_length (int l);
	int get_length () const;
	void increase_length (int n = 1);
	void decrease_length (int n = 1);

	void level_up();
	int get_level() const;
	int get_health() const;
	int get_strength() const;
	int get_endurance() const;
	int get_regeneration() const;
	int get_agility() const;
	int get_luck() const;

	void set_damage_dealed(int dam);
	int get_damage_dealed() const;
};

class Enemyclass : public Heroclass {
public:
	Enemyclass();
	static int AliveEnemies;
};
