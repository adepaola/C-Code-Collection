/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 8 - Pointers
 *
 * This program creates a list of 5 integers, saves sum and product in
 * variables passed by reference, then finds the memory address of a
 * specific value saved in the array. If the value is found the data
 * stored in it's memory location is changed to -9999.
*/

#include <stdio.h>

void calculator(int list[], int *sum, int *product);
int* find(int target, int list[], int size);

int main()
{
	int sum = 0;
	int product = 1;
	int target = 6;
	int list[5] = {15, 6, 2, 18, 9};
	int *found = NULL;
	
	calculator(list, &sum, &product);
	printf("Sum: %d\nProduct:%d\n", sum, product);
	
    found = find(target, list, 5);
    
    if (found == NULL)
    {
        printf("%d not found in list.\n", target);
    }
    else
    {
        printf("%d found at memory location %p\n", target, found);
        *found = -9999;
        printf("Data in %p changed to %d\n", found, *found);
    }
}

void calculator(int list[], int *sum, int *product)
{
    *sum = 0;
    *product = 1;
    
    for(int i = 0; i < 5; i++)
    {
        *sum += list[i];
        *product *= list[i];
    }
}

int* find(int target, int list[], int size)
{
    int* result = NULL;
    for(int i = 0; i < size; i++)
    {
        if(list[i] == target)
        {
            result = &list[i];
        }
    }
    
    return result;
}