#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** smej = 0; // ������� ���������
    int** inc = 0; // ������� �������������
    int i, j, ver, k, Count = 0, g;
    
    cout << "������� ���������� ������ �����: ";
    cin >> ver;
   
    smej = new int* [ver];
    if (ver == NULL) 
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver; i++) 
    {
        smej[i] = new int[ver];
    }
   
    // ������������ ��������� �������� ��� ������� ���������
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

    // �������� ������� ��������� �� �����
    cout << "������� ���������:" << endl;
   
    for (i = 0; i < ver; i++) 
    {
        for (j = 0; j < ver; j++) 
        {
            cout << smej[i][j] << " ";
        }
        cout << endl;
    }
   
    //������� �����
    for (i = 0; i < ver; i++) 
    {
        for (j = i + 1; j < ver; j++) 
        {
            if (smej[i][j] == 1) 
            {
                Count++;
            }
        }
    }

    //������ �� �������� 
    cout << "������ ����� �����: " << Count << endl;

    int* A = 0;
    A = new int[ver];
    for (i = 0; i < ver; i++)
    {
        A[i] = 0;
        for (j = 0; j < ver; j++)
        {
            if (smej[i][j] == 1)
            {
                A[i]++;
            }
        }
       
        if (A[i] == 1)
        {
            cout << i + 1 << "-�� ������� - ��������" << endl;
        }
        else if (A[i] == ver - 1)
        {
            cout << i + 1 << "-�� ������� - ������������" << endl;
        }
        else if (A[i] == 0)
        {
            cout << i + 1 << "-�� ������� - �������������" << endl;
        }
    }
    delete[] A;

    //��������� ������
    inc = new int* [ver];
    if (inc == NULL) 
    {
        cout << "�� ������� �������� ������!" << endl;
        return;
    }
    for (i = 0; i < ver; i++) 
    {
        inc[i] = new int[Count];
    }

    g = Count;
   
    // ���������� ������� �������������
    Count = 0;
    for (i = 0; i < ver; i++) 
    {
        for (j = i + 1; j < ver; j++) 
        {
            if (smej[i][j] == 1) 
            {
                for (k = 0; k < ver; k++) 
                {
                    if (k == i || k == j) 
                    {
                        inc[k][Count] = 1;
                    }
                    else 
                    {
                        inc[k][Count] = 0;
                    }
                }
                Count++;
            }
        }
    }
   
    // ����� ������� ������������� �� �����
    cout << "������� �������������:" << endl;
    
    for (i = 0; i < ver; i++) 
    {
        for (j = 0; j < Count; j++) 
        {
            cout << inc[i][j] << " ";
        }
        cout << endl;
    }

    //������ �� ��������
    cout << "������ ����� �����: " << Count << endl;
    
    int* Ar;
    Ar = new int[ver];
   
    for (i = 0; i < ver; i++) 
    {
        Ar[i] = 0;
        for (j = 0; j < g; j++) 
        {
            if (inc[i][j] == 1)
                Ar[i]++;
        }
        
        if (Ar[i] == 1)
        {
            cout << i + 1 << "-�� ������� - ��������" << endl;
        }
        else if (Ar[i] == ver - 1)
        {
            cout << i + 1 << "-�� ������� - ������������" << endl;
        }
        else if (Ar[i] == 0)
        {
            cout << i + 1 << "-�� ������� - �������������" << endl;
        }
    }

    delete[] Ar;

    // ������������ ������
    for (i = 0; i < ver; i++)
    {
        delete[] smej[i];
        delete[] inc[i];
    }
    delete[] smej;
    delete[] inc;
}