//Card test on village


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// Create variables
	struct gameState G;
	int k[10] = {adventurer, smithy, minion, village, feast, baron, great_hall, tribute, ambassador, cutpurse};
	srand(time(0));
	int seed = rand();
	int i;
	int action_bef, action_after;

	// Start the game
	initializeGame(2, k, seed, &G);
	//Place some cards in deck
	for (i=0; i<10; i++) {
		gainCard(k[rand()%10], &G, 1, 1);
		gainCard(rand()%3+4, &G, 1, 1);
	}

	
	printf("For the test to pass, There should be one more card in deck and 2 more actions should be available.\n");

	
	for (i=0; i<MAX_HAND; i++) {
		G.hand[1][i] = -1;
	}
	G.hand[1][0] = village;

	//cards before calling the village function

	printf("Cards before: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");
	printf("Actions before: ");
	action_bef = G.numActions;
	printf("%i\n", action_bef);

	//villageEffect(1, &G, 0);
	//cardEffect(village, 0, 0, 0, &G, 0, 0);
	cardEffect(village, 0, 0, 0, &G, 0, 0);
	
	//Card after
	printf("Cards after: ");
	for (i=0; i<5; i++) {
		printf("%i, ", G.hand[1][i]);
	}
	printf("\n");
	printf("Actions after: ");
	action_after = G.numActions;
	printf("%i\n", action_after);

	// Check results
	int success = 1;
	if (G.hand[1][0] == -1 ||
		G.hand[1][1] != -1 ||
		G.hand[1][2] != -1 ||
		G.hand[1][3] != -1 ||
		G.hand[1][4] != -1)
		success = 0;
	
	if (action_bef + 2 != action_after)
		success = 0;

	if (success) printf("TEST SUCCESSFULLY COMPLETED.\n");
	else printf("TEST FAILED.\n");

	return 0;
}