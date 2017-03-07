#ifndef ENEMY_H
#define ENEMY_H
#include "Monster.h"

class Slime : public Monster{
	public:
		Slime(std::string _name, int _maxHp=30, int _strength=10, int _defence=3, int _crits=20);
};

class Troll : public Monster{
	public:
		Troll(std::string _name, int _maxHp=35, int _strength=20, int _defence=5, int _crits=35);
};

class Dragon : public Monster{
	public:
		Dragon(std::string _name, int _maxHp=150, int _strength=20, int _defence=30, int _crits=1);
};

#endif
