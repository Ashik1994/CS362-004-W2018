//unit test on isGameOver() function


#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

int main(){
	
	printf("Performing test on isGameOver() function \n");
	
	struct gameState G;
	int k[10] = {adventurer, smithy, minion, village, feast, baron, great_hall, tribute, ambassador, cutpurse};
	srand(time(0));
	int s = rand();
	int a;
	
	initializeGame(2, k, s, &G);
	G.supplyCount[province] = 0;
	a = isGameOver(&G);
	assert(a == 1);
	G.supplyCount[1] = 0;
	G.supplyCount[2] = 0;
	G.supplyCount[7] = 0;
	a = isGameOver(&G);
	assert (a == 1);
	
	printf("Test on isGameOver passed\n");
	return 0;
	
}