#include "RpgCreature.h"

RpgCreature::RpgCreature(){}
RpgCreature::RpgCreature(std::string name){
	this->name = name;
}
RpgCreature::RpgCreature(std::string name, int maxHp, int strength, int defence){
	this->name = name;
	this->maxHp = maxHp;
	this->strength = strength;
	this->defence = defence;
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
void RpgCreature::attack(RpgCreature& enemy){
    int damage = strength - enemy.getDefence();
	enemy.loseHp(damage);
}
void RpgCreature::setCurrentMap(int mapIndex){
	currentMap = mapIndex;
}
int RpgCreature::getCurrentMap(){
	return currentMap;
}
