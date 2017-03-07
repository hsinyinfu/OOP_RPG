#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "RpgCreature.h"

class Monster: public RpgCreature{
public:
    Monster(std::string _name, int _maxHp, int _strength, int _defence, int _crits);
	int getCoinDrop();
	int getExpGain();
protected:
	int coinDrop;
	int expGain;
};

#endif // MONSTER_H_INCLUDED
