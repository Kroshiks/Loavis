#include "Library.h"

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void fillings3(int size)
{
    int* a = NULL;
    int i;
    double T1 = 0.0;
	double T2 = 0.0;
	double T3 = 0.0;
	double T4 = 0.0;
    clock_t start, end;
    FILE* qsort1, * qsort2, * qsort3, * qsort4;

    //Последовательно
    MemoryAllocation(&a, size);

    qsort1 = fopen("qsortUp.txt", "w");
    fprintf(qsort1, "До сортировки\n");

    for (i = 0; i < size; i++)
    {
        a[i] = i;
        fprintf(qsort1, "%d\t", a[i]);
    }

    start = clock();
    qsort(a, size, sizeof(int), compare);
    end = clock();
    T1 = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(qsort1, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qsort1, "%d\t", a[i]);
    }
    fclose(qsort1);

    free(a);

    //Убывающее
    MemoryAllocation(&a, size);

    qsort2 = fopen("qsortDown.txt", "w");
    fprintf(qsort2, "До сортировки\n");

    for (i = 0; i < size; i++)
    {
        a[i] = size - i - 1;
        fprintf(qsort2, "%d\t", a[i]);
    }

    start = clock();
    qsort(a, size, sizeof(int), compare);
    end = clock();
    T2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    fprintf(qsort2, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qsort2, "%d\t", a[i]);
    }
    fclose(qsort2);

    free(a);;

    //Половинное
    MemoryAllocation(&a, size);

    qsort3 = fopen("qsortHalf.txt", "w");
    fprintf(qsort3, "До сортировки\n");

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
        fprintf(qsort3, "%d\t", a[i]);
    }

    start = clock();
    qsort(a, size, sizeof(int), compare);
    end = clock();
    T3 = ((double)(end - start)) / CLOCKS_PER_SEC;

    fprintf(qsort3, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qsort3, "%d\t", a[i]);
    }
    fclose(qsort3);

    free(a);

    //Случайное
    MemoryAllocation(&a, size);

    qsort4 = fopen("qsortRand.txt", "w");
    fprintf(qsort4, "До сортировки\n");

    for (i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
        fprintf(qsort4, "%d\t", a[i]);
    }

    start = clock();
    qsort(a, size, sizeof(int), compare);
    end = clock();
    T4 = ((double)(end - start)) / CLOCKS_PER_SEC;


    fprintf(qsort4, "\n\nПосле сортировки\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qsort4, "%d\t", a[i]);
    }
    fclose(qsort4);

    free(a);

	printf("| qsort|   %f   |    %f   |   %f    |   %f  |\n", T1, T2, T3, T4);
	
}
