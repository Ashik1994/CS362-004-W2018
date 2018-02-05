//card test on adventurer() function

#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"



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


	printf("For this test to pass, expect 2 treasures in hand after.\n");


	for (i=0; i<MAX_HAND; i++) {
		G.hand[1][i] = -1;
	}
	G.hand[1][0] = adventurer;

	printf("Cards before: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");
	
	int c = k[rand()%10];
	int *temphand;
	temphand = malloc(10*sizeof(int));
	memcpy(temphand,G.hand[1],10);
	
	adventurer_duplicate(&G, 1, 0, c, temphand, 0);

	printf("Cards after: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");

	int found = 0;
	if ((G.hand[1][0] == copper || G.hand[1][0] == silver || G.hand[1][0] == gold) && (G.hand[1][1] == copper || G.hand[1][1] == silver || G.hand[1][1] == gold))
		found = 1;

	if (found) printf("TEST SUCCESSFULLY COMPLETED.\n");
	else printf("TEST FAILED.\n");

	return 0;
}