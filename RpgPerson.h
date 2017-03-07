#ifndef RPGPERSON_H_INCLUDED
#define RPGPERSON_H_INCLUDED

#include "RpgCreature.h"
#include "Monster.h"

class RpgPerson: public RpgCreature{
public:
    RpgPerson(std::string _name, int _maxHp, int _strength, int _defence, int _x, int _y, int _crits, int _level, int _experience, int _coin);
	virtual ~RpgPerson();
  	int getX();
    int getY();
    void setPosition(int x, int y);
	void move(int xMove, int yMove);
    void setExperience(bool up_down,int value);
    bool checkLevelUp();
    void levelUp();
    virtual void statusUp()=0;
    virtual void printStatus()=0;
	int getLevel();
	int getExperience();
	void setRequiredExp();
	int getRequiredExp();
	virtual void useSkill(char skillNumber,RpgPerson& player, Monster& monster)=0;
	virtual void printSkill()=0;
	int getCoin();
	void setCoin(int _coin);
	void recoverHp();
	virtual std::string getJob()=0;
protected:
    int level;
    int experience;
    int x;
    int y;
	int requiredExp;
	int coin;
};

#endif // RPGPERSON_H_INCLUDED
