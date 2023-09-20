#include "Library.h"

//Сортировка Шеллла
void shell(int* items, int count)
{
    int  i, j, gap, k;
    int x, a[5];
    
    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
   
    for (k = 0; k < 5; k++) {
        gap = a[k];
        for ( i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void fillings1(int size)
{
    int* a = NULL;
    int i;
    double T1 = 0.0;
	double T2 = 0.0;
	double T3 = 0.0;
	double T4 = 0.0;
    clock_t start, end;
    FILE* Shell1, * Shell2, * Shell3, * Shell4;

    //Последовательное
    MemoryAllocation(&a, size);
   
    Shell1 = fopen("ShellUp.txt", "w");
    fprintf(Shell1, "До сортировки\n");

    for ( i = 0; i < size; i++)
    {
        a[i] = i; 
        fprintf(Shell1, "%d\t", a[i]);
    }
   
    start = clock();
    shell(a, size);
    end = clock();
    T1 = ((double)(end - start)) / CLOCKS_PER_SEC;
   

    fprintf(Shell1, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(Shell1, "%d\t", a[i]);
    }
    fclose(Shell1);

    free(a);

    //Убывающее
    MemoryAllocation(&a, size);

    Shell2 = fopen("ShellDown.txt", "w");
    fprintf(Shell2, "До сортировки\n");

    for ( i = 0; i < size; i++)
    {
        a[i] = size-i-1;
        fprintf(Shell2, "%d\t", a[i]);
    }
    
    start = clock();
    shell(a, size);
    end = clock();
    T2 = ((double)(end - start)) / CLOCKS_PER_SEC;
 
    fprintf(Shell2, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(Shell2, "%d\t", a[i]);
    }
    fclose(Shell2);

    free(a);
    
    //Половинное
    MemoryAllocation(&a, size);

    Shell3 = fopen("ShellHalf.txt", "w");
    fprintf(Shell3, "До сортировки\n");
    
    for ( i = 0; i < size / 2; i++) 
    {
        a[i] = i;
    }

    for ( i = size / 2; i < size; i++) 
    {
        a[i] = size - i-1;
    }

    for (i = 0; i < size; i++)
    {
        fprintf(Shell3, "%d\t", a[i]);
    }

    start = clock();
    shell(a, size);
    end = clock();
    T3 = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(Shell3, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(Shell3, "%d\t", a[i]);
    }
    fclose(Shell3);

    free(a);

    //Случайное
    MemoryAllocation(&a, size);

    Shell4 = fopen("ShellRand.txt", "w");
    fprintf(Shell4, "До сортировки\n");

    for (i = 0; i < size; i++)
    {
        a[i] = rand()%100;
        fprintf(Shell4, "%d\t", a[i]);
    }
  
    start = clock();
    shell(a, size);
    end = clock();
    T4 = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(Shell4, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(Shell4, "%d\t", a[i]);
    }
    fclose(Shell4);

    free(a);

	printf("|  Sh  |   %f   |    %f   |   %f    |   %f  |\n", T1, T2, T3, T4);
	
}

