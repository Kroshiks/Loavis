#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

typedef struct Spis {
    int inf;
    struct Spis* next;
}SP;

extern int i, j;
using namespace std;

void Zad1(int** smej1, int** smej2, int ver1, int ver2, SP** MassSpis1, SP** MassSpis2);
void main();
void Zad2(int ver1, int ver2, int** smej1);




