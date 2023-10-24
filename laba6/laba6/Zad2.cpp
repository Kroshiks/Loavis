#include "Header.h"

void IdentificationMatrix(int*** smej, int ver, int veri1, int veri2) 
{
    // Меняем ребра отождествляемой вершины на новую вершину
    for (int i = 0; i < ver; i++) 
    {
        (*smej)[i][veri1] = (*smej)[veri2][i];
        (*smej)[veri1][i] = (*smej)[i][veri2];
    }

    // Удаляем отождествляемую вершину (удаляем строку и столбец)
    for (int i = veri2; i < ver - 1; i++) 
    {
        (*smej)[i] = (*smej)[i + 1];
    }
    (*smej)[ver - 1] = nullptr;
    for (int i = 0; i < ver; i++) 
    {
        for (int j = veri2; j < ver - 1; j++) 
        {
            (*smej)[i][j] = (*smej)[i][j + 1];
        }
        (*smej)[i][ver - 1] = 0;
    }

    // Освобождаем память для последней строки и столбца
    delete[](*smej)[ver - 1];
    (*smej)[ver - 1] = nullptr;
    for (int i = 0; i < ver - 1; i++) 
    {
        (*smej)[i][ver - 1] = 0;
    }

    // Уменьшаем размер матрицы
    int** temp = new int* [ver - 1];
    for (int i = 0; i < ver - 1; i++) 
    {
        temp[i] = new int[ver - 1];
    }
    for (int i = 0; i < ver - 1; i++) 
    {
        for (int j = 0; j < ver - 1; j++) 
        {
            temp[i][j] = (*smej)[i][j];
        }
    }
    delete[] (*smej)[ver - 1];
    delete[] *smej;
    *smej = temp;
}

void Zad2(int ver1, int ver2, int** smej1)
{
    int choice = 0, graf = 0;
    int veri1 = 0, veri2 = 0;
    bool prov1 = 1, prov2 = 1;

    do
    {
        cout << "1)Отождествление вершин;" << endl;
        cout << "2)Стягивания ребра;" << endl;
        cout << "3)Расщепления вершины;" << endl;
        cout << "4)Вернуться к выбору задания;" << endl;
        cout << "Выберите действие:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                cout << "Выберите граф в котором хотите осуществить отождествление вершин(1 или 2):";
                cin >> graf;
                if (graf == 1 || graf == 2)
                    prov1 = 0;
                else
                    cout << "Ошибка: неверный ввод номера графа! Повторите попытку.";
            } while (prov1);

            if (graf == 1)
            {
                do
                {
                    cout << "Введите номера вершин, которые хотите отождествить:";
                    cin >> veri1;
                    cin >> veri2;
                    if (veri1-1 >= ver1 || veri2-1 >= ver1 || veri1-1 < 0 || veri2-1 < 0)
                        cout << "Ошибка: неверный ввод номеров вершин! Повторите попытку.";
                    else
                        prov2 = 0;
                } while (prov2);
                IdentificationMatrix(&smej1,ver1,veri1-1,veri2-1);
                for (i = 0; i < ver1; i++) {
                    for (j = 0; j < ver1; j++) {
                        printf("%-2d ", smej1[i][j]);
                    }
                    printf("\n");
                }
            }
            else if (graf == 2)
            {
                do
                {
                    cout << "Введите номера вершин, которые хотите отождествить:";
                    cin >> veri1 >> veri2;
                    if (veri1-1 >= ver2 || veri2-1 >= ver2 || veri1-1 < 0 || veri2-1 < 0)
                        cout << "Ошибка: неверный ввод номеров вершин! Повторите попытку.";
                    else
                        prov2 = 0;
                } while (prov2);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
           cout << "Неверный выбор! Повторите попытку.";
           break;
        }
    } while (choice != 4);
}