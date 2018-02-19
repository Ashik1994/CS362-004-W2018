//unit test on buyCard() function


#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

int main(){
	printf("Performing test on buyCard() function \n");
	
	struct gameState G;
	int k[10] = {adventurer, smithy, minion, village, feast, baron, great_hall, tribute, ambassador, cutpurse};
	srand(time(0));
	int s = rand();
	int a, b, c;
	
	initializeGame(2, k, s, &G);
	
	G.numBuys = 0;   //no buys left
	a = buyCard(5, &G);
	assert (a == -1);
	
	G.numBuys = 5;	//no coins 
	G.coins = 0;
	b = buyCard(5, &G);
	assert (b == -1);
	
	G.numBuys = 5;
	G.coins = 100;
	c = buyCard(5, &G);
	assert (c == 0);
	
	printf("Test on buyCard() function passed!\n");
	
	return 0;
	
}
	
	