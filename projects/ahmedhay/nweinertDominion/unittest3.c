#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void myAssert(int result){
    if(result < 0){
        printf("failed\n");
    } else {
        printf("successful\n");
    }
}

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


  	int choice1 = 0;
  	int handPos = 3;


/*    for (int i = 0; i < state.numPlayers; i++) {
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
    }*/

    for (int i = 0; i < state.numPlayers; i++){
      state.hand[i][0] = copper;
      state.hand[i][1] = copper;
      state.hand[i][2] = copper;
      state.hand[i][3] = copper;
      state.hand[i][4] = copper;
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
        drawCard(i, &state);
      state.hand[i][5] = copper;
      state.hand[i][6] = copper;
      state.hand[i][7] = copper;
      state.hand[i][8] = copper;
      state.hand[i][9] = copper;
    }

  	int currentPlayerHand1 = state.handCount[0];
  	int nextPlayerHand1 = state.handCount[1];
  	//printf("%d\n", nextPlayerHand1);

    for (int i = 0; i < state.numPlayers; i++){
    	printf("Player %d has %d cards \n", i, state.handCount[i]);
    }

    printf("Testing AMBASSADOR card, Choice 1:\n");

	//cardEffect(ambassador, choice1, choice2, choice3, &state, handPos, 0);
  int choice2 = 2;
   
  state.hand[currentPlayer][choice1] = copper;
  int preStateSC = state.supplyCount[copper];
  ambassadorEffect(choice1, choice2, handPos, currentPlayer, &state);
  int postStateSC = state.supplyCount[copper];

	int currentPlayerHand2 = state.handCount[0];
    int nextPlayerHand2 = state.handCount[1];
    //printf("%d\n", nextPlayerHand2);

    for (int i = 0; i < state.numPlayers; i++){
    	printf("Player %d has %d cards \n", i, state.handCount[i]);
    }

    if(nextPlayerHand2 > nextPlayerHand1){
    	printf("Passed test 1, opponent gained 1 card from current player\n");
    }
    else{
    	printf("Failed test 1, opponent did not gain 1 card from current player\n");
    }

    int result = 0;
    printf("Testing to see if 2 coppers returned to supplyCount ");
    if (preStateSC == postStateSC - 2){
      result = 1;
    }
    else{
      result = -1;
    }
    myAssert(result);

}
