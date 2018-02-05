#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	    // TODO: rewrite this function
	char arr[9] = {'a', 'x','(', ')', '{', '}', '[', ']', ' '};
	int a = rand()%9;
	//printf("Random char are: %c\n", arr[a]);

    return arr[a];
}

char *inputString()
{	
	char array[5] = {'r','e','s','t','s'};
    // TODO: rewrite this function
	
	static char array_contains[6];
    int string_length = 4;
    int count = 0;
    int r;
    int i;
   
    while (string_length >= 0) {
        r = rand()%5;
        array_contains[count] = array[r];
        count++;
        for (i = r; i < string_length; i++) {
          array[i] = array[i+1];
        }
        string_length--;
    }
	
    //printf("Random string generated: %s\n", *array_contains);
    array_contains[5] = '\0';
    return array_contains;
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
