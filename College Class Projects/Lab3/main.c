/**
 * Andrew DePaola
 * 
 * Lab 3 - Using Selection
 * 
 * This program prompts a user for either a 1 or 2.
 * Depending on their input the program with either output a joke or a fact.
*/

#include <stdio.h>

int main()
{
    puts("Enter either a 1 or 2.");
    puts("1. Tell a joke");
    puts("2. Tell a fact");
    
    int choice = 0;
    
    do
    {
        scanf(" %d", &choice);
        
        if (choice % 2 == 0 && choice != 2)
        {
            puts("Can you EVEN?! You made an invalid selection");
        }
        else if (choice % 2 == 1 && choice != 1)
        {
            puts("Hmm that's ODD... Your input is invalid");
        }
        
    }while (choice < 1 || choice > 2);

    if(choice == 1)
    {
        puts("\"Someone sent me a postcard picture of the earth. On the back it said, \"Wish you were here.\"\" - Steven Wright");
            
    }
    else if(choice == 2)
    {
        puts("H.P. Lovecraft's impressions of Newburyport, MA inspired the setting of his first published book \"The Shadow over Innsmouth.\"");
    }
    
    puts("Goodbye");
}
