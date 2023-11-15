#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <iomanip>

using namespace std;

int i, j;

typedef struct GraphSettings {
    int weighted;  // 1, ���� ���� ����������, ����� 0
    int orientation;  // 1, ���� ���� ���������������, ����� 0
} GS;

GS values(int argc, char* argv[])
{
    GS val = { 1,1 };

    for (i = 1; i < argc; i++) 
    {
        if (strcmp(argv[i], "-w") == 0) 
        {
            val.weighted = 1;
        }
        else if (strcmp(argv[i], "-o") == 0) 
        {
            val.orientation = 1;
        }
    }

    return val;
}
void SearchDist(int** smej, int* visit, int ver, int ver1, int* dist)
{
    int newdist = 0;
    queue<int> q;  // ������ �������
    visit[ver1 - 1] = 0;
    dist[ver1 - 1] = 0;
        q.push(ver1);
    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();
        for (int i = 0; i < ver; i++) 
        {
           
            if (smej[current - 1][i] > 0 && visit[i] == -1)
            {
                newdist = dist[current - 1] + smej[current - 1][i];
                if (newdist < dist[i])
                {
                    dist[i] = newdist;
                    visit[i] = current;
                    q.push(i + 1);
                }
            }
        }
    }
}

void SearchPadAndDiam(int** smej, int* visit, int ver, int ver1)
{
    queue<int> Q;  // ������ �������
    visit[ver1] = 0;
   
    Q.push(ver1);
    while (!Q.empty())
    {
        int current = Q.front();
        Q.pop();
        for (i = 0; i < ver; i++)
        {
            if (smej[current][i] > 0 && visit[i] == -1)
            {
                visit[i] = visit[current] + smej[current][i];             
                    Q.push(i);
            }
        }
    }
}
void main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    GS gs = values(argc, argv);
    int** smej = 0; 
    int* visit = 0;  
    int* dist = 0;
    int* eksen = 0;
    int choice, ver, ver1, k = 0, first = 0, MaxDist = 0, D = 0, R = 0;
    bool  prov1 = true;

    cout << "������� ���������� ������ �����: ";
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
                if (gs.weighted == 1 && gs.orientation == 1)
                {
                    smej[i][j] = (-9) + rand() % 19; 
                    if (smej[i][j] < 0)
                    {
                        smej[i][j] = 0;
                        smej[j][i] = rand() % 10;
                    }
                    else  smej[j][i] = 0;

                }
                else if (gs.weighted == 0 && gs.orientation == 1)
                {
                    smej[i][j] = (-1) + rand() % 3;
                    if (smej[i][j] <0)
                    {
                        smej[i][j] = 0;
                        smej[j][i] = rand() % 2;
                    }
                    else  smej[j][i] = 0;
                }
                else if (gs.weighted == 1 && gs.orientation == 0)
                {
                    smej[i][j] = rand() % 10;
                    smej[j][i] = smej[i][j];
                }
                else if (gs.weighted == 0 && gs.orientation == 0)
                {
                    smej[i][j] = rand() % 2;
                    smej[j][i] = smej[i][j];
                }
            }
        }
    }

    //����� ������� ���������
    cout << "�������:" << endl;
    for (i = 0; i < ver; i++)
    {
        for (j = 0; j < ver; j++)
        {
            cout << setw(3) << smej[i][j];
        }
        cout << endl;
    }
    cout << endl;
    do
    {
        cout << endl;
        cout << "1)����� ���������� ����� ���������." << endl;
        cout << "2)���������� ������� � ��������, ����� ����������� ����������� � ������������ ������." << endl;
        cout << "3)�����." << endl;
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
                visit[i] = -1;
            }
            dist = new int[ver];
            if (dist == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++)
            {
                dist[i] = INT_MAX;
            }

            do
            {
                cout << endl;
                cout << "������� �������, � ������� ������ ������ ����� ����������:";
                cin >> ver1;

                if (ver1 < 1 || ver1 > ver) cout << "������������ ����� �������! ��������� �������." << endl;
                else
                {
                    for (i = 0; i < ver; i++)
                    {
                        if (smej[ver1 - 1][i] != 0 || smej[i][ver1 - 1] != 0)
                        {

                            k++;
                        }
                    }
                    if (k == 0)
                        cout << "������� " << ver1 << " �������������! ������� ������ ��������� �������." << endl;
                    else
                        prov1 = false;
                }
                    
            } while (prov1);

            cout << "����� ���������� ��� ��������!" << endl;
            SearchDist(smej, visit, ver, ver1, dist);
            for (i = 0; i < ver; i++)
            {
                if (dist[i] == INT_MAX)
                    cout << "������� " << ver1 << " �� ����� ����  � ������� " << i + 1 << endl;
                else
                    cout << "����������� ���������� �� ������� " << ver1 << " �� ������� " << i + 1 << " = " << dist[i] << endl;
            }
            cout << endl;
            delete[] dist;
            delete[] visit;
            break;
        case 2:
            D = INT_MIN;
            R = INT_MAX;
            visit = new int[ver];
            if (visit == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }                 
            eksen = new int[ver];
            if (eksen == NULL)
            {
                cout << "�� ������� �������� ������!" << endl;
                return;
            }
            for (i = 0; i < ver; i++)
            {
                eksen[i] = 0;
            }
            for (first = 0; first < ver; first++)
            {
                for (i = 0; i < ver; i++)
                {
                    visit[i] = -1;
                }
               
                SearchPadAndDiam(smej,visit, ver, first);
                MaxDist = 0;
                for (i = 0; i < ver; i++)
                {
                    if (visit[i] > MaxDist)
                    {
                        MaxDist = visit[i];
                    }                  
                }              
                eksen[first] = MaxDist;
                cout << first + 1 << ") " << eksen[first]<< endl;
                
            }        
           for (i = 0; i < ver; i++) 
            {
                if (eksen[i] > D)
                {
                    D = eksen[i];
                }
            }
           R = D;
            for (i = 0; i < ver; i++)
            {
                if (eksen[i] < R)
                {
                    R = eksen[i];
                }
            }
            cout << endl << "������ �����:" << R << endl;
            cout << "������� �����:" << D << endl;       
            cout  << "����������� �������";
            for (i = 0; i < ver; i++) 
            {
                if (eksen[i] == R)
                {
                    cout << " " << i + 1;
                }
              
            }         
            cout << endl << "������������ �������";
            for (i = 0; i < ver; i++) 
            {
                if (eksen[i] == D)
                {
                    cout << " " << i + 1;
                }
            }    
            cout << endl;
            delete[] dist;
            delete[] visit;
            delete[] eksen;
            break;
        case 3:
            system("cls");
            cout << "�� ��������!";
            break;
        default:
            cout << endl;
            cout << "�������� �����! ��������� �������.";
            cout << endl;

            break;
        }
    } while (choice != 3);

    for (i = 0; i < ver; i++)
    {
        delete[] smej[i];
    }
    delete[] smej;
    
}


