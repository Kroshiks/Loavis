#include "Header.h"
int i, j;

void main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** smej1 = 0; //1 ������� ���������
    int** smej2 = 0; //2 ������� ���������
    int ver1, ver2, choice;
    bool prov = 1;

    SP** MassSpis1 = NULL;//������ ������� ��������� 1
    SP** MassSpis2 = NULL;//������ ������� ��������� 2

    do
    {
        cout << "  �������" << endl;
        cout << "1)������� 1." << endl;
        cout << "2)������� 2." << endl;
        cout << "3)������� 3." << endl;
        cout << "4)������� 4." << endl;
        cout << "5)�����." << endl;
        cout << "�������� ����� �������:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "������� 1" << endl;
            do
            {
                cout << "������� ���������� ������ 1-��� �����: ";
                cin >> ver1;
                cout << "������� ���������� ������ 2-��� �����: ";
                cin >> ver2;
                if (ver1 < 0 || ver2 < 0)
                    cout << "������: �������� ���� ������� ������! ��������� �������.";
                else
                    prov = 0;
            } while (prov);

            Zad1(smej1, smej2, ver1, ver2, MassSpis1, MassSpis2);
            break;

        case 2:
            cout << "������� 2" << endl;
            Zad2(ver1,ver2, smej1);
        }
    } while (choice != 5);
}