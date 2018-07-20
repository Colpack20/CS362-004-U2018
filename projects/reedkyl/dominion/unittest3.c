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

    printf ("TESTING fullDeckCount():\n");

				numPlayer = 2;
				//handCount = 5;

                //printf("Test player %d with %d treasure card(s).\n", p, handCount);

	printf("test 1 on player 1 for number of duchy cards after initialize game is run\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                //G.handCount = handCount;                 // set the number of cards on hand
				//G.supplyCount[province] = 1;
				//printf("supply count is %d \n", G.supplyCount[duchy]);
                //memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                //int a = isGameOver(&G);
				
				//printf("a is %d\n", isGameOver(&G));
				//printf("count is %d\n", fullDeckCount(0, copper, &G));
				int h, total;
				//total = 0;
				//for (h = 0; h < 27; h++){
					//printf("card %d is %d\n", h, fullDeckCount(0, h, &G));
					total = fullDeckCount(0, 2, &G);
				//}
				//printf("total is %d\n", total);
				//printf("deck count is %d\n", G.deckCount[0]);
				
				printf("hand count is %d\n", G.handCount[0]);
				int a;
				for(a = 0; a< G.handCount[0]; a++)
					printf("hand card number %d is %d\n", a, G.hand[0][a]);
				
				printf("deck count is %d\n", G.deckCount[0]);
				for(a=0; a<G.deckCount[0]; a++)
					printf("deck card number %d is %d\n", a, G.deck[0][a]);
				printf("discard count is %d\n", G.discardCount[0]);
				if(total == 0)
					printf("passed, player 1 has no duchy cards\n");
				else
					printf("failed, player 1 has duchy cards\n");
				//int h, total;
	printf("test 2 on player 2 for deck count and full deck count totals after initialize game is run, which should be the same\n");
				total = 0;
				for (h = 0; h < 27; h++)
				{
					//printf("card %d is %d\n", h, fullDeckCount(1, h, &G));
					total += fullDeckCount(1, h, &G);//this is statement is just checking the total number of cards, not any specific ones
				}
				//printf("total is %d\n", total);
				//printf("deck count is %d\n", G.deckCount[1]);
				printf("hand count is %d\n", G.handCount[1]);
				for(a = 0; a< G.handCount[1]; a++)
					printf("hand card number %d is %d\n", a, G.hand[1][a]);
				
				printf("deck count is %d\n", G.deckCount[1]);
				for(a=0; a<G.deckCount[1]; a++)
					printf("deck card number %d is %d\n", a, G.deck[1][a]);
				printf("discard count is %d\n", G.discardCount[1]);
				if(total == (G.deckCount[1]+G.discardCount[1] + G.handCount[1]) && total == 10)
					printf("passed, player 2 hasn't drawn any cards into their hand or discarded any cards, so the full deck count is the same as the deckcount attribute of player 2\n");
				else
					printf("failed, player 2 hasn't drawn any cards into their hand or discarded any cards, but the full deck count is not the same as the deckcount attribute of player 2\n");
	printf("test 3 on player 2 after initialize game is run for number of coppers\n");
				int coppertotal = fullDeckCount(1, copper, &G);
				
				if(coppertotal == 7)
					printf("passed, there are 7 coppers total\n");
				else
					printf("failed, there aren't 7 coppers total\n");
	printf("test 4 on player 1 after initialize game is run for number of estates\n");
				int estatetotal = fullDeckCount(0, estate, &G);
				if(estatetotal == 3)
					printf("passed, there are 3 estates total\n");
				else
					printf("failed, there aren't 3 estates total\n");			
	printf("test 5 on player 1 for total number of smithys with smithys added to the discard pile\n");
				
				G.hand[0][0] = smithy;
				printf("hand count is %d\n", G.handCount[0]);
				printf("player 1's hand is\n");
				int j;
				for(j = 0; j< G.handCount[0]; j++)
					printf("hand card number %d is %d\n", j, G.hand[0][j]);
				
				printf("player 1's deck is\n");
				printf("deck count is %d\n", G.deckCount[0]);
				G.deck[0][1] = smithy;
				for(j=0; j<G.deckCount[0]; j++)
					printf("deck card number %d is %d\n", j, G.deck[0][j]);
				
				
				G.discard[0][0] = smithy;
				G.discardCount[0]++;
				G.discard[0][1] = duchy;
				G.discardCount[0]++;
				G.discard[0][2] = smithy;
				G.discardCount[0]++;
				printf("discard count is %d\n", G.discardCount[0]);
				for(j=0; j<G.discardCount[0]; j++)
					printf("discard card number %d is %d\n", j, G.discard[0][j]);
				int smithyTotal = fullDeckCount(0, smithy, &G);
				printf("smithytotal is %d \n", smithyTotal);
				if(smithyTotal == 4)
					printf("passed, there are 4 smithys total\n");
				else
					printf("failed, there aren't 4 smithys total\n");
				
    printf("All tests taken!\n");

    return 0;
}
