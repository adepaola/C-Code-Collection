/*
Andrew DePaola
CIS 205 - T8

Lab2 - Basic IO and data type

This program prompts the user for a sequence of values
that are then used to explore the properties and boundaries
of C's data types.

*/

#include <stdio.h>

int main()
{
	int num1 = 0;
	int num2 = 0;
	char char1 = 'a';
	float deci = 0.0;
	
    puts("Enter an integer:");
    scanf(" %d", &num1);
    puts("Enter an integer:");
    scanf(" %d", &num2);
    puts("Enter a character: ");
    scanf(" %c", &char1);
    puts("Enter a float");
    scanf(" %f", &deci);
    
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);
    printf("Character 1: %c\n", char1);
    printf("Float: %.3f\n", deci);
    
    //Using the %d modifer for a char prints it's ASCII value
    printf("Char as int: %d\n", char1);
    
    char char2 = (char1 + 2);
    
    //Adding 2 to the char increases it's int value and moves it up the ASCII chart
    printf("Character 2: %c\n", char2);
    printf("Character 2 as int: %d\n", char2);
    
    int sumNums = (num1 + num2);
    printf("Sum of integers %d + %d = %d\n", num1, num2, sumNums);
    
    float numsAndFloat = (sumNums + deci);
    printf("Sum of integers and float %d + %d + %.3f = %.3f\n", num1, num2, deci, numsAndFloat);
    
    
    //Integer division: everything after decimal truncated before storage resulting in 0.0 rather than 0.5
    float numDivision = (num1 / num2);
    printf("Integer division %d / %d = %.3f\n", num1, num2, numDivision);
    
    //Casting one int to float causes quotient to maintain decimal numbers
    float castDivison = ((float)num1 / num2);
    printf("Integer cast to float division %.3f / %d = %.3f\n", (float)num1, num2, castDivison);
    
    //Quotient maintains decimals because one of the variables is a float
    float deciDivision = (deci / num1);
    printf("Float divided by int %.3f / %d = %.3f\n", deci, num1, deciDivision);
    
    int numsMod = (num1 % num2);
    printf("Nums modded %d %% %d = %d\n", num1, num2, numsMod);
    
    float sumOfTests = (sumNums + numsAndFloat + numDivision + castDivison + deciDivision);
    printf("Sum of all tests (Sum of integers -> Nums modded): %.3f\n", sumOfTests);
    
    return 0;
}