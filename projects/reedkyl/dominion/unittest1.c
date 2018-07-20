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

    printf ("TESTING getCost():\n");
	char bec[5] = "sell";
	//char grif = "happy";
	//memset(&G, 23, sizeof(struct gameState));   // clear the game state
    //r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    //G.handCount[p] = handCount;                 // set the number of cards on hand
    //memcpy(G.hand[p], smithy, sizeof(int) * handCount); // set all the cards to copper
    int x = getCost(smithy);
	int y = getCost(smithy + 1);
	int z = getCost(200);
	int xx = getCost(27);
	int yy = getCost("Hi");
	int zz = getCost(bec);
	//int aa = getCost(grif);
	int bb = getCost(curse);//0
	int cc = getCost(estate);//2
	int dd = getCost(duchy);//5
	int ee = getCost(province);//8
	int ff = getCost(copper);//0
	int gg = getCost(silver);//3
	int hh = getCost(gold);//6
	int c = getCost(adventurer);//6
	int ii = getCost(council_room);//5
	int jj = getCost(feast);//4
	int kk = getCost(gardens);//4
	int ll = getCost(mine);//5
	int mm = getCost(remodel);//4
	int nn = getCost(baron);//4
	int oo = getCost(great_hall);//3
	int pp = getCost(minion);//5
	int qq = getCost(steward);//3
	int rr = getCost(tribute);//5
	int ss = getCost(ambassador);//3
	int tt = getCost(cutpurse);//4
	int uu = getCost(embargo);//2
	int vv = getCost(outpost);//5
	int ww = getCost(salvager);//4
	int a = getCost(sea_hag);//4
	int b = getCost(treasure_map);//4
	//gold, adventurer, 
	//hh c
	//int zzz = getCost(1, 2);
	//int z = smithy;
	//printf("z is %d\n", z);
	if (x == 4)
		printf("Test 1 passed, testing smithy returned 4\n");
	else
		printf("Test 1 failed, testing smithy didn't return 4\n");
	
	if(y == 3)
		printf("Test 2 passed, testing smithy + 1 returned cost of village\n");
	else
		printf("Test 2 failed, testing smithy + 1 didn't return cost of village\n");
	
	if(z == -1)
		printf("Test 3 passed, testing number outside of 0-26 returns -1\n");
	else
		printf("Test 3 failed, testing number outside of 0-26 doesn't return -1\n");
	
	if(xx == -1)
		printf("Test 4 passed, testing number outside of 0-26 returns -1\n");
	else
		printf("Test 4 failed, testing number outside of 0-26 doesn't return -1\n");
	
	if(yy == -1)
		printf("Test 5 passed, testing unusual input ('Hi') returns -1\n");
	else
		printf("Test 5 failed, testing unusual input ('Hi') doesn't return -1\n");
	
	if(zz == -1)
		printf("Test 6 passed, testing unusual input (char array) returns -1\n");
	else
		printf("Test 6 failed, testing unusual input (char array) doesn't return -1\n");
	
	/*if(aa == -1)
		printf("Test 7 passed, testing unusual input (char variable) returns -1\n");
	else
		printf("Test 7 failed, testing unusual input (char variable) doesn't return -1\n");*/
	if(bb == 0 && ff == 0)
		printf("Test 7 passed, testing curse and copper returned 0\n");
	else
		printf("Test 7 failed, testing curse and copper didn't return 0\n");
	if(cc == 2 && uu == 2)
		printf("Test 8 passed, testing estate and embargo returned 2\n");
	else
		printf("Test 8 failed, testing estate and embargo didn't return 2\n");
	if(gg == 3 && oo == 3 && qq == 3 && ss == 3)
		printf("Test 9 passed, testing silver, great_hall, steward, and ambassador returned 3\n");
	else
		printf("Test 9 failed, testing silver, great_hall, steward, and ambassador didn't return 3\n");
	if(jj == 4 && kk == 4 && mm == 4 && nn == 4 && tt == 4 && ww == 4 && a == 4 && b == 4)
		printf("Test 10 passed, testing feast, gardens, remodel, baron, cutpurse, salvager, sea_hag, and treasure_map returned 4\n");
	else
		printf("Test 10 failed, testing feast, gardens, remodel, baron, cutpurse, salvager, sea_hag, and treasure_map didn't return 4\n");
	if(dd == 5 && ii == 5 && ll == 5 && pp == 5 && rr == 5 && vv == 5)
		printf("Test 11 passed, testing duchy, council_room, mine, minion, tribute, and outpost returned 5\n");
	else
		printf("Test 11 failed, testing duchy, council_room, mine, minion, tribute, and outpost didn't return 5\n");
	if(hh == 6 && c == 6)
		printf("Test 12 passed, testing gold and adventurer returned 6\n");
	else
		printf("Test 12 failed, testing gold and adventurer didn't return 6\n");	
	if(ee == 8)
		printf("Test 13 passed, testing province returns 8\n");
	else
		printf("Test 13 failed, testing province doesn't return 8\n");
    printf("All tests taken!\n");

    return 0;
}
