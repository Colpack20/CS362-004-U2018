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
    printf ("TESTING adventurer():\n");

				numPlayer = 2;

	printf("test 1 add adventurer to index 0 (hand position 1) and use card effect of adventurer for player 1\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand
				memcpy(&testcaseG, &G, sizeof(struct gameState));
				testcaseG.hand[0][0] = adventurer;
				//G.handCount[1]++;

				//G.whoseTurn = 1;
				int total = 0;
				int h;
				
				int firstDeckcount = G.deckCount[0];
				for (h = 0; h < 27; h++)	
					total += fullDeckCount(0, h, &G);
				//for(h =0; h < testcaseG.handCount[0]; h++)
					//printf("hand card %d is %d\n", h, testcaseG.hand[0][h]);
				//for(h =0; h < testcaseG.handCount[0]; h++)
					//printf("deck card %d is %d\n", h, testcaseG.deck[0][h]);
				cardEffect(adventurer, choice1, choice2, choice3, &testcaseG, handpos, bonus);//play adventurer from index 0 of hand
			
				firstDeckcount = testcaseG.deckCount[0];
				int newtotal = 0;
				for (h = 0; h < 27; h++)	
					newtotal += fullDeckCount(0, h, &testcaseG);
				addedCards = 2;
				addedCoins = 0;
				if(testcaseG.coins == G.coins)
					printf("Passed: the expected coin total is %d, and the current coin total is %d\n", G.coins, testcaseG.coins);
				else
					printf("Failed: the expected coin total is %d, and the current coin total is %d\n", G.coins, testcaseG.coins);
				//else(testcaseG.discardCount[currentPlayer] != G.discardCount[currentPlayer] + 1)
				if(testcaseG.discardCount[currentPlayer] == G.discardCount[currentPlayer] + discardedCards)
					printf("Passed: %d card(s) correctly added to the discard pile\n", discardedCards);
				else
					printf("Failed: %d card(s) added to the discard pile, %d cards expected to be added to the discard pile\n", testcaseG.discardCount[currentPlayer] - G.discardCount[currentPlayer], discardedCards);
				if (testcaseG.handCount[currentPlayer] == G.handCount[currentPlayer] + addedCards - discardedCards)
					printf("Passed: The hand count for the current Player is %d and the expected hand count is %d \n", testcaseG.handCount[currentPlayer], G.handCount[currentPlayer] + addedCards - discardedCards);
				else
					printf("Failed: The hand count for the current Player is %d and the expected hand count is %d \n", testcaseG.handCount[currentPlayer], G.handCount[currentPlayer] + addedCards - discardedCards);
				if(G.hand[0][5] == 4)
					if(G.hand[0][4] == 4)
						printf("test passed, both new cards in Player 1's hand are treasures (copper)\n");
					else
						printf("test failed, only 1 new card in Player 1's hand is a treasure (copper)\n");
				else if(G.hand[0][4] == 4)
					printf("test failed, only 1 new card in Player 1's hand is a treasure (copper)\n");
				else
					printf("test failed, both new cards in Player 1's hand aren't treasures (copper)\n");
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
				
printf("\ntest 2, when deck count is 0, and the discard pile has 5 coppers and there is 1 adventurer card in player 2's hand\n");		
				
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand
 
				G.hand[1][0] = adventurer;
				G.handCount[1]++;
				//printf("the handcount before card effect is %d \n", G.handCount[1]);
				G.deckCount[1] = 0;
				G.discardCount[1] = 5;
				int j;
				for(j = 0; j<5; j++)
					G.discard[1][j] = silver;

				G.whoseTurn = 1;
				total = 0;

				firstDeckcount = G.deckCount[1];
				for (h = 0; h < 27; h++)
					total += fullDeckCount(1, h, &G);
				
				int x = cardEffect(adventurer, -1, -1, -1, &G, 0, bonus);//play smithy from index 0 of hand
				//printf("the handcount after card effect is %d \n", G.handCount[1]);
				newtotal = 0;
				for (h = 0; h < 27; h++)
					newtotal += fullDeckCount(1, h, &G);
				//printf("total is %d, newtotal is %d\n", total, newtotal);
				//int u;
				//for(u = 0; u < G.handCount[1]; u++)
					//printf("card %d is %d\n", u, G.hand[1][u]);
				printf("test 2A: are there two cards in Player 2's hand?\n");
				if(G.handCount[1] == 2)
					printf("test passed, there are two cards in Player 2's hand\n");
				else
					printf("test failed, there aren't two cards in Player 2's hand\n");
				printf("test 2B: was adventurer discarded from player 2's hand?\n");
				if(G.hand[1][0] == 7)
					printf("test failed, adventurer was not discarded from the hand\n");
				else
					printf("test passed, adventurer was discarded from the hand\n");
				printf("test 2C: were any cards trashed or added unnecessarily to Player 2's full deck?\n");
				if(total == newtotal)
					printf("test passed, no cards were trashed or added unnecessarily to Player 2's full deck\n");
				else if(total > newtotal)
					printf("test failed, %d card(s) was/were trashed unnecessarily from Player 2's full deck\n", total-newtotal);
				else
					printf("test failed, some cards were added unnecessarily\n");
				printf("test 2D: were 2 treasures added to Player 2's hand?\n");
				if(G.hand[1][1] == 5)
					if(G.hand[1][0] == 5)
						printf("test passed, both cards in Player 2's hand are treasures (copper)\n");
					else
						printf("test failed, only 1 card in Player 2's hand is a treasure (copper)\n");
				else if(G.hand[1][0] == 5)
					printf("test failed, only 1 card in Player 2's hand is a treasure (copper)\n");
				else
					printf("test failed, both cards in Player 2's hand aren't treasures (copper)\n");
printf("\ntest 3: drawing multiple cards to find a treasure \n");
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand

				G.hand[1][0] = adventurer;
				G.handCount[1] = 1;
				G.deckCount[1] = 4;
				int n;
				G.deck[1][0] = smithy;
				G.deck[1][1] = gold;
				G.deck[1][2] = gold;
				G.deck[1][3] = smithy;
				G.discardCount[1] = 0;
				
				G.whoseTurn = 1;
				total = 0;
				//printf("in hand %d\n", G.hand[1][0]);
					
				//for (h = 0; h < 4; h++)
					//printf("card %d is %d\n", h, G.deck[1][h]);//should be 11 total
				
				//printf("deckcount is %d \n", G.deckCount[1]);
				int q = cardEffect(adventurer, -1, -1, -1, &G, 0, bonus);
				newtotal = 0;
				//printf("deckcount is %d \n", G.deckCount[1]);
				for (h = 0; h < 27; h++)
					newtotal += fullDeckCount(1, h, &G);
				printf("test 3A: are there two cards in Player 2's hand?\n");
				if(G.handCount[1] == 2)
					printf("Test passed! there are 2 cards in player 2's hand\n");
				else
					printf("Test failed! there aren't 2 cards in player 2's hand\n");
				/*for (h = 0; h < 2; h++){
					printf("player 1's hand: the card %d is %d\n",h,G.hand[1][h]); 
				}*/
				printf("test 3B: were 2 treasures added to Player 2's hand?\n");
				if(G.hand[1][1] == 6)
					if(G.hand[1][0] == 6)
						printf("test passed, both cards in Player 2's hand are treasures (copper)\n");
					else
						printf("test failed, only 1 card in Player 2's hand is a treasure (copper)\n");
				else if(G.hand[1][0] == 6)
					printf("test failed, only 1 card in Player 2's hand is a treasure (copper)\n");
				else
					printf("test failed, both cards in Player 2's hand aren't treasures (copper)\n");
				printf("test 3C: were two cards added to the discard pile of player 2?\n");
				if(G.discardCount[1] == 2)
					printf("Test passed, two cards were correctly added to the discard pile of player 2\n");
				else
					printf("Test failed, %d card(s) was/were added to the discard pile of player 2\n", G.discardCount[1]);
				printf("test 3D: are both cards in the discard pile the smithy cards that were in Player 2's hand?\n");
				if(G.discard[1][0] == smithy && G.discard[1][1] == smithy)
					printf("Test passed! both discarded cards in player 2's discard pile are smithy\n");
				else
					printf("Test failed! the first card is %d and there is no second card in the discard pile\n", G.discard[1][0]);
				
printf("\nTest 4: does playing the adventurer card cause player 1 to draw a gold and a silver into their hand? (When the top deck card is a gold and then a silver)\n");
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G);
				G.hand[0][0] = adventurer;
				G.hand[0][1] = smithy;
				G.hand[0][2] = smithy;
				G.hand[0][3] = smithy;
				G.handCount[0] = 4;
				G.deckCount[0] = 3;
				
				
				G.deck[0][0] = silver;
				G.deck[0][1] = silver;
				G.deck[0][2] = gold;
				G.whoseTurn = 0;
				int w = cardEffect(adventurer, -1, -1, -1, &G, 0, bonus);
				/*for (h = 0; h < 5; h++){
					printf("the card %d is %d\n",h,G.hand[0][h]); 
				}*/
				if(G.hand[0][4] == gold)
					if(G.hand[0][5] == silver) 
						printf("Test passed, a gold and silver were correctly drawn into player 1's hand\n");
					else
						printf("Test failed, a gold was correctly drawn, but a silver was not correctly drawn into player 1's hand\n");
				else if(G.hand[0][5] == silver)
					printf("Test failed, a silver was correctly drawn, but a gold was not correctly drawn into player 1's hand\n");
				else
					printf("Test failed, neither a gold nor a silver was not drawn into player 1's hand\n");
				
printf("\nTest 5: does playing the adventurer card cause player 1 to draw a silver and a copper into their hand? (When the top deck card is a silver and then a copper)\n");
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G);
				G.hand[0][0] = adventurer;
				G.hand[0][1] = smithy;
				G.hand[0][2] = smithy;
				G.hand[0][3] = smithy;
				G.handCount[0] = 4;
				G.deckCount[0] = 3;
				
				
				G.deck[0][0] = gold;
				G.deck[0][1] = copper;
				G.deck[0][2] = silver;
				G.whoseTurn = 0;
				int e = cardEffect(adventurer, -1, -1, -1, &G, 0, bonus);
				/*for (h = 0; h < 5; h++){
					printf("the card %d is %d\n",h,G.hand[0][h]); 
				}*/
				if(G.hand[0][4] == silver)
					if(G.hand[0][5] == copper) 
						printf("Test passed, a silver and copper were correctly drawn into player 1's hand\n");
					else
						printf("Test failed, a silver was correctly drawn, but a copper was not correctly drawn into player 1's hand\n");
				else if(G.hand[0][5] == copper)
					printf("Test failed, a copper was correctly drawn, but a silver was not correctly drawn into player 1's hand\n");
				else
					printf("Test failed, neither a copper or a silver was not drawn into player 1's hand\n");
				
    printf("All tests taken!\n");

    return 0;
}