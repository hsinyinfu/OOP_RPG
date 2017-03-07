#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include "RpgCreature.h"

class Monster: public RpgCreature{
public:
    Monster(std::string _name, int _maxHp, int _strength, int _defence, int _crits);
private:
};

#endif // MONSTER_H_INCLUDED
