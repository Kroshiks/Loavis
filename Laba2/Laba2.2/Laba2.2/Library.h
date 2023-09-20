#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void MemoryAllocation(int** arr, int size);
void shell(int* items, int count);
void fillings1(int size);
void fillings2(int size);
void qs(int* items, int left, int right);
int compare(const void* a, const void* b);
void fillings3(int size);
