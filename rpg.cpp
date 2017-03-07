#include<iostream>
#include<fstream>
#include "Map.h"
#include "RpgCreature.h"
#include "RpgPerson.h"
#include "Monster.h"
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void printOperationNotice(){
	cout <<"\n*****\n" <<"Use w/s/a/d to move up/down/left/right.\n" <<"Enter i to show your status.\n" <<"Enter exit to leave game.\n" <<"*****\n";
}
void fight(RpgCreature &attacker, RpgCreature &victim){
	while(!attacker.isDead() && !victim.isDead()){
		attacker.attack(victim);
		cout <<attacker.getName()<<" attacked "<<victim.getName()<<", caused " <<attacker.getStrength() <<" damages\n";
		victim.attack(attacker);
		cout <<victim.getName()<<" attacked "<<attacker.getName()<<", caused " <<victim.getStrength() <<" damages\n";
	}
}
void playerWin(RpgPerson &player, Monster monster){
	int exp = rand()%2+1;
	cout <<"You beat a " <<monster.getName() <<",got " <<exp <<" exp.\n";
	player.raiseExperience(exp);
	if(player.checkLevelUp()){
		player.levelUp();
		cout <<"Level up!!!You are now level " <<player.getLevel() <<".\n";
		player.statusUp();
		cout <<"HP recovered.\n";
		player.recoverHp();
	}
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
	cout <<" -----------------------------------------\n" <<"|     Welcome to oop assignment2 rpg.     |\n" <<" ------------------------------------------\n";
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
		fin >> _initialPositionY;
		fin >> _initialPositionX;
		fin >> _width;
		fin >> _height;
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
	cin >> _name;
	RpgPerson player1(_name,25,7,2,map[0].getinitialPositionX(),map[0].getinitialPositionY(),0);	//player實作
	map[0].addPlayer(player1);
	map[0].printMap(player1.getX(),player1.getY());//輸入名字後第一次印地圖
	printOperationNotice();//輸入名字後第一次印指令
	srand((unsigned)time(NULL));
	while(cin >> command){
		if(command == "exit")
			return 0;
		else if(command == "i"){
			player1.printStatus();
			cout <<"Map: " <<map[player1.getCurrentMap()].getName() <<endl<<endl;
		}
		else if(command =="w" || command =="s" || command == "a" || command == "d"){
			if(command == "w"){
				if(!walk(map[player1.getCurrentMap()],player1,-1,0))
					continue;
			}
			else if(command == "s"){
				if(!walk(map[player1.getCurrentMap()],player1,1,0))
					continue;
			}
			else if(command == "a"){

				if(!walk(map[player1.getCurrentMap()],player1,0,-1))
					continue;
			}
			else{
				if(!walk(map[player1.getCurrentMap()],player1,0,1))
					continue;
			}
			if(!(rand()%4)){	//fight!
				Monster monster("Slime",20,6,3);
				cout << "You meet a " << monster.getName() <<"!!! The fight starts!!!" <<endl;
				cout<<"-----\n"<<"Enter f to fight,e to escape.\n"<<"-----\n";
				string fight_command;
				while(cin>>fight_command){
					if(fight_command == "f"){
						fight(player1,monster);
						if(player1.isDead()){
							cout <<"You lose!Game over\n";
							return 0;
						}
						else
							playerWin(player1,monster);
						break;
					}
					else if(fight_command == "e"){
						if( rand()%10<3 )
							cout <<"You successfully escaped from the fight!\n";
						else{
							cout <<"Escape failed!!!\n";
							fight(monster,player1);
							if(player1.isDead()){
								cout <<"You lose!Game over\n";
								return 0;
							}
							else
								playerWin(player1,monster);
						}
						break;
					}
					else{
						cout <<"Wrong input!\n";
					}
				}
			}
			if(map[player1.getCurrentMap()].getMapData(player1.getX(),player1.getY()) == '@'){
				for(int i=0; i<3; i++){
					if(map[player1.getCurrentMap()].getNextMapName() == map[i].getName()){
						cout <<"map i=" <<i <<endl;
						map[player1.getCurrentMap()].removePlayer();
						player1.setCurrentMap(i);
						map[i].addPlayer(player1);
						player1.setPosition(map[player1.getCurrentMap()].getinitialPositionX(),map[player1.getCurrentMap()].getinitialPositionY());
						break;
					}
				}
			}
		}
		else{
			cout <<"Entered the wrong command! Please try again\n";
			continue;
		}
		map[player1.getCurrentMap()].printMap(player1.getX(),player1.getY());
		printOperationNotice();
	}
}
