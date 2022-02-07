/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 10 - File IO and Command Line Arguments  
 *
 * This program reads in a text file passed by the user into an array. Each character
 * in the array is then printed to a separate file (with a name passed by the user.)
 * If the character is an s, S, a, i, or h, however, the special characters $, @, !, or #
 * are printed to the file instead.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        FILE *textFile;
        FILE *swappedText;
        
        if ((textFile = fopen(argv[1], "r")) == NULL)
        {
            puts("ERROR: File unable to be opened.");
        }
        else
        {
            long size = 0;
            
            //read number of characters in file. ftell counts bits, chars are bits, all is well.
            fseek(textFile, 0, SEEK_END);
            size = ftell(textFile);
            rewind(textFile);
            
            //calloc the space needed and populate
            char *textFromFile = calloc(size, sizeof(char));
            
            for(int i = 0; i < size; i++)
            {
                fscanf(textFile, "%c", &textFromFile[i]);
            }
            
            fclose(textFile);
            
            //create another file and populate it with swapped characters
            if ((swappedText = fopen(argv[2], "w")) == NULL)
            {
                puts("Error opening output file.");
            }
            else
            {
                for(int i = 0; i < size; i++)
                {
                    switch (textFromFile[i])
                    {
                        case 's':
                        case 'S':
                            fprintf(swappedText, "%c", '$');
                            break;
                        case 'a':
                            fprintf(swappedText, "%c", '@');
                            break;
                        case 'i':
                            fprintf(swappedText, "%c", '!');
                            break;
                        case 'H':
                            fprintf(swappedText, "%c", '#');
                            break;
                        default:
                            fprintf(swappedText, "%c", textFromFile[i]);
                            break;
                    }
                }
                
                free(textFromFile);
                textFromFile = NULL;
                fclose(swappedText);
            }
            
        }
    }
    else
    {
        puts("Error: Parameter mismatch");
    }
}