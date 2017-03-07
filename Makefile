CC = g++
CFLAGS = -Wall -O2

rpg : rpg.o Map.o Monster.o RpgCreature.o RpgPerson.o job.o Battle.o enemy.o save.o
	$(CC) $(CFLAGS) -o rpg rpg.o Map.o Monster.o RpgCreature.o RpgPerson.o job.o Battle.o enemy.o save.o
	rm *.o
rpg.o : rpg.cpp Map.h Monster.h RpgPerson.h RpgCreature.h job.h Battle.h enemy.h save.h
	$(CC) $(CFLAGS) -c rpg.cpp
Map.o : Map.cpp Map.h RpgPerson.h
	$(CC) $(CFLAGS) -c Map.cpp
Monster.o : Monster.cpp Monster.h RpgCreature.h
	$(CC) $(CFLAGS) -c Monster.cpp
RpgCreature.o : RpgCreature.cpp RpgCreature.h
	$(CC) $(CFLAGS) -c RpgCreature.cpp
RpgPerson.o : RpgPerson.cpp RpgPerson.h RpgCreature.h
	$(CC) $(CFLAGS) -c RpgPerson.cpp
job.o : job.h job.cpp RpgPerson.h
	$(CC) $(CFLAGS) -c job.cpp
Battle.o : Battle.h Battle.cpp RpgPerson.h RpgCreature.h Monster.h
	$(CC) $(CFLAGS) -c Battle.cpp
enemy.o : enemy.h enemy.cpp Monster.h
	$(CC) $(CFLAGS) -c enemy.cpp
save.o : save.h save.cpp
	$(CC) $(CFLAGS) -c save.cpp
clean:
	rm rpg
