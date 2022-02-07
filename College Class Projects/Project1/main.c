/**
 * Andrew DePaola
 * CIS205 - T8
 * 
 * Project 1 - Nim
 * 
 * This program plays a game of Nim between a computer and a human. 20-30
 * toothpicks are created, then the player and computer alternate taking away
 * 1-3 toothpicks until none remain. After the pile has been depleted the user
 * is told whether they won or lost and then are prompted to play again.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    int toothpicks = (rand() % 11) + 20;
    int turn = 1;
    int choice = 0;
    char keepPlaying = 'a';

    do
    {
        toothpicks = (rand() % 11) + 20;
        turn = 1;
        
        while (toothpicks > 0)
        {
            printf("Toothpicks remaining: %d\n", toothpicks);
            
            if (turn % 2 == 1)
            {
                puts("How many toothpicks would you like to take? (1-3)");
                
                scanf(" %d", &humanChoice);
                
                while (humanChoice < 1 || humanChoice > 3)
                {
                   puts("Invalid choice, try again");
                   scanf(" %d", &choice);
                }
            }
            else
            {
                choice = (rand() % 3) + 1;
                printf("Computer choice: %d\n", choice);
            }
            
            toothpicks -= choice;
            turn++;
        }
        
        if(turn % 2 == 1)
        {
            puts("YOU WIN");
        }
        else
        {
            puts("YOU LOSE");
        }
        
        puts("Play again? 'q' to quit");
        scanf(" %c", &keepPlaying);
    
    }while (keepPlaying != 'q');
}
