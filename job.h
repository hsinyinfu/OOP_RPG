#ifndef JOB_H
#define JOB_H
#include "RpgPerson.h"

class SwordMan : public RpgPerson{
	public:
		SwordMan(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y, int _currentMap, int _crits);
		~SwordMan();
		void statusUp();
		void printStatus();
		void useSkill(char skillNumber,RpgPerson& player,Monster& monster);
		void printSkill();
};

class Thief : public RpgPerson{
	public:
		Thief(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y, int _currentMap, int _crits);
		~Thief();
		void statusUp();
		void printStatus();
		void useSkill(char skillNumber,RpgPerson& player,Monster& monster);
		void printSkill();
};

class Magician : public RpgPerson{
	public:
		Magician(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y, int _currentMap, int _crits);
		~Magician();
		void statusUp();
		void printStatus();
		void useSkill(char skillNumber,RpgPerson& player,Monster& monster);
		void printSkill();
};
#endif
