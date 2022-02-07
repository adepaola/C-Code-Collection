#include "Rotation.h"

/*
n rotations can be completed in O(n) time by finding the index where the original array would begin after rotations complete.
The whole list of values can be flipped, then flipped twice more, once from the 0th to the 'new beginning' index (non-inclusive) and again from the 'new beginning' to the end.
*/
void genRotate(void* values, int length, int turns, size_t width)
{
	int turnIndex = turns % length;
	genFlip(values, 0, length, width);
	genFlip(values, 0, turnIndex, width);
	genFlip(values, turnIndex, length, width);
}

/*
genFlip can take any pointer and flip the values from start to end as long as it is given the width of the intended data type.
*/
void genFlip(void* values, int start, int end, size_t width)
{
	void* startIter = values + (start * width);
	void* endIter = values + ((end - 1) * width);
	void* temp = malloc(width);
	
	for(int i = 0; i < ((end - start) / 2); i++)
	{	
		memmove(temp, startIter, width);
		memmove(startIter, endIter, width);
		memmove(endIter, temp, width);
	
		startIter = startIter + width;
		endIter = endIter - width;
	}
	free(startIter);
	free(endIter);
	free(temp);
}

void populate_nums(void* nums, int length)
{
	void* iterator = nums;
	for (int i = 0; i < length; i++)
	{
		*(int*)iterator = i;
		iterator = iterator + sizeof(int);
	}
	free(iterator);
}

void populate_letters(void* letters, int length)
{
	void* iterator = letters;
	for(int i = 0; i < length; i++)
	{
		*(char*)iterator = i + 'a';
		iterator = iterator + sizeof(char);
	}
	free(iterator);
}

/*
genPrint will print values according to the format specified with the printer function pointer.
*/
void genPrint(void* values, int length, size_t width, void(*printer)(void* prData))
{
	void* iterator = values;
	for(int i = 0; i < length; i++)
	{
		printer(iterator);
		iterator = iterator + width;
	}
	puts("\n");
	free(iterator);
}

void print_num(void* nums)
{
	int num = *(int*)nums;
	printf("%d ", num);
}

void print_letter(void* letters)
{
	char letter = *(char*)letters;
	printf("%c ", letter);
}