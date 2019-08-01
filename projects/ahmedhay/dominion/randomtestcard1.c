#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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


//Baron Random Test
int main(){
    //randomize choice 1 or 2
    int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
    struct gameState state, preState;

    int seed = 2;
    int choice1 = 0;
    int choice2 = 0;
    int handPos = 0;
    int currentPlayer;
    //int currentPlayer = 0;
    //int nextPlayer = 1;
    srand(time(NULL));
    int numPlayers;
    int result = 0;


    printf("Random Testing BARON card\n");
    for(int i = 0; i < 20000; i++){ 

        //clear struct
        memset(&state, 23, sizeof(struct gameState));
        memset(&preState, 23, sizeof(struct gameState));

        numPlayers = 2;
        currentPlayer = 0;

        //choice 1 or 2 are both tested for
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
            state.handCount[i] = rand() % 5;
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

        int estateSC1 = state.supplyCount[estate];

        //currentPlayer = 0;


        //copy memory
        memcpy(&preState, &state, sizeof(struct gameState));

        printf("Playing BARON card: Choice 1 is %d and Choice2 is %d \n", choice1, choice2);

        //store variables that will be tested for
        int beforeNumBuys = state.numBuys;
        int beforeHandCount = state.handCount[currentPlayer];

        //randomize number of extates in currentPlayer's hand to ensure that it will be tested under this condition
        int numEstates = rand() % 3 + -1;
        printf("\tNumber of estates in currentPlayer's hand: %d \n", numEstates);
        if (numEstates > 0){
            for (int q = 0; q < numEstates; q++)
                state.hand[currentPlayer][q] = estate;
        }

        baronEffect(&state, choice1, choice2, handPos, currentPlayer);

        //happens regardless of choice
        printf("\tTest for numBuys ");
        if (beforeNumBuys < state.numBuys){
            result = 1;
        } else {
            result = -1;
        }
        myAssert(result);

        if (choice1 == 1 && numEstates > 0){
            for(int i = 0; i < state.handCount[currentPlayer]; i++){
                if(state.hand[currentPlayer][i] == estate){
                    if (preState.coins + 4 == state.coins ) {
                        result = 1;
                    }
                    else {
                        result = -1;
                    }
                    printf( "\tTesting to see if there are four more coins after discarding estate card ");
                    myAssert(result);

                    if (state.discard[currentPlayer][state.discardCount[currentPlayer]] == state.hand[currentPlayer][i]){
                        result = 1;
                    }
                    else { 
                        result = -1;
                    }
                    printf("\tTesting to see if state.discard[currentPlayer][state.discardCount[currentPlayer]] was set ");
                    myAssert(result);

                    if (state.hand[currentPlayer][state.handCount[currentPlayer]] == -1){
                        result = 1;
                    }
                    else { 
                        result = -1; 
                    }
                    printf("\tTesting to see if hand was adjusted to -1 ");
                    myAssert(result);

                    if (preState.discardCount[currentPlayer] == state.discardCount[currentPlayer] - 1){
                        result = 1;
                    }
                    else { 
                        result = -1; 
                    }
                    printf( "\tTesting to see if discard count was incremented ");
                    myAssert( result );

                    if (preState.handCount[currentPlayer] == state.handCount[currentPlayer] + 1){
                        result = 1;
                    }
                    else { 
                        result = -1; 
                    }
                    printf( "\tTesting to see if hand count was decremented ");
                    myAssert( result );
                }

            }
        }
        
        else if (choice1 == 1 && numEstates == 0){
                        
            if (preState.handCount[currentPlayer] < state.handCount[currentPlayer]){
                result = 1;
                }
            else { 
                result = -1; 
            }
            printf( "\tTesting to see if hand count was incremented ");
            myAssert(result);

            if (preState.supplyCount[estate] > state.handCount[currentPlayer]){
                result = 1;
                }
            else { 
                result = -1; 
            }
            printf( "\tTesting to see if supply count was decremented ");
            myAssert(result);

        }

        else{
            if (estateSC1 > state.supplyCount[estate] ){
                result = 1;
            }
            else { 
                result = -1; 
            }
            printf( "\tTesting to see if supplyCount of estate decreased as expected: " );
            myAssert( result );
            printf( "\tTesting to see if player's handCount increased: " );
            if (beforeHandCount == state.handCount[currentPlayer] - 1 ){
                result = 1;
                }
                else { result = -1; }
            myAssert( result );

        }

    }

}
