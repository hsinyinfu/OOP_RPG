#ifndef RPGPERSON_H_INCLUDED
#define RPGPERSON_H_INCLUDED

#include <vector>
#include "RpgCreature.h"

class RpgPerson: public RpgCreature{
public:
    RpgPerson(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y, int _currentMap);
  	int getX();
    int getY();
    void setPosition(int x, int y);
	void move(int xMove, int yMove);
    void raiseExperience(int value);
    bool checkLevelUp();
    void levelUp();
    void statusUp();
    void printStatus();
	int getLevel();
private:
    int level;
    int experience;
    int x;
    int y;
};

#endif // RPGPERSON_H_INCLUDED
