/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 9 - Strings
 *
 * This program takes a string input and counts the occurrence of each word in the
 * string.
 */
 
 #include <stdio.h>
 #include <string.h>
 
 void counting(char *word, char *wordsInString[], int wordCount[]);
 void printTable(int wordCount[], char *words[]);

 #define SIZE 100
 #define MAX_WORDS 50
 #define MAX_SIZE 15

 int main()
 {
    char * wordsInString[MAX_WORDS] = {""};
    int wordCount[MAX_WORDS] = {0};
	char string[SIZE];
	
	puts("Enter string to count the words of: ");
	fgets(string, SIZE, stdin);
	
	//strchr used to get rid of new line
	char *newline = strchr(string, '\n');
	if (newline != NULL)
	{
	    *newline = 0;
	}
	
	char *word = strtok(string, " ");

	while(word != NULL)
	{
	    counting(word, wordsInString, wordCount);
	    word = strtok(NULL, " ");
	}
	
	printTable(wordCount, wordsInString);
 }
 
 void counting(char *word, char *wordsInString[], int wordCount[])
 {
 	for(int i = 0; i < MAX_WORDS; i++)
	    {
	    	if (wordsInString[i] == NULL)
	    	{
	    		wordsInString[i] = "";
	    	}
	    	if(strcmp(word, wordsInString[i]) == 0)
	    	{
	    		wordCount[i]++;
	    		i = MAX_WORDS;
	    	}
	    	else if (wordsInString[i] == "")
	    	{
	    		wordsInString[i] = word;
	    		wordCount[i]++;
	    		i = MAX_WORDS;
	    	}
	    }
 }
 
 void printTable(int wordCount[], char *words[])
 {
 	for(int i = 0; i < MAX_WORDS; i++)
	{
	    if(wordCount[i] != 0)
	    {
	        printf("%-10s|%3d\n", words[i], wordCount[i]);
	    }
	}
 }