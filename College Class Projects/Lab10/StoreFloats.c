/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 10 - File IO and Command Line Arguments  
 *
 * This program opens/creates a file with a name specified by the user. The file
 * is then populated with up to 10 floats given by the user.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *floatFile;
        
        if ((floatFile = fopen(argv[1], "w")) == NULL)
        {
            puts("ERROR: File unable to be opened.");
        }
        else
        {
        
            puts("Enter 10 floats, or enter EOF to end: ");
            float input=0.0;
            int floatCounter = 0;
            
            while(!feof(stdin) && floatCounter < 10)
            {
                scanf("%f ", &input);
                fprintf(floatFile, "%f\n", input);
                floatCounter++;
            }
            
            fclose(floatFile);
        }
    }
    else
    {
        puts("Error: Parameter mismatch");
    }
}