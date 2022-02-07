/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 4 - Bits and Files  
 * 
 * 
 * This program is intended to separate text spliced together by the "Splice.exe"
 * program packaged with it. This program begins by opening the spliced text file
 * as well as the two files it will be outputting to. The spliced text is then 
 * allocated memory and pointed to by the 'splicedText' pointer. A loop is then used
 * to read two characters at a time from the splicedText. The first half of the
 * two characters are stored as 'character1' (with the bits from the second spliced
 * character shifted to the least significant bits), and the second half of the 
 * two characters are stored as 'character2' (with the bits from the second character
 * being shifted into the most significant bits). The newly reconstructed character1
 * is then output into file1, while the reconstructed character2 is output into file2.
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
        
        if((spliced = fopen(argv[1], "r")) == NULL)
        {
            puts("Error: Spliced file unable to be opened.");
        }
        else if((file1 = fopen(argv[2], "w")) == NULL)
        {
            puts("Error: File1 unable to be opened.");
        }
        else if((file2 = fopen(argv[3], "w")) == NULL)
        {
            puts("Error: File2 unable to be opened.");
        }
        else
        {
            long size = 0;
            BYTE *splicedText;
            BYTE mask1 = 0b11110000;
            BYTE mask2 = 0b00001111;
            BYTE character1 = 0;
            BYTE character2 = 0;
            
            
             //get size of file in bytes (char size)
            fseek(spliced, 0, SEEK_END);
            size = ftell(spliced);
            rewind(spliced);
            
            //create and populate array
            splicedText = calloc(size, sizeof(BYTE));
            
            for (int i = 0; i < size; i++)
            {
                fscanf(spliced, "%c", &splicedText[i]);
            }
            
            //step by 2 because each character needs information from two bytes to complete itself
            for(int i = 0; i < size; i+=2)
            {
                //shifts to make sure bits are moved in the right position after reading through the mask.
                character1 = (splicedText[i] & mask1) + ((splicedText[i+1] & mask1) >> 4);
                character2 = ((splicedText[i] & mask2) << 4) + (splicedText[i+1] & mask2);
                
                //only print the character to the file if it's saving a value
                if (character1 != 0)
                {
                    fprintf(file1, "%c", character1);
                }
                if (character2 != 0)
                {
                    fprintf(file2, "%c", character2);
                }
            }
            
            free(splicedText);
            splicedText = NULL;
            //close files
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