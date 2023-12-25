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
        cout << "������ ���������� ������ � �����:";
        cin >> ver;

        if (cin.fail() || ver < 1 || ver > 100) {
           cout << "������������ ����! ������� ����� �� 1 �� 100." << std::endl;
            cin.clear(); // ������� ���� ������ �����
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ���� ���� �� ������� ����� ������
        }
        else prov = false;
    } while (prov);


    // ������� ���������
    int** smej = new int* [ver];
    if (smej == NULL) 
    {
        cout << "�� ������� �������� ������!" << endl;
        return 1;
    }
    for (int i = 0; i < ver; i++)
    {
        smej[i] = new int[ver];
    }

    // ��������� ������� ���������
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

    // ����� ������� ���������
    cout << "������� ���������:" << endl;
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
            smejRev[i][j] = smej[i][j]; // �������������� ��� ����� ��������� �����
        }
    }


    // ������ ������� ���������
    SP** MassSpis = new SP * [ver];
    if (MassSpis == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return 1;
    }
    for (int i = 0; i < ver; i++)
    {
        MassSpis[i] = NULL;
    }

    SP** MassSpisRev = new SP * [ver];
    if (MassSpisRev == NULL)
    {
        cout << "�� ������� �������� ������!" << endl;
        return 1;
    }
    for (int i = 0; i < ver; i++)
    {
        MassSpisRev[i] = NULL;
    }

    // ��������� ������ ���������
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

    // ����� ������ ���������
    cout << "������ ���������:" << endl;
    for (int i = 0; i < ver; i++)
    {
        if (MassSpis[i] == NULL)
        {
            cout << "������� " << i + 1 << " �� ����� �������";
        }
        else {
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

    // ������������ ��������� �����
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            if (smej[i][j] == 1) {
                // �������� ����������� ����� ��� ������������ ��������� �����
                smejRev[j][i] = 1;
                smejRev[i][j] = 0;
            }
        }
    }

    // ����� ������� ��������� ��������� �������
    cout << endl << "������� ��������� ��������� �������:" << endl;
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            cout << smejRev[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // ��������� ������ ��������� ��������� �����
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

    // ����� ������ ��������� ��������� �����
    cout << "������ ��������� ��������� �������:" << endl;
    for (int i = 0; i < ver; i++)
    {
        if (MassSpisRev[i] == NULL)
        {
            cout << "������� " << i + 1 << " �� ����� �������";
        }
        else
        {
            cout << "������� " << i + 1 << " ������ �:";
            SP* current = MassSpisRev[i];
            while (current != NULL)
            {
                cout << current->inf << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

    // ������������ ������
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