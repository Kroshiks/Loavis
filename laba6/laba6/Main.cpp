#include "Header.h"
int i, j;

void main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** smej1 = 0; //1 матрица смежности
    int** smej2 = 0; //2 матрица смежности
    int ver1, ver2, choice;
    bool prov = 1;

    SP** MassSpis1 = NULL;//Массив списков смежности 1
    SP** MassSpis2 = NULL;//Массив списков смежности 2

    do
    {
        cout << "  ЗАДАНИЯ" << endl;
        cout << "1)Задание 1." << endl;
        cout << "2)Задание 2." << endl;
        cout << "3)Задание 3." << endl;
        cout << "4)Задание 4." << endl;
        cout << "5)Выход." << endl;
        cout << "Выберите номер задания:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "Задание 1" << endl;
            do
            {
                cout << "Введите количество вершин 1-ого графа: ";
                cin >> ver1;
                cout << "Введите количество вершин 2-ого графа: ";
                cin >> ver2;
                if (ver1 < 0 || ver2 < 0)
                    cout << "Ошибка: неверный ввод номеров вершин! Повторите попытку.";
                else
                    prov = 0;
            } while (prov);

            Zad1(smej1, smej2, ver1, ver2, MassSpis1, MassSpis2);
            break;

        case 2:
            cout << "Задание 2" << endl;
            Zad2(ver1,ver2, smej1);
        }
    } while (choice != 5);
}