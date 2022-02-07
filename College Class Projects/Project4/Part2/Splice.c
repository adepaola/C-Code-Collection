/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 4 - Bits and Files  
 * 
 * This program splices two text files together, zippering nybble by nybble. It
 * begins by opening two text files as well as the output file. The two text files
 * are then allocated memory and pointed to by the pointers 'text1' and 'text2'.
 * While there is still text in one of the files, a mask is used to split the characters
 * from each file in half and store them into two new characters, 'character1' and 'character2'.
 * The first half of the two new characters are each half of one character from 'text1', while
 * the second half of the new characters is half of the character from 'text2'.
 * The two new characters are then printed into the output file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTE uint8_t

int main(int argc, char *argv[])
{
    
    if (argc == 4)
    {
        FILE *file1;
        FILE *file2;
        FILE *spliced;
        
        if((file1 = fopen(argv[1], "r")) == NULL)
        {
            puts("Error: File1 unable to be opened.");
        }
        else if((file2 = fopen(argv[2], "r")) == NULL)
        {
            puts("Error: File2 unable to be opened.");
        }
        else if((spliced = fopen(argv[3], "w")) == NULL)
        {
            puts("Error: Splicing file unable to be opened.");
        }
        else
        {
            long size1 = 0;
            long size2 = 0;
            BYTE *text1;
            BYTE *text2;
            BYTE mask1 = 0b11110000;
            BYTE mask2 = 0b00001111;
            BYTE character1 = 0;
            BYTE character2 = 0;
            
            
             //get size of files in bytes (char size)
            fseek(file1, 0, SEEK_END);
            size1 = ftell(file1);
            rewind(file1);
            fseek(file2, 0, SEEK_END);
            size2 = ftell(file2);
            rewind(file2);
            
            //create and populate arrays
            text1 = calloc(size1, sizeof(BYTE));
            text2 = calloc(size2, sizeof(BYTE));
            
            for (int i = 0; i < size1; i++)
            {
                fscanf(file1, "%c", &text1[i]);
            }
            for (int i = 0; i < size2; i++)
            {
                fscanf(file2, "%c", &text2[i]);
            }
            
            
            for(int i = 0; i < size1 || i < size2; i++)
            {
                if (i < size1)
                {
                    //character shifting to move bits from second file into most significant in variable
                    character1 = (text1[i] & mask1);
                    character2 = ((text1[i] & mask2) << 4);
                }
                else
                {
                    //if the first file is out of characters set the two printing characters to 0.
                    character1 = 0;
                    character2 = 0;
                }
                
                if (i < size2)
                {
                    //character shifting to move bits from second file into least significant in variable
                    character1 += ((text2[i] & mask1) >> 4);
                    character2 += (text2[i] & mask2);
                }
                
                fprintf(spliced, "%c%c", character1, character2);
            }
            
            free(text1);
            free(text2);
            text1 = NULL;
            text2 = NULL;
            
            fclose(file1);
            fclose(file2);
            fclose(spliced);
            
        }
    }
    else
    {
        puts("Error: Parameter mismatch.");
    }
}