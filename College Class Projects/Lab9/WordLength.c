/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 9 - Strings
 *
 * This program reads a string from the user and prints how many words of each
 * length appear in the string. 
 */
 
 #include <stdio.h>
 #include <string.h>

void printTable(int wordSizes[]);

 #define SIZE 100
 #define MAX_WORD 15

 int main()
 {
    int wordSizes[MAX_WORD] = {0};
	char string[SIZE];
	
	puts("Enter string: ");
	fgets(string, SIZE, stdin);
	
	//strchr used to get rid of new line, otherwise last word is one character too long.
	char *newline = strchr(string, '\n');
	if (newline != NULL)
	{
	    *newline = 0;
	}
	
	char *word = strtok(string, " ");
	
	while(word != NULL)
	{
	    wordSizes[strlen(word)]++;
	    word = strtok(NULL, " ");
	}
	
	printTable(wordSizes);
 }
 
void printTable(int wordSizes[])
 {
 	printf("%-3s|%3c\n", "Length", '#');
 	puts("----------");
 	for(int i = 0; i < MAX_WORD; i++)
	{
	    if(wordSizes[i] != 0)
	    {
	        printf("%6d|%3d\n", i, wordSizes[i]);
	    }
	}
 }