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
	bonus = 0;
    printf ("TESTING Smithy():\n");
				numPlayer = 2;

	printf("test 1 add smithy to index 0 (hand position 1) and use card effect of smithy\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                //G.handCount = handCount;                 // set the number of cards on hand
				//G.supplyCount[province] = 1;
				//printf("supply count is %d \n", G.supplyCount[duchy]);
                //G.drawcard(1, G); 
				G.hand[1][0] = smithy;
				G.handCount[1]++;
				//memcpy(G.hand[1][0], smithy, sizeof(int) * handCount); // set all the cards to copper
                //int a = isGameOver(&G);
				//printf("card is %d\n", G.hand[1][0]);
				//printf("player 2 handcount is %d\n", G.handCount[1]);
				//printf("a is %d\n", isGameOver(&G));
				//printf("whose turn %d\n", G.whoseTurn = 1);
				G.whoseTurn = 1;
				int total = 0;
				int h;
				//G.deck[1][10] = smithy;
				//G.deckCount[1]++;
				printf("deck count is %d\n", G.deckCount[1]);//should be 11
				int firstDeckcount = G.deckCount[1];
				for (h = 0; h < 27; h++){
					//printf("card %d is %d\n", h, fullDeckCount(1, h, &G));//should be 11 total
					total += fullDeckCount(1, h, &G);
				}
				//printf("total is %d\n", total);
				
				int x = cardEffect(smithy, -1, -1, -1, &G, 0, bonus);//play smithy from index 0 of hand
				//playcard(smithy, -1, -1, -1, &G, 0);
				//printf("new deck count is %d\n", G.deckCount[1]); //is this only counting the cards in the deck or discard pile and not in the hand?				
				int newtotal = 0;
				for (h = 0; h < 27; h++){
					//printf("card %d is %d\n", h, fullDeckCount(1, h, &G));
					newtotal += fullDeckCount(1, h, &G);
				}
				//printf("new total is %d\n", newtotal);//It looks like discarding a card actually ended up trashing it instead of just discarding it.
				//card, choice1, choice2, choice3, state, handPos, &coin_bonus
				
				//printf("card is %d\n", G.hand[1][0]);
				//printf("card is %d\n", G.hand[1][1]);
				//printf("card is %d\n", G.hand[1][2]);
				//printf("card is %d\n", G.hand[1][3]);
				//printf("card is %d\n", G.hand[1][4]);
				//printf("handcount is %d\n", G.handCount[1]);
				if(G.handCount[1] == 3)
					printf("test passed, there are three cards in Player 2's hand\n");
				else
					printf("test failed, there aren't three cards in Player 2's hand\n");
				if(total == newtotal)
					printf("test passed, no cards were trashed unnecessarily from Player 2's hand\n");
				else
					printf("test failed, cards were trashed unnecessarily from Player 2's hand\n");
				if(G.deckCount[1] == firstDeckcount - 3)
					printf("test passed, three cards were drawn from the deck successfully\n");
				else
					printf("test failed, three cards weren't drawn from the deck successfully\n");
printf("test 2 add smithy to index 2 (hand position 3) and use card effect of smithy\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                //G.handCount = handCount;                 // set the number of cards on hand
				//G.supplyCount[province] = 1;
				//printf("supply count is %d \n", G.supplyCount[duchy]);
                //G.drawcard(1, G); 
				G.hand[1][2] = smithy;
				G.handCount[1]++;
				//memcpy(G.hand[1][0], smithy, sizeof(int) * handCount); // set all the cards to copper
                //int a = isGameOver(&G);
				//printf("handcount initial %d\n", G.handCount[1]);
				
				//printf("a is %d\n", isGameOver(&G));
				//printf("whose turn %d\n", G.whoseTurn = 1);
				G.whoseTurn = 1;
				total = 0;
				
				//G.deck[1][10] = smithy;
				//G.deckCount[1]++;
				//printf("deck count is %d\n", G.deckCount[1]);//should be 11
				firstDeckcount = G.deckCount[1];
				for (h = 0; h < 27; h++){
					//printf("card %d is %d\n", h, fullDeckCount(1, h, &G));//should be 11 total
					total += fullDeckCount(1, h, &G);
				}
				//printf("total is %d\n", total);
				
				int z = cardEffect(smithy, -1, -1, -1, &G, 2, bonus);//play smithy from index 0 of hand
				//playcard(smithy, -1, -1, -1, &G, 0);
				//printf("new deck count is %d\n", G.deckCount[1]); //is this only counting the cards in the deck or discard pile and not in the hand?				
				newtotal = 0;
				for (h = 0; h < 27; h++){
					//printf("card %d is %d\n", h, fullDeckCount(1, h, &G));
					newtotal += fullDeckCount(1, h, &G);
				}
				//printf("new total is %d\n", newtotal);//It looks like discarding a card actually ended up trashing it instead of just discarding it.
				//card, choice1, choice2, choice3, state, handPos, &coin_bonus
				
				//printf("card is %d\n", G.hand[1][0]);
				//printf("card is %d\n", G.hand[1][1]);
				//printf("card is %d\n", G.hand[1][2]);
				//printf("card is %d\n", G.hand[1][3]);
				//printf("card is %d\n", G.hand[1][4]);
				//printf("handcount is %d\n", G.handCount[1]);
				if(G.handCount[1] == 3)
					printf("test passed, there are three cards in Player 2's hand\n");
				else
					printf("test failed, there aren't three cards in Player 2's hand\n");
				if(total == newtotal)
					printf("test passed, no cards were trashed unnecessarily from Player 2's hand\n");
				else
					printf("test failed, cards were trashed unnecessarily from Player 2's hand\n");
				if(G.deckCount[1] == firstDeckcount - 3)
					printf("test passed, three cards were drawn from the deck successfully\n");
				else
					printf("test failed, three cards weren't drawn from the deck successfully\n");

			

    printf("All tests taken!\n");

    return 0;
}
