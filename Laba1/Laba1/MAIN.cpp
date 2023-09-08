#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
int i, j;
struct student //�������� ���������
{
    char FAM[30], NAM[30], FACL[20], GR[10];
}st[3];

void Z123()
{
    printf("������� 1,2,3.\n");
    int* MAS = 0;
    int size, MAX, MIN;
    printf("������� ������ �������:");
    scanf("%d", &size);
    MAS = (int*)malloc(size * sizeof(int));//��������� ������ ��� ������
    if (MAS == NULL)
    {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (i = 0; i < size; i++) 
    {
        MAS[i] = rand()%100;//������������� �������
        printf("%d\n", MAS[i]);//����� �������
    }
    MIN = MAS[0];
    MAX = MAS[0];
    //����� ����������� � ����������� ��������
    for (i = 0; i < size; i++) 
    {
        if (MAS[i] < MIN)
            MIN = MAS[i];
        if (MAS[i] > MAX)
            MAX = MAS[i];
    }
    printf("MAX=%d   MIN=%d\n", MAX, MIN);
    printf("������� ����� MAX � MIN=%d\n", MAX-MIN);
    free(MAS);
}

void Z4()
{
    printf("\n������� 4(�� �������).\n");
    int DMAS[4][4], S;
    for (i = 0; i < 4; i++)
    {
        printf("%d).", i + 1);
        for (j = 0; j < 4; j++)
        {
            DMAS[i][j] = rand() % 100;//������������� ���������� �������
            printf(" %d\t", DMAS[i][j]);
        }
        printf("\n");
    }
    //����� ����� �� �������
    for (i = 0; i < 4; i++)
    {
        S = 0;
        for (j = 0; j < 4; j++)
        {
            S += DMAS[i][j];
        }
        printf("\n%d). %d\n", i + 1, S);
    }
}

void vuvod()//����� ��������� �� ����� 
{
    printf("\n|  �  |       �������       |         ���         |     ���������      |   ������   |\n");
    printf("|-----+---------------------+---------------------+--------------------+------------|\n");
    for (i = 0; i < 3; i++)
    {
        printf("|%-5d|%-21s|%-21s|%-20s|%-12s|\n", i + 1, st[i].FAM, st[i].NAM, st[i].FACL, st[i].GR);
    }
    printf("|___________________________________________________________________________________|\n");
}

void Z5()
{
    printf("\n������� 5.\n");
    //���������� ���������
    for (i = 0; i < 3; i++)
    {
        printf("������� ������� %d-��� ��������: ", i+1);
        scanf("%s", &st[i].FAM);
        printf("������� ��� %d-��� ��������: ", i+1);
        scanf("%s", &st[i].NAM);
        printf("������� �������� %d-��� ��������: ", i+1);
        scanf("%s", &st[i].FACL);
        printf("������� ����� ������ %d-��� ��������: ", i+1);
        scanf("%s", &st[i].GR);
    }
   
    char SrchFAM[30], SrchNAM[30], SrchFACL[20], SrcGR[10], h;
    int O = 0;
    //�����
    while(1)
    {
        vuvod();
        printf("�������� �� ������ �������� ������������ �����:\n");
        printf("1)������� ��������\n");
        printf("2)��� ��������\n");
        printf("3)��������� ��������\n");
        printf("4)������ ��������\n");
        printf("0)������ ������\n");
        scanf_s("%c", &h);
        system("cls");
        switch (h)
        {
        //����� �� �������
        case('1'):
        {
            vuvod();
            printf("������� ������� �������� ��� ������: ");
            scanf("%s", SrchFAM);
            system("cls");
            printf("\n|  �  |       �������       |         ���         |     ���������      |   ������   |\n");
            printf("|-----+---------------------+---------------------+--------------------+------------|\n");
            for (i = 0; i < 3; i++)
            {
                if (strcmp(st[i].FAM, SrchFAM) == 0)//���������
                {
                    printf("|%-5d|%-21s|%-21s|%-20s|%-12s|\n", i + 1, st[i].FAM, st[i].NAM, st[i].FACL, st[i].GR);
                    O++;
                }
            }
            printf("|___________________________________________________________________________________|\n");
            if (O == 0)
            {
                system("cls");
                printf("������, ��������� � �������� %s �� ����������!!!", SrchFAM);
            }
            else
                printf("����� ��� ��������!");
           
            return;
        }
        //����� �� �����
        case('2'):
        {
            vuvod();
            printf("������� ��� �������� ��� ������: ");
            scanf("%s", SrchNAM);
            system("cls");
            printf("\n|  �  |       �������       |         ���         |     ���������      |   ������   |\n");
            printf("|-----+---------------------+---------------------+--------------------+------------|\n");
            for (i = 0; i < 3; i++)
            {
                if (strcmp(st[i].NAM, SrchNAM) == 0)
                {
                    printf("|%-5d|%-21s|%-21s|%-20s|%-12s|\n", i + 1, st[i].FAM, st[i].NAM, st[i].FACL, st[i].GR);
                    O++;
                }
            }
            printf("|___________________________________________________________________________________|\n");
            if (O == 0)
            {
                system("cls");
                printf("������, ��������� � ������ %s �� ����������!!!", SrchNAM);
            }
            else
                printf("����� ��� ��������!");

            return;
        }
        //����� �� ����������
        case('3'):
        {
            vuvod();
            printf("������� ��������� �������� ��� ������: ");
            scanf("%s", SrchFACL);
            system("cls");
            printf("\n|  �  |       �������       |         ���         |     ���������      |   ������   |\n");
            printf("|-----+---------------------+---------------------+--------------------+------------|\n");
            for (i = 0; i < 3; i++)
            {
                if (strcmp(st[i].FACL, SrchFACL) == 0)
                {
                    printf("|%-5d|%-21s|%-21s|%-20s|%-12s|\n", i + 1, st[i].FAM, st[i].NAM, st[i].FACL, st[i].GR);
                    O++;
                }
            }
            printf("|___________________________________________________________________________________|\n");
            if (O == 0)
            {
                system("cls");
                printf("������, ��������� � ���������� %s �� ����������!!!", SrchFACL);
            }
            else
                printf("����� ��� ��������!");
            
            return;
        }
        //����� �� ������
        case('4'):
        {
            vuvod();
            printf("������� ������ �������� ��� ������: ");
            scanf("%s", SrcGR);
            system("cls");
            printf("\n|  �  |       �������       |         ���         |     ���������      |   ������   |\n");
            printf("|-----+---------------------+---------------------+--------------------+------------|\n");
            for (i = 0; i < 3; i++)
            {
                if (strcmp(st[i].GR, SrcGR) == 0)
                {
                    printf("|%-5d|%-21s|%-21s|%-20s|%-12s|\n", i + 1, st[i].FAM, st[i].NAM, st[i].FACL, st[i].GR);
                    O++;
                }
            }
            printf("|___________________________________________________________________________________|\n");
            if (O == 0)
            {
                system("cls");
                printf("������, ��������� �� ������ %s �� ����������!!!", SrcGR);
            }
            else
             printf("����� ��� ��������!");
            
            return;
        }
        case('0'):
        {
            return; 
        }
        }
    }
}
void main()//�������� ���� ���������
{

    SetConsoleCP(1251);//��������� �����
    SetConsoleOutputCP(1251);
    srand(time(NULL));//��������� �������
    Z123();
    Z4();
    Z5();
    printf("\n�����!");
    getchar();
 }