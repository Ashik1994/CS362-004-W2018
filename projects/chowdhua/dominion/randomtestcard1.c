//SMITHY RANDOM TEST

#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>

void test_smithy(struct gameState *G) {
  int i, play;
  G->whoseTurn = rand() % 2;
  //generate random values for number of hand, deck and discard
  int max_hand = rand() % (400 + 1);
  int max_turn = rand() % (16 + 1);
  int max_deck = rand() % (400 + 1);
  int max_discard = rand() % (400 + 1);

  G->hand[G->whoseTurn][0]= 7;
  G->handCount[G->whoseTurn]=max_hand;
  for (i = 1;i < G->handCount[G->whoseTurn];i++)
    G->hand[G->whoseTurn][i]=max_turn;

  G->deckCount[G->whoseTurn]=max_deck;
  for (i = 0;i < G->deckCount[G->whoseTurn];i++)
    G->deck[G->whoseTurn][i]=max_turn;

  G->discardCount[G->whoseTurn]=max_discard;
  for (i = 0;i < G->discardCount[G->whoseTurn];i++)
    G->discard[G->whoseTurn][i]=max_turn;

//set up the hand for opponent
  if (G->whoseTurn==0)
    play = 1;
  else
    play = 0;

  G->handCount[play] = max_hand;
  for (i = 0; i < G->handCount[play]; i++)
    G->hand[play][i] = max_turn;

  G->deckCount[play] = max_deck;
  for (i = 0; i < G->deckCount[play]; i++)
    G->deck[play][i] = max_turn;

  G->discardCount[play] = max_discard;
  for (i = 0; i < G->discardCount[play]; i++)
    G->discard[play][i] = max_turn;
}

int main() {
	int counter = 1;
	srand(time(NULL));
	int seed = rand() % 100 + 1;
  int run_times = rand() % 500 + 50;
	int number_players = 2;
  int hand_before, hand_after;
	struct gameState G;
	int k[10] = {adventurer, smithy, minion, village, feast, baron, great_hall, tribute, ambassador, cutpurse};
	initializeGame(number_players, k, seed, &G);
	G.phase = 0;
	G.numBuys = 1;
	//Run the game in random loop between 50 and 500 times
	int a;
	for(a = 0; a < run_times; a++){
	
    printf("\n");
    printf("Random_test number %d\n", counter);
		test_smithy(&G);
		struct gameState dominion;
		dominion = G;
  //record the number before card is drawn
    printf("Number of hand before: %d\n", G.handCount[G.whoseTurn]);
    hand_before = G.handCount[G.whoseTurn];
		cardEffect(smithy, 0, 0, 0, &G, 0, 0);
 //record the number after card is drawn
    printf("Number of hand after: %d\n", G.handCount[G.whoseTurn]);
    hand_after = G.handCount[G.whoseTurn];
    if (hand_before == hand_after - 2)
      printf("Test passed \n\n");
    else {
      printf("Test failed \n");
      printf("Number of hand (expected): %d\n", hand_after - 1);
      printf("Number of hand: %d\n\n", hand_after);
    }
		counter++;
	}
  return 0;
}
