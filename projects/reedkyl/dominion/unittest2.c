/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
	//int a = 3;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING isGameOver():\n");
	
				numPlayer = 2;
				//handCount = 5;
#if (NOISY_TEST == 1)
                //printf("Test player %d with %d treasure card(s).\n", p, handCount);
#endif*/
	printf("test 1 with 1 province left\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                //G.handCount = handCount;                 // set the number of cards on hand
				G.supplyCount[province] = 1;
				//printf("supply count is %d \n", G.supplyCount[duchy]);
                //memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                //int a = isGameOver(&G);
				
				//printf("a is %d\n", isGameOver(&G));
				if (!isGameOver(&G))
					printf("test 1 passed, the game is not over\n");
				else
					printf("test 1 failed, the game is over\n");
	printf("test 2 with 0 provinces left\n");			
				G.supplyCount[province] = 0;
				//printf("a is %d\n", isGameOver(&G));
				if (isGameOver(&G))
					printf("test 2 passed, the game is over\n");
				else
					printf("test 2 failed, the game is not over\n");
	printf("test 3 with 0 duchy and 0 copper\n");
				G.supplyCount[province] = 1;
				G.supplyCount[duchy] = 0;
				G.supplyCount[copper] = 0;
				//printf("a is %d\n", isGameOver(&G));
				if (!isGameOver(&G))
					printf("test 3 passed, the game is not over\n");
				else
					printf("test 3 failed, the game is over\n");
	printf("test 4 with 0 duchy, 0 copper, and 0 estate\n");
				G.supplyCount[province] = 1;
				G.supplyCount[duchy] = 0;
				G.supplyCount[copper] = 0;
				G.supplyCount[estate] = 0;
				//printf("a is %d\n", isGameOver(&G));
				if (isGameOver(&G))
					printf("test 4 passed, the game is over\n");
				else
					printf("test 4 failed, the game is not over\n");
	printf("test 5 with 0 smithy\n");
				G.supplyCount[duchy] = 1;
				G.supplyCount[copper] = 1;
				G.supplyCount[estate] = 1;
				G.supplyCount[smithy] = 0;
				if (!isGameOver(&G))
					printf("test 5 passed, the game is not over\n");
				else
					printf("test 5 failed, the game is over\n");	

    printf("All tests taken!\n");

    return 0;
}
