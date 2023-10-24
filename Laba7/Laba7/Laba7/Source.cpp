#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

typedef struct Spis {
    int inf;
    struct Spis* next;
}SP;

int i, j, ver;

void BypassMatrix(int** smej,int ver1, int* visit, int ver )
{
    visit[ver1] = 1; // �������� ������� ������� ��� ����������
    cout << ver1 + 1 << " ";

    for (int i = 0; i < ver; i++) 
    {
        if (smej[ver1][i] == 1 && visit[i] !=1) 
        {
            BypassMatrix(smej, i, visit, ver);
        }
    }
}

void BypassSpisok(SP** MassSpis, int ver2, int* visit)
{
    visit[ver2] = 1; // �������� ������� ������� ��� ����������
    cout << ver2 + 1 << " ";

    SP* current = MassSpis[ver2];
    while (current != NULL) 
    {
        int temp = current->inf;
        if (!visit[--temp])
        {
            BypassSpisok(MassSpis, temp, visit);
        }
        current = current->next;
    }
}

void BypassNoRek(int** smej, int* visit, int ver3, int ver) 
{
    int* stack = new int[ver]; // ����
    int top = -1; // ������� �����
    stack[++top] = ver3; // �������� ��������� ������� � ����

    while (top != -1) {
        int temp = stack[top--]; // ��������� ������� �� �����

        if (visit[temp] != 1)
        {
            visit[temp] = 1; // �������� ������� ��� ����������
            printf("%d ", temp + 1); // ������� �������
            for (int i = ver - 1; i >= 0; i--) 
            {
                if (smej[temp][i] == 1 && visit[i] != 1) 
                {
                    stack[++top] = i; // �������� ������� ������������ ������� � ����
                }
            }
        }
    }
    delete[] stack;
}



void main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** smej = 0; //������� ���������
    int choice, ver1, ver2, ver3;
    SP** MassSpis = NULL;//������ ������� ��������� 
    int* visit = 0;
    bool  prov1 = 1, prov2=1, prov3=1;

    cout << "������� ���������� ������ 1-��� �����: ";
    cin >> ver;
    cout << endl;

    //��������� ������ ��� ������ ���������
    smej = new int* [ver];
    if (smej == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver; i++)
    {
        smej[i] = new int[ver];
    }

    //��������� ������ ��� ������ �������
    MassSpis = new SP* [ver];
    if (MassSpis == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver; i++)
    {
        MassSpis[i] = NULL;
    }

    //��������� ������� ���������
    for (i = 0; i < ver; i++)
    {
        for (j = i; j < ver; j++)
        {
            if (i == j)
            {
                smej[i][j] = 0; // �� ������� ��������� ����
            }
            else
            {
                smej[i][j] = rand() % 2; // ��������� �������� 0 ��� 1
                smej[j][i] = smej[i][j]; // ����������� ��������� �������� ��� ������������������ �����
            }
        }
    }

    //��������� ������ ���������
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

    //����� ������� ���������
    cout << "������� ���������:" << endl;
    for (i = 0; i < ver; i++)
    {
        for (j = 0; j < ver; j++)
        {
            cout << smej[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //����� ������ ���������
    cout << "������ ���������:" << endl;
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

    do
    {
        cout << endl;
        cout << "1)����� ����� � ������� � ������� ������� ���������." << endl;
        cout << "2)����� ����� � ������� � ������� ������ ���������." << endl;
        cout << "3)����� ����� � �������, �� ��������� ��������." << endl;
        cout << "4)�����." << endl;
        cout << "�������� ��������:";
        cin >> choice; 
        switch (choice)
        {
        case 1:
            visit = new int[ver];
            if (visit == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++) 
            {
                visit[i] = 0;
            }

            do
            {
                cout << endl;
                cout << "������� �������, � ������� ������ ������:";
                cin >> ver1;

                if (ver1 < 1 || ver1 > ver)
                    printf("������������ ����� �������! ��������� �������.\n");
                else
                    prov1 = 0;
            } while (prov1);

            cout << "����� ����� � ������ ������� ��������� ��� ��������!" << endl;
            cout << "���������:";
            BypassMatrix(smej, ver1 - 1, visit, ver);  
            cout << endl;
            delete[] visit;
            break;
        case 2:
            visit = new int[ver];
            if (visit == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++)
            {
                visit[i] = 0;
            }

            do
            {
                cout << endl;
                cout << "������� �������, � ������� ������ ������:";
                cin >> ver2;

                if (ver2 < 1 || ver2 > ver)
                    printf("������������ ����� �������! ��������� �������.\n");
                else
                    prov2 = 0;
            } while (prov2);

            cout << "����� ����� � ������ ������ ��������� ��� ��������!" << endl;
            cout << "���������:";
            BypassSpisok(MassSpis, ver2 - 1, visit);
            cout << endl;
            delete[] visit;
            break;
        case 3:
            visit = new int[ver];
            if (visit == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++)
            {
                visit[i] = 0;
            }

            do
            {
                cout << endl;
                cout << "������� �������, � ������� ������ ������:";
                cin >> ver3;

                if (ver3 < 1 || ver3 > ver)
                    printf("������������ ����� �������! ��������� �������.\n");
                else
                    prov3 = 0;
            } while (prov3);

            cout << "����� ����� ��� �������� ��� ��������!" << endl;
            cout << "���������:";
            BypassNoRek(smej,visit,ver3,ver);
            cout << endl;
            delete[] visit;
            break;
        case 4:
            system("cls");
            cout << "�� ��������!";
            break;

        default:
            cout << endl;
            cout << "�������� �����! ��������� �������.";
            cout << endl;
            break;
        }
    } while (choice != 4);

    delete[] MassSpis;
    for (i = 0; i < ver; i++)
    {
        delete[] smej[i];  
    }
    delete[] smej;
}