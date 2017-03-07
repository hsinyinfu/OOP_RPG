#ifndef BATTLE_H_INCLUDE
#define BATTLE_H_INCLUDE

#include "RpgPerson.h"
#include "Map.h"
#include "enemy.h"

void battleNotice();
void fight(RpgCreature& , RpgCreature& );
bool startBattle(RpgPerson& , Monster& );
void playerWin(RpgPerson& , Monster& );
void playerLose(RpgPerson& );
void meetEnemy(Map& currentMap, Monster** monster);

#endif
