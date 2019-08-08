CFLAGS= -g -Wall -Wextra -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o interface.o
	gcc -o unittest1 -lm unittest1.c dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o interface.o
	gcc -o unittest2 -lm unittest2.c dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o interface.o
	gcc -o unittest3 -lm unittest3.c dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o interface.o
	gcc -o unittest4 -lm unittest4.c dominion.o rngs.o interface.o $(CFLAGS)

unittest5: unittest5.c dominion.o rngs.o interface.o
	gcc -o unittest5 -lm unittest5.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o interface.o
	gcc -o cardtest1 -lm cardtest1.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o interface.o
	gcc -o cardtest2 -lm cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o interface.o
	gcc -o cardtest3 -lm cardtest3.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o interface.o
	gcc -o cardtest4 -lm cardtest4.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest5: cardtest5.c dominion.o rngs.o interface.o
	gcc -o cardtest5 -lm cardtest5.c dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestcard3: randomtestcard3.c dominion.o rngs.o
	gcc -o randomtestcard3 -g  randomtestcard3.c dominion.o rngs.o $(CFLAGS)

unittestresults: unittest1 unittest2 unittest3 unittest4 unittest5 cardtest1 cardtest2 cardtest3 cardtest4 cardtest5
	@echo "unittest1.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory unittest1
	@./unittest1 >> unittestresults.out
	
	@echo "unittest2.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory unittest2
	@./unittest2 >> unittestresults.out

	@echo "unittest3.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory unittest3
	@./unittest3 >> unittestresults.out

	@echo "unittest4.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory unittest4
	@./unittest4 >> unittestresults.out

	@echo "unittest5.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory unittest5
	@./unittest5 >> unittestresults.out

	@echo "cardtest1.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory cardtest1
	@./cardtest1 >> unittestresults.out
	
	@echo "cardtest2.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory cardtest2
	@./cardtest2 >> unittestresults.out	

	@echo "cardtest3.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory cardtest3
	@./cardtest3 >> unittestresults.out

	@echo "cardtest4.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory cardtest4
	@./cardtest4 >> unittestresults.out	
	
	@echo "cardtest5.c:" >> unittestresults.out
	@$(MAKE) --no-print-directory cardtest5
	@./cardtest5 >> unittestresults.out	

randomtestresults: randomtestcard1 randomtestcard2 randomtestcard3
	./randomtestcard1 &> randomtestresults.out
	./randomtestcard2 >> randomtestresults.out
	./randomtestcard3 >> randomtestresults.out

	@echo  >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	@echo >> randomtestresults.out
	gcov dominion.c -b -f >> randomtestresults.out
	@echo >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out	
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player runtests unittestresults randomtestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
	rm -f randomtestcard1 randomtestcard2 randomtestcard3