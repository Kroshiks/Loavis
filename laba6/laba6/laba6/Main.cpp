#include "Header.h"
int i, j;

void GeneratMatrix(int ver, int*** smej)
{
    for (i = 0; i < ver; i++)
    {
        for (j = i; j < ver; j++)
        {
            if (i == j)
            {
                (*smej)[i][j] = 0; // �� ������� ��������� ����
            }
            else
            {
                (*smej)[i][j] = rand() % 2; // ��������� �������� 0 ��� 1
                (*smej)[j][i] = (*smej)[i][j]; // ����������� ��������� �������� ��� ������������������ �����
            }
        }
    }
}

void PrintMatrix(int ver, int*** smej)
{
    for (i = 0; i < ver; i++)
    {
        for (j = 0; j < ver; j++)
        {
            cout << setw(3) << (*smej)[i][j];
        }
        cout << endl;
    }
}

//������ � ��������� ���������
void MatrixSmej(int*** smej1, int*** smej2, int ver1, int ver2)
{
    //��������� ������ ��� ������� 1
    *smej1 = new int* [ver1];

    if (*smej1 == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver1; i++)
    {
        (*smej1)[i] = new int[ver1];
    }

    //��������� ������ ��� ������� 2
    *smej2 = new int* [ver2];

    if (*smej2 == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver2; i++)
    {
        (*smej2)[i] = new int[ver2];
    }

    // �������� ������� ��������� 1
    GeneratMatrix(ver1, smej1);

    // �������� ������� ��������� 2
    GeneratMatrix(ver2, smej2);
}

void GeneratSpisok(int ver, SP** MassSpis, int** smej)
{
    for (i = 0; i < ver; i++)
    {
        for (j = 0; j < ver; j++)
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
}

void PrintSpisok(int ver, SP** MassSpis)
{
    for (i = 0; i < ver; i++)
    {
        if (MassSpis[i] == NULL)
        {
            cout << "������� " << i + 1 << " �� ����� �������";
        }
        else
        {
            cout << "������� " << i + 1 << " ������ �:";
            SP* current = MassSpis[i];

            while (current != NULL)
            {
                cout << current->inf << " ";
                current = current->next;
            }
        }
        cout << endl;
    }
   
}

//������ �� �������� ���������
void SpisokSmej(int**& smej1, int**& smej2, int ver1, int ver2, SP**& MassSpis1, SP**& MassSpis2)
{
    //��������� ������ ��� ������ ������� 1
    MassSpis1 = new SP * [ver1];
    if (MassSpis1 == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver1; i++)
    {
        MassSpis1[i] = NULL;
    }

    //��������� ������ ��� ������ ������� 2
    MassSpis2 = new SP * [ver2];
    if (MassSpis2 == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver2; i++)
    {
        MassSpis2[i] = NULL;
    }

    //�������� ������ ��������� 1
    GeneratSpisok(ver1, MassSpis1, smej1);

    //�������� ������ ��������� 2
    GeneratSpisok(ver2, MassSpis2, smej2);
}

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
        cout << "������� ���������� ������ 1-��� �����: ";
        cin >> ver1;
        cout << "������� ���������� ������ 2-��� �����: ";
        cin >> ver2;
        if (ver1 < 0 || ver2 < 0)
            cout << "������: �������� ���� ������� ������! ��������� �������.";
        else
            prov = 0;
    } while (prov);

    MatrixSmej(&smej1, &smej2, ver1, ver2);
    SpisokSmej(smej1, smej2, ver1, ver2, MassSpis1, MassSpis2);

    do
    {
        system("cls");
        // ����� ������� ��������� 1 �� �����
        cout << "������� ��������� 1" << endl;
        PrintMatrix(ver1, &smej1);
        cout << endl;

        // ����� ������� ��������� 2 �� �����
        cout << "������� ��������� 2" << endl;
        PrintMatrix(ver2, &smej2);
        cout << endl;

        //����� ������ ��������� 1
        cout << "������ ��������� 1" << endl;
        PrintSpisok(ver1, MassSpis1);
        cout << endl;

        //����� ������ ��������� 2
        cout << "������ ��������� 2" << endl;
        PrintSpisok(ver2, MassSpis2);
        cout << endl;
        cout << "  �������" << endl;
        cout << "1)������� 2." << endl;
        cout << "2)������� 3 � 4." << endl;
        cout << "3)�����." << endl;
        cout << "�������� ����� �������:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            Zad2(ver1, ver2, smej1, smej2, MassSpis1, MassSpis2);
            break;
        case 2:
            Zad34(ver1, ver2, smej1, smej2, MassSpis1, MassSpis2);
            break;
        case 3:
            break;

            cout << "�� ��������!" << endl;
        default:
            cout << "�������� �����! ��������� �������.";
            break;
        }
    } while (choice != 3);
    for (i = 0; i < ver1; i++)
    {
        delete[] smej1[i];
    }
    delete[] smej1;
    for (i = 0; i < ver2; i++)
    {
        delete[] smej2[i];
    }
    delete[] smej2;
    delete[] MassSpis1;
    delete[] MassSpis2;
}