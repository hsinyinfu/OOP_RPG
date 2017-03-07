#include "Map.h"

Map::Map(){}
Map::Map(std::string _name, std::string _nextMapName, int _initialPositionX, int _initialPositionY, int _width, int _height, char _mapData[11][21]) : name(_name),nextMapName(_nextMapName),initialPositionX(_initialPositionX),initialPositionY(_initialPositionY),width(_width),height(_height){
	for(int i=0; i<10; i++){
		for(int j=0; j<20; j++){
			mapData[i][j] = _mapData[i][j];
		}
	}
}
Map::~Map(){}

void Map::setMap(std::string _name, std::string _nextMapName, int _initialPositionX, int _initialPositionY, int _width, int _height, char _mapData[11][21]){
	this->name = _name;
	nextMapName = _nextMapName;
	initialPositionX = _initialPositionX;
	initialPositionY = _initialPositionY;
	width = _width;
	height = _height;
	for(int i=0; i<11; i++){
		for(int j=0; j<21; j++){
			mapData[i][j] = _mapData[i][j];
		}
	}
}

std::string Map::getName(){
   return name;  
}
std::string Map::getNextMapName(){
	return nextMapName;
}
int Map::getWidth(){
    return width;
}
int Map::getHeight(){
    return height;
}
int Map::getinitialPositionX(){
    return initialPositionX;
}
int Map::getinitialPositionY(){
    return initialPositionY;
}
char Map::getMapData(int x, int y){ 
	return mapData[x][y];
}
bool Map::canMove(int x, int y){
    if(getMapData(x,y)=='0' || getMapData(x,y)=='@')
		return true;
	else
		return false;
}
void Map::printMap(int playerPositionX, int playerPositionY){ 
	std::cout <<std::endl;
	for(int i=0; i<10; i++){
		for(int j=0; j<20; j++){
			if(i==playerPositionX && j==playerPositionY){
				std::cout <<'#';
			}
			else if(mapData[i][j]=='0'){
				std::cout <<' ';
			}
			else{
				std::cout <<mapData[i][j];
			}
		}
		std::cout <<std::endl;
	}
}
void Map::addPlayer(RpgPerson& _player){
	this->player = &_player;
}
void Map::removePlayer(){
	this->player = NULL;
}
