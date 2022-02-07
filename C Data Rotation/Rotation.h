#ifndef ROTATION_H
#define ROTATION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h> //for memmove()

#define ARRAY_SIZE 26

void genRotate(void* values, int length, int turns, size_t width);
void genFlip(void* values, int start, int end, size_t width);

void populate_nums(void* nums, int length);
void populate_letters(void* letters, int length);

void genPrint(void* values, int length, size_t width, void(*printer)(void* prData));
void print_num(void* nums);
void print_letter(void* letters);

#endif
