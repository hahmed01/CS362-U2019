#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


//Test Get Winners
int main (int argc, char** argv) {
	int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
	struct gameState state, state1;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int numPlayers = 2;
	int players[MAX_PLAYERS];

	int result = 0;
    //int flag = -1;

	printf("Testing END TURN:\n");
  	int initResult = initializeGame(numPlayers, k, 2, &state);


  	if(initResult == -1){
  		printf("Game initialization failed\n");
  	}
  	else{
  		printf("Game initialization successful\n");
  	}


    for(int j = 0; j < 5; j++){
    	state.hand[currentPlayer][j] = province;
    	//state.discard[currentPlayer][j] = duchy;

   	    state.hand[nextPlayer][j] = estate;
        //state.discard[nextPlayer][j] = estate;
    }


    getWinners(players, &state);

    printf( "Test 1: Setting the first player as the winner\n" );

    if (players[0] > 0 && players[1] == 0){
    	printf("Test 1 Setting the first player as the winner passed\n");
    } else{
    	printf("Test 1 Setting the first player as the winner failed\n");
    }

    printf( "Test 2: Setting the second player as the winner\n" );

    for(int j = 0; j < 5; j++){
    	state1.hand[nextPlayer][j] = province;

   	    state1.hand[currentPlayer][j] = estate;
    }

    getWinners(players, &state1);


    if (players[1] > 0 && players[0] == 0){
    	printf("Test 2 Setting the second player as the winner passed\n");
    } else{
    	printf("Test 2 Setting the second player as the winner failed\n");
    }
    
  }