/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 7 - 2D Arrays
 * 
 * This program creates a 2D-array full of zeroes, fills the arrays with random numbers
 * between 1 and 9, multiplies each number by a factor of 2, and finally prints the
 * sum of each number in each row and column of the array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void print2DArray(int arr[][3], int size);
void fill2DArray(int arr[][3]);
void scale2DArray(int arr[][3], int scale);
void sumRows(int arr[][3]);
void sumCols(int arr[][3]);


void main()
{
    int arr[3][3] = {{0},{0},{0}};
    print2DArray(arr, SIZE);
    
    fill2DArray(arr);
    print2DArray(arr, SIZE);
    
    scale2DArray(arr, 2);
    print2DArray(arr, SIZE);
    
    sumRows(arr);
    sumCols(arr);
}

void print2DArray(int arr[][3], int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            if (c == 0)
            {
                printf("{%d", arr[r][c]);
            }
            else
            {
                printf(", %d", arr[r][c]);
            }
        }
        puts("}");
    }
    puts("");
}

void fill2DArray(int arr[][3])
{
    srand(time(NULL));
    
    for(int r = 0; r < SIZE; r++)
    {
        for(int c = 0; c < SIZE; c++)
        {
           arr[r][c] = ((rand() % 9) + 1);
        }
    }
}

void scale2DArray(int arr[][3], int scale)
{
    for(int r = 0; r < SIZE; r++)
    {
        for(int c = 0; c < SIZE; c++)
        {
           arr[r][c] = (arr[r][c] * scale);
        }
    }
}

void sumRows(int arr[][3])
{
    int sum = 0;
    for(int r = 0; r < SIZE; r++)
    {
        for(int c = 0; c < SIZE; c++)
        {
           sum += arr[r][c];
        }
        printf("Row %d sum: %d\n", r, sum);
        sum = 0;
    }
}

void sumCols(int arr[][3])
{
    int sum = 0;
    for(int c = 0; c < SIZE; c++)
    {
        for(int r = 0; r < SIZE; r++)
        {
           sum += arr[r][c];
        }
        printf("Column %d sum: %d\n", c, sum);
        sum = 0;
    }
}