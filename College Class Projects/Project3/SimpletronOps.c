/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 3 - Simpletron
 * 
 * This file contains all function definitions needed for the operation codes
 * in the Simpletron program.
 */

#include "SimpletronHeader.h"

void read(int *memLoc)
{
    puts("Enter number:");
    scanf("%d", memLoc);
}

void write(int *memLoc)
{
    printf("%d\n", *memLoc);
}

void load(int *memLoc, int *accu)
{
    *accu = *memLoc;
}

void store(int *memLoc, int *accu)
{
    *memLoc = *accu;
}

void add(int *memLoc, int *accu)
{
    *accu += *memLoc;
}

void subtract(int *memLoc, int *accu)
{
    *accu -= *memLoc;
}

void multiply(int *memLoc, int *accu)
{
    *accu *= *memLoc;
}

void divide(int *memLoc, int *accu)
{
    *accu /= *memLoc;
}

void branch(int *memLoc, int **programCounter)
{
    *programCounter = memLoc;
}
