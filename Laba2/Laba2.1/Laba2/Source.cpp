#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void multiplications()
{

	clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r, size;
	int **a, **b, **c;
	int elem_c;
	double Time = 0.0;
	size = 0;
	printf("Ведите размер матриц:");
	scanf("%d", &size);
	//Выделение памяти под матрицу a
	a = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}
	if (a == NULL)
	{
		printf("\nНе удалось выделить память!\n");
		return;
	}
	//Выделение памяти под матрицу b
	b = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
	{
		b[i] = (int*)malloc(size * sizeof(int));
	}
	if (b == NULL)
	{
		printf("\nНе удалось выделить память!\n");
		return;
	}
	//Выделение памяти под матрицу c
	c = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
	{
		c[i] = (int*)malloc(size * sizeof(int));
	}
	if (c == NULL)
	{
		printf("\nНе удалось выделить память!\n");
		return;
	}

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < size)
	{
		while (j < size)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < size)
	{
		while (j < size)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	start = clock();
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			elem_c = 0;
			for (r = 0; r < size; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	end = clock();

	Time = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Время затраченное на умножение двух матриц размерами %d x %d = %f\n\n", size, size, Time);

	free(a);
	free(b);
	free(c);
}

int main()
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	SetConsoleCP(1251);//Установка языка
	SetConsoleOutputCP(1251);

	multiplications();
	multiplications();
	multiplications();
	multiplications();
	multiplications();
	multiplications();
	multiplications();
}