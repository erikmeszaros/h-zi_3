#include <string>
#include <iostream>
#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H
#include <fstream>
class Character
{
private:
	int hp;
	const int  damage;
	const double attackCD;
	const std::string name;
	void attack(Character& target) const;
	bool isDead() const;
	void battle_help(Character& faster, Character& slower, bool const defenderIsFaster, bool& end);

public:
	Character(std::string char_name, int char_hp, int char_dmg, double attackCD);
	std::string getName() const;
	int getHp() const;
	int getDamage() const;
	double getAttackCD() const;
	void take_turn (Character& target, bool& end);
	void battle(Character& defender);
	friend std::ostream& operator<<(std::ostream& os, const Character& character);
	static Character parseUnit(const std::string &filename );
};
std::ostream& operator<<(std::ostream& os, const Character& character);
#endif
