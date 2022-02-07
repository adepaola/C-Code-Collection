/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 10 - File IO and Command Line Arguments  
 *
 * This program opens/creates a file with a name passed by the user. The file is
 * then populated with 1000 random numbers and saved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *randomNums;
        
        if ((randomNums = fopen(argv[1], "w")) == NULL)
        {
            puts("ERROR: File unable to be opened.");
        }
        else
        {
            srand(time(0));
            float input=0.0;
            int floatCounter = 0;
            
            for (int i = 0; i < 1000; i++)
            {
                fprintf(randomNums, "%d\n", rand());
            }
            
            fclose(randomNums);
        }
    }
    else
    {
        puts("Error: Parameter mismatch");
    }
}