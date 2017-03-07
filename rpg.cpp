#include<iostream>
#include<fstream>
#include "Map.h"
#include "RpgCreature.h"
#include "RpgPerson.h"
#include "Monster.h"
#include "job.h"
#include "Battle.h"
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void printOperationNotice(){
	cout <<"\n*****\n" <<"Use w/s/a/d to move up/down/left/right.\n" <<"Enter i to show your status.\n" <<"Enter exit to leave game.\n" <<"*****\n";
}
int walk(Map map, RpgPerson &player, int xMove, int yMove){
	if(map.canMove(player.getX()+xMove,player.getY()+yMove)){
		player.move(xMove,yMove);
		return 1;
	}
	else{
		if(xMove > 0)
			cout <<"Can't move down, try another direction.\n";
		else if(xMove < 0)
			cout <<"Can't move up, try another direction.\n";
		else if(yMove > 0)
			cout <<"Can't move right, try another direction.\n";
		else if(yMove < 0)
			cout <<"Can't move left, try another direction.\n";
		return 0;
	}
}
int main(){
	cout <<" -----------------------------------------\n" <<"|     Welcome to oop assignment3 rpg.     |\n" <<" ------------------------------------------\n";
	ifstream fin("map.txt");
	if(!fin){
		cout <<"Failed to load map data\n" <<"The game is off\n";
		return 0;
	}
	Map map[3];	//宣告map
	for(int i=0; i<3; i++){	//吃地圖
		string _name,_nextMapName,tmp;
		int _initialPositionX,_initialPositionY,_width,_height;
		char _mapData[21][21];
		getline(fin,_name);
		getline(fin,_nextMapName);
		fin >> _initialPositionY >>_initialPositionX >>_width >>_height;
		for(int p=0; p<10; p++){
			for(int q=0; q<20; q++){
				fin.get(_mapData[p][q]);
				if(_mapData[p][q]!='0' && _mapData[p][q]!='1' && _mapData[p][q]!='@')
					q--;
			}
		}
		getline(fin,tmp);
		getline(fin,tmp);
		map[i].setMap(_name,_nextMapName,_initialPositionX,_initialPositionY,_width,_height,_mapData);
	}	//	結束吃地圖
	fin.close();
	cout <<"Enter your name:";//吃名字
	string _name,command,currentMap=map[0].getName();
	char _job;
	RpgPerson* player;
	cin >> _name;
	cout <<"Enter your job(1-3):(1.SwordMan 2.Thief 3.Magician)\n";
	cin >> _job;
	while(_job!='1' && _job!='2' && _job!='3'){
		cout<<"Please enter 1 or 2 or 3\n";
		cin >>_job;
	}
	switch(_job){
		case'1':
			player = new SwordMan(_name,1,7,2,map[0].getinitialPositionX(),map[0].getinitialPositionY(),0,20);
			break;
		case'2':
			player = new Thief(_name,100,7,2,map[0].getinitialPositionX(),map[0].getinitialPositionY(),0,20);
			break;
		case'3':
			player = new Magician(_name,100,7,2,map[0].getinitialPositionX(),map[0].getinitialPositionY(),0,20);
			break;
	}
	player->setRequiredExp();
	map[0].addPlayer(*(player));
	map[0].printMap(player->getX(),player->getY());//輸入名字後第一次印地圖
	printOperationNotice();//輸入名字後第一次印指令
	srand((unsigned)time(NULL));
	while(cin >> command){
		if(command == "exit"){
			delete player;
			return 0;
		}
		else if(command == "i"){
			player->printStatus();
			cout <<"Map: " <<map[player->getCurrentMap()].getName() <<endl<<endl;
		}
		else if(command =="w" || command =="s" || command == "a" || command == "d"){
			if(command == "w"){
				if(!walk(map[player->getCurrentMap()],*(player),-1,0))
					continue;
			}
			else if(command == "s"){
				if(!walk(map[player->getCurrentMap()],*(player),1,0))
					continue;
			}
			else if(command == "a"){
				if(!walk(map[player->getCurrentMap()],*(player),0,-1))
					continue;
			}
			else{
				if(!walk(map[player->getCurrentMap()],*(player),0,1))
					continue;
			}
			if(!(rand()%4)){	//fight!
				Monster monster("Slime",30,10,3,20);
				cout << "You meet a " << monster.getName() <<"!!! The fight starts!!!" <<endl;
				if(startBattle(*(player),monster)){
					if(player->isDead())
						playerLose(*(player));
					else
						playerWin(*(player),monster);
				}
				cout <<"HP recovered\n";
				player->recoverHp();
			}
			if(map[player->getCurrentMap()].getMapData(player->getX(),player->getY()) == '@'){
				for(int i=0; i<3; i++){
					if(map[player->getCurrentMap()].getNextMapName() == map[i].getName()){
						cout <<"map i=" <<i <<endl;
						map[player->getCurrentMap()].removePlayer();
						player->setCurrentMap(i);
						map[i].addPlayer(*(player));
						player->setPosition(map[player->getCurrentMap()].getinitialPositionX(),map[player->getCurrentMap()].getinitialPositionY());
						break;
					}
				}
			}
		}
		else{
			cout <<"Entered the wrong command! Please try again\n";
			continue;
		}
		map[player->getCurrentMap()].printMap(player->getX(),player->getY());
		printOperationNotice();
	}
}
