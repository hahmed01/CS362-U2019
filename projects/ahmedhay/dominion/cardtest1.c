#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void myAssert(int result){

    if(result < 0){
        printf( "failed\n" );
    } else {
        printf( "successful\n" );
    }
}

int main (int argc, char** argv) {
	struct gameState state, state1, state2;
	int start = -1;
	int numPlayers = 2;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int result= 0;


	//Test if number of player is >= 2
	int result1 = initializeGame(numPlayers, k, 2, &state);
	if(result1 == -1){
		printf("Test Case 1: Initialising game with 2 players failed\n");
	} else{
		printf("Test Case 1: Initialising game with 2 players passed\n");
	}

	//Test for 0 players
	int result2 = initializeGame(0, k, 2, &state1);
	if(result2 == -1){
		printf("Test 2: Initialising game with 0 Players failed, as expected\n");
	} else{
		printf("Test 2: Initialising game with 0 PPlayers succeeded, unexpected\n");
	}

	//Test for player >= MAX_PLAYERS
	int result3 = initializeGame(5, k, 2, &state2);
	if(result3 == -1){
		printf("Test 2: Initialising game with 5 Players failed, as expected\n");
	} else{
		printf("Test 2: Initialising game with 5 PPlayers succeeded, unexpected\n");
	}


	printf("Tests for all possible number of players should pass the following tests: \n");
	        
    printf("Testing curse \n");
    if (state.supplyCount[curse] == 10) {
	   	result = 1;
	    } else {
	     result = -1;
	 }

    printf( "Testing embargo token ");
    	if(state.embargoTokens[0] == 0){
	        	result = 1;
	        } else {
	        	result = -1;
	        }
    myAssert(result);

    printf( "Testing outpost state ");
    	if(state.outpostPlayed == 0){
	        	result = 1;
	        } else {
	        	result = -1;
	        }
    myAssert(result);

    printf( "Testing phase state ");
		if(state.phase == 0){
	        	result = 1;
	        } else {
	        	result = -1;
	        }
    myAssert(result);

    printf("Testing num actions ");
		if(state.numActions == 1){
	        	result = 1;
	        } else {
	        	result = -1;
	        }
    myAssert(result);

    printf( "Testing num buys ");
		if(state.numBuys == 1){
	        	result = 1;
	        } else {
	        	result = -1;
	        }
    myAssert(result);

    printf( "Testing playedCardCount ");
		if(state.playedCardCount == 0){ 
	        	result = 1;
	        } else {
	        	result = -1;
	        }
    myAssert(result);

    printf( "Testing whoseTurn ");
		if(state.whoseTurn == 0){
	        	result = 1;
	        } else {
	        	result = -1;
	        }
    myAssert(result);

    printf( "Testing hand count ");
	if(state.handCount[0] == 5){
	        	result = 1;
	        } else {
	        	result = -1;
	        }
    myAssert(result);


    for( int numPlayers = 2; numPlayers <= 4; numPlayers++ ){

        memset(&state, 2, sizeof(struct gameState));

       result= initializeGame( numPlayers, k, 2, &state );
        printf("Initializing the game to %d players ", numPlayers );
        myAssert(result);

	    if(numPlayers == 2 ){
	        if (state.supplyCount[curse] == 10) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
	        printf( "Testing curse cards for %d players ", numPlayers );
	        myAssert(result);

	        if (state.supplyCount[estate] == 8) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
	        printf( "Testing estate cards for %d players ", numPlayers );
	        myAssert(result);

	        if (state.supplyCount[duchy] == 8) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
	        printf( "Testing duchy cards for %d players ", numPlayers );
	        myAssert(result);

	        if (state.supplyCount[province] == 8) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
	        printf( "Testing province cards for %d players ", numPlayers );
	        myAssert(result);

	        if (state.supplyCount[copper] == 46) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
	        printf( "Testing copper cards for %d players ", numPlayers );
	        myAssert(result);

	        if (state.supplyCount[silver] == 40) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
	        printf( "Testing silver cards for %d players ", numPlayers );
	        myAssert(result);

	        if (state.supplyCount[gold] == 30) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
	        printf( "Testing gold cards for %d players ", numPlayers );
	        myAssert(result);

    	}
    	else if( numPlayers == 3 ){
            if (state.supplyCount[curse] == 20) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing curse cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[estate] == 12) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing estate cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[duchy] == 12) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing duchy cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[province] == 12) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing province cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[copper] == 39) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing copper cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[silver] == 40) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing silver cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[gold] == 30) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing gold cards for %d players ", numPlayers );
            myAssert(result);

        } else {
            if (state.supplyCount[curse] == 30) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing curse cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[estate] == 12) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing estate cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[duchy] == 12) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing duchy cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[province] == 12) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing province cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[copper] == 32) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing copper cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[silver] == 40) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
            printf( "Testing silver cards for %d players ", numPlayers );
            myAssert(result);

            if (state.supplyCount[gold] == 30) {
	        	result = 1;
	        } else {
	        	result = -1;
	        }
	        printf( "Testing gold cards for %d players ", numPlayers );
            myAssert(result);
        
        }
    }
}
