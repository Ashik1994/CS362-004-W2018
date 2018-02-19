//card test on smithy() function

#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



int main() {

	struct gameState G;
	int k[10] = {adventurer, smithy, minion, village, feast, baron, great_hall, tribute, ambassador, cutpurse};
	srand(time(0));
	int s = rand();
	int i;

	initializeGame(2, k, s, &G);

	
	for (i=0; i<10; i++) {
		gainCard(k[rand()%10], &G, 1, 1);
		gainCard(rand()%3+4, &G, 1, 1);
	}

	
	printf("For this test to pass, expect a 13 in the hand before,\n");
	printf("and 3 random cards in the hand after.\n");

	
	for (i=0; i<MAX_HAND; i++) {
		G.hand[1][i] = -1;
	}
	G.hand[1][0] = smithy;

	
	printf("Before: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");

	
	smithy_duplicate(&G, 1, 0);


	printf("After: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");

	
	int found = 1;
	if (G.hand[1][0] == -1 || G.hand[1][1] == -1 || G.hand[1][2] == -1 || G.hand[1][3] != -1 || G.hand[1][4] != -1)
		found = 0;

	if (found) printf("TEST foundFULLY COMPLETED.\n");
	else printf("TEST FAILED.\n");

	return 0;
}