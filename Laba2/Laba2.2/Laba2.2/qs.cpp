#include "Library.h"

void qs(int* items, int left, int right)
{
    // ������� ���� 
    int stack[100];
    int top = -1;
    int x, y;
    int j, i;

    // ��������� ��������� �������� � ����
    stack[++top] = left;
    stack[++top] = right;

    // ���� ���� �� ����
    while (top >= 0) {
        // ��������� ���� �������� �� �����
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

        // ��������� ����� ���� �������� � ����
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
    double T = 0.0;
    clock_t start, end;
    FILE* qs1, * qs2, * qs3, * qs4;

    //����������������
    MemoryAllocation(&a, size);

    qs1 = fopen("qsUp.txt", "w");
    fprintf(qs1, "�� ����������\n");

    for (i = 0; i < size; i++)
    {
        a[i] = i;
        fprintf(qs1, "%d\t", a[i]);
    }

    start = clock();
    qs(a, 0, size-1);
    end = clock();
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(���������������� �����) = %f�\n", T);

    fprintf(qs1, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qs1, "%d\t", a[i]);
    }
    fclose(qs1);

    free(a);

    //���������
    MemoryAllocation(&a, size);

    qs2 = fopen("qsDown.txt", "w");
    fprintf(qs2, "�� ����������\n");

    for (i = 0; i < size; i++)
    {
        a[i] = size - i - 1;
        fprintf(qs2, "%d\t", a[i]);
    }

    start = clock();
    qs(a, 0, size - 1);
    end = clock();
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(�������� �����) = %f�\n", T);

    fprintf(qs2, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qs2, "%d\t", a[i]);
    }
    fclose(qs2);

    free(a);

    //����������
    MemoryAllocation(&a, size);

    qs3 = fopen("qsHalf.txt", "w");
    fprintf(qs3, "�� ����������\n");

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
    T = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("�����(���������� �����) = %f�\n", T);

    fprintf(qs3, "\n\n����� ����������\n");
    for (i = 0; i < size; i++)
    {
        fprintf(qs3, "%d\t", a[i]);
    }
    fclose(qs3);

    free(a);

    //���������
    MemoryAllocation(&a, size);

    qs4 = fopen("qsRand.txt", "w");
    fprintf(qs4, "�� ����������\n");

    for (i = 0; i < size; i++)
    {
        a[i] = rand() % 100;
        fprintf(qs4, "%d\t", a[i]);
    }

   start = clock();
   qs(a, 0, size - 1);
   end = clock();
   T = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("�����(��������� �����)= %f�\n", T);

   fprintf(qs4, "\n\n����� ����������\n");
   for (i = 0; i < size; i++)
   {
       fprintf(qs4, "%d\t", a[i]);
   }
   fclose(qs4);

   free(a);
}