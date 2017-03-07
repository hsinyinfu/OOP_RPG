#include "RpgCreature.h"


RpgCreature::RpgCreature(){}
RpgCreature::RpgCreature(std::string name){
	this->name = name;
}
RpgCreature::RpgCreature(std::string name, int maxHp, int strength, int defence, int crits){
	this->name = name;
	this->maxHp = maxHp;
	this->strength = strength;
	this->defence = defence;
	this-> crits = crits;
	currentHp = maxHp;
}
std::string RpgCreature::getName(){
   return name; 
}
int RpgCreature::getMaxHp(){
    return maxHp;
}
int RpgCreature::getCurrentHp(){
    return currentHp;
}
int RpgCreature::getStrength(){
    return strength;
}
int RpgCreature::getDefence(){
    return defence;
}
int RpgCreature::getCrits(){
	return crits;
}
bool RpgCreature::isDead(){
   if(currentHp<0 || currentHp==0)
	  return 1;
   else
	  return 0; 
}
void RpgCreature::loseHp(int value){
    currentHp-=value;
}
void RpgCreature::recoverHp(){
   currentHp = maxHp;
}
int RpgCreature::attack(RpgCreature& enemy){
	int extraDamage = rand()%7-3;
    int damage = strength - enemy.getDefence() + extraDamage;
	if( rand()%1000 <= crits){
		std::cout <<"<" <<name <<" has crits!" <<">\n";
		damage*=2;
	}
	if(enemy.getDefence() >= damage){
		enemy.loseHp(1);
		return 1;
	}
	else{
		enemy.loseHp(damage);
		return damage;
	}
}
void RpgCreature::setCurrentHp(int _currentHp){
	currentHp = _currentHp;
}
