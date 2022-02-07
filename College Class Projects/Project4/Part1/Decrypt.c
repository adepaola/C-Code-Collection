/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 4 - Bits and Files  
 * 
 * This program decrypts a text file encripted by the "Encrypt.exe" program
 * packaged alongside it. It begins by opening the source of the encrypted text
 * as well as the file it will be outputting the encrypted text to. The encrypted
 * text is stored in memory and pointed to by the BYTE pointer 'text'. For each
 * byte in the allocated memory, a mask is used to save the least significant bits
 * of the current byte. The current byte is then shifted down two bits, and the stored
 * least significant bits are shifted into the most significant spaces. The current byte
 * and stored bits are then added together and printed as a character to the output file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTE uint8_t

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        FILE *original;
        FILE *decrypted;
        
        if((original = fopen(argv[1], "r")) == NULL)
        {
            puts("Error: Original file unable to be opened.");
        }
        else if((decrypted = fopen(argv[2], "w")) == NULL)
        {
            puts("Error: decrypted file unable to be opened.");
        }
        else
        {
            long size = 0;
            BYTE *text;
            BYTE mask = 0b00000011;
            BYTE endBits = 0;
            
            //get size of file in bytes (char size)
            fseek(original, 0, SEEK_END);
            size = ftell(original);
            rewind(original);
            //allocate memory for text and populate from original
            text = calloc(size, sizeof(BYTE));
            for (int i = 0; i < size; i++)
            {
                fscanf(original, "%c", &text[i]);
            }
            
            /*For every character in text, use mask to get it's most significant bits,
              shift the least significant bits to the most significant, and append
              that shifted character to the end of the decrypted file.
            */
            for (int i = 0; i < size; i++)
            {
                endBits = (text[i] & mask);
                endBits <<= 6;
                fprintf(decrypted, "%c", ((text[i] >> 2) + endBits));
            }
            
            fclose(original);
            fclose(decrypted);
        }
    }
    else
    {
        puts("Error: Parameter mismatch.");
    }
}