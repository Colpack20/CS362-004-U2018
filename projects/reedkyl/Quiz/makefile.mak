CC = gcc 
CFLAGS = -Wall -fpic -coverage -lm -std=c99

all: testUpdateCoins
	
testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
	$(CC) -Wall -fpic -coverage -lm -std=c99 -o testUpdateCoins -g testUpdateCoins.c dominion.o rngs.o 
	
rngs.o: rngs.h rngs.c
	$(CC) -c $(CFLAGS) rngs.c -g -Wall -fpic -coverage -lm -std=c99

dominion.o: dominion.h dominion.c rngs.o
	$(CC) -c $(CFLAGS) dominion.c -g -Wall -fpic -coverage -lm -std=c99
	
clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe