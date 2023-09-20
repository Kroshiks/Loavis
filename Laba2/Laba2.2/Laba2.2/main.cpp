#include "Library.h"

//������� ��� ��������� ������ ��� ������
void MemoryAllocation(int** arr, int size)
{
    *arr = (int*)malloc(size * sizeof(int));

    if (*arr == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
}

//�������� ������� ���������
void main()
{
    SetConsoleCP(1251);//��������� �����
    SetConsoleOutputCP(1251);
    srand(time(NULL));//��������� �������
   
    int size;
    printf("������ ������ �������:");
    scanf("%d", &size);

    printf("\n���������� �����:\n");
    fillings1(size);

    printf("\n������� ����������:\n");
    fillings2(size);

    printf("\n���������� �������� qsort:\n");
    fillings3(size);
}