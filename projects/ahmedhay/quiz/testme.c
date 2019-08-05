#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char inputChar()
{
  char charOutput[] = {'r','e','s','t', 'a', 'b','c','d','f','g','h','i','g','k','q','l','m','n','o','p', '[','(','{',' ','a','x','}',')',']'};
  int randInt = rand()% sizeof(charOutput);
  randInt -= 1;
  return charOutput[randInt];
}

char *inputString()
{
  int choice = rand() % 2;
  if(choice == 0){
    int i = 0;
    char charArray[16] = {'a','b','c','d','f','g','h','i','g', 'r','e','s','e','t'};
    char *string = malloc(sizeof(char)*6);
    while(i < 6){
      string[i] = charArray[rand() % sizeof(charArray)];
      i++;
    }
    string[5] = '\0';
    return string;
  }
  else{
    return "reset";
  }

}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  int i = 300000;
  while (i > 0)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
    i--;
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}