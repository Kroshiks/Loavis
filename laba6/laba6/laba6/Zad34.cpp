#include "Header.h"

void CombiningGraphs(int** smej1, int** smej2, int ver1, int ver2)
{
    int maxver;
    if (ver1 > ver2)
        maxver = ver1;
    else
        maxver = ver2;
    int** smejcomb = new int* [maxver];
    for (i = 0; i < maxver; i++)
    {
        smejcomb[i] = new int[maxver];
        for (j = 0; j < maxver; j++)
        {
            int val1;
            if (i < ver1 && j < ver1) val1 = smej1[i][j];
            else val1 = 0;

            int val2;
            if (i < ver2 && j < ver2) val2 = smej2[i][j];
            else val2 = 0;

            smejcomb[i][j] = val1 || val2;
        }
    }
    cout << "Резельтат обьединения графов" << endl << endl;
    PrintMatrix(maxver, &smejcomb);
    cout << endl;
    for (i = 0; i < maxver; i++)
    {
        delete[] smejcomb[i];
    }
    delete[] smejcomb;
}

void IntersectionGraphs(int** smej1, int** smej2, int ver1, int ver2)
{
    int maxver;
    if (ver1 > ver2)
        maxver = ver1;
    else
        maxver = ver2;
    int** smejinter = new int* [maxver];
    for (i = 0; i < maxver; i++)
    {
        smejinter[i] = new int[maxver];
        for (j = 0; j < maxver; j++)
        {
            int val1;
            if (i < ver1 && j < ver1) val1 = smej1[i][j];
            else val1 = 0;

            int val2;
            if (i < ver2 && j < ver2) val2 = smej2[i][j];
            else val2 = 0;

            smejinter[i][j] = val1 && val2;
        }
    }
    cout << "Резельтат пересечения графов" << endl << endl;
    PrintMatrix(maxver - 1, &smejinter);
    cout << endl;
    for (i = 0; i < maxver; i++)
    {
        delete[] smejinter[i];
    }
    delete[] smejinter;
}

void SummGraphs(int** smej1, int** smej2, int ver1, int ver2)
{
    int maxver;
    if (ver1 > ver2)
        maxver = ver1;
    else
        maxver = ver2;

    int p = abs(ver1 - ver2);
    int** smejsumm = new int* [maxver];
    for (i = 0; i < maxver; i++)
    {
        smejsumm[i] = new int[maxver];
        for (j = 0; j < maxver; j++)
        {
            if (i < ver1 || j < ver1 || j < ver2 || i < ver2)
            {
                if (i == j) smejsumm[i][j] = 0;
                else
                {
                    int val1;
                    if (i < ver1 && j < ver1) val1 = smej1[i][j];
                    else val1 = 0;

                    int val2;
                    if (i < ver2 && j < ver2) val2 = smej2[i][j];
                    else val2 = 0;

                    smejsumm[i][j] = val1 || val2;
                }
            }
            else smejsumm[i][j] = 0;
        }
    }
    for (i = 0; i < maxver - p; i++)
    {
        for (j = 0; j < maxver - p; j++)
        {
            if (smej1[i][j] == 1 && smej2[i][j] == 1) smejsumm[i][j] = 0;
        }
    }
    cout << "Резельтат кольцевой суммы графов" << endl << endl;
    PrintMatrix(maxver, &smejsumm);
    cout << endl;
    for (i = 0; i < maxver; i++)
    {
        delete[] smejsumm[i];
    }
    delete[] smejsumm;
}

void DecartGraphs(int** smej1, int** smej2, int ver1, int ver2)
{
    int decver = ver1 * ver2;
    int decveri = ver1 * ver2;

    int** smejdec = new int* [decver];
    for (i = 0; i < decver; i++)
    {
        smejdec[i] = new int[decver];
        for (j = 0; j < decver; j++)
        {
            smejdec[i][j] = 0;
        }
    }

    int u = 0, v = 0, i1, j1;
    for (i = 0; i < ver1; i++)
    {
        for (j = 0; j < ver2; j++)
        {
            for (i1 = 0; i1 < ver1; i1++)
            {
                for (j1 = 0; j1 < ver1; j1++)
                {
                    u = i * ver2 + j;
                    v = i1 * ver2 + j1;
                    if (j == j1) smejdec[u][v] = smej1[i][i1];
                    if (i == i1) smejdec[u][v] = smej2[j][j1];
                    if (i != i1 && j != j1) smejdec[u][v] = 0;
                }
            }
        }
    }
    cout << "Резельтат декартова произведения графов" << endl << endl;
    for (i = 0; i < decver; i++)
    {
        for (j = 0; j < decveri; j++)
        {
            cout << setw(3) << smejdec[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Zad34(int ver1, int ver2, int** smej1, int** smej2, SP** MassSpis1, SP** MassSpis2)
{
    int choice;
    system("cls");
    cout << "Задание 2";
    // вывод матрицы смежности 1 на экран
    cout << endl << "Матрица смежности 1" << endl;
    PrintMatrix(ver1, &smej1);
    cout << endl;

    // вывод матрицы смежности 2 на экран
    cout << "Матрица смежности 2" << endl;
    PrintMatrix(ver2, &smej2);
    cout << endl;

    //Вывод списка смежности 1
    cout << "Список смежности 1" << endl;
    PrintSpisok(ver1, MassSpis1);
    cout << endl;

    //Вывод списка смежности 2
    cout << "Список смежности 2" << endl;
    PrintSpisok(ver2, MassSpis2);
    cout << endl;
    do
    {
        cout << "1)ОбЪединение графов;" << endl;
        cout << "2)Пересечение графов;" << endl;
        cout << "3)Кольцевая сумма;" << endl;
        cout << "4)Декартово произведение;" << endl;
        cout << "5)Вернуться к выбору задания;" << endl;
        cout << "Выберите действие:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            CombiningGraphs(smej1, smej2, ver1, ver2);
            break;
        case 2:
            IntersectionGraphs(smej1, smej2, ver1, ver2);
            break;
        case 3:
            SummGraphs(smej1, smej2, ver1, ver2);
            break;
        case 4:
            DecartGraphs(smej1, smej2, ver1, ver2);
            break;
        case 5:
            break;
            cout << endl;
        default:
            cout << "Неверный выбор! Повторите попытку.";
            break;
        }
    } while (choice != 5);
}