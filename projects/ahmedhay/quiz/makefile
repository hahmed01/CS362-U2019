CFLAGS= -Wall -coverage -lm -std=c99 -g

test: testme.c
	gcc -o testme testme.c $(CFLAGS)

runtest: test
	./testme &> testresults.out

all: test runtest 

clean:
	rm -f *.o testme.exe  *.gcno *.gcov *.gcda *.out