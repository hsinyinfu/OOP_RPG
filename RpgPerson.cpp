#include "RpgPerson.h"
RpgPerson::RpgPerson(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y,int _currentMap):RpgCreature(_name,_maxHp,_strength,_defence){
	level=1;
	experience=0;
	x = _x;
	y = _y;
	currentMap = _currentMap;
}
int RpgPerson::getX(){
    return x;
}
int RpgPerson::getY(){
    return y;
}
void RpgPerson::setPosition(int _x, int _y){
    x = _x;
	y = _y;
}
void RpgPerson::move(int xMove, int yMove){
	x+=xMove;
	y+=yMove;
}
void RpgPerson::raiseExperience(int value){
    experience+=value;
}
bool RpgPerson::checkLevelUp(){
    if(experience>=level)
		return 1;
	else
		return 0;
}
void RpgPerson::levelUp(){
    experience-=level;
	level++;
}
void RpgPerson::statusUp(){
    maxHp+=5;
	strength+=1;
	defence+=1;
}
void RpgPerson::printStatus(){
	std:: cout <<"Name: " <<name <<std::endl;
	std::cout <<"Lv: " <<level <<std::endl;
	std::cout <<"Hp: " <<maxHp <<std::endl;
	std::cout <<"Strength: " <<strength <<std::endl;
	std::cout <<"Defence: " <<defence <<std::endl;
	std::cout <<"Exp: " <<experience <<"/" <<level <<std::endl;
}
int RpgPerson::getLevel(){
	return level;
}
