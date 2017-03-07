#ifndef JOB_H
#define JOB_H
#include "RpgPerson.h"

class SwordMan : public RpgPerson{
	public:
		SwordMan(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y, int _crits, int _level=1, int _experience=0, int _coin=0);
		~SwordMan();
		void statusUp();
		void printStatus();
		void useSkill(char skillNumber,RpgPerson& player,Monster& monster);
		void printSkill();
		std::string getJob();
};

class Thief : public RpgPerson{
	public:
		Thief(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y, int _crits, int _level=1, int _experience=0, int _coin=0);
		~Thief();
		void statusUp();
		void printStatus();
		void useSkill(char skillNumber,RpgPerson& player,Monster& monster);
		void printSkill();
		std::string getJob();
};

class Magician : public RpgPerson{
	public:
		Magician(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y, int _crits, int _level=1, int _experience=0, int _coin=0);
		~Magician();
		void statusUp();
		void printStatus();
		void useSkill(char skillNumber,RpgPerson& player,Monster& monster);
		void printSkill();
		std::string getJob();
};
#endif
