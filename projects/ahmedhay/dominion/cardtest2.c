#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void myAssert(int result){

    if(result < 0)
    {
        printf( "failed\n" );
    } else {
        printf( "successful\n" );
    }

}

//Test Shuffle
int main (int argc, char** argv) {
	int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
	struct gameState state, state1;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int players = 2;
	int cards[10] = {1, 2, 3, 4, 5};
    int flag = -1;

	printf("Testing SHUFFLE:\n");
  	int initResult = initializeGame(players, k, 2, &state);

  	if(initResult == -1){
  		printf("Game initialization failed\n");
  	}
  	else{
  		printf("Game initialization successful\n");
  	}

  	for(int i = 0; i < players; i++ ){
        for(int j = 0; j < 5; j++ ){
            state.deck[i][j] = cards[j];
        }
    }

    printDeck(0, &state);

    printf("Testing SHUFFLE on Current Player's Deck\n" );
    int result = shuffle(0, &state );

    for(int i = 0; i < 10; i++ ){
        if(cards[i] != state.deck[0][i]){
            result = 1;
        }
    }
    printf("SHUFFLE on Player One's deck: " );
    myAssert(result);

    printDeck(0, &state);

}