//card test on minion() function

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
	

	for (i=0; i<MAX_HAND; i++) {
		G.hand[1][i] = -1;
	}
	G.hand[1][0] = minion;
	

	printf("Before: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");
	
	G.coins = 0;
	G.numActions = 0;
	//minion_duplicate(1,0,0,&G, 1, 1);
	cardEffect(minion, 0, 0, 0, &G, 0, 0);
	int a = G.numActions;
	assert (a == 1);
	//minion_duplicate2(1,0,0,&G, 1, 1);
	int b = G.coins;
	//assert (b == 2);
	
	int success = 1;
	if (G.hand[1][0] == -1 ||
		G.hand[1][1] == -1 ||
		G.hand[1][2] == -1 ||
		G.hand[1][3] == -1 ||
		G.hand[1][4] != -1)
		success = 0;
	
	
	printf("Cards after: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");
	
	return 0;
}
