/**
 * Andrew DePaola
 * CIS205 - T8
 * 
 * Project 2 - Prefix Calculator
 * 
 * This program reads a character from the user specifying the math operation they wish to perform.
 * The numbers required for the calculation are then read, the calculation is performed, and the
 * result is printed to the screen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define e 2.71828182846

void print_menu();
void print_instructions();
void division(float num1, float num2);
float power(float base, int exponent);
long factorial(int base);
int random_range(int start, int end);
int sum_range(int start, int end);
int product_range(int start, int end);
int standard_round(float num);
int round_up(float num);
int round_down(float num);
float find_minimum(float num1, float num2);
float find_maximum(float num1, float num2);
void odd_or_even(int num);

int main()
{
    char characterEntered = 'a';
    float num1 = 0;
    float num2 = 0;
    int exponent = 0;
    int start = 0;
    int end = 0;
    
    print_instructions();
    
    do
    {
        puts("Enter Equation");
        scanf(" %c", &characterEntered);
        
        switch(characterEntered)
        {
            case '+':
                scanf(" %f %f", &num1, &num2);
                printf("%f\n", num1 + num2);
                break;
            case '-':
                scanf(" %f %f", &num1, &num2);
                printf("%f\n", num1 - num2);
                break;
            case '*':
                scanf(" %f %f", &num1, &num2);
                printf("%f\n", num1 * num2);
                break;
            case '/':
                scanf(" %f %f", &num1, &num2);
                division(num1, num2);
                break;
            case '^':
                scanf(" %f %d", &num1, &exponent);
                printf("%f\n", power(num1, exponent));
                break;
            case 'e':
                scanf(" %d", &exponent);
                printf("%f\n", power(e, exponent));
                break;
            case '!':
                scanf(" %d", &start);
                printf("%ld\n", factorial(start));
                break;
            case 'r':
                scanf(" %d %d", &start, &end);
                printf("%d\n", random_range(start, end));
                break;
            case 's':
                scanf(" %d %d", &start, &end);
                printf("%d\n", sum_range(start, end));
                break;
            case 'p':
                scanf(" %d %d", &start, &end);
                printf("%d\n", product_range(start, end));
                break;
            case '~':
                scanf(" %f", &num1);
                printf("%d\n", standard_round(num1));
                break;
            case '\'':
                scanf(" %f", &num1);
                printf("%d\n", round_up(num1));
                break;
            case '_':
                scanf(" %f", &num1);
                printf("%d\n", round_down(num1));
                break;
            case '<':
                scanf(" %f %f", &num1, &num2);
                printf("%f\n", find_minimum(num1, num2));
                break;
            case '>':
                scanf(" %f %f", &num1, &num2);
                printf("%f\n", find_maximum(num1, num2));
                break;
            case '#':
                scanf("%d", &start);
                odd_or_even(start);
                break;
            case 'h':
                print_instructions();
                print_menu();
                break;
            case 'm':
                print_menu();
                break;
            case 'q':
                break;
            default:
                print_instructions();
                print_menu;
                break;
        }
    }while (characterEntered != 'q');
}

void print_menu()
{
    puts("+ - Add");
    puts("- - Subtract");
    puts("* - Multiply");
    puts("/ - Divide");
    puts("^ - Power");
    puts("e - Exponential");
    puts("! - Factorial");
    puts("r - Random Range");
    puts("s - Sum Range");
    puts("p - Product Range");
    puts("~ - Round");
    puts("` - Round Up");
    puts("_ - Round Down");
    puts("< - Find Minimum");
    puts("> - Find Maximum");
    puts("# - Determine Odd or Even");
    puts("m - Print Menu");
    puts("h - Help");
    puts("q - Quit");
}

void print_instructions()
{
    puts("Prefix Calculator: Enter desired operator followed by the numbers required for the operation seperated by a space.");
    puts("Example, add 2 and 3: + 2 3");
    puts("Enter 'm' for menu, 'q' to quit, 'h' for help");
}

void division(float num1, float num2)
{
    if (num2 != 0)
    {
        printf("%f\n", num1 / num2);
    }
    else
    {
        puts("Error: 0 divisor");
    }
}

float power(float base, int exponent)
{
    float result = 1;
    int isNegative = 0;
    
    if (exponent < 0)
    {
        isNegative = 1;
        exponent *= -1;
    }
    
    if(exponent == 0)
    {
        return 1;
    }
    else
    {
        result = base * power(base, exponent - 1);
    }
    
    if(isNegative == 1)
    {
        result = 1 / result;
    }
    
    return result;
}

long factorial(int base)
{
    if(base == 1)
    {
        return 1;
    }
    else
    {
        return base * factorial(base - 1);
    }
}

int random_range(int start, int end)
{
    srand(time(NULL));
    int random = 0;
    
    if(start < end)
    {
        random = (rand() % ((end - start) + 1)) + start;
    }
    else
    {
        random = (rand() % ((start - end) + 1)) + end;
    }
    
    return random;
}

int sum_range(int start, int end)
{
    int sum = 0;
    for(int i = start; i <= end; i++)
    {
        sum += i;
    }
    
    return sum;
}

int product_range(int start, int end)
{
    int product = 1;
    for(int i = start; i <= end; i++)
    {
        product *= i;
    }
    
    return product;
}

int standard_round(float num)
{
    int rounded = 0;
    
    if((num - (int)num) < .5)
    {
        rounded = round_down(num);
    }
    else
    {
        rounded = round_up(num);
    }
    
    return rounded;
}

int round_down(float num)
{
    return (int)num;
}

int round_up(float num)
{
    return round_down(num) + 1;
}

float find_minimum(float num1, float num2)
{
    float least = num1;
    if (num2 < num1)
    {
        least = num2;
    }
    return least;
}

float find_maximum(float num1, float num2)
{
    float greatest = num1;
    if (num2 > num1)
    {
        greatest = num2;
    }
    return greatest;
}

void odd_or_even(int num)
{
    if(num % 2 == 0)
    {
        puts("Even");
    }
    else
    {
        puts("Odd");
    }
}