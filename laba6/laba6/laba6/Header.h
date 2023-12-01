#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>
using namespace std;

//Структура для списка смежности
typedef struct Spis
{
    int inf;
    struct Spis* next;
}SP;
extern int i, j; 

void PrintSpisok(int ver, SP** MassSpis);
void PrintMatrix(int ver, int*** smej);
void GeneratSpisok(int ver, SP** MassSpis, int** smej);
void Zad2(int ver1, int ver2, int** smej1, int** smej2, SP** MassSpis1, SP** MassSpis2);
void Zad34(int ver1, int ver2, int** smej1, int** smej2, SP** MassSpis1, SP** MassSpis2);
