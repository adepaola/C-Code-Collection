/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 5 - Functions
 * 
 * This program presents a menu of various conversions and prompts the user for
 * a choice. They are then prompted for their starting value and their
 * chosen conversion is carried out.
 * 
*/

#include <stdio.h>

void print_menu();
int get_choice();
void process_choice(int);
float far_to_cel(int farTemp);
float mi_to_km(float miles);
float lbs_to_kg(float pounds);

int main()
{
    int choice = 5;
    int keepRunning = 1;
    
    //While sentinel loop.
    while (keepRunning != 0)
    {
        print_menu();
        choice = get_choice();
        process_choice(choice);
        
        puts("Make another conversion? 0 to quit.");
        scanf(" %d", &keepRunning);
    }
    
    puts("Goodbye");
}

void print_menu()
{
    puts("1. Convert Fahrenheit to Celsius");
    puts("2. Convert Miles to Kilometers");
    puts("3. Convert Pounds to Kilograms");
}

int get_choice()
{
    int choice = 1;
    
    puts("Enter choice: ");
    
    //Do-while validation. If statement prints re-prompt on all iterations after the first
    do
    {
        if(choice < 1 || choice > 3)
        {
            puts("Enter valid choice.");
        }
        
        scanf(" %d", &choice);
        
    }while(choice < 1 || choice > 3);
    
    return choice;
}

void process_choice(int choice)
{
    
    switch (choice)
    {
        case 1:
            puts("Enter Fahrenheit Temperature: ");
            int farTemp = 0;
            scanf(" %d", &farTemp);
            printf("%dF is %.1fC\n", farTemp, far_to_cel(farTemp));
            break;
        case 2:
            puts("Enter distance in miles: ");
            float miles = 0.0;
            scanf(" %f", &miles);
            printf("%.1fmi is %.2fkm\n", miles, mi_to_km(miles));
            break;
        case 3:
            puts("Enter weight in pounds: ");
            float pounds = 0.0;
            scanf(" %f", &pounds);
            printf("%.1flbs is %.2fkg\n", pounds, lbs_to_kg(pounds));
            break;
        default:
            puts("Thanks for breaking my program");
            break;
    }
}

float far_to_cel(int farTemp)
{
    return (farTemp - 32) / 1.8;
}

float mi_to_km(float miles)
{
    return (miles / 0.62137);
}

float lbs_to_kg(float pounds)
{
    return (pounds / 2.2046);
}