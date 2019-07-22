#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


//Ambassador Unit Test
int main (int argc, char** argv) {
	int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
	struct gameState state, state2;
	int currentPlayer = 0;
	int nextPlayer = 1;

  	printf("Testing AMBASSADOR card, Choice 1:\n");
  	int initResult = initializeGame(2, k, 2, &state);

  	if(initResult == -1){
  		printf("Game initialization failed\n");
  	}
  	else{
  		printf("Game initialization successful\n");
  	}


  	int choice1 = 1;
  	int choice2 = 0;
  	int choice3 = 0;
  	int handPos = 1;


    for (int i = 0; i < state.numPlayers; i++) {
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
    }

  	int currentPlayerHand1 = state.handCount[0];
  	int nextPlayerHand1 = state.handCount[1];
  	printf("%d\n", nextPlayerHand1);

    for (int i = 0; i < state.numPlayers; i++){
    	printf("Player %d has %d cards \n", i, state.handCount[i]);
    }

    printf("Testing AMBASSADOR card, Choice 1:\n");

	cardEffect(ambassador, choice1, choice2, choice3, &state, handPos, 0);

	int currentPlayerHand2 = state.handCount[0];
    int nextPlayerHand2 = state.handCount[1];
    printf("%d\n", nextPlayerHand2);

    for (int i = 0; i < state.numPlayers; i++){
    	printf("Player %d has %d cards \n", i, state.handCount[i]);
    }

    if(nextPlayerHand2 > nextPlayerHand1){
    	printf("Passed test 1, opponent gained 1 card from current player\n");
    }
    else{
    	printf("Failed test 1, opponent did not gain 1 card from current player\n");
    }



}
