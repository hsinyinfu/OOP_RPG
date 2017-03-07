#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "RpgPerson.h"

class Map{
public:
    Map();
    Map(std::string _name, std::string _nextMapName, int _initialPositionX, int _initialPositionY, int _width, int _height, char _mapData[11][21]);
    ~Map();
	void setMap(std::string _name, std::string _nextMapName, int _initialPositionX, int _initialPositionY, int _width, int _height, char _mapData[11][21]);
    std::string getName();
    std::string getNextMapName();
    int getWidth();
    int getHeight();
    int getinitialPositionX();
    int getinitialPositionY();
	char getMapData(int x, int y);
    bool canMove(int x, int y);
    void printMap(int playerPositionX, int playerPositionY);
    void addPlayer(RpgPerson& _player);
    void removePlayer();
private:
    std::string name;
    std::string nextMapName;
    int initialPositionX;
    int initialPositionY;
    int width;
    int height;
    char mapData[11][21];
    RpgPerson* player;
};

#endif // MAP_H_INCLUDED
