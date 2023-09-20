#include "Library.h"

//���������� ������
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
    double T = 0.0;
    clock_t start, end;
    FILE* Shell1, * Shell2, * Shell3, * Shell4;

    //����������������
    MemoryAllocation(&a, size);
   
    Shell1 = fopen("ShellUp.txt", "w");
    fprintf(Shell1, "�� ����������\n");

    for ( i = 0; i < size; i++)
    {
        a[i] = i; 
        fprintf(Shell1, "%d\t", a[i]);
    }
   
    start = clock();
    shell(a, size);
    end = clock();
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(���������������� �����) = %f�\n", T);

    fprintf(Shell1, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(Shell1, "%d\t", a[i]);
    }
    fclose(Shell1);

    free(a);

    //���������
    MemoryAllocation(&a, size);

    Shell2 = fopen("ShellDown.txt", "w");
    fprintf(Shell2, "�� ����������\n");

    for ( i = 0; i < size; i++)
    {
        a[i] = size-i-1;
        fprintf(Shell2, "%d\t", a[i]);
    }
    
    start = clock();
    shell(a, size);
    end = clock();
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(�������� �����) = %f�\n", T);

    fprintf(Shell2, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(Shell2, "%d\t", a[i]);
    }
    fclose(Shell2);

    free(a);
    
    //����������
    MemoryAllocation(&a, size);

    Shell3 = fopen("ShellHalf.txt", "w");
    fprintf(Shell3, "�� ����������\n");
    
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
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(���������� �����) = %f�\n", T);

    fprintf(Shell3, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(Shell3, "%d\t", a[i]);
    }
    fclose(Shell3);

    free(a);

    //���������
    MemoryAllocation(&a, size);

    Shell4 = fopen("ShellRand.txt", "w");
    fprintf(Shell4, "�� ����������\n");

    for (i = 0; i < size; i++)
    {
        a[i] = rand()%100;
        fprintf(Shell4, "%d\t", a[i]);
    }
  
    start = clock();
    shell(a, size);
    end = clock();
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(��������� �����)= %f�\n", T);

    fprintf(Shell4, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(Shell4, "%d\t", a[i]);
    }
    fclose(Shell4);

    free(a);
}
