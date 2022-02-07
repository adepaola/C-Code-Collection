/**
 * Andrew DePaola
 * CIS205 - T8 
 * Project 3 - Simpletron
 * 
 * This header contains all defines and prototypes for the Simpletron program.
 */

#ifndef SIMPLETRON_HEADER
#define SIMPLETRON_HEADER

    #include <stdio.h>
    #include <stdlib.h>
    
    enum Menu {LOADPROG = 1, RUNPROG, DUMPMEM};
    
    #define READ 10
    #define WRITE 11
    #define LOAD 20
    #define STORE 21
    #define ADD 30
    #define SUBTRACT 31
    #define MULTIPLY 32
    #define DIVIDE 33
    #define BRANCH 40
    #define BRANCHNEG 41
    #define BRANCHZERO 42
    #define HALT 43
    
    void printMenu();
    void dumpMem(int memSize, int *memory, int accumulator, int instructionReg);
    void loadProg(int memSize, int *memory);
    void runProg(int memSize, int *memory, int *accumulator, int *instructionReg);
    void fetch(int *programCounter, int *instructionReg);
    void decode(int instructionReg, int *opCode, int *address);
    
    void read(int *memLoc);
    void write(int *memLoc);
    void load(int *memLoc, int *accu);
    void store (int *memLoc, int *accu);
    void add(int *memLoc, int *accu);
    void subtract(int *memLoc, int *accu);
    void multiply(int *memLoc, int *accu);
    void divide(int *memLoc, int *accu);
    void branch(int *memLoc, int **programCounter);

#endif