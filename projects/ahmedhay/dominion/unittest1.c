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
        printf( "succeeded\n" );
    }

}

//Baron Card
int main (int argc, char** argv) {
	int k[10] = {adventurer, minion, council_room, feast, gardens, mine, remodel, smithy, village, baron};
	struct gameState state, state1;
	int currentPlayer = 0;
	int nextPlayer = 1;


    printf("Testing BARON card:\n");
    int initResult = initializeGame(2, k, 2, &state);
    printf("Game initialization ");
    myAssert(initResult);

  	int choice1 = 1;
  	int choice2 = 0;
  	int choice3 = 0;
  	int handPos = 0;
	
	int numCoins1Choice1 = state1.coins;
  	printf("Coins: %d\n", numCoins1Choice1);
  	int estates1Choice1 = supplyCount(estate, &state1);
  	printf("Estate1s: %d\n", estates1Choice1);

  	// for (int i = 0; i < state1.numPlayers; i++) {
  	// 	printHand(i, &state1);
  	// }


  	cardEffect(baron, choice1, choice2, choice3, &state1, handPos, 0);

  	int numCoins2Choice1 = state1.coins;
  	printf("Coins: %d\n", numCoins2Choice1);
  	int estates2Choice1 = supplyCount(estate, &state1);
  	printf("Estate1s: %d\n", estates1Choice1);

  	for (int i = 0; i < state1.numPlayers; i++) {
  		printHand(i, &state1);
  	}

  	int coinsDifference = numCoins2Choice1 - numCoins1Choice1;
  	if(coinsDifference == 4){
  		printf("Test case passed, since player chose Choice 1, number of coins was incremented by 4\n");
  	}
  	else{
  		printf("Test case failed, player chose Choice 1, number of coins was not incremented by 4\n");	
  	}



  	printf("Testing BARON card, Choice 2:\n");
  	initResult = initializeGame(2, k, 2, &state);

  	choice1 = 0;
  	choice2 = 1;
  	choice3 = 0;
  	handPos = 0;
	
	int numCoins1 = state.coins;
  	printf("Coins: %d\n", numCoins1);
  	int estates1 = supplyCount(estate, &state);
  	printf("Estates: %d\n", estates1);



  	cardEffect(baron, choice1, choice2, choice3, &state, handPos, 0);

  	int numCoins2 = state.coins;
  	printf("Coins: %d\n", numCoins2);
  	int estates2 = supplyCount(estate, &state);
  	printf("Estates: %d\n", estates2);


  	if(estates2 < estates1){
  		printf("Test case 2: passed, since player chose choice2, supplyCount of estate was decremented\n");
  	}
  	else{
  		printf("Test case 2: failed, player chose choice2, supplyCount of estate was not decremented\n");	
  	}

  	printf("Test 3: supplyCount of Estate error checking\n");
  	printf("Test will run the Baron Card Choice 2 for as many estates as there are left\n");


  	for(int i = 0; i < estates2; i++){
  		cardEffect(baron, choice1, choice2, choice3, &state, handPos, 0);
  	}
  	int estates3 = supplyCount(estate, &state);

  	if(estates3 < 0){
  		printf("Test case 3 failed, estates entered negative values\n");
  	}
  	else{
  		printf("Test case 3 passed, estates did not enter negative values\n");	
  	}
}