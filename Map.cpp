#include "Map.h"

Map::Map(){}
Map::Map(std::string _name, std::string _nextMapName, int _initialPositionX, int _initialPositionY, int _width, int _height, std::vector<std::string> _mapData, std::vector<std::string> _monster) : name(_name),nextMapName(_nextMapName),initialPositionX(_initialPositionX),initialPositionY(_initialPositionY),width(_width),height(_height),mapData(_mapData),monster(_monster){}

Map::~Map(){}

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
	return mapData[y][x];
}
bool Map::canMove(int x, int y){
    if(mapData[y][x]=='0' || mapData[y][x]=='@')
		return true;
	else
		return false;
}
void Map::printMap(){ 
	std::cout <<std::endl;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if((i==player->getY()) && (j==player->getX())){
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
void Map::printStatus(){
	player->printStatus();
	std::cout <<"Map: " <<name <<std::endl <<std::endl;
}
std::vector<std::string> Map::getMonsterInMap(){
	return monster;
}
