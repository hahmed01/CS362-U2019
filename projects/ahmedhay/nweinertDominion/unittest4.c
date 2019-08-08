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

//Tribute Card

int main (int argc, char** argv) {
    int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
    struct gameState state, state1;
    int currentPlayer = 0;
    int nextPlayer = 1;


    printf("Testing TRIBUTE card:\n");
    int initResult = initializeGame(2, k, 2, &state);
    printf("Game initialization ");
    myAssert(initResult);

    state.deck[nextPlayer][state.deckCount[1] - 1 ] = copper;
    state.deck[nextPlayer][state.deckCount[1] - 2 ] = copper;

    int coinsNum = state.coins;
    //printf("%d\n", coinsNum);

    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;

    //cardEffect( tribute, choice1, choice2, choice3, &state, handPos, 0 );
    tributeEffect(currentPlayer, nextPlayer, &state);

    int coinsNum2 = state.coins;
    //printf("%d\n", coinsNum2);
    printf("Test 1: Case where a Treasure is revealed...currentPlayer should have 2 additional coins \n");
    if (coinsNum2 == coinsNum + 2){
    	printf("Test 1: Pass coin test\n");
    }
    else {
    	printf("Test 1: Fail coin test\n");
    }

    printf("Test 2: Case where a Action is revealed...currentPlayer should have 2 additional coins and 2 additional actions \n");
    state.deck[nextPlayer][state.deckCount[1] - 1 ] = village;
    state.deck[nextPlayer][state.deckCount[1] - 2 ] = silver;

    int actionsNum = state.numActions; 
    //printf("%d\n", actionsNum);
    coinsNum = state.coins;

    //cardEffect( tribute, choice1, choice2, choice3, &state, handPos, 0 );
    tributeEffect(currentPlayer, nextPlayer, &state);

    int actionsNum2 = state.numActions; 

    //printf("%d\n", actionsNum2);
    if (actionsNum2 == actionsNum + 2){
    	printf("Test 2: Pass action test\n");
    }
    else {
    	printf("Test 2: Fail action test\n");
    }

    coinsNum2 = state.coins;
    //printf("%d\n", coinsNum2);
    if (coinsNum2 == coinsNum + 2){
    	printf("Test 2: Pass coin test\n");
    }
    else {
    	printf("Test 2: Fail coin test\n");
    }

    printf("Test 3: Case where a Victory is revealed...currentPlayer should have 1 additional card and 2 additional coins\n");
    state.deck[nextPlayer][state.deckCount[1] - 1 ] = duchy;
    state.deck[nextPlayer][state.deckCount[1] - 2 ] = gold;
   	coinsNum = state.coins;
	int cards = state.handCount[0];
	//printf("%d\n", cards);

    //cardEffect( tribute, choice1, choice2, choice3, &state, handPos, 0 );
    tributeEffect(currentPlayer, nextPlayer, &state);
    
    coinsNum2 = state.coins;
    int cards2 = state.handCount[0];

    //printf("%d\n", coinsNum2);
    if (coinsNum2 == coinsNum + 2){
    	printf("Test 3: Pass coin test\n");
    }
    else {
    	printf("Test 3: Fail coin test\n");
    }

    //printf("%d\n", cards2);
    if (cards2 == cards + 1){
    	printf("Test 3: Pass card test\n");
    }
    else {
    	printf("Test 3: Fail card test\n");
    }

}