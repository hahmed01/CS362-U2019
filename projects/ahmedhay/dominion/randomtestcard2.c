#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


void myAssert(int result){

    if(result < 0){
        printf( "failed\n" );
    } else {
        printf( "succeeded\n" );
    }
    
}

//Minion Random Test
int main(){
    //randomize choice 1 or 2
    int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
    struct gameState state, preState;

    int seed = 2;
    int choice1 = 0;
    int choice2 = 0;
    int handPos = 0;
    int currentPlayer = 0;
    //int currentPlayer = 0;
    //int nextPlayer = 1;
    srand(time(NULL));
    int numPlayers;
    int result = 0;

    printf("Random Testing MINION card\n");
    for(int i = 0; i < 600; i++){

        memset(&state, 23, sizeof(struct gameState));
        memset(&preState, 23, sizeof(struct gameState));

        numPlayers = 2;
        currentPlayer = 0;

        choice1 = rand() % 2;
        if( choice1 == 0 ){
            choice2 = 1;
        } else {
            choice2 = 0;
        }

        initializeGame(numPlayers, k, seed, &state);
        //randomize game variables that are potentially relevant
        state.numActions = rand() % INT_MAX - 10;
        state.numBuys = rand() % INT_MAX - 10;
        state.coins = rand() % INT_MAX - 10;
        state.whoseTurn = currentPlayer;
        state.playedCardCount = rand() % MAX_DECK;


        for(int i = 0; i < state.numPlayers; i++){
            state.deckCount[i] = rand() % MAX_DECK;
            state.discardCount[i] = rand() % MAX_DECK;
            state.handCount[i] = rand() % 10;
        }


        for(int i = 0; i < 27; i++){
            state.supplyCount[i] = rand() % INT_MAX;
            state.embargoTokens[i] = rand() % INT_MAX;
        }

        for(int i = 0; i < state.numPlayers; i++){
            for(int j = 0; j < state.handCount[i]; j++) {
                state.hand[i][j] = rand() % 27;
            }
        }

        for(int i = 0; i < state.numPlayers; i++){
            for(int j = 0; j < MAX_DECK; j++) {
                state.discard[i][j] = rand() % 27;
            }
        }
        

        memcpy(&preState, &state, sizeof(struct gameState));
        state.supplyCount[estate] = 5;

        int estateSC1 = state.supplyCount[estate];

        printf("Playing MINION card: Choice 1 is %d and Choice2 is %d \n", choice1, choice2);
        minionEffect(&state, choice1, choice2, handPos, currentPlayer);

        if(choice1 == 1){
            printf("\tTesting to see if gained two coins: ");
            result = (preState.coins + 2 == state.coins) ? 1 : -1;
            myAssert(result);
        } else{

            printf("\tTesting to see if currentPlayer has 4 cards: ");
            result = (state.handCount[currentPlayer] == 4) ? 1 : -1;
            myAssert(result);

            for (int i = 0; i < state.numPlayers; i++){
                if(i != currentPlayer){
                    if(preState.handCount[i] > 4){
                        printf("\tTesting to see if opponents have 4 cards: ");
                        result = (state.handCount[currentPlayer] == 4) ? 1 : -1;
                        myAssert(result);
                    }
                }

            }


        }
    }


}