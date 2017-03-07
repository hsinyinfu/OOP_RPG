CC = g++
CFLAGS = -Wall -O2

rpg : rpg.o Map.o Monster.o RpgCreature.o RpgPerson.o
	$(CC) $(CFLAGS) -o rpg rpg.o Map.o Monster.o RpgCreature.o RpgPerson.o
	rm *.o
rpg.o : rpg.cpp Map.h Monster.h RpgPerson.h RpgCreature.h
	$(CC) $(CFLAGS) -c rpg.cpp
Map.o : Map.cpp Map.h RpgPerson.h
	$(CC) $(CFLAGS) -c Map.cpp
Monster.o : Monster.cpp Monster.h RpgCreature.h
	$(CC) $(CFLAGS) -c Monster.cpp
RpgCreature.o : RpgCreature.cpp RpgCreature.h
	$(CC) $(CFLAGS) -c RpgCreature.cpp
RpgPerson.o : RpgPerson.cpp RpgPerson.h RpgCreature.h
	$(CC) $(CFLAGS) -c RpgPerson.cpp
clean:
	rm rpg
