#include "Rotation.h"

int main()
{
	int* nums = (int*)calloc(ARRAY_SIZE, sizeof(int));
	char* letters = (char*)calloc(ARRAY_SIZE, sizeof(char));
	
	puts("Populate Numbers");
	populate_nums(nums, ARRAY_SIZE);
	
	puts("Print Integers");
	genPrint(nums, ARRAY_SIZE, sizeof(int), print_num);
	
	puts("Rotating Integers to the right 14 times.");
	genRotate(nums, ARRAY_SIZE, 14, sizeof(int));
	genPrint(nums, ARRAY_SIZE, sizeof(int), print_num);
	
	puts("Populate Characters");
	populate_letters(letters, ARRAY_SIZE);
	
	puts("Print Letters");
	genPrint(letters, ARRAY_SIZE, sizeof(char), print_letter);
	
	puts("Rotating Letters to the right 15 times");
	genRotate(letters, ARRAY_SIZE, 15, sizeof(char));
	genPrint(letters, ARRAY_SIZE, sizeof(char), print_letter);
	
	
	puts("Press enter to close");
	getchar();
	fflush(stdin);
	
	free(nums);
	free(letters);


	return 0;
}