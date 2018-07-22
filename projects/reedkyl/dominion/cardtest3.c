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

int main() {
    int i;
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
	bonus = 0;
    printf ("TESTING village():\n");

				numPlayer = 2;

	printf("test 1 add village to index 0 (hand position 1) and use card effect of village on player 2\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand

				G.hand[1][0] = village;
				G.handCount[1]++;

				G.whoseTurn = 1;
				int total = 0;
				int h;

				int firstDeckcount = G.deckCount[1];
				for (h = 0; h < 27; h++)
					total += fullDeckCount(1, h, &G);
				
				int x = cardEffect(village, -1, -1, -1, &G, 0, bonus);//play smithy from index 0 of hand
				
				int newtotal = 0;
				for (h = 0; h < 27; h++)
					newtotal += fullDeckCount(1, h, &G);
				printf("test 1A: are there 3 actions for player 2 after playing the village card?\n");
				if(G.numActions == 3)
					printf("test passed, there are 3 actions for player 2\n");
				else
					printf("test failed, there aren't 3 actions for player 2\n");
				printf("test 1B: is there 1 card in Player 2's hand after playing the village card?\n");
				if(G.handCount[1] == 1)
					printf("test passed, there is 1 card in Player 2's hand\n"); 
				else
					printf("test failed, there are %d card(s) in Player 2's hand\n", G.handCount[1]);
				printf("test 1C: were there any cards trashed or added unnecessarily after playing the village card?\n");
				if(total == newtotal)
					printf("test passed, no cards were trashed or added unnecessarily to Player 2's full deck\n");
				else if(total < newtotal)
					printf("test failed, some cards were added unnecessarily to player 2's full deck\n");		
				else
					printf("test failed, %d card(s) was/were trashed unnecessarily from Player 2's full deck\n", total-newtotal);
				printf("test 1D: was 1 card drawn from the deck successfully?\n");				
				if(G.deckCount[1] == (firstDeckcount - 1))
					printf("test passed, 1 card was drawn from the deck successfully\n");
				else if(G.deckCount[1] == firstDeckcount)
					printf("test failed, no cards were draw from the deck\n");
				else if (G.deckCount[1] > firstDeckcount)
					printf("test failed, cards were added to the deck\n");
				else
					printf("test failed, %d cards were drawn from the deck\n", firstDeckcount-G.deckCount[1]);

printf("\ntest 2 add village to index 0 (hand position 1) and use card effect of village on player 1\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand
				G.hand[0][5] = village;
				G.handCount[0]++;
				
				G.whoseTurn = 0;
				total = 0;

				firstDeckcount = G.deckCount[0];
				for (h = 0; h < 27; h++)
					total += fullDeckCount(0, h, &G);
				
				int z = cardEffect(village, -1, -1, -1, &G, 5, bonus);//play smithy from index 0 of hand
			
				newtotal = 0;
				for (h = 0; h < 27; h++)
					newtotal += fullDeckCount(0, h, &G);
				printf("test 2A: are there 3 actions for player 1 after playing the village card?\n");
				if(G.numActions == 3)
					printf("test passed, there are 3 actions for player 1\n");
				else
					printf("test failed, there aren't 3 actions for player 1\n");
				printf("test 2B: are there 6 cards in Player 2's hand after playing the village card?\n");
				if(G.handCount[0] == 6)
					printf("test passed, there are 6 cards in Player 1's hand same as there was to start\n");
				else
					printf("test failed, there aren't 6 cards in Player 1's hand same as there was to start\n");
				printf("test 2C: were there any cards trashed or added unnecessarily after playing the village card?\n");
				if(total == newtotal)
					printf("test passed, no cards were trashed or added unnecessarily to Player 1's hand\n");
				else if(total < newtotal)
					printf("test failed, cards were added unnecessarily to Player 1's hand\n");		
				else
					printf("test failed, %d card(s) was/were trashed unnecessarily from Player 1's hand\n", total-newtotal);
				printf("test 2D: was 1 card drawn from the deck successfully?\n");
				if(G.deckCount[0] == (firstDeckcount - 1))
					printf("test passed, 1 card was drawn from the deck successfully\n");
				else if(G.deckCount[0] == firstDeckcount)
					printf("test failed, no cards were draw from the deck\n");
				else if (G.deckCount[0] > firstDeckcount)
					printf("test failed, cards were added to the deck\n");
				else
					printf("test failed, %d cards were drawn from the deck\n", firstDeckcount-G.deckCount[0]);

    printf("All tests taken!\n");

    return 0;
}
