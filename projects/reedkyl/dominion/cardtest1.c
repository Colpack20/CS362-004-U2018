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
    int i, addedCards;
    int seed = 1000;
	int addedCoins;
	int shuffledCards = 0;
    int numPlayer = 2;
    int maxBonus = 10;
	int discardedCards = 1;
	int currentPlayer = 0;
    int p, r, handCount;
    int bonus = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testcaseG;
	
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

	printf("Test 1 add smithy to index 0 (hand position 1) and use card effect of smithy\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game set the number of cards on hand															 
				// copy the game state to a test case
				memcpy(&testcaseG, &G, sizeof(struct gameState));
				
				//cardEffect(smithy, choice1, choice2, choice3, &testcaseG, handpos, &bonus);
				//testcaseG.hand[0][0] = smithy;
				
				//assert(testG.coins == G.coins + addedCoins);
				//G.hand[1][0] = copper;
				//G.hand[1][0] = copper;
				//G.hand[1][0] = copper;
				//G.hand[1][0] = copper;
				
				//G.handCount[1]++;
				//G.handCount[1] = 1;
				//G.discardCount[1] = 0;
				
				//G.whoseTurn = 1;
				int total = 0;
				int h;
				//printf("Player 1's hand is %d, their deck is %d, and their discard pile is %d \n", testcaseG.handCount[0], testcaseG.deckCount[0], testcaseG.discardCount[0]);
				//printf("Player 2's hand is %d, their deck is %d, and their discard pile is %d \n", testcaseG.handCount[1], testcaseG.deckCount[1], testcaseG.discardCount[1]);
				//printf("deck count is %d\n", G.deckCount[1]);//should be 11
				int firstDeckcount = G.deckCount[0];
				for (h = 0; h < 27; h++)	
					total += fullDeckCount(0, h, &G);
				//printf("first total is %d\n", total);
				
				
				
				cardEffect(smithy, choice1, choice2, choice3, &testcaseG, handpos, bonus);//play smithy from index 0 of hand
				//printf("Player 1's hand is %d, their deck is %d, and their discard pile is %d \n", testcaseG.handCount[0], testcaseG.deckCount[0], testcaseG.discardCount[0]);
				firstDeckcount = testcaseG.deckCount[0];
				int newtotal = 0;
				for (h = 0; h < 27; h++)	
					newtotal += fullDeckCount(0, h, &testcaseG);
				//printf("second total is %d\n", newtotal);
				
				addedCards = 3;
				addedCoins = 0;
				if(testcaseG.coins == G.coins)
					printf("Passed: the expected coin total is %d, and the current coin total is %d\n", G.coins, testcaseG.coins);
				else
					printf("Failed: the expected coin total is %d, and the current coin total is %d\n", G.coins, testcaseG.coins);
				//else(testcaseG.discardCount[currentPlayer] != G.discardCount[currentPlayer] + 1)
				if(testcaseG.discardCount[currentPlayer] == G.discardCount[currentPlayer] + 1)
					printf("Passed: %d card(s) correctly added to the discard pile\n", discardedCards);
				else
					printf("Failed: %d card(s) added to the discard pile, %d cards expected to be added to the discard pile\n", testcaseG.discardCount[currentPlayer] - G.discardCount[currentPlayer], discardedCards);
				if (testcaseG.handCount[currentPlayer] == G.handCount[currentPlayer] + addedCards - discardedCards)
					printf("Passed: The hand count for the current Player is %d and the expected hand count is %d \n", testcaseG.handCount[currentPlayer], G.handCount[currentPlayer] + addedCards - discardedCards);
				else
					printf("Failed: The hand count for the current Player is %d and the expected hand count is %d \n", testcaseG.handCount[currentPlayer], G.handCount[currentPlayer] + addedCards - discardedCards);
				
				if(testcaseG.deckCount[currentPlayer] == G.deckCount[currentPlayer] - addedCards + shuffledCards)
					printf("Passed: the deck count is %d and the expected deck count is %d\n", testcaseG.deckCount[currentPlayer], G.deckCount[currentPlayer] - addedCards + shuffledCards);
				else
					printf("Failed: the deck count is %d and the expected deck count is %d\n", testcaseG.deckCount[currentPlayer], G.deckCount[currentPlayer] - addedCards + shuffledCards);
				if(testcaseG.handCount[1] == G.handCount[1])
					printf("Passed: Player 2's hand count didn't change\n");
				else
					printf("Failed: Player 2's hand count changed\n");
				if(testcaseG.deckCount[1] == G.deckCount[1])
					printf("Passed: Player 2's deck count didn't change\n");
				else
					printf("Failed: Player 2's deck count changed\n");
				if(testcaseG.discardCount[1] == G.discardCount[1])
					printf("Passed: Player 2's discard count didn't change\n");
				else
					printf("Failed: Player 2's discard count changed\n");
				if(testcaseG.supplyCount[estate] == G.supplyCount[estate] && testcaseG.supplyCount[duchy] == G.supplyCount[duchy] && testcaseG.supplyCount[province] == G.supplyCount[province])
					printf("Passed: the victory card counts are unchanged\n");
				else
					printf("Failed: the victory card counts have changed\n");
				int m;
				for(m = 7; m < 17; m++)
					if(testcaseG.supplyCount[m] == G.supplyCount[m])
						printf("Passed: The supply count of kingdom card %d has stayed the same\n", m);
					else
						printf("Failed: The supply count of kingdom card %d has changed\n", m);
				
				
				//printf("test 1B: were any cards trashed or added unnecessarily to Player 1's full deck?\n");
				if(total == newtotal)
					printf("Test passed, no cards were trashed unnecessarily from Player 1's full deck\n");
				else if(total > newtotal)
					printf("Test failed, %d card(s) was/were trashed unnecessarily from Player 1's full deck\n", total-newtotal);
				else
					printf("Test failed, some cards were added unnecessarily to Player 1's full deck\n");
				//printf("test 1C: were three cards drawn from the deck successfully?\n");
				//printf("initial deckCount is %d and then deck count is %d\n", firstDeckcount, G.deckCount[1]);
				//if(testcaseG.deckCount[0] == (firstDeckcount - 3))
					//printf("test passed, three cards were drawn from the deck successfully\n");
				//else
					//printf("test failed, three cards weren't drawn from the deck successfully, %d cards were drawn\n", firstDeckcount-G.deckCount[1]);
				/*
				printf("test 1D: did Player 1's state (hand, deck, and discard) change at all unnecessarily? Assuming that Player 1 started with 5 cards in their deck, 5 cards in their hand, and 0 cards in the discard pile)\n");
				printf("Player 1's hand is %d, their deck is %d, and their discard pile is %d \n", G.handCount[0], G.deckCount[0], G.discardCount[0]);
				printf("Player 2's hand is %d, their deck is %d, and their discard pile is %d \n", G.handCount[1], G.deckCount[1], G.discardCount[1]);				
				printf("kingdom cards is %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", k[0], k[1], k[2], k[3], k[4], k[5], k[6], k[7], k[8], k[9]);   */
				//if
				
				//else
	

    printf("All tests taken!\n");

    return 0;
}
