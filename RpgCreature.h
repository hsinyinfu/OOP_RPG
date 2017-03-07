#ifndef RPGCREATURE_H_INCLUDED
#define RPGCREATURE_H_INCLUDED

#include <iostream>
#include <time.h>
#include <stdlib.h>

class RpgCreature{
public:
    RpgCreature();
    RpgCreature(std::string name);
    RpgCreature(std::string name, int maxHp, int strength, int defence);
    std::string getName();
    int getMaxHp();
    int getCurrentHp();
    int getStrength();
    int getDefence();
    bool isDead();
    void loseHp(int value);
    void recoverHp();
    void attack(RpgCreature& enemy);
	void setCurrentMap(int mapIndex);
	int getCurrentMap();
protected:
    std::string name;
    int maxHp;
    int currentHp;
    int strength;
    int defence;
	int currentMap;
};

#endif // RPGCREATURE_H_INCLUDED
