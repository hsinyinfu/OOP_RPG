#include"Battle.h"
void battleNotice(){
	std::cout<<"-----\n"<<"Enter '1' to attack, '2' to use skill, '3' to escape.\n"<<"-----\n";
}

void fight(RpgCreature& attacker, RpgCreature& victim){
	int damage = attacker.attack(victim);
	std::cout <<attacker.getName()<<" attacked "<<victim.getName()<<", caused " <<damage <<" damages\n";
	if(!victim.isDead())
		std::cout <<victim.getName() <<"'s hp: " <<victim.getCurrentHp() <<".\n";
	else
		std::cout <<victim.getName() <<"'s hp: 0" <<".\n";
}

bool startBattle(RpgPerson& player, Monster& monster){  //return1:someone win;return0:escape;
	battleNotice();
	char fightCommand;
	while(std::cin >> fightCommand){
		switch(fightCommand){
			case'1':{
				fight(player,monster);
				if(!monster.isDead())
					fight(monster,player);
				else
					return 1;
				break;}
			case'2':{
				player.printSkill();
				char skillNumber;
				std::cin >>skillNumber;
				player.useSkill(skillNumber,player,monster);
				break;}
			case'3':{
				if( rand()%10<3 ){
					std::cout <<"You successfully escaped from the fight!\n";
					return 0;
				}
				else{
					std::cout <<"Escape failed!!!\n";
					fight(monster,player);
					if(!player.isDead())
						fight(player,monster);
					else
						return 1;
				}
				break;}
			default:{
				std::cout <<"Wrong input!\n";
				break;}
		}
		if(player.isDead() || monster.isDead())
			return 1;
		battleNotice();
	}
}

void playerLose(RpgPerson& player){
	int loseExp = rand()%2+1;
	std::cout <<"Your hero is dead. Lost "<<loseExp<<" exp.\n";
	if(player.getExperience() <= loseExp)
		player.setExperience(0,0);
	else
		player.setExperience(0,loseExp);
	std::cout <<"HP recovered\n";
	player.recoverHp();
}

void playerWin(RpgPerson &player,Monster& monster){
	std::cout <<"You beat a "<<monster.getName()<<",got "<<monster.getExpGain()<<" exp and " <<monster.getCoinDrop() <<" coins.\n";
	player.setExperience(1,monster.getExpGain());
	if(player.checkLevelUp()){
		player.levelUp();
		player.statusUp();
		std::cout <<"Level up!!! You are level " <<player.getLevel() <<".\n";
		std::cout <<"HP recovered\n";
		player.recoverHp();
	}
	player.setCoin(monster.getCoinDrop());
}

void meetEnemy(Map& currentMap, Monster** monster){
	std::vector<std::string> monsterList = currentMap.getMonsterInMap();
	int monsterNum = monsterList.size();
	int random = rand()% monsterNum;
	if(monsterList[random] == "Slime"){
		*monster = new Slime("Slime");
		std::cout <<"You meet a Slime!!! The fight  starts!!!\n" <<std::endl;
	}
	else if(monsterList[random] == "Troll"){
		*monster = new Troll("Troll");
		std::cout <<"You meet a Troll!!! The fight  starts!!!\n" <<std::endl;
	}
	else if(monsterList[random] == "Dragon"){
		*monster = new Dragon("Dragon");
		std::cout <<"You meet a Dragon!!! The fight  starts!!!\n" <<std::endl;
	}
}
