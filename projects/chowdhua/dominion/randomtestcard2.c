//Test for village

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  struct gameState G;
  int i, j;
  int num_players, num_card, seed1;
  int hand_bef, card_before, coin_before, discard_before, action_before;
  int action_after, hand_after, card_after, coin_after, discard_after;
  int k[10] = {adventurer, smithy, minion, village, feast, baron, great_hall, tribute, ambassador, cutpurse};
  seed1 = rand() % 100 + 10;

  int test_num = rand() % 500 + 50;
  for (i = 0; i < test_num; i++){    //Run the game in random loop between 50 and 500 times
    num_players = rand()% 2;
	
    printf("Test Number: %d\n", i+1);
    j = initializeGame(num_players, k, seed1, &G);

    G.deckCount[num_players] = rand() % 300 + 1;
    G.discardCount[num_players] = rand() % 300 + 1;
    G.handCount[num_players] = rand() % 300 + 1;
    G.numActions = 1;

    G.coins = rand() % 10 + 5;
    num_card = G.handCount[num_players] + G.deckCount[num_players];
	//before using card
    printf("Number of hand before: %d\n", G.handCount[num_players]);
    hand_bef = G.handCount[num_players];
    printf("Number of discard card before: %d\n", G.discardCount[num_players]);
    discard_before = G.discardCount[num_players];
    printf("Number of card before: %d\n", num_card);
    card_before = num_card;
    printf("Number of coin before: %d\n", G.coins);
    coin_before = G.coins;
    printf("Number of action before: %d\n", G.numActions);
    action_before = G.numActions;
    j = cardEffect(village, 0, 0, 0, &G, 0, 0);
    num_card = G.handCount[num_players] + G.deckCount[num_players];

	//after using card
    printf("Number of hand after: %d\n", G.handCount[num_players]);
    hand_after = G.handCount[num_players];
    printf("| Discard Count: %d\n", G.discardCount[num_players]);
    discard_after = G.discardCount[num_players];
    printf("Number of discard card after: %d\n", num_card);
    card_after = num_card;
    printf("Number of coin after: %d\n", G.coins);
    coin_after = G.coins;
    printf("Number of action after: %d\n", G.numActions);
    action_after = G.numActions;
	//Compare the numbers from before and after
    if(coin_before==coin_after && discard_before==discard_after && card_before==card_after
        && hand_bef==hand_after && action_before==action_after - 2)
      printf("Test passed\n\n");
    else
      printf("Test failed\n\n");
  }
  return 0;
}