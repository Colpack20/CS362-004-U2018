#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function

	int num = rand() % 9 + 1;

	if (num == 1)
		return '[';
    	if (num == 2)
		return '(';
	if (num == 3)
		return '{';
	if (num == 4)
		return ' ';
	if (num == 5)
		return 'a';
	if (num == 6)
		return 'x';
	if (num == 7)
		return '}';
	if (num == 8)
		return ')';
	if (num == 9)
		return ']';
	
}

char *inputString()
{
    // TODO: rewrite this function
	char input[6];
	int num;
	int i;
	char randomletter;
	memset(input, '\0', sizeof(input));
	for(i=0; i<5; i++)
	{
		num = rand() % 4 + 1;
		if(num == 1)
			randomletter = 'r';
		if(num == 2)
			randomletter = 'e';
		if(num == 3)
			randomletter = 's';
		if(num == 4)
			randomletter = 't';
		input[i] = randomletter;
	}
    return input;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
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
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
