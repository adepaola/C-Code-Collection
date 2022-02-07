/**
 * Andrew DePaola
 * CIS205 - T8 
 * Lab 4 - Control Structures
 * 
 * This program presents a menu of various conversions and prompts the user for
 * a choice. They are then prompted for their starting value and their
 * chosen conversion is carried out.
 * 
 * While sentinel loop in main()
 * Do-While validation loop in get_choice()
 * Switch in process_choice()
 * 
*/

#include <stdio.h>

void print_menu();
int get_choice();
void process_choice(int);
void far_to_cel();
void mi_to_km();
void lbs_to_kg();

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
            far_to_cel();
            break;
        case 2:
            mi_to_km();
            break;
        case 3:
            lbs_to_kg();
            break;
        default:
            puts("Thanks for breaking my program");
            break;
    }
}

void far_to_cel()
{
    int farTemp = 0;
    float celTemp = 0;
    
    puts("Enter Fahrenheit Temperature: ");
    scanf(" %d", &farTemp);
    
    celTemp = (farTemp - 32) / 1.8;
    
    printf("%dF is %.1fC\n", farTemp, celTemp);
}

void mi_to_km()
{
    float miles = 0.0;
    float kilometers = 0.0;
    
    puts("Enter distance in miles: ");
    scanf(" %f", &miles);
    
    kilometers = (miles / 0.62137);
    
    printf("%.1fmi is %.2fkm\n", miles, kilometers);
}

void lbs_to_kg()
{
    float pounds = 0;
    float kilograms = 0;
    
    puts("Enter weight in pounds: ");
    scanf(" %f", &pounds);
    
    kilograms = (pounds / 2.2046);
    
    printf("%.1flbs is %.2fkg", pounds, kilograms);
}