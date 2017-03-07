#include "job.h"
#include "Battle.h"
SwordMan::SwordMan(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y,int _currentMap,int _crits):RpgPerson(_name,_maxHp,_strength,_defence,_x,_y,_currentMap,_crits){}

Thief::Thief(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y,int _currentMap,int _crits):RpgPerson(_name,_maxHp,_strength,_defence,_x,_y,_currentMap,_crits){}

Magician::Magician(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y,int _currentMap,int _crits):RpgPerson(_name,_maxHp,_strength,_defence,_x,_y,_currentMap,_crits){}

SwordMan::~SwordMan(){}

Thief::~Thief(){}

Magician::~Magician(){}
void SwordMan::statusUp(){
	maxHp+=5;
	strength+=1;
	defence+=2;
	crits+=0;
}
void Thief::statusUp(){
	maxHp+=5;
	strength+=1;
	defence+=1;
	crits+=5;
}
void Magician::statusUp(){
	maxHp+=5;
	strength+=2;
	defence+=1;
	crits+=0;
}
void SwordMan::printStatus(){
	std::cout <<"Name: " <<name <<std::endl;
	std::cout <<"Lv: " <<level <<std::endl;
	std::cout <<"Job: " <<"SwordMan" <<std::endl;
	std::cout <<"Hp: " <<currentHp <<std::endl;
	std::cout <<"Strength: " <<strength <<std::endl;
	std::cout <<"Defence: " <<defence <<std::endl;
	std::cout <<"Crits: " <<crits <<std::endl;
	std::cout <<"Exp: " <<experience <<"/" << requiredExp <<std::endl;

}
void Thief::printStatus(){
	std::cout <<"Name: " <<name <<std::endl;
	std::cout <<"Lv: " <<level <<std::endl;
	std::cout <<"Job: " <<"Thief" <<std::endl;
	std::cout <<"Hp: " <<currentHp <<std::endl;
	std::cout <<"Strength: " <<strength <<std::endl;
	std::cout <<"Defence: " <<defence <<std::endl;
	std::cout <<"Crits: " <<crits <<std::endl;
	std::cout <<"Exp: " <<experience <<"/" <<requiredExp <<std::endl;

}
void Magician::printStatus(){
	std::cout <<"Name: " <<name <<std::endl;
	std::cout <<"Lv: " <<level <<std::endl;
	std::cout <<"Job: " <<"Magicain" <<std::endl;
	std::cout <<"Hp: " <<currentHp <<std::endl;
	std::cout <<"Strength: " <<strength <<std::endl;
	std::cout <<"Defence: " <<defence <<std::endl;
	std::cout <<"Crits: " <<crits <<std::endl;
	std::cout <<"Exp: " <<experience <<"/" <<requiredExp <<std::endl;

}
void SwordMan::useSkill(char skillNumber,RpgPerson& player,Monster& monster){
	switch(skillNumber){
		case'a':{
					int damage = strength+level*2;
					std::cout <<"<"<<name <<" uses the skill:Penetrate!>\n";
					std::cout <<name <<" attacked " <<monster.getName() <<"ignoring its defence, caused " <<damage <<" damages.\n";
					monster.loseHp(damage);
					if(!monster.isDead()){
						std::cout <<monster.getName() <<"'s hp: " <<monster.getCurrentHp() <<".\n";
						fight(monster,player);
					}
					else
						std::cout <<monster.getName() <<"'s hp: 0.\n";
					break;}
		case'b':{
					if(level<2){
						std::cout <<"Can’t use this skill! Your Level is too low!\n";
						break;
					}
					else{
						int tmp = maxHp - currentHp;
						if(tmp==0){
							std::cout <<"Your HP is maximum.\n";
							break;
						}
						std::cout <<"<"<<name <<" uses the skill:Healing!>\n";
						int heal = (rand()%tmp)+1;
						std::cout <<name <<" got " <<heal <<" hp.\n";
						currentHp+=heal;
						std::cout <<name <<"'s hp: " <<currentHp <<".\n";
						fight(monster,player);
						break;}}
		case'c':{
					if(level<3){
						std::cout <<"Can’t use this skill! Your Level is too low!\n";
						break;
					}
					else{
						std::cout <<"<"<<name <<" uses the skill:Reflection!>\n";
						std::cout <<monster.getName() <<" attacked itself.\n";
						fight(monster,monster);
						break;}}
		default:
						std::cout<<"Wrong input!!!\n";
						break;
	}
}
void Thief::useSkill(char skillNumber,RpgPerson& player,Monster& monster){
	switch(skillNumber){
		case'a':{
					int damage = strength+level*2;
					std::cout <<"<"<<name <<" uses the skill:Penetrate!>\n";
					std::cout <<name <<" attacked " <<monster.getName() <<"ignoring its defence, caused " <<damage <<" damages.\n";
					monster.loseHp(damage);
					if(!monster.isDead()){
						std::cout <<monster.getName() <<"'s hp: " <<monster.getCurrentHp() <<".\n";
						fight(monster,player);
					}
					else
						std::cout <<monster.getName() <<"'s hp: 0.\n";
					break;}
		case'b':{
					if(level<2){
						std::cout <<"Can’t use this skill! Your Level is too low!\n";
						break;
					}
					else{
						int tmp = strength - monster.getDefence();
						std::cout <<"<"<<name <<" uses the skill:Blood Sucking!>\n";
						int suck = rand()%tmp*(1+level);
						std::cout <<name <<" sucked " <<monster.getName() <<" "<<suck <<" hp.\n";
						currentHp+=suck;
						if(currentHp>maxHp)
							currentHp = maxHp;
						monster.loseHp(suck);
						std::cout <<"[" <<name <<"'s hp: " <<currentHp <<".]\n";
						if(!monster.isDead()){
							std::cout <<"[" <<monster.getName() <<"'s hp: " <<monster.getCurrentHp() <<".]\n";
							fight(monster,player);
						}
						else
							std::cout <<"[" <<monster.getName() <<"'s hp: 0.]\n";
						break;}}
		case'c':{
					if(level<3){
						std::cout <<"Can’t use this skill! Your Level is too low!\n";
						break;
					}
					else{
						std::cout <<"<"<<name <<" uses the skill:Reflection!>\n";
						std::cout <<monster.getName() <<" attacked itself.\n";
						fight(monster,monster);
						break;}}
		default:
						std::cout<<"Wrong input!!!\n";
						break;
	}
}
void Magician::useSkill(char skillNumber,RpgPerson& player,Monster& monster){
	switch(skillNumber){
		case'a':{
					int damage = strength+level*2;
					std::cout <<"<"<<name <<" uses the skill:Penetrate!>\n";
					std::cout <<name <<" attacked " <<monster.getName() <<"ignoring its defence, caused " <<damage <<" damages.\n";
					monster.loseHp(damage);
					if(!monster.isDead()){
						std::cout <<monster.getName() <<"'s hp: " <<monster.getCurrentHp() <<".\n";
						fight(monster,player);
					}
					else
						std::cout <<monster.getName() <<"'s hp: 0.\n";
					break;}
		case'b':{
					if(level<2){
						std::cout <<"Can’t use this skill! Your Level is too low!\n";
						break;
					}
					else{
						int tmp = maxHp - currentHp;
						if(tmp==0){
							std::cout <<"Your HP is maximum.\n";
							break;
						}
						std::cout <<"<"<<name <<" uses the skill:Healing!>\n";
						int heal = (rand()%tmp)+1;
						std::cout <<name <<" got " <<heal <<" hp.\n";
						currentHp+=heal;
						std::cout <<name <<"'s hp: " <<currentHp <<".\n";
						fight(monster,player);
						break;}}
		case'c':{
					if(level<3){
						std::cout <<"Can’t use this skill! Your Level is too low!\n";
						break;
					}
					else{
						std::cout <<"<"<<name <<" uses the skill:Reflection!>\n";
						std::cout <<monster.getName() <<" attacked itself.\n";
						fight(monster,monster);
						break;
						default:
						std::cout<<"Wrong input!!!\n";
						break;}}
	}
}
void SwordMan::printSkill(){
	std::cout <<"******************************\n"<<"*   a.Penetrate              *\n"<<"*   b.Healing                *\n"<<"*   c.Reflection             *\n"<<"******************************\n";
}
void Thief::printSkill(){
	std::cout <<"******************************\n"<<"*   a.Penetrate              *\n"<<"*   b.Blood Sucking          *\n"<<"*   c.Reflection             *\n"<<"******************************\n";
}
void Magician::printSkill(){
	std::cout <<"******************************\n"<<"*   a.Penetrate              *\n"<<"*   b.Healing                *\n"<<"*   c.Reflection             *\n"<<"******************************\n";
}
