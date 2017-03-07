#include<iostream>
#include<fstream>
#include "Map.h"
#include "RpgCreature.h"
#include "RpgPerson.h"
#include "Monster.h"
#include "job.h"
#include "Battle.h"
#include "enemy.h"
#include "save.h"
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void printOperationNotice();
int walk(Map& map, RpgPerson& player, int xMove, int yMove);
bool loadMap(vector<Map>& map);
void moveToNextMap(vector<Map>& map,int& currentMapIndex,RpgPerson& player);
bool readSave(vector<Save>& save);
void printRecord(vector<Save>& save);
bool saveRecord(vector<Save>& save, RpgPerson& player, string currentMapName);
int main(){
	cout <<" -----------------------------------------\n" <<"|     Welcome to oop assignment4 rpg.     |\n" <<" -----------------------------------------\n" <<"| 1. New game                             |\n| 2. Load game                            |\n| 3. Exit                                 |\n"<<" -----------------------------------------\n"<<"Enter your choice:";
	char choice;
	RpgPerson* player=NULL;
	vector<Map> map;
	vector<Save> save;
	int currentMapIndex=0;
	if(!loadMap(map))
		return 0;
	while(cin >> choice){
		if(choice!='1' && choice!='2' && choice!='3')
			cout <<"Wrong input\n";
		else
			break;
	}
	if(!readSave(save) && choice=='2'){
		cout <<"You have 0 record.Start a new game automatically.\n";
		choice = '1';
	}
	switch(choice){
		case '1':{
				   cout <<"Enter your name:";//吃名字
				   string _name;
				   char _job;
				   cin >> _name;
				   cout <<"Enter your job(1-3):(1.SwordMan 2.Thief 3.Magician)";
				   cin >> _job;
				   while(_job!='1' && _job!='2' && _job!='3'){
					   cout<<"Please enter 1 or 2 or 3\n";
					   cin >>_job;
				   }
				   switch(_job){
					   case'1':{
								   player = new SwordMan(_name,100,7,2,map[currentMapIndex].getinitialPositionX(),map[currentMapIndex].getinitialPositionY(),20);
								   player->setRequiredExp();
								   map[currentMapIndex].addPlayer((*player));
								   break;}
					   case'2':{
								   player = new Thief(_name,100,7,2,map[currentMapIndex].getinitialPositionX(),map[currentMapIndex].getinitialPositionY(),20);
								   player->setRequiredExp();
								   map[currentMapIndex].addPlayer((*player));
								   break;}
					   case'3':{
								   player = new Magician(_name,100,7,2,map[currentMapIndex].getinitialPositionX(),map[currentMapIndex].getinitialPositionY(),20);
								   player->setRequiredExp();
								   map[currentMapIndex].addPlayer((*player));
								   break;}
				   }
				   break;
			   }
		case '2':{	
				   printRecord(save);
				   cout <<"Load record(Enter 1, 2, ...):";
				   int record;
				   while(cin >> record){
					   if(record>save.size() || record<1)
						   cout <<"Wrong input!\n";
					   else
						   break;
				   }
				   record--;
				   if(save[record].getSaveJob() == "SwordMan")
					   player = new SwordMan(save[record].getSaveName(),save[record].getSaveMaxHp(),save[record].getSaveStrength(),save[record].getSaveDefence(),save[record].getSaveCurrentX(),save[record].getSaveCurrentY(),save[record].getSaveCrits(),save[record].getSaveLevel(),save[record].getSaveExperience(),save[record].getSaveCoin());
				   else if(save[record].getSaveJob() == "Thief")
					   player = new Thief(save[record].getSaveName(),save[record].getSaveMaxHp(),save[record].getSaveStrength(),save[record].getSaveDefence(),save[record].getSaveCurrentX(),save[record].getSaveCurrentY(),save[record].getSaveCrits(),save[record].getSaveLevel(),save[record].getSaveExperience(),save[record].getSaveCoin());
				   else
					   player = new Magician(save[record].getSaveName(),save[record].getSaveMaxHp(),save[record].getSaveStrength(),save[record].getSaveDefence(),save[record].getSaveCurrentX(),save[record].getSaveCurrentY(),save[record].getSaveCrits(),save[record].getSaveLevel(),save[record].getSaveExperience(),save[record].getSaveCoin());
				   player->setCurrentHp(save[record].getSaveCurrentHp());
				   for(Map _map:map){
					   if(_map.getName() == save[record].getSaveCurrentMap())
						   break;
					   else
						   currentMapIndex++;
				   }
				   player->setRequiredExp();
				   map[currentMapIndex].addPlayer((*player));
				   break;
			   }
		case '3':{
				   return 0;}
	}
	map[currentMapIndex].printMap();
	printOperationNotice();
	srand((unsigned)time(NULL));
	string command;
	while(cin >> command){
		if(command == "exit"){
			delete player;
			return 0;
		}
		else if(command == "i")
			map[currentMapIndex].printStatus();
		else if(command == "h"){
			if(player->getCurrentHp() == player->getMaxHp())
				cout <<"Your HP is maximum.\n";
			else{
				cout <<"Use 5 coins to recover your hp.(yes/no)\n";
				string confirm;
				while(cin >> confirm){
					if(confirm!="yes" && confirm!="no")
						cout <<"Wrong input.\n";
					else
						break;
				}
				if(confirm == "no"){}
				else{
					if(player->getCoin() < 5)
						cout <<"You don't have enough coins.("<<player->getCoin()<<"/5)\n";
					else{
						cout <<"Hp  recovered.\n";
						player->setCoin(-5);
						player->recoverHp();
					}
				}
			}
		}
		else if(command == "save")
			saveRecord(save,(*player),map[currentMapIndex].getName());
		else if(command =="w" || command =="s" || command == "a" || command == "d"){
			if(command == "a"){
				if(!walk(map[currentMapIndex],*(player),-1,0))
					continue;
			}
			else if(command == "d"){
				if(!walk(map[currentMapIndex],*(player),1,0))
					continue;
			}
			else if(command == "w"){
				if(!walk(map[currentMapIndex],*(player),0,-1))
					continue;
			}
			else{
				if(!walk(map[currentMapIndex],*(player),0,1))
					continue;
			}
			if(!(rand()%4)){	//fight!
				Monster* monster=NULL;
				meetEnemy(map[currentMapIndex], &monster);
				if(startBattle(*(player),(*monster))){
					if(player->isDead())
						playerLose(*(player));
					else
						playerWin(*(player),(*monster));
				}
				delete monster;
				monster = NULL;
			}
			if(map[currentMapIndex].getMapData(player->getX(),player->getY()) == '@')
				moveToNextMap(map,currentMapIndex,(*player));
		}
		else{
			cout <<"Entered the wrong command! Please try again\n";
			continue;
		}
		map[currentMapIndex].printMap();
		printOperationNotice();
	}
}
void printOperationNotice(){
	cout <<"\n*****\n" <<"Use w/s/a/d to move up/down/left/right.\n" <<"Enter i to show your status.\n" <<"Enter h to recover your hp(need 5 coins).\n" <<"Enter save to save game.\n" <<"Enter exit to leave game.\n" <<"*****\n";
}
bool loadMap(vector<Map>& map){
	ifstream fin("map.txt");
	if(!fin){
		cout <<"Failed to load map data\n" <<"The game is off\n";
		return false;
	}
	string input;
	while(fin >> input){
		string _mapName,_nextMapName;
		_mapName = input;
		fin >> input;
		_nextMapName = input;
		int _x,_y,_width,_height;
		fin >> _x >> _y >> _width >> _height;
		vector<string> _mapData;
		for(int i=0; i<_height; i++){
			fin >> input;
			_mapData.push_back(input);
		}
		fin >> input;
		vector<string> _monster;
		while(input!="---"){
			_monster.push_back(input);
			fin >> input;
		}
		Map tmpMap(_mapName,_nextMapName,_x,_y,_width,_height,_mapData,_monster);
		map.push_back(tmpMap);
	}
	fin.close();	
	return true;
}
int walk(Map& map, RpgPerson& player, int xMove, int yMove){
	if(map.canMove(player.getX()+xMove,player.getY()+yMove)){
		player.move(xMove,yMove);
		return 1;
	}
	else{
		if(xMove > 0)
			cout <<"Can't move right, try another direction.\n";
		else if(xMove < 0)
			cout <<"Can't move left, try another direction.\n";
		else if(yMove > 0)
			cout <<"Can't move down, try another direction.\n";
		else if(yMove < 0)
			cout <<"Can't move up, try another direction.\n";
		return 0;
	}
}
void moveToNextMap(vector<Map>& map,int& currentMapIndex,RpgPerson& player){
	string nextMapName = map[currentMapIndex].getNextMapName();
	map[currentMapIndex].removePlayer();
	int count=0;
	for(Map& _map : map){
		if(_map.getName() == nextMapName){
			currentMapIndex = count;
			_map.addPlayer(player);
			player.setPosition(_map.getinitialPositionX(),_map.getinitialPositionY());
			break;
		}
		else
			count++;
	}
}
bool readSave(vector<Save>& save){
	ifstream fin("save.txt");
	if(!fin)
		return false;
	string name,job,currentMap,input;
	int level,currentHp,maxHp,strength,defence,crits,coin,experience,currentX,currentY;
	while(fin >> name){
		fin >>level >>job >>currentHp >>maxHp >>strength >>defence >>crits >>coin >>experience >>currentMap >>currentX >>currentY;
		Save _save(name,level,job,currentHp,maxHp,strength,defence,crits,coin,experience,currentMap,currentX,currentY);
		save.push_back(_save);
	}
	fin.close();
	return true;
}
void printRecord(vector<Save>& save){
	cout <<"You have " <<save.size() <<" records.\n";
	int record;
	for(record=0 ; record<save.size() ; record++){
		cout <<"-----record " <<record+1 <<"-----\n";
		cout <<"Name: " <<save[record].getSaveName() <<endl;
		cout <<"Job: " <<save[record].getSaveJob() <<endl;
		cout <<"Lv: " <<save[record].getSaveLevel() <<endl;
		cout <<"------------------\n";
	}
}
/*it will go wrong if user enter a english letter.*/
bool saveRecord(vector<Save>& save, RpgPerson& player, string currentMapName){
	printRecord(save);
	cout <<"Save to record (1, 2, ...)";
	int saveTo;
	while(cin >> saveTo){
		if(saveTo < 1 || saveTo > save.size()+1)
			cout <<"Please enter 1 to " <<save.size() <<" to overwritten the existing records,and enter " <<save.size()+1 <<" to have a new record.\n";
		else
			break;
	}
	if(saveTo <= save.size()){
		cout <<"Overwritten record " <<saveTo <<"?(yes/no)";
		string confirm;
		while(cin >> confirm){
			if(confirm == "no")
				return 1;
			else if(confirm == "yes")
				break;
			else
				cout <<"Wrong input\n";
		}
	}
	else
		cout <<"Save to record " <<saveTo <<endl;
	string name,job,currentMap,input;
	int level,currentHp,maxHp,strength,defence,crits,coin,experience,currentX,currentY;
	name = player.getName();
	level = player.getLevel();
	job = player.getJob();
	currentHp = player.getCurrentHp();
	maxHp = player.getMaxHp();
	strength = player.getStrength();
	defence = player.getDefence();
	crits = player.getCrits();
	coin = player.getCoin();
	experience = player.getExperience();
	currentMap = currentMapName;
	currentX = player.getX();
	currentY = player.getY();
	Save _save(name,level,job,currentHp,maxHp,strength,defence,crits,coin,experience,currentMap,currentX,currentY);
	if(saveTo <= save.size())
		save[saveTo-1] = _save;
	else
		save.push_back(_save);
	ofstream fout("save.txt");
	if(!fout){
		cout <<"Failed to save.\n";
		return 0;
	}
	for(Save& _save : save){
		fout <<_save.getSaveName() <<endl;
		fout <<_save.getSaveLevel() <<endl;
		fout <<_save.getSaveJob() <<endl;
		fout <<_save.getSaveCurrentHp() <<endl;
		fout <<_save.getSaveMaxHp() <<endl;
		fout <<_save.getSaveStrength() <<endl;
		fout <<_save.getSaveDefence() <<endl;
		fout <<_save.getSaveCrits() <<endl;
		fout <<_save.getSaveCoin() <<endl;
		fout <<_save.getSaveExperience() <<endl;
		fout <<_save.getSaveCurrentMap() <<endl;
		fout <<_save.getSaveCurrentX() <<endl;
		fout <<_save.getSaveCurrentY() <<endl;
	}
	return 1;
}
