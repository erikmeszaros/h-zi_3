#include "Character.h"
#include <iostream>


Character::Character(std::string char_name,  int char_hp, int char_dmg, double char_attackCD ) : name(char_name),hp(char_hp), damage(char_dmg), attackCD(char_attackCD) {
}
std::string Character::getName() const {
	return name;
}
int Character::getHp() const {
	return hp;
}
int Character::getDamage() const{
	return damage;
}
double Character::getAttackCD() const{
	return attackCD;
}
void Character::attack(Character&  target) const{
	if (target.getHp() < getDamage()){
		target.hp=0;
	}
	else{
		target.hp-=getDamage();	
	}
}
bool Character::isDead() const{
	return getHp()==0;
}
Character Character::parseUnit(const std::string &filename){
	std::ifstream file;
	file.open(filename);
	if (!file.is_open()) throw -99;
	else{
		std::string line;
		std::size_t found;
		std::string name;
		int hp,dmg;
		double attackCD;
		while (std::getline(file,line)){
  			if (found=line.find("name")!=std::string::npos){
				found=line.find(":");
				line=line.substr(found,line.length());
				found=line.find("\"");
				std::size_t found2;
				found2=line.find_last_of("\"");
				name=line.substr(found+1,found2-found-1);
			}
   			else if (found=line.find("hp")!=std::string::npos){
				found=line.find(":");
				hp=std::stoi(line.substr(found+2,line.length()-1));
			}
			else if (found=line.find("dmg")!=std::string::npos){
				found=line.find(":");
				dmg=std::stoi(line.substr(found+2,line.length()-1));
			}
			else if (found=line.find("attackcooldown")!=std::string::npos){
				found=line.find(":");
				attackCD=std::stod(line.substr(found+2,line.length()-1));
			}
		}
		file.close();
		return Character(name, hp, dmg, attackCD);
	}
}
std::ostream& operator<<(std::ostream& os, const Character& character){
    os <<character.getName()<<" wins. Remaining HP:"<<character.getHp()<<"\n";
    return os;
}

void Character::take_turn (Character& target, bool& end){
	attack(target);
	if (target.isDead()){
		end=true;
		std::cout<<this;
	}
}
void Character::battle_help(Character& faster, Character& slower, bool const defenderIsFaster, bool& end){
	double time=slower.getAttackCD();
	double counter=faster.getAttackCD();
	while(!end){
		time-=counter;
		if (time==0){
			time+=slower.getAttackCD();
			if (defenderIsFaster){
				slower.take_turn(faster,end);
				if (!end) faster.take_turn(slower,end);
			}
			else{
				faster.take_turn(slower,end);
				if (!end) slower.take_turn(faster,end);
			}
		}
		else if (time<0){
			time+=slower.getAttackCD();
			slower.take_turn(faster,end);
			if (!end) faster.take_turn(slower,end);
		}
		else{
			faster.take_turn(slower,end);
		}
	}
}
void Character::battle(Character& defender){
	bool defenderIsFaster=defender.getAttackCD()<attackCD;
	bool end=false;
	if (defenderIsFaster){
		battle_help(defender,*this,defenderIsFaster,end);
	}
	else{
		battle_help(*this,defender,defenderIsFaster,end);
	}
}

