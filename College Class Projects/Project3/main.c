/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 3 - Simpletron
 * 
 * This program allows users to program a Simpletron using the
 * Simpletron Machine Language.
 */

#include "SimpletronHeader.h"

int main()
{
    puts("Welcome to Simpletron.");
    int memSize = 0;
    puts("Enter memory size: ");
    scanf("%d", &memSize);
    
    while(memSize < 10 || memSize > 999)
    {
        puts("Error: Invalid memory size");
        scanf("%d", &memSize);
    }
    
	int *memory = calloc(memSize, sizeof(int));
	int *programCounter = memory;
	int accumulator = 0;
	int instructionReg = 0;
	int menuChoice = 0;
	
	do
	{
    	printMenu();
    	scanf("%d", &menuChoice);
    	
    	while((menuChoice != LOADPROG) && (menuChoice != RUNPROG) &&
    	      (menuChoice != DUMPMEM) && (menuChoice != 0))
    	{
    	    puts("Invalid menu choice. Please enter again.");
    	    scanf("%d", &menuChoice);
    	}
    	
    	switch(menuChoice)
    	{
    	    case LOADPROG:
        	    loadProg(memSize, memory);
        	    break;
    	    case RUNPROG:
        	    runProg(memSize, memory, &accumulator, &instructionReg);
        	    break;
    	    case DUMPMEM:
        	    dumpMem(memSize, memory, accumulator, instructionReg);
        	    break;
    	}
	}while (menuChoice != 0);
	
	free(memory);
	memory = NULL;
}

void printMenu()
{
    printf("%12s\n%-16s | %d\n%-16s | %d\n%-16s | %d\n%-16s | %d\n",
             "Menu", "Load Into Memory", LOADPROG, "Run Program", RUNPROG, "Dump Memory", DUMPMEM, "Quit", 0);
}

void dumpMem(int memSize, int *memory, int accumulator, int instructionReg)
{
    printf("\n%40s\n", "Dumping Memory:");
    printf("%35s : %d\n", "Instruction Register", instructionReg);
    printf("%35s : %d\n\n", "Accumulator", accumulator);
    int memoryLoc = 0;
    
    for(int i = 0; i < 10; i++)
    {
        if(i < memSize)
        {
            printf("%6d", i);
        }
    }
    
    puts("");
    
    for(int row = 0; row <= ((memSize - 1) / 10); row++)
    {
        printf("%03d: ", row*10);
        for(int col = 0; col < 10 && memoryLoc != memSize; col++)
        {
            printf("%05d ", memory[memoryLoc]);
            memoryLoc++;
        }
        puts("");
    }
    puts("\n");
}

void loadProg(int memSize, int *memory)
{
    for(int i = 0; i < memSize; i++)
    {
        printf("%03d << ", i);
        scanf("%d", (memory+i));
        
        while(*(memory+i) > 99999 || (*(memory+i) % 1000) > (memSize - 1))
        {
            if(*(memory+i) > 99999)
            {
                puts("Data entered exceeds instruction size.");
            }
            if((*(memory+i) % 1000) > (memSize - 1))
            {
                puts("Location entered out of bounds.");
            }
            printf("%03d > ", i);
            scanf("%d", (memory+i));
        }
        
    }
}

void runProg(int memSize, int *memory, int *accumulator, int *instructionReg)
{
    int opCode = 0;
    int address = 0;
    int *programCounter = memory;
    
    do
    {
        fetch(programCounter, instructionReg);
        decode(*instructionReg, &opCode, &address);
        
        switch(opCode)
        {
            case(READ):
                read(memory+address);
                programCounter++;
                break;
            case(WRITE):
                write(memory+address);
                programCounter++;
                break;
            case(LOAD):
                load((memory+address), accumulator);
                programCounter++;
                break;
            case(STORE):
                store((memory+address), accumulator);
                programCounter++;
                break;
            case(ADD):
                add((memory+address), accumulator);
                programCounter++;
                break;
            case(SUBTRACT):
                subtract((memory+address), accumulator);
                programCounter++;
                break;
            case(MULTIPLY):
                multiply((memory+address), accumulator);
                programCounter++;
                break;
            case(DIVIDE):
                divide((memory+address), accumulator);
                programCounter++;
                break;
            case(BRANCH):
                branch((memory+address), &programCounter);
                break;
            case(BRANCHNEG):
                if(*accumulator < 0)
                {
                    branch((memory+address), &programCounter);
                }
                else
                {
                    programCounter++;
                }
                break;
            case(BRANCHZERO):
                if(*accumulator == 0)
                {
                    branch((memory+address), &programCounter);
                }
                else
                {
                    programCounter++;
                }
                break;
            case(HALT):
                break;
        }
    }while(opCode != HALT);
    dumpMem(memSize, memory, *accumulator, *instructionReg);
}

void fetch(int *programCounter, int *instructionReg)
{
    *instructionReg = *programCounter;
}

void decode(int instructionReg, int *opCode, int *address)
{
    *opCode = instructionReg / 1000;
    *address = instructionReg % 1000;
}