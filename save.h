#ifndef SAVE_H
#define SAVE_H

#include<iostream>

class Save{
	public:
		Save(std::string name, int level, std::string job, int currentHp, int maxHp, int strength, int defence, int crits, int coin, int experience, std::string currentMap, int currentX, int currentY);
		std::string getSaveName();
		int getSaveLevel();
		std::string getSaveJob();
		int getSaveCurrentHp();
		int getSaveMaxHp();
		int getSaveStrength();
		int getSaveDefence();
		int getSaveCrits();
		int getSaveCoin();
		int getSaveExperience();
		std::string getSaveCurrentMap();
		int getSaveCurrentX();
		int getSaveCurrentY();
//		int getRecordNumber();
		void setSaveName(std::string _name);
		void setSaveLevel(int _level);
		void setSaveJob(std::string _job);
		void setSaveCurrentHp(int _currentHp);
		void setSaveMaxHp(int _maxHp);
		void setSaveStrength(int _strength);
		void setSaveDefence(int _defence);
		void setSaveCrits(int _crits);
		void setSaveCoin(int _coin);
		void setSaveExperience(int _experience);
		void setSaveCurrentMap(std::string _currentMap);
		void setSaveCurrentX(int _currentX);
		void setSaveCurrentY(int _currentY);
//		void setSaveRecordNumber(int _recordNo);
	private:
		std::string name;
		int level;
		std::string job;
		int currentHp;
		int maxHp;
		int strength;
		int defence;
		int crits;
		int coin;
		int experience;
		std::string currentMap;
		int currentX;
		int currentY;
//		int recordNumber;
};
#endif
