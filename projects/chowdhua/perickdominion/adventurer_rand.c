#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int main() {
  srand(time(NULL));
	struct gameState g;
  int numTests = rand() % 80 + 21;
	int seed = rand() % 80 + 21;
	int passed = 0, pass = 0, beforeHand = 0, afterHand = 0;
	int draw = 0, discard = 0;
	int player = 0, randDeck, randHand, randCard, randKCard;
	int copper, silver, gold;
	int beforeCoins = 0, afterCoins = 0;
	int i, j, n;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
              remodel, tribute, smithy, council_room };
	for (i = 0; i < numTests; i++) {
		initializeGame(2, k, seed, &g);
		beforeCoins = 0, afterCoins = 0;
		randDeck = rand() % (500 + 1);
		randHand = rand() % (randDeck + 1);
		g.deckCount[0] = randDeck - randHand;
		g.handCount[0] = randHand;
		//Radomize each player's starting deck
		for (j = 0; j < 2; j++) {
			for (n = 0; n < g.deckCount[j]; n++) {
				randCard = rand() % 51;
				if (randCard == 1)
					g.deck[j][n] = copper;
				else if (randCard == 2)
					g.deck[j][n] = silver;
				else if (randCard == 3)
					g.deck[j][n] = gold;
				else {
					randKCard = rand() % 10;
					g.deck[j][n] = k[randKCard];
				}
			}
		}
		for (j = 0; j < g.handCount[player]; j++) {
			if (g.hand[player][j] == copper || g.hand[player][j] == silver || g.hand[player][j] == gold)
				beforeCoins += 1;
		}
    printf("|--------------------\n");
    printf("| Before Coins: %d\n", beforeCoins);
    beforeHand = g.handCount[g.whoseTurn];
    printf("| Before Hand: %d\n", beforeHand);
		cardEffect(adventurer, 0, 0, 0, &g, 0, 0);
		for (j = 0; j < g.handCount[player]; j++) {
			if (g.hand[player][j] == copper || g.hand[player][j] == silver || g.hand[player][j] == gold)
				afterCoins += 1;
		}
    printf("| After Coins: %d\n", afterCoins);
    beforeHand = g.handCount[g.whoseTurn];
    printf("| After Hand: %d\n", afterHand);
    printf("|--------------------\n");
		copper = 0, silver = 0, gold = 0;
		for (j = 0; j < g.discardCount[player]; j++) {
			if (g.discard[player][j] == copper)
				copper += 1;
			else if (g.discard[player][j] == silver)
				silver += 1;
			else if (g.discard[player][j] == gold)
				gold += 1;
		}
		pass = 1;
		if (afterCoins != (beforeCoins + 2) || afterCoins < beforeCoins) {
			draw++;
			pass = 0;
		}
		if (gold != 0 || silver != 0 || copper != 0) {
			discard++;
			pass = 0;
		}
		if (pass == 1)
			passed++;
	}
	printf(" \n");
  printf("|---------------------------------|\n");
	printf("| Test results for adventurer\n");
	printf("| PASSED: %d\n", passed);
	printf("| FAILED Draw: %d\n", draw);
	printf("| FAILED Discard: %d\n", discard);
  printf("|---------------------------------|\n\n");
	return 0;
}