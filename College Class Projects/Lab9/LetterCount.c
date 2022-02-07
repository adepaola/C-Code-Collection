/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 9 - Strings
 * 
 * This program takes a string input from the user. Each letter is then counted,
 * and the count is shown for each letter present in the string.
*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int main()
{
	int letterCounter[26] = {0};
	char * letters = {"abcdefghijklmnopqrstuvwxyz"};
	char string[SIZE];
	
	puts("Enter string: ");
	fgets(string, SIZE, stdin);
	
	for(int i = 0; string[i] != '\0'; i++)
	{
	    if(isalpha(string[i]))
	    {
	        letterCounter[tolower(string[i]) - 'a']++;
	    }
	}
	
	for(int i = 0; i < 26; i++)
	{
	    if(letterCounter[i] != 0)
	    {
	        printf("%-3c|%3d\n", letters[i], letterCounter[i]);
	    }
	}
}
