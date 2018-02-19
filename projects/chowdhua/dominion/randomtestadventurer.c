//Test for Adventurer 

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
	struct gameState G;
	int run_times = rand() % 200 + 50;
	int seed = rand() % 100 + 20;
	int test_pass = 0, pass = 0;
	int draw = 0, discard = 0;
	int player = 0, random_deck, random_hand, random_card, random_card2;
	int copper, silver, gold;
	int bef_coin, aft_coin, bef_hand, aft_hand;
	int i, j, a;
	int k[10] = {adventurer, smithy, minion, village, feast, baron, great_hall, tribute, ambassador, cutpurse};
   
	for(i = 0; i < run_times; i++) {		//Run the Game in a loop between 200 and 50 times
		initializeGame(2, k, seed, &G);		//Initialize Game
		bef_coin = 0, aft_coin = 0;
		random_deck = rand() % (500 + 1);
		random_hand = rand() % (random_deck + 1);
		G.deckCount[0] = random_deck - random_hand;
		G.handCount[0] = random_hand;
		
		for(j = 0; j < 2; j++) {
			for(a = 0; a < G.deckCount[j]; a++) {
				random_card = rand() % 51;
				if(random_card==1)
					G.deck[j][a] = copper;
				else if(random_card==2)
					G.deck[j][a] = silver;
				else if(random_card==3)
					G.deck[j][a] = gold;
				else{
					random_card2 = rand() % 10;
					G.deck[j][a] = k[random_card2];
				}
			}
		}
		for(j = 0; j < G.handCount[player]; j++){
			if(G.hand[player][j] == copper || G.hand[player][j] == silver || G.hand[player][j] == gold)
				bef_coin += 1;
		}
		//Check coins and hand before drawing the card
    printf("\n");
    printf("Coins before the card: %d\n", bef_coin);
    bef_hand = G.handCount[G.whoseTurn];
    printf("Hand before the card: %d\n", bef_hand);
		cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
		for(j = 0; j < G.handCount[player]; j++) {
			if(G.hand[player][j] == copper || G.hand[player][j] == silver || G.hand[player][j] == gold)
				aft_coin += 1;
		}
		//check coins and hand after drawing the card
    printf("Coins after the card: %d\n", aft_coin);
    bef_hand = G.handCount[G.whoseTurn];
    printf("Hand after the card: %d\n", aft_hand);
    printf("\n");
		copper = 0, silver = 0, gold = 0;
		for(j = 0; j < G.discardCount[player]; j++) {
			if(G.discard[player][j]==copper)
				copper += 1;
			else if(G.discard[player][j]==silver)
				silver += 1;
			else if(G.discard[player][j]==gold)
				gold += 1;
		}
		//compare before and after the card is drawn
		pass = 1;
		if(aft_coin != (bef_coin + 2) || aft_coin < bef_coin) {
			draw++;
			pass = 0;
		}
		if(gold != 0 || silver != 0 || copper != 0) {
			discard++;
			pass = 0;
		}
		if(pass == 1)
			test_pass++;
	}
	printf(" \n");
	printf("Final results for Adventurer Card\n");
	printf("Test Passed: %d\n", test_pass);
	printf("Draw failed: %d\n", draw);
	printf("Discard failed: %d\n", discard);
	printf("\n");
	
	return 0;
}