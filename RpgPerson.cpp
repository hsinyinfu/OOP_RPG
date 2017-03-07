#include "RpgPerson.h"
RpgPerson::RpgPerson(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y,int _crits, int _level, int _experience, int _coin):RpgCreature(_name,_maxHp,_strength,_defence,_crits),x(_x),y(_y),level(_level),experience(_experience),coin(_coin){}

RpgPerson::~RpgPerson(){}

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
void RpgPerson::setExperience(bool up_down,int value){
    if(up_down)	//1=add
		experience+=value;
	else{	//0=subtract
		if(value==0)
			experience=0;
		else
			experience-=value;
	}
}
bool RpgPerson::checkLevelUp(){
    if(experience>=requiredExp)
		return 1;
	else
		return 0;
}
void RpgPerson::levelUp(){
	int requiredExp = (int)(7*(0.5+(float)getLevel()/2));
    experience-=requiredExp;
	level++;
	setRequiredExp();
}
int RpgPerson::getLevel(){
	return level;
}
int RpgPerson::getExperience(){
	return experience;
}
void RpgPerson::setRequiredExp(){
	requiredExp = (int)(7*(0.5+((float)level/2)));
}
int RpgPerson::getRequiredExp(){
	return requiredExp;
}
int RpgPerson::getCoin(){
	return coin;
}
void RpgPerson::setCoin(int _coin){
	coin += _coin;
}
void RpgPerson::recoverHp(){
	currentHp = maxHp;
}
