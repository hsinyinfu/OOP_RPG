#include "save.h"

Save::Save(std::string name, int level, std::string job, int currentHp, int maxHp, int strength, int defence, int crits, int coin, int experience, std::string currentMap, int currentX, int currentY) : name(name),level(level),job(job),currentHp(currentHp),maxHp(maxHp),strength(strength),defence(defence),crits(crits),coin(coin),experience(experience),currentMap(currentMap),currentX(currentX),currentY(currentY){}

std::string Save::getSaveName(){	return name;	}
int Save::getSaveLevel(){	return level;	}
std::string Save::getSaveJob(){	return job;	}
int Save::getSaveCurrentHp(){	return currentHp;	}
int Save::getSaveMaxHp(){	return maxHp;	}
int Save::getSaveStrength(){	return strength;	}
int Save::getSaveDefence(){	return defence;	}
int Save::getSaveCrits(){	return crits;	}
int Save::getSaveCoin(){	return coin;	}
int Save::getSaveExperience(){	return experience;	}
std::string Save::getSaveCurrentMap(){	return currentMap;	}
int Save::getSaveCurrentX(){	return currentX;	}
int Save::getSaveCurrentY(){	return currentY;	}
//int Save::getRecordNumber(){	return recordNumber;	}
void Save::setSaveName(std::string _name){	name = _name; }
void Save::setSaveLevel(int _level){ level = _level; }
void Save::setSaveJob(std::string _job){ job = _job; }
void Save::setSaveCurrentHp(int _currentHp){ currentHp = _currentHp; }
void Save::setSaveMaxHp(int _maxHp){ maxHp = _maxHp; }
void Save::setSaveStrength(int _strength){ strength = _strength; }
void Save::setSaveDefence(int _defence){ defence = _defence; }
void Save::setSaveCrits(int _crits){ crits = _crits; }
void Save::setSaveCoin(int _coin){ coin = _coin; }
void Save::setSaveExperience(int _experience){ experience = _experience; }
void Save::setSaveCurrentMap(std::string _currentMap){ currentMap = _currentMap; }
void Save::setSaveCurrentX(int _currentX){ currentX = _currentX; }
void Save::setSaveCurrentY(int _currentY){ currentY = _currentY; }
//void Save::setSaveRecordNumber(int _recordNo){ recordNumber = _recordNo; }
