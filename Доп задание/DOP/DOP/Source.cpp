#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

typedef struct Spis {
    int inf;
    struct Spis* next;
} SP;

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int ver;
    bool prov = true;
    do
    {
        cout << "Ведите количество вершин в графе:";
        cin >> ver;

        if (cin.fail() || ver < 1 || ver > 100) {
           cout << "Некорректный ввод! Введите число от 1 до 100." << std::endl;
            cin.clear(); // Очищаем флаг ошибки ввода
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем весь ввод до символа новой строки
        }
        else prov = false;
    } while (prov);


    // Матрица смежности
    int** smej = new int* [ver];
    if (smej == NULL) 
    {
        cout << "Не удалось выделить память!" << endl;
        return 1;
    }
    for (int i = 0; i < ver; i++)
    {
        smej[i] = new int[ver];
    }

    // Генерация матрицы смежности
    for (int i = 0; i < ver; i++)
    {
        for (int j = i; j < ver; j++)
        {
            if (i == j)
            {
                smej[i][j] = 0;
            }
            else
            {
                smej[i][j] = 0 + rand() % 2;
                if (smej[i][j] == 0)
                {
                    smej[i][j] = 0;
                    smej[j][i] = rand() % 2;
                }
                else
                {
                    smej[j][i] = 0;
                }
            }
        }
    }

    // Вывод матрицы смежности
    cout << "Матрица смежности:" << endl;
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            cout << smej[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int** smejRev = new int* [ver];
    for (int i = 0; i < ver; i++)
    {
        smejRev[i] = new int[ver];
        for (int j = 0; j < ver; j++)
        {
            smejRev[i][j] = smej[i][j]; // Инициализируем как копию исходного графа
        }
    }


    // Массив списков смежности
    SP** MassSpis = new SP * [ver];
    if (MassSpis == NULL)
    {
        cout << "Не удалось выделить память!" << endl;
        return 1;
    }
    for (int i = 0; i < ver; i++)
    {
        MassSpis[i] = NULL;
    }

    SP** MassSpisRev = new SP * [ver];
    if (MassSpisRev == NULL)
    {
        cout << "Не удалось выделить память!" << endl;
        return 1;
    }
    for (int i = 0; i < ver; i++)
    {
        MassSpisRev[i] = NULL;
    }

    // Генерация списка смежности
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            if (smej[i][j] == 1)
            {
                SP* newSP = new SP;
                newSP->inf = j + 1;
                newSP->next = MassSpis[i];
                MassSpis[i] = newSP;
            }
        }
    }

    // Вывод списка смежности
    cout << "Список смежности:" << endl;
    for (int i = 0; i < ver; i++)
    {
        if (MassSpis[i] == NULL)
        {
            cout << "Вершина " << i + 1 << " не имеет смежных";
        }
        else {
            cout << "Вершина " << i + 1 << " смежна с:";
            SP* current = MassSpis[i];
            while (current != NULL)
            {
                cout << current->inf << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

    // Формирование обратного графа
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            if (smej[i][j] == 1) {
                // Изменяем направление ребра при формировании обратного графа
                smejRev[j][i] = 1;
                smejRev[i][j] = 0;
            }
        }
    }

    // Вывод матрицы смежности обратного орграфа
    cout << endl << "Матрица смежности обратного орграфа:" << endl;
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            cout << smejRev[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Генерация списка смежности обратного графа
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            if (smejRev[i][j] == 1)
            {
                SP* newSP = new SP;
                newSP->inf = j + 1;
                newSP->next = MassSpisRev[i];
                MassSpisRev[i] = newSP;
            }
        }
    }

    // Вывод списка смежности обратного графа
    cout << "Список смежности обратного орграфа:" << endl;
    for (int i = 0; i < ver; i++)
    {
        if (MassSpisRev[i] == NULL)
        {
            cout << "Вершина " << i + 1 << " не имеет смежных";
        }
        else
        {
            cout << "Вершина " << i + 1 << " смежна с:";
            SP* current = MassSpisRev[i];
            while (current != NULL)
            {
                cout << current->inf << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

    // Освобождение памяти
    delete[] MassSpis;
    delete[] MassSpisRev;
    for (int i = 0; i < ver; i++)
    {
        delete[] smejRev[i];
    }
    delete[] smejRev;
    for (int i = 0; i < ver; i++)
    {
        delete[] smej[i];
    }
    delete[] smej;
}