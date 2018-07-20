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
    printf ("TESTING adventurer():\n");

				numPlayer = 2;

	printf("test 1 add adventurer to index 0 (hand position 1) and use card effect of adventurer for player 2\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand

				G.hand[1][0] = adventurer;
				G.handCount[1]++;

				G.whoseTurn = 1;
				int total = 0;
				int h;
				
				int firstDeckcount = G.deckCount[1];
				for (h = 0; h < 27; h++)
					total += fullDeckCount(1, h, &G);
				
				int y = printf("cardeffect %d \n", cardEffect(adventurer, -1, -1, -1, &G, 0, bonus));//play smithy from index 0 of hand
			
				int newtotal = 0;
				for (h = 0; h < 27; h++)
					newtotal += fullDeckCount(1, h, &G);

				if(G.handCount[1] == 2)
					printf("test passed, there are two cards in Player 2's hand\n");
				else
					printf("test failed, there aren't two cards in Player 2's hand\n");
				if(G.hand[1][0] == 7)
					printf("test failed, adventurer was not discarded from the hand\n");
				else
					printf("test passed, adventurer was discarded from the hand\n");
				if(total == newtotal)
					printf("test passed, no cards were trashed unnecessarily from Player 2's hand\n");
				else
					printf("test failed, cards were trashed unnecessarily from Player 2's hand\n");
				if(G.hand[1][1] == 4)
					if(G.hand[1][0] == 4)
						printf("test passed 100%, 2 treasures(copper) were added to Player 2's hand\n");
					else
						printf("test passed 50%, only 1 treasure(copper) was added to Player 2's hand\n");
				else if(G.hand[1][0] == 4)
					printf("test passed 50%, only 1 treasure(copper) was added to Player 2's hand\n");
				else
					printf("test failed 0%, 1 treasure(copper) was added to Player 2's hand\n");
				
				
printf("test 2 add adventurer to index 0 and use card effect of adventurer for player 1\n");
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand

				G.hand[0][0] = adventurer;
				G.handCount[0] = 1;

				G.whoseTurn = 0;
				total = 0;

				firstDeckcount = G.deckCount[0];
				for (h = 0; h < 27; h++)
					total += fullDeckCount(0, h, &G);
				
				int z = cardEffect(adventurer, -1, -1, -1, &G, 0, bonus);//play smithy from index 0 of hand
			
				newtotal = 0;
				for (h = 0; h < 27; h++)
					newtotal += fullDeckCount(0, h, &G);

				printf("handcount is %d\n", G.handCount[0]);
				if(G.handCount[0] == 2)
					printf("test passed, there are two cards in Player 1's hand\n");
				else
					printf("test failed, there aren't two cards in Player 1's hand\n");
				if(G.hand[0][0] == 7)
					printf("test failed, adventurer was not discarded from the hand\n");
				else
					printf("test passed, adventurer was discarded from the hand\n");
				if(total == newtotal)
					printf("test passed, no cards were trashed unnecessarily\n");
				else
					printf("test failed, cards were trashed unnecessarily\n");
				if(G.hand[0][1] == 4)
					if(G.hand[0][0] == 4)
						printf("test passed 100%, both new cards in Player 1's hand are treasures (copper)\n");
					else
						printf("test passed 50%, only 1 new card in Player 1's hand is a treasure (copper)\n");
				else if(G.hand[0][0] == 4)
					printf("test passed 50%, only 1 new card in Player 1's hand is a treasure (copper)\n");
				else
					printf("test failed 0%, both new cards in Player 1's hand aren't treasures (copper)\n");
		printf("test 3, when deck count is 0, and discard pile has 5 coppers and 1 adventurer card in player 2's hand\n");		
				
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand
 
				G.hand[1][0] = adventurer;
				G.handCount[1]++;
				G.deckCount[1] = 0;
				G.discardCount[1] = 5;
				int j;
				for(j = 0; j<5; j++)
					G.discard[1][j] = copper;

				G.whoseTurn = 1;
				total = 0;

				firstDeckcount = G.deckCount[1];
				for (h = 0; h < 27; h++)
					total += fullDeckCount(1, h, &G);
				
				int x = cardEffect(adventurer, -1, -1, -1, &G, 0, bonus);//play smithy from index 0 of hand
			
				newtotal = 0;
				for (h = 0; h < 27; h++)
					newtotal += fullDeckCount(1, h, &G);
				
				if(G.handCount[1] == 2)
					printf("test passed, there are two cards in Player 2's hand\n");
				else
					printf("test failed, there aren't two cards in Player 2's hand\n");
				if(G.hand[1][0] == 7)
					printf("test failed, adventurer was not discarded from the hand\n");
				else
					printf("test passed, adventurer was discarded from the hand\n");
				if(total == newtotal)
					printf("test passed, no cards were trashed unnecessarily from Player 2's hand\n");
				else
					printf("test failed, cards were trashed unnecessarily from Player 2's hand\n");
				if(G.hand[1][1] == 4)
					if(G.hand[1][0] == 4)
						printf("test passed 100%, both cards in Player 2's hand are treasures (copper)\n");
					else
						printf("test passed 50%, only 1 card in Player 2's hand is a treasure (copper)\n");
				else if(G.hand[1][0] == 4)
					printf("test passed 50%, only 1 card in Player 2's hand is a treasure (copper)\n");
				else
					printf("test failed 0%, both cards in Player 2's hand aren't treasures (copper)\n");
		printf("test 4: drawing multiple cards to find a treasure \n");
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
															// set the number of cards on hand

				G.hand[1][0] = adventurer;
				G.handCount[1] = 1;
				G.deckCount[1] = 4;
				int n;
				G.deck[1][0] = smithy;
				G.deck[1][1] = copper;
				G.discardCount[1] = 0;
				for(n = 2; n < 4; n++)
					G.deck[1][n] = smithy; 
				
				G.whoseTurn = 1;
				total = 0;
				printf("in hand %d\n", G.hand[1][0]);
					
				for (h = 0; h < 4; h++)
					printf("card %d is %d\n", h, G.deck[1][h]);//should be 11 total
				
				//printf("deckcount is %d \n", G.deckCount[1]);
				int q = cardEffect(adventurer, -1, -1, -1, &G, 0, bonus);
				newtotal = 0;
				//printf("deckcount is %d \n", G.deckCount[1]);
				for (h = 0; h < 27; h++)
					newtotal += fullDeckCount(1, h, &G);

				if(G.handCount[1] == 2)
					printf("Test passed! there are 2 cards in player 2's hand\n");
				else
					printf("Test failed! there aren't 2 cards in player 2's hand\n");
				/*for (h = 0; h < 2; h++){
					printf("player 1's hand: the card %d is %d\n",h,G.hand[1][h]); 
				}*/
				if(G.hand[1][1] == 4)
					if(G.hand[1][0] == 4)
						printf("test passed 100%, both cards in Player 2's hand are treasures (copper)\n");
					else
						printf("test passed 50%, only 1 card in Player 2's hand is a treasure (copper)\n");
				else if(G.hand[1][0] == 4)
					printf("test passed 50%, only 1 card in Player 2's hand is a treasure (copper)\n");
				else
					printf("test failed 0%, both cards in Player 2's hand aren't treasures (copper)\n");
				if(G.discardCount[1] == 2)
					printf("Test passed, two cards were correctly added to the discard pile of player 2\n");
				else
					printf("Test failed, two cards were not correctly added to the discard pile of player 2\n");

				if(G.discard[1][0] == smithy && G.discard[1][1] == smithy)
					printf("Test passed! both discarded cards in player 2's discard pile are smithy\n");
				else
					printf("Test passed! both discarded cards in player 2's discard pile aren't smithy\n");
				
				printf("TEST 5: drawing a gold\n");
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
				for (h = 0; h < 5; h++){
					printf("the card %d is %d\n",h,G.hand[0][h]); 
				}
				if(G.hand[0][4] == gold)
					if(G.hand[0][5] == silver) 
						printf("Test passed 100%, a gold and silver were correctly drawn into player 1's hand\n");
					else
						printf("Test passed 50%, a gold was correctly drawn, but a silver was not correctly drawn into player 1's hand\n");
				else if(G.hand[0][5] == silver)
					printf("Test passed 50%, a silver was correctly drawn, but a gold was not correctly drawn into player 1's hand\n");
				else
					printf("Test failed 0%, neither a gold or a silver was not drawn into player 1's hand\n");
				
				printf("test 6: drawing a silver\n");
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
						printf("Test passed 100%, a silver and copper were correctly drawn into player 1's hand\n");
					else
						printf("Test passed 50%, a silver was correctly drawn, but a copper was not correctly drawn into player 1's hand\n");
				else if(G.hand[0][5] == copper)
					printf("Test passed 50%, a copper was correctly drawn, but a silver was not correctly drawn into player 1's hand\n");
				else
					printf("Test failed 0%, neither a copper or a silver was not drawn into player 1's hand\n");
				
    printf("All tests taken!\n");

    return 0;
}
