#include "Header.h"

void free(SP* head)
{
    SP* current = head;
    while (current != NULL)
    {
        SP* temp = current;
        current = current->next;
        delete temp;;
    }
}

void IdentificationMatrix(int** smej, int* ver, int veri1, int veri2, SP** MassSpis)
{
    int T;

    if (veri1 > veri2)
    {
        T = veri1;
        veri1 = veri2;
        veri2 = T;
    }

    bool hasEdge = smej[veri1][veri2];

  for (int i = 0; i < *ver; ++i) 
  {
      if (i != veri1 && i != veri2)
        {
            smej[veri1][i] = smej[veri1][i] || smej[veri2][i]; // Объединяем строки veri1 и veri2
            smej[i][veri1] = smej[i][veri1] || smej[i][veri2]; // Объединяем столбцы veri1 и veri2
        }
    }

    for (i = veri2; i < *ver - 1; i++)
    {
        for (j = 0; j < *ver - 1; j++)
        {
            smej[i][j] = smej[i + 1][j];
        }
    }

    for ( i = 0; i < *ver - 1; i++)
    {
        for ( j = veri2; j < *ver - 1; j++)
        {
            smej[i][j] = smej[i][j + 1];
        }
    }

    for (i = 0; i < *ver - 1; i++)
    {
        for (j = 0; j < *ver - 1; j++)
        {
            if (i==j) smej[i][j] = 0;
           
        }
    }

    if (hasEdge)
    {
        smej[veri1][veri1] = 1;
    }
    cout << "Вершина " << veri1 + 1 << " и вершина " << veri2 + 1 << " успешно отождествлены." << endl;
    PrintMatrix(*ver - 1, &smej);

    (*ver)--;

    for (int i = 0; i < *ver + 1; i++)
    {
        free(MassSpis[i]);
        MassSpis[i] = NULL;
    }
    GeneratSpisok(*ver, MassSpis, smej);
    PrintSpisok(*ver, MassSpis);
    cout << endl;
}

void RibTightening(int** smej, int* ver, int veri1, int veri2, SP** MassSpis)
{
    int T;

    if (veri1 > veri2)
    {
        T = veri1;
        veri1 = veri2;
        veri2 = T;
    }

    if (smej[veri1][veri2] == 0)
    {
        printf("Между вершинами должно быть ребро!\n");
        return;
    }

    bool* hasEdge = new bool [*ver];
    memset(hasEdge, false, sizeof(bool) * (*ver));

    for (i = 0; i < *ver; ++i)
    {
        if (smej[i][i] == 1) 
        {
            hasEdge[i] = true;
        }
    }

    for (i = 0; i < *ver; i++)
    {
        for (j = 0; j < *ver; j++)
        {
            smej[i][veri1] = smej[i][veri1] || smej[i][veri2];
            smej[veri1][j] = smej[veri1][j] || smej[veri2][j];
        }
    }

    for (i = 0; i < *ver - 1; i++)
    {
        for (j = veri2; j < *ver - 1; j++)
        {
            smej[i][j] = smej[i][j + 1];
        }
    }

    for (i = veri2; i < *ver - 1; i++)
    {
        for (j = 0; j < *ver - 1; j++)
        {
            smej[i][j] = smej[i + 1][j];
        }
    }
    
    for (i = 0; i < *ver-1; ++i) 
    {
        if (i != veri1 && i != veri2 && hasEdge[i]) smej[i][i] = 1;     
        else smej[i][i] = 0;
    }
   
    delete[] hasEdge;

    cout << " Между вершиной " << veri1 + 1 << " и вершиной " << veri2 + 1 << " было успешно стянуто ребро." << endl;
    PrintMatrix(*ver - 1, &smej);

    (*ver)--;
    for (int i = 0; i < *ver + 1; i++)
    {
        free(MassSpis[i]);
        MassSpis[i] = NULL;
    }
    GeneratSpisok(*ver, MassSpis, smej);
    PrintSpisok(*ver, MassSpis);
    cout << endl;
}

void SplittingAVertex(int** smej, int* ver, int veri1, SP** MassSpis)
{
    int newver = *ver + 1;
    int** smejprom = new int* [newver];
    if (smejprom == NULL)
    {
        cout << "Не удалось выделить память!" << endl;
        return;
    }
    for (i = 0; i < newver; i++)
    {
        smejprom[i] = new int[newver];
        for (j = 0; j < newver; j++)
        {
            if (i < *ver && j < *ver)
            {
                smejprom[i][j] = smej[i][j];  // копируем связи исходной матрицы
            }
            else if (i == *ver && j < *ver)
            {
                smejprom[i][j] = smej[veri1][j];  // новая вершина соединена со смежными вершинами выбранной вершины
            }
            else if (i < *ver && j == *ver)
            {
                smejprom[i][j] = smej[i][veri1];  // смежные вершины соединены с новой вершиной
            }
            else
            {
                smejprom[i][j] = 0;  // новая вершина не связана с остальными вершинами
            }
        }
    }

    (*ver)++;
    smej = new int* [*ver];
    if (smej == NULL)
    {
        cout << "Не удалось выделить память!" << endl;
        return;
    }
    for (i = 0; i < *ver; i++)
    {
        smej[i] = new int[*ver];
    }
    for (i = 0; i < *ver; i++)
    {
        for (j = 0; j < *ver; j++)
        {
            if (i == veri1 && j == *ver - 1 || j == veri1 && i == *ver - 1)  smej[i][j] = 1;
            else smej[i][j] = smejprom[i][j];
        }
    }
    cout << "Резльтат расщепления вершины: " << veri1 + 1 << endl;
    PrintMatrix(*ver, &smej);

    for (int i = 0; i < *ver - 1; i++)
    {
        free(MassSpis[i]);
        MassSpis[i] = NULL;
    }
    MassSpis = new SP * [*ver];
    if (MassSpis == NULL)
    {
        cout << "Не удалось выделить память!" << endl;
        return;
    }
    for (i = 0; i < *ver; i++)
    {
        MassSpis[i] = NULL;
    }
    GeneratSpisok(*ver, MassSpis, smej);
    PrintSpisok(*ver, MassSpis);
    cout << endl;

    for (i = 0; i < newver; i++)
    {
        delete[] smejprom[i];
    }
    delete[] smejprom;

}

void Zad2(int ver1, int ver2, int** smej1, int** smej2, SP** MassSpis1, SP** MassSpis2)
{
    int choice = 0, graf = 0;
    int veri1 = 0, veri2 = 0;
    bool prov1 = true, prov2 = true, prov3 = true;
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
        cout << "1)Отождествление вершин;" << endl;
        cout << "2)Стягивания ребра;" << endl;
        cout << "3)Расщепления вершины;" << endl;
        cout << "4)Вернуться к выбору задания;" << endl;
        cout << "Выберите действие:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            prov1 = true;
            prov2 = true;
            prov3 = true;
            do
            {
                cout << endl;
                cout << "Выберите граф в котором хотите осуществить отождествление вершин(1 или 2):";
                cin >> graf;
                if (graf == 1 || graf == 2)
                    prov1 = false;
                else
                    cout << "Ошибка: неверный ввод номера графа! Повторите попытку." << endl;
            } while (prov1);

            if (graf == 1)
            {
                do
                {
                    cout << "Введите номера вершин, которые хотите отождествить(через пробел):";
                    cin >> veri1 >> veri2;
                    if (veri1 - 1 >= ver1 || veri2 - 1 >= ver1 || veri1 - 1 < 0 || veri2 - 1 < 0 || veri1 == veri2)
                        cout << "Ошибка: неверный ввод номеров вершин! Повторите попытку." << endl;
                    else
                        prov2 = false;
                } while (prov2);

                IdentificationMatrix(smej1, &ver1, veri1 - 1, veri2 - 1, MassSpis1);

            }
            else if (graf == 2)
            {
                do
                {
                    cout << "Введите номера вершин, которые хотите отождествить(через пробел):";
                    cin >> veri1 >> veri2;
                    if (veri1 - 1 >= ver2 || veri2 - 1 >= ver2 || veri1 - 1 < 0 || veri2 - 1 < 0 || veri1 == veri2)
                        cout << "Ошибка: неверный ввод номеров вершин! Повторите попытку." << endl;
                    else
                        prov3 = false;
                } while (prov3);

                IdentificationMatrix(smej2, &ver2, veri1 - 1, veri2 - 1, MassSpis2);
            }
            break;
        case 2:
            prov1 = true;
            prov2 = true;
            prov3 = true;
            veri1 = 0;
            veri2 = 0;
            do
            {
                cout << endl;
                cout << "Выберите граф в котором хотите осуществить стягивание ребра(1 или 2):";
                cin >> graf;
                if (graf == 1 || graf == 2)
                    prov1 = false;
                else
                    cout << "Ошибка: неверный ввод номера графа! Повторите попытку.";
            } while (prov1);
            if (graf == 1)
            {
                do
                {
                    cout << "Введите номера вершин, между которыми надо стянуть ребро(через пробел):";
                    cin >> veri1 >> veri2;
                    if (veri1 - 1 >= ver1 || veri2 - 1 >= ver1 || veri1 - 1 < 0 || veri2 - 1 < 0 || veri1 == veri2)
                        cout << "Ошибка: неверный ввод номеров вершин! Повторите попытку." << endl;
                    else
                        prov2 = false;
                } while (prov2);

                RibTightening(smej1, &ver1, veri1 - 1, veri2 - 1, MassSpis1);

            }
            else if (graf == 2)
            {
                do
                {
                    cout << "Введите номера вершин, между которыми надо стянуть ребро(через пробел):";
                    cin >> veri1 >> veri2;
                    if (veri1 - 1 >= ver2 || veri2 - 1 >= ver2 || veri1 - 1 < 0 || veri2 - 1 < 0 || veri1 == veri2)
                        cout << "Ошибка: неверный ввод номеров вершин! Повторите попытку." << endl;
                    else
                        prov3 = false;
                } while (prov3);

                RibTightening(smej2, &ver2, veri1 - 1, veri2 - 1, MassSpis2);
            }
            break;
        case 3:
            prov1 = true;
            prov2 = true;
            prov3 = true;
            veri1 = 0;
            do
            {
                cout << endl;
                cout << "Выберите граф в котором хотите осуществить расщепление вершины(1 или 2):";
                cin >> graf;
                if (graf == 1 || graf == 2)
                    prov1 = false;
                else
                    cout << "Ошибка: неверный ввод номера графа! Повторите попытку." << endl;
            } while (prov1);
            if (graf == 1)
            {
                do
                {
                    cout << "Введите номер вершины, которую хотите расщепить:";
                    cin >> veri1;
                    if (veri1 - 1 >= ver1 || veri1 - 1 < 0)
                        cout << "Ошибка: неверный ввод номера вершины! Повторите попытку." << endl;
                    else
                        prov2 = false;
                } while (prov2);

                SplittingAVertex(smej1, &ver1, veri1 - 1, MassSpis1);

            }
            else if (graf == 2)
            {
                do
                {
                    cout << "Введите номер вершины, которую хотите расщепить:";
                    cin >> veri1;
                    if (veri1 - 1 >= ver2 || veri1 - 1 < 0)
                        cout << "Ошибка: неверный ввод номера вершины! Повторите попытку." << endl;
                    else
                        prov3 = false;
                } while (prov3);

                SplittingAVertex(smej2, &ver2, veri1 - 1, MassSpis2);
            }
            break;
        case 4:
            break;
            cout << endl;
        default:
            cout << "Неверный выбор! Повторите попытку." << endl;
            break;
        }
    } while (choice != 4);
}