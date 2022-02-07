/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 4 - Bits and Files  
 * 
 * 
 * This program is intended to encrypt a text file with a bitwise Caesar cypher.
 * It begins by opening a text file as well as the file it is going to output the
 * encrypted text to. The text file is then stored into memory and pointed to by the
 * BYTE pointer 'text'. For each byte in the allocated memory, a mask stores the
 * most significant bits. The current byte is then shifted to the left two bits, 
 * and the stored bits are shifted to the least significant bit spaces. The two values
 * are then added together and stored into the output text file as a character.
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
        FILE *encrypted;
        
        if((original = fopen(argv[1], "r")) == NULL)
        {
            puts("Error: Original file unable to be opened.");
        }
        else if((encrypted = fopen(argv[2], "w")) == NULL)
        {
            puts("Error: Encrypted file unable to be opened.");
        }
        else
        {
            long size = 0;
            BYTE *text;
            BYTE mask = 0b11000000;
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
              shift the most significant bits to the least significant, and append
              that shifted character to the end of the encrypted file.
            */
            for (int i = 0; i < size; i++)
            {
                endBits = (text[i] & mask);
                endBits >>= 6;
                fprintf(encrypted, "%c", ((text[i] << 2) + endBits));
            }
            
            fclose(original);
            fclose(encrypted);
        }
    }
    else
    {
        puts("Error: Parameter mismatch.");
    }
}