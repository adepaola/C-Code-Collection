/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 6 - Arrays
 * 
 * This program creates and prints an array of 100 numbers between 0 and 20.
 * The user is then prompted 10 times for integers to search the array for.
 * The frequency of each number in the array is then printed along with the sum of
 * each number in the array and the array's average.
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void printArray(int arr[], int size);
int findInArray(int arr[], int size, int search);
void getFrequency(int arr[], int size);

void main()
{
    srand(time(NULL));
    
    int nums[SIZE] = {0};
    int search = 0;
    int foundResult = 0;
    
    for(int i = 0; i < SIZE; i++)
    {
        nums[i] = (rand() % 21);
    }
    
    printArray(nums, SIZE);
    
    for(int i = 0; i < 10; i++)
    {
        puts("Enter an integer to search for: ");
        scanf(" %d", &search);
        foundResult = findInArray(nums, SIZE, search);
        
        if(foundResult == -1)
        {
            printf("%d not found in array.\n", search);
        }
        else
        {
            printf("%d found in array at index %d\n", search, foundResult);
        }
    }
    
    getFrequency(nums, SIZE);
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            printf("{%d", arr[i]);
        }
        else
        {
            printf(", %d", arr[i]);
        }
    }
    puts("}");
}

int findInArray(int arr[], int size, int search)
{
    int found = -1;
    
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == search)
        {
            found = i;
            i = size;
        }
    }
    
    return found;
}

void getFrequency(int arr[], int size)
{
    int frequency[21]= {0};
    int sum = 0;
    
    for(int i = 0; i < size; i++)
    {
        frequency[arr[i]]++;
        sum += arr[i];
    }
    
    printArray(frequency, 21);
    printf("Sum of the array: %d\n", sum);
    printf("Average of the array: %d\n", sum/size);
}