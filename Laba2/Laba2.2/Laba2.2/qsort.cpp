#include "Library.h"

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void fillings3(int size)
{
    int* a = NULL;
    int i;
    double T = 0.0;
    clock_t start, end;
    FILE* qsort1, * qsort2, * qsort3, * qsort4;

    //���������������
    MemoryAllocation(&a, size);

    qsort1 = fopen("qsortUp.txt", "w");
    fprintf(qsort1, "�� ����������\n");

    for (i = 0; i < size; i++)
    {
        a[i] = i;
        fprintf(qsort1, "%d\t", a[i]);
    }

    start = clock();
    qsort(a, size, sizeof(int), compare);
    end = clock();
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(���������������� �����) = %f�\n", T);

    fprintf(qsort1, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qsort1, "%d\t", a[i]);
    }
    fclose(qsort1);

    free(a);

    //���������
    MemoryAllocation(&a, size);

    qsort2 = fopen("qsortDown.txt", "w");
    fprintf(qsort2, "�� ����������\n");

    for (i = 0; i < size; i++)
    {
        a[i] = size - i - 1;
        fprintf(qsort2, "%d\t", a[i]);
    }

    start = clock();
    qsort(a, size, sizeof(int), compare);
    end = clock();
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(�������� �����) = %f�\n", T);
    
    fprintf(qsort2, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qsort2, "%d\t", a[i]);
    }
    fclose(qsort2);

    free(a);;

    //����������
    MemoryAllocation(&a, size);

    qsort3 = fopen("qsortHalf.txt", "w");
    fprintf(qsort3, "�� ����������\n");

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
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(���������� �����) = %f�\n", T);

    fprintf(qsort3, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qsort3, "%d\t", a[i]);
    }
    fclose(qsort3);

    free(a);

    //���������
    MemoryAllocation(&a, size);

    qsort4 = fopen("qsortRand.txt", "w");
    fprintf(qsort4, "�� ����������\n");

    for (i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
        fprintf(qsort4, "%d\t", a[i]);
    }

    start = clock();
    qsort(a, size, sizeof(int), compare);
    end = clock();
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(��������� �����)= %f�\n", T);

    fprintf(qsort4, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qsort4, "%d\t", a[i]);
    }
    fclose(qsort4);

    free(a);
}