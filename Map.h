#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "RpgPerson.h"
#include <vector>
class Map{
public:
    Map();
    Map(std::string _name, std::string _nextMapName, int _initialPositionX, int _initialPositionY, int _width, int _height, std::vector<std::string> _mapData, std::vector<std::string> monster);
    ~Map();
    std::string getName();
    std::string getNextMapName();
    int getWidth();
    int getHeight();
    int getinitialPositionX();
    int getinitialPositionY();
	char getMapData(int x, int y);
    bool canMove(int x, int y);
    void printMap();
    void addPlayer(RpgPerson& _player);
    void removePlayer();
	void printStatus();
	std::vector<std::string> getMonsterInMap();
private:
    std::string name;
    std::string nextMapName;
    int initialPositionX;
    int initialPositionY;
    int width;
    int height;
	std::vector<std::string> mapData;
    RpgPerson* player;
	std::vector<std::string> monster;
};

#endif // MAP_H_INCLUDED
