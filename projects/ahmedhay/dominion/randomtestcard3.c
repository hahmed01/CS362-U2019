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
    int nextPlayer = 1;
    //int currentPlayer = 0;
    //int nextPlayer = 1;
    srand(time(NULL));
    int numPlayers;
    int result = 0;
    time_t t;

    printf("Random Testing TRIBUTE card\n");
    for(int n = 0; n < 10000; n++){

        memset(&state, 23, sizeof(struct gameState));
        memset(&preState, 23, sizeof(struct gameState));

        numPlayers = rand() % 2 + 2;

        choice1 = rand() % 2;
        if( choice1 == 0 ){
            choice2 = 1;
        } else {
            choice2 = 0;
        }

        initializeGame(numPlayers, k, seed, &state);

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

    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;


    int actionsNum = state.numActions; 
    int coinsNum = state.coins;
    int cards = state.handCount[currentPlayer];


    state.discardCount[nextPlayer] = floor(Random() * MAX_DECK);
    state.deckCount[nextPlayer] = floor(Random() * MAX_DECK);
    state.handCount[nextPlayer] = floor(Random() * MAX_HAND);

    int preTestDiscardCount = state.discardCount[nextPlayer];
    int preTestDeckCount = state.deckCount[nextPlayer];
    int preTestHandCount = state.handCount[nextPlayer];

    int tributeCards[12] = {smithy, cutpurse, estate, duchy, province, great_hall, gardens, copper, silver, gold, village, adventurer};
    int card1 = floor(Random() * 12);
    int card2 = floor(Random() * 12);

    int tributeRevealedCard[2];
    tributeRevealedCard[0] = tributeCards[card1];
    tributeRevealedCard[1] = tributeCards[card2];

    state.deck[nextPlayer][state.deckCount[1] - 1 ] = tributeCards[card1];
    state.deck[nextPlayer][state.deckCount[1] - 2 ] = tributeCards[card2]; 

    tributeEffect(&state, nextPlayer, tributeRevealedCard, currentPlayer);

    if ((preTestDiscardCount + preTestDeckCount) <= 1){
        printf("Testing Condition: (state->discardCount[nextPlayer] + state->deckCount[nextPlayer]) <= 1) ");
        if (preTestDeckCount > 0){
            printf("and (state->deckCount[nextPlayer] > 0)\n");
            if (state.deckCount[nextPlayer] < preTestDeckCount){
                result = 1;
            } else {
                result -1;
            }
            printf("\tDeck Count test for nextPlayer ");
            myAssert(result);

        }
        else if (preTestDiscardCount > 0){
            printf("and (state->discardCount[nextPlayer] > 0) \n");
            if (state.discardCount[nextPlayer] < preTestDiscardCount){
                result = 1;
            } else {
                result -1;
            }
            printf("\tDiscard Count test for nextPlayer ");
            myAssert(result);
            
        }
        else{
          //No Card to Reveal
          if (DEBUG){
          printf("No cards to reveal \n");
          }
        }
      }

      else{
        if (preTestDeckCount == 0){
            printf("Testing Condition: state->deckCount[nextPlayer] == 0 \n");
            if (state.discardCount[nextPlayer] < preTestDiscardCount){
                result = 1;
            } else {
                result -1;
            }
            printf("\tDiscard Count test for nextPlayer ");
            myAssert(result);

        } 
        printf("Testing all other conditions\n");
        if (state.deckCount[nextPlayer] < preTestDeckCount){
            result = 1;
        } else {
            result -1;
        }
        printf("\tDeck Count test for nextPlayer ");
        myAssert(result);

      }    


        int actionsNum2 = state.numActions; 
        int coinsNum2 = state.coins;
        int cards2 = state.handCount[currentPlayer];


            for (int i = 0; i < 2; i ++){
                if (tributeRevealedCard[i] == copper || tributeRevealedCard[i] == silver || tributeRevealedCard[i] == gold){//Treasure cards
                    printf("\tTreasure card revealed, coin test (gain 2 coins) " );

                    if (coinsNum2 > coinsNum){
                        result = 1;
                    } else {
                        result = -1;
                    }
                    myAssert(result);
                } 
                else if (tributeRevealedCard[i] == estate || tributeRevealedCard[i] == duchy || tributeRevealedCard[i] == province || tributeRevealedCard[i] == gardens || tributeRevealedCard[i] == great_hall){//Victory Card Found
                    printf("\tVictory card revealed, card test (gain 2 cards)" );
                    if (cards2 > cards ){
                        result = 1;
                    } else {
                        result = -1;
                    }
                    myAssert(result);
                } 
                else{
                    printf("\tAction card revealed, action test (gain 2 actions) " );
                    if (actionsNum2 > actionsNum){
                        result = 1;
                    } else {
                        result = -1;
                    }
                    myAssert(result);
                }
            }

    }

}
