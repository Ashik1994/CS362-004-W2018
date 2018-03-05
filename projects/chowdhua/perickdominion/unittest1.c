//unit test on gainCard() function


#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

int main(){
	printf("Performing test on gainCard() function \n");
	return 0;
	struct gameState G;
	int k[10] = {adventurer, smithy, minion, village, feast, baron, great_hall, tribute, ambassador, cutpurse};
	srand(time(0));
	int s = rand();
	int a, b, c;
	int i;
	int temp=0;
	int temp1=0;
	int temp2=0;
	int temp3=0;
	
	initializeGame(2, k, s, &G);
	
	//added card for [whoseTurn] current player:
	// toFlag = 0 : add to disc
	// toFlag = 1 : add to deck
	// toFlag = 2 : add to hand
	
	//test for no card left
	printf("deck is empty \n");
	c = k[rand()%10];
	G.supplyCount[c] = 0;
	temp = gainCard(c, &G, 1, 1);
	assert(temp == -1);
	printf("deck is empty passed\n");
	
	//test for toflag 0 condition add to discard
	printf("add to disc\n");
	c = k[rand()%10];
	b = G.supplyCount[c];
	gainCard(c, &G, 0, 1);
	a = G.supplyCount[c];
	temp1 = a+1;
	assert(b == temp1);
	printf("add to disc passed\n");
	
	//test for toflag 1 condition add to deck
	printf("add to deck\n");
	c = k[rand()%10];
	b = G.supplyCount[c];
	gainCard(c, &G, 1, 1);
	a = G.supplyCount[c];
	temp2 = 0;
	for (i = 0; i<G.deckCount[1]; i++){
		if (G.deck[1][i] != c){
			temp2 = 1;
			break;
		}
		
	}

	assert (temp2 != 1);
	assert(b == a+1);
	printf("add to deck passed\n");
	
	//test for toflag 2 condition add to hand
	printf("add to hand\n");
	c = k[rand()%10];
	b = G.supplyCount[c];
	gainCard(c, &G, 2, 1);
	a = G.supplyCount[c];
	temp3 = G.hand[1][0];
	assert(temp3 == c);
	assert(b == a+1);
	printf("add to hand passed\n");
	
	printf("All test on gainCard function passed\n");
	
	return 0; 
	
}

