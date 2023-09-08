#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
int i, j, size;
struct student //Создание структуры
{
    char FAM[30], NAM[30], FACL[20], GR[10];
}st[3];

void Z123()
{
    printf("ЗАДАНИЕ 1,2,3.\n");
    int* MAS = 0;
    int  MAX, MIN;
    printf("Введите размер массива:");
    scanf("%d", &size);
    MAS = (int*)malloc(size * sizeof(int));//Выделение памяти под массив
    if (MAS == NULL)
    {
        printf("Не удалось выделить память!\n");
        return;
    }
    for (i = 0; i < size; i++)
    {
        MAS[i] = rand() % 100;//Инициализация массива
        printf("%d\n", MAS[i]);//Вывод массива
    }
    MIN = MAS[0];
    MAX = MAS[0];
    //Поиск наименьшего и наибольшего значения
    for (i = 0; i < size; i++)
    {
        if (MAS[i] < MIN)
            MIN = MAS[i];
        if (MAS[i] > MAX)
            MAX = MAS[i];
    }
    printf("MAX=%d   MIN=%d\n", MAX, MIN);
    printf("Разница между MAX и MIN=%d\n", MAX - MIN);
    free(MAS);
}

void Z4()
{
    printf("\nЗАДАНИЕ 4(По строкам).\n");
    int **DMAS, S, st, sl, g;
    printf("Введите количество строк:");
    scanf("%d", &st);
    printf("Введите количество столбцов:");
    scanf("%d", &sl);
    DMAS = (int**)malloc(st * sizeof(int));
    for (i = 0; i < st; i++)
    {
        DMAS[i] = (int*)malloc(sl * sizeof(int));
    }
    if (DMAS == NULL)
    {
        printf("\nНе удалось выделить память!\n");
        return;
    }


    for (i = 0; i < st; i++)
    {
        for (j = i; j < sl ; j++)
        {
            if ((g = rand() % 2) == 0)
                DMAS[i][j] = 0;
            else
                DMAS[i][j] = rand() % 100;

            DMAS[j][i] = DMAS[i][j];
              
            if (i == j)
            {
                DMAS[i][j] = 0;
            }
        }
    }
    //Поиск суммы по строкам
    for (i = 0; i < st; i++)
    {
        printf("%d).", i + 1);
        for (j = 0; j < sl; j++)
        {
            printf(" %d\t", DMAS[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < st; i++)
    {
        S = 0;
        for (j = 0; j < sl; j++)
        {
            S += DMAS[i][j];
        }
        printf("\n%d). %d\n", i + 1, S);
    }
}

void vuvod()//Вывод структуры на экран 
{
    printf("\n|  №  |       Фамилия       |         Имя         |     Факультет      |   Группа   |\n");
    printf("|-----+---------------------+---------------------+--------------------+------------|\n");
    for (i = 0; i < 3; i++)
    {
        printf("|%-5d|%-21s|%-21s|%-20s|%-12s|\n", i + 1, st[i].FAM, st[i].NAM, st[i].FACL, st[i].GR);
    }
    printf("|___________________________________________________________________________________|\n");
}

void Z5()
{
    printf("\nЗАДАНИЕ 5.\n");
    //Заполнение структуры
    for (i = 0; i < 3; i++)
    {
        printf("Введите фамилию %d-ого студента: ", i + 1);
        scanf("%s", &st[i].FAM);
        printf("Введите имя %d-ого студента: ", i + 1);
        scanf("%s", &st[i].NAM);
        printf("Введите факульте %d-ого студента: ", i + 1);
        scanf("%s", &st[i].FACL);
        printf("Введите номер группы %d-ого студента: ", i + 1);
        scanf("%s", &st[i].GR);
    }

    char SrchFAM[30], SrchNAM[30], SrchFACL[20], SrcGR[10], h;
    int O = 0;
    //Поиск
    while (1)
    {
        vuvod();
        printf("Выберите по какому критерию осуществлять поиск:\n");
        printf("1)Фамилия студента\n");
        printf("2)Имя студента\n");
        printf("3)Факультет студента\n");
        printf("4)Группа студента\n");
        printf("0)Отмена поиска\n");
        scanf_s("%c", &h);
        system("cls");
        switch (h)
        {
            //Поиск по фамилии
        case('1'):
        {
            vuvod();
            printf("Введите фамилию студента для поиска: ");
            scanf("%s", SrchFAM);
            scanf("%s", SrchNAM);
            system("cls");
            printf("\n|  №  |       Фамилия       |         Имя         |     Факультет      |   Группа   |\n");
            printf("|-----+---------------------+---------------------+--------------------+------------|\n");
            for (i = 0; i < 3; i++)
            {
                if ((strcmp(st[i].FAM, SrchFAM) == 0) && (strcmp(st[i].NAM, SrchNAM) == 0))//Сравнение
                {
                    printf("|%-5d|%-21s|%-21s|%-20s|%-12s|\n", i + 1, st[i].FAM, st[i].NAM, st[i].FACL, st[i].GR);
                    O++;
                }
            }
            printf("|___________________________________________________________________________________|\n");
            if (O == 0)
            {
                system("cls");
                printf("Ошибка, студентов с фамилией %s не существует!!!", SrchFAM);
            }
            else
                printf("Поиск был выполнен!");

            return;
        }
        //Поиск по имени
        case('2'):
        {
            vuvod();
            printf("Введите имя студента для поиска: ");
            scanf("%s", SrchNAM);
            system("cls");
            printf("\n|  №  |       Фамилия       |         Имя         |     Факультет      |   Группа   |\n");
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
                printf("Ошибка, студентов с именем %s не существует!!!", SrchNAM);
            }
            else
                printf("Поиск был выполнен!");

            return;
        }
        //Поиск по факультету
        case('3'):
        {
            vuvod();
            printf("Введите факультет студента для поиска: ");
            scanf("%s", SrchFACL);
            system("cls");
            printf("\n|  №  |       Фамилия       |         Имя         |     Факультет      |   Группа   |\n");
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
                printf("Ошибка, студентов с факультета %s не существует!!!", SrchFACL);
            }
            else
                printf("Поиск был выполнен!");

            return;
        }
        //Поиск по группе
        case('4'):
        {
            vuvod();
            printf("Введите группу студента для поиска: ");
            scanf("%s", SrcGR);
            system("cls");
            printf("\n|  №  |       Фамилия       |         Имя         |     Факультет      |   Группа   |\n");
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
                printf("Ошибка, студентов из группы %s не существует!!!", SrcGR);
            }
            else
                printf("Поиск был выполнен!");

            return;
        }
        case('0'):
        {
            return;
        }
        }
    }
}
void main()//Основной файл программы
{

    SetConsoleCP(1251);//Установка языка
    SetConsoleOutputCP(1251);
    srand(time(NULL));//Установка времени
    Z123();
    Z4();
    Z5();
    printf("\nКОНЕЦ!");
    getchar();
}