#include <stdio.h>
#include <stdlib.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

//Mine Card

void myAssert(int result){
    if(result < 0){
        printf("failed\n");
    } else {
        printf("successful\n");
    }
}

int main (int argc, char** argv) {
    int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
    struct gameState state, state1;
    int currentPlayer = 0;
    int nextPlayer = 1;


    printf("Testing MINE card:\n");
    int initResult = initializeGame(2, k, 2, &state);
    printf("Game initialization ");
    myAssert(initResult);

    int choice1 = 1;
    int choice2 = gold;
    int choice3 = 0;
    int handPos = 0;


    state.hand[currentPlayer][0] = mine;
    state.hand[currentPlayer][1] = copper;
    state.hand[currentPlayer][2] = mine;
    state.hand[currentPlayer][3] = mine;
    state.hand[currentPlayer][4] = mine;

    printf("Player %d has %d cards \n", 0, state.handCount[0]);
    printHand(0, &state);
    
    int preHandCount =  state.handCount[0];
    //cardEffect(mine, 1, copper, choice3, &state1, handPos, 0);
    mineEffect(choice1, choice2, currentPlayer, handPos, &state);

    printf("Test 1: Testing if currentPlayer drops the copper ");
    int result = 1;
    for(int i = 0; i < state.handCount[currentPlayer]; i++){
        if(state.hand[0][i] == copper){
            result = -1;
            break;
        }
    }
    myAssert(result);

    result = -1;
    printf("Test 1: Testing if currentPlayer gains silver ");
    for(int i = 0; i < state.handCount[currentPlayer]; i++ ){
        if(state.hand[0][i] == silver ){
            result = 1;
            break;
        }
    }
    myAssert(result);

    printf("Test 1: Testing if currentPlayer gained gold when they weren't supposed to");
    for(int i = 0; i < state.handCount[currentPlayer]; i++ ){
        if(state.hand[0][i] == gold ){
            result = 1;
            break;
        }
    }
    myAssert(result);


    printf("Test 2: Player %d has %d cards \n", 0, state.handCount[0]);
    printf("They should have %d cards \n", state.handCount[0]-1);

    printHand(0, &state);



    



}