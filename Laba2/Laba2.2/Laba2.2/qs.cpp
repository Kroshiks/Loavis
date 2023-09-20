#include "Library.h"

void qs(int* items, int left, int right)
{
    // Создаем стек 
    int stack[100];
    int top = -1;
    int x, y;
    int j, i;

    // Добавляем начальные значения в стек
    stack[++top] = left;
    stack[++top] = right;

    // Пока стек не пуст
    while (top >= 0) {
        // Извлекаем пару индексов из стека
        right = stack[top--];
        left = stack[top--];

        i = left; j = right;
        x = items[(left + right) / 2];
        do {
            while ((items[i] < x) && (i < right)) i++;
            while ((x < items[j]) && (j > left)) j--;

            if (i <= j) {
                y = items[i];
                items[i] = items[j];
                items[j] = y;
                i++; j--;
            }
        } while (i <= j);

        // Добавляем новые пары индексов в стек
        if (left < j) {
            stack[++top] = left;
            stack[++top] = j;
        }
        if (i < right) {
            stack[++top] = i;
            stack[++top] = right;
        }
    }
}

void fillings2(int size)
{
    int* a = NULL;
    int i;
    double T1 = 0.0;
	double T2 = 0.0;
	double T3 = 0.0;
	double T4 = 0.0;
    clock_t start, end;
    FILE* qs1, * qs2, * qs3, * qs4;

    //Последовательное
    MemoryAllocation(&a, size);

    qs1 = fopen("qsUp.txt", "w");
    fprintf(qs1, "До сортировки\n");

    for (i = 0; i < size; i++)
    {
        a[i] = i;
        fprintf(qs1, "%d\t", a[i]);
    }

    start = clock();
    qs(a, 0, size-1);
    end = clock();
    T1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    fprintf(qs1, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qs1, "%d\t", a[i]);
    }
    fclose(qs1);

    free(a);

    //Убывающее
    MemoryAllocation(&a, size);

    qs2 = fopen("qsDown.txt", "w");
    fprintf(qs2, "До сортировки\n");

    for (i = 0; i < size; i++)
    {
        a[i] = size - i - 1;
        fprintf(qs2, "%d\t", a[i]);
    }

    start = clock();
    qs(a, 0, size - 1);
    end = clock();
    T2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    fprintf(qs2, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qs2, "%d\t", a[i]);
    }
    fclose(qs2);

    free(a);

    //Половинное
    MemoryAllocation(&a, size);

    qs3 = fopen("qsHalf.txt", "w");
    fprintf(qs3, "До сортировки\n");

    for (i = 0; i < size / 2; i++) 
    {
        a[i] = i;
    }

    for (i = size / 2; i < size; i++) 
    {
        a[i] = size - i - 1;
    }

    for (i = 0; i < size; i++)
    {
        fprintf(qs3, "%d\t", a[i]);
    }

    start = clock();
    qs(a, 0, size - 1);
    end = clock();
    T3 = ((double)(end - start)) / CLOCKS_PER_SEC;
   
    fprintf(qs3, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qs3, "%d\t", a[i]);
    }
    fclose(qs3);

    free(a);

    //Случайное
    MemoryAllocation(&a, size);

    qs4 = fopen("qsRand.txt", "w");
    fprintf(qs4, "До сортировки\n");

    for (i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
        fprintf(qs4, "%d\t", a[i]);
    }

   start = clock();
   qs(a, 0, size - 1);
   end = clock();
   T4 = ((double)(end - start)) / CLOCKS_PER_SEC;
  
   fprintf(qs4, "\n\nПосле сортировки\n");
   for (i = 0; i < size; i++)
   {
       fprintf(qs4, "%d\t", a[i]);
   }
   fclose(qs4);

   free(a);
	
	printf("|  qs  |   %f   |    %f   |   %f    |   %f  |\n", T1, T2, T3, T4);
	
}
