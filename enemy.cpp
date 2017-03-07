#include "enemy.h"

Slime::Slime(std::string _name, int _maxHp, int _strength, int _defence, int _crits):Monster("Slime",_maxHp,_strength,_defence,_crits){
	coinDrop = 1;
	expGain = 2;
}

Troll::Troll(std::string _name, int _maxHp, int _strength, int _defence, int _crits):Monster("Troll",_maxHp,_strength,_defence,_crits){
	coinDrop = 5;
	expGain = 10;
}

Dragon::Dragon(std::string _name, int _maxHp, int _strength, int _defence, int _crits):Monster("Dragon",_maxHp,_strength,_defence,_crits){
	coinDrop = 15;
	expGain = 25;
}
