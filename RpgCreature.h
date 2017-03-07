#ifndef RPGCREATURE_H_INCLUDED
#define RPGCREATURE_H_INCLUDED

#include<iostream>

class RpgCreature{
public:
    RpgCreature();
    RpgCreature(std::string name);
    RpgCreature(std::string name, int maxHp, int strength, int defence, int crits);
    std::string getName();
    int getMaxHp();
    int getCurrentHp();
    int getStrength();
    int getDefence();
	int getCrits();
    bool isDead();
    void loseHp(int value);
    void recoverHp();
    int attack(RpgCreature& enemy);
	void setCurrentHp(int _currentHp);
protected:
    std::string name;
    int maxHp;
    int currentHp;
    int strength;
    int defence;
	int crits;
};

#endif // RPGCREATURE_H_INCLUDED
