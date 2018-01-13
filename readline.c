/*	I Pledge my Honor that I have not cheated, and will not cheat, on this assignment - Si Dang
 	THIS IS THE GIVEN READLINE FUNCTION AND IT DEPENDS ON readline.h 
	The program was wittern by Si Dang #U25273656 
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "readline.h"

int read_line(char str[], int n)
{
	int ch, i = 0;
  
	while (isspace(ch = getchar()))
		;
	str[i++] = ch;
	while ((ch = getchar()) != '\n')
	{
		if (i < n)
		str[i++] = ch;
  	}
	str[i] = '\0';
	return i;
}
