/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 10 - File IO and Command Line Arguments  
 *
 * This programs a file full of floats specified by the user. The file is then
 * scanned to count the number of floats in it. Memory is then allocated to hold
 * all the floats in the file. Finally, the lowest, highest, and average of the 
 * floats is then calculated and printed.
*/

#include <stdio.h>
#include <stdlib.h>

float averageFloats(float *floatsFromFile, int size);
float lowestFloat(float *floatsFromFile, int size);
float highestFloat(float *floatsFromFile, int size);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *floatFile;
        
        if ((floatFile = fopen(argv[1], "r")) == NULL)
        {
            puts("ERROR: File unable to be opened.");
        }
        else
        {
            float next = 0;
            int size = 0;
            
            //read number of floats in the file, fscanf returns number of items read.
            while(!feof(floatFile))
            {
                size += fscanf(floatFile, "%f ", &next);
            }
            rewind(floatFile);
            
            //calloc the space needed and populate
            float *floatsFromFile = calloc(size, sizeof(float));
            
            for(int i = 0; i < size; i++)
            {
                fscanf(floatFile, "%f ", &floatsFromFile[i]);
            }
            
            printf("Average: %f\nLowest: %f\nHighest: %f\n", 
                    averageFloats(floatsFromFile, size), lowestFloat(floatsFromFile, size), highestFloat(floatsFromFile, size));
                    
            free(floatsFromFile);
            floatsFromFile = NULL;
            fclose(floatFile);
        }
    }
    else
    {
        puts("Error: Parameter mismatch");
    }
}


float averageFloats(float *floatsFromFile, int size)
{
    float sum = 0.0;
    for(int i = 0; i < size; i++)
    {
        sum += floatsFromFile[i];
    }
    return sum/size;
}

float lowestFloat(float *floatsFromFile, int size)
{
    float lowest = floatsFromFile[0];
    
    for (int i = 1; i < size; i++)
    {
        if (floatsFromFile[i] < lowest)
        {
            lowest = floatsFromFile[i];
        }
    }
    
    return lowest;
}

float highestFloat(float *floatsFromFile, int size)
{
    float highest = floatsFromFile[0];
    
    for (int i = 1; i < size; i++)
    {
        if (floatsFromFile[i] > highest)
        {
            highest = floatsFromFile[i];
        }
    }
    
    return highest;
}