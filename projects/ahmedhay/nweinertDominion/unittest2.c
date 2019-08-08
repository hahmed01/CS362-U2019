#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
 

//Minion unit test
int main (int argc, char** argv) {
	int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
	struct gameState state, state2;
	int currentPlayer = 0;

  	printf("Testing MINION card, Choice 1:\n");
  	int initResult = initializeGame(2, k, 2, &state);

  	if(initResult == -1){
  		printf("Game initialization failed\n");
  	}
  	else{
  		printf("Game initialization successful\n");
  	}

  	int choice1 = 1;
  	int choice2 = 0;
  	int handPos = 0;
  	int choice3 = 0;

  	state.coins = 0;

  	//Testing choice 1
  	//cardEffect(minion, choice1, choice2, choice3, &state, handPos, 0);
    minionEffect(handPos, currentPlayer, choice1, choice2, &state);
  	int coinResult =  state.coins;
  	if (coinResult == 2){
  		printf("Passed test 1 for choice 1, player gained 2 coins from Choice 1\n");
  	} else{
  		printf("Failed test 1 for choice 1, player did not gain 2 coins from Choice 1\n");
  	}


  	//Testing choice 2
  	printf("Testing MINION card, Choice 2:\n");
  	choice1 = 0;
  	choice2 = 1;

  	initializeGame(2, k, 2, &state2);
  	

 
    drawCard(1, &state2);
    drawCard(1, &state2);
    

  	int currentPlayerHand1 = state2.handCount[0];
  	int nextPlayerHand1 = state2.handCount[1];
    printf("np cards %d\n", nextPlayerHand1);

    //cardEffect(minion, choice1, choice2, choice3, &state2, handPos, 0);
    minionEffect(handPos, currentPlayer, choice1, choice2, &state);

    int currentPlayerHand2 = state2.handCount[0];
    int nextPlayerHand2 = state2.handCount[1];
    printf("np cards %d\n", nextPlayerHand2);

    printf("After card effect, currentPlayer discards hand should draws four cards\n");

    for (int i = 0; i < state2.numPlayers; i++){
    	printf("Player %d has %d cards \n", i, state2.handCount[i]);
    }
    

  	int numHandResult = numHandCards(&state2);
    int currentPlayerDifference = currentPlayerHand1 - currentPlayerHand2;

    if (currentPlayerDifference > 1){
      printf("Failed test 2 for Choice 2, currentPlayer should not have discarded their hand\n");
    } else {
      printf("Passed test for 2 Choice 2, currentPlayer did not discard their hand\n");
    }

    printf("Next player has 2 cards, they should not discard their hand \n");
    int nextPlayerDifference = nextPlayerHand1 - nextPlayerHand2;
    if (nextPlayerDifference < 0){
      printf("Failed test 2 for Choice 2, nextPlayer should not have discarded their hand\n");
    } else {
      printf("Passed test for 2 Choice 2, nextPlayer did not discard their hand\n");
    }

}