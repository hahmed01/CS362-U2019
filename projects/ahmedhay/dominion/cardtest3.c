#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void myAssert( int result ){

    if(result < 0){
        printf("failed\n");
    } else {
        printf("successful\n");
    }


}

//Test End Turn
int main (int argc, char** argv) {
	int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
	struct gameState state, state1;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int players = 2;
	int cards[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("Testing END TURN:\n");
  	int initResult = initializeGame(players, k, 2, &state);


  	if(initResult == -1){
  		printf("Game initialization failed\n");
  	}
  	else{
  		printf("Game initialization successful\n");
  	}

    endTurn(&state);

    printf("Resetting cards in hand to -1 ");
    int result = 1;
    for( int i = 0; i < 5; i++ ){
        if( state.hand[0][i] != -1 ){
            result = -1;
        }
    }
    myAssert(result);

    printf("Resetting hand count ");
    if(state.handCount[currentPlayer] == 0){
    	result = 1;
    } else{
    	result = -1;
    }
    myAssert(result);

    printf("Resetting whoseTurn ");
    if(state.whoseTurn == currentPlayer + 1){
    	result = 1;
    } 
    else if (state.whoseTurn == 0){
    	result = 1;
    }
    else{
    	result = -1;
    }
    myAssert(result);


    printf("Resetting outpost " );
    if(state.outpostPlayed == 0){
    	result = 1;
    } else{
    	result = -1;
    }
    myAssert(result);

    printf("Resetting state phase " );
    if(state.phase == 0){
    	result = 1;
    } else{
    	result = -1;
    }
    myAssert(result);

    printf("Resetting numActions " );
    if(state.numActions == 1){
    	result = 1;
    } else{
    	result = -1;
    }
    myAssert(result);

	printf("Resetting coins " );
    if(state.coins <= 5){
    	result = 1;
    } else{
    	result = -1;
    }
    myAssert(result);

	printf("Resetting numBuuys " );
    if(state.numBuys == 1){
    	result = 1;
    } else{
    	result = -1;
    }
    myAssert(result);

    printf("Resetting playedCardCount " );
    if(state.playedCardCount == 0){
    	result = 1;
    } else{
    	result = -1;
    }
    myAssert(result);

	printf("Resetting handCount for nextPlayer " );
    if(state.handCount[state.whoseTurn] == 5){
    	result = 1;
    } else{
    	result = -1;
    }
    myAssert(result);
}