#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void myAssert(int result){

    if(result < 0){
        printf( "failed\n" );
    } else {
        printf( "successful\n" );
    }
}

//Draw Card

int main(){

    int players = 2;
    int kingdomCards[10] = {ambassador, baron, embargo, village, minion, mine, cutpurse, sea_hag, tribute, gardens};
    int seed = 2;
    struct gameState prevGameState;
    struct gameState state;
    int result = 0;

    printf("Testing DRAW CARD:\n");

    result = initializeGame( players, kingdomCards, seed, &state );



    int testDeck = state.deckCount[0];
    int playersHandCount = state.handCount[0];
    int prevDeckCard = state.deck[0][state.handCount[0]-1];

    drawCard(0, &state );

    int testDeck2 = state.deckCount[0];
    int playersHandCount2 = state.handCount[0];


    if (testDeck2 == testDeck - 1){
        printf("Passed Test 1, deckCount was decremented\n");
    } else {
        printf("Failed Test 1, deckCount was not decrementedc\n");
    }
    
    if (playersHandCount2 == playersHandCount + 1) {
        printf("Passed Test 3, handCount was incremented\n");
    } else {
        printf("Failed Test 3, handCount was not incremented\n");
    }

    if (prevDeckCard == state.hand[0][state.handCount[0]-1]){
        printf("Passed Test 2, the card from the deck was moved into the player's hand\n");
    } else {
        printf("Failed Test 2, the card from the deck did not move into the player's hand\n");
    }


    
}