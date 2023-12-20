#include <vector>
#include <iostream>
#include <ctime>
#include <locale>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct Spis
{
	int inf;
	struct Spis* next;
}SP;

//�������� ������ ���������
void GeneratSpisok(int ver, vector<SP*>& masSP, vector<vector<int>>& graf)
{
	for (int i = 0; i < ver; i++)
	{
		for (int j = 0; j < ver; j++)
		{
			if (graf[i][j] == 1)
			{
				SP* newSP = new SP;
				newSP->inf = j + 1;
				newSP->next = masSP[i];
				masSP[i] = newSP;
			}
		}
	}
}

//����� ������ ���������
void PrintSpisok(int ver, vector<SP*>& masSP)
{
	for (int i = 0; i < ver; i++)
	{
		if (masSP[i] == NULL)
		{
			cout << "������� " << i + 1 << " �� ����� �������";
		}
		else
		{
			cout << "������� " << i + 1 << " ������ �:";
			SP* current = masSP[i];

			while (current != NULL)
			{
				cout << current->inf << " ";
				current = current->next;
			}
		}
		cout << endl;
	}

}

//����� ������� ��������� ��� �����
void print(const vector<vector<int>>& graf)
{
	for (const auto& znach1 : graf)//auto-������������� ���������� ���
	{
		for (int znach2 : znach1)
		{
			cout << setw(3) << znach2;
		}
		cout << endl;
	}
}

//������� �������������
void paintGraph(vector<vector<int>>& graf, vector<int> colors, int ver, vector<SP*>& masSP)
{
	ofstream outputFile;
	vector<pair<int, int>> degrees;//������ ���(�������, �����)
	for (int i = 0; i < ver; i++)
	{
		int degree = 0;
		for (int j = 0; j < ver; j++)
		{
			degree += graf[i][j];
		}
		degrees.push_back(make_pair(degree, i));//������� ������� � �����
	}	
	sort(degrees.rbegin(), degrees.rend());//��������� ������ �� �������(�� ���������� �� �����������)
	
	colors.assign(ver, 0);//��������� ������ ������ ������

	int r = 1; //��������� ����	
	for(int k = 0; k<ver; k++)
	{
		int u = degrees[k].second;//������� ������ �������

		//�������� ������ ������� ������
		vector<bool> usedCol(r + 1, false);
		for (int j = 0; j < ver; ++j) 
		{
			if (graf[u][j] && colors[j] > 0) 
			{
				usedCol[colors[j]] = true;
			}
		}
		
		//������� ����������� ���������� ����
		int minCol;
		for (minCol = 1; minCol <= r; ++minCol) 
		{
			if (!usedCol[minCol]) 
			{
				break;
			}
		}
		if (minCol > r) 
		{
			r++;
			colors[u] = r;
		}
		else colors[u] = minCol;			
	}	
	for (int i = 0; i < ver; ++i)
	{
		cout << "������� " << i + 1 << " �������� � ����: " << colors[i] << endl;
	}
	
	//�������� �����
	outputFile.open("rez.txt" , ios::out);
	if (!outputFile.is_open())
	{
		cout << "������ �������� �����!������ �� ���� �������� � ���� rez.txt. ���������  �������,�������� ����. ������� ����� �������..." << endl;
		_getch();
		return;
	}

	//������ ����� � ����
	for (const auto& znach1 : graf)
	{
		for (int znach2 : znach1)
		{
			outputFile << setw(3) << znach2;
		}
		outputFile << endl;
	}
	outputFile << endl;

	//������ ������ ��������� � ����
	for (int i = 0; i < ver; i++)
	{
		if (masSP[i] == NULL)
		{
			outputFile << "������� " << i + 1 << " �� ����� �������" << endl;
		}
		else {
			outputFile << "������� " << i + 1 << " ������ �: ";
			SP* current = masSP[i];

			while (current != NULL) 
			{
				outputFile << current->inf << " ";
				current = current->next;
			}
			outputFile << endl;
		}
	}
	outputFile << endl;

	//������ ������� ����� � ����
	for (int i = 0; i < ver; ++i)
	{
		outputFile << "������� " << i + 1 << " �������� � ����: " << colors[i] << endl;
	}
	outputFile.close();
	cout << endl << "������ ������� �������� � ���� rez.txt.";
}
void menu(vector<vector<int>>& graf)
{
	int choice;
	int ver = graf.size();
	vector<int> colors(ver);
	vector<SP*> masSP(ver);
	ofstream outputFile;
	do
	{
		system("cls");
		cout << setw(10) << "����." << endl;
		cout << "1.�������� �����." << endl;
		cout << "2.���������� ����." << endl;
		cout << "3.�������� ���� � ����(input.txt) ��� ����������� �������������." << endl;
		cout << "4.��������� � �������� �����." << endl;
		cout << "5.�����." << endl;
		cout << "�������� ��������:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "������� ��������� ��� �����:" << endl;
			print(graf);
			cout << endl;
			masSP.resize(ver);
			GeneratSpisok(ver, masSP, graf);
			PrintSpisok(ver, masSP);
			_getch();
			break;
		case 2:
			system("cls");
			cout << "������� ��������� ��� �����:" << endl;
			print(graf);
			cout << endl;
			masSP.resize(ver);
			GeneratSpisok(ver, masSP, graf);
			PrintSpisok(ver, masSP);
			cout << endl;
			paintGraph(graf, colors, ver, masSP);
			_getch();
			break;
		case 3:
			system("cls");
			outputFile.open("input.txt");
			if (!outputFile.is_open())
			{
				cout << "������ �������� �����! ���������  �������, �������� ����. ������� ����� �������..." << endl;
				_getch();
				break;
			}
			for (const auto& znach1 : graf) 
			{
				for (int znach2: znach1)
				{
					outputFile << setw(3) << znach2;
				}
				outputFile << endl;
			}
			outputFile.close();
			cout << "���� ������� ������� � ����." << endl << "������� ����� �������...";
			_getch();
			break;
		case 4:
			return;
		case 5:
			system("cls");
			cout << "�� ��������!";
			exit(0);
		default:
			cout << endl;
			cout << "�������� �����! ��������� �������.";
			cout << endl;
			break;
		}
	} while (choice != 5);
}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "\n" << setw(90) << "�������� ������" << endl << setw(105) << "����: ���������� ��������� ������������� �����" << setw(90) << endl << "\n\n\n" << setw(105) << "��������: ��. ��. 22���1" << endl << setw(104) << "�������� �.�.";
	int choice, ver;
	bool prov = true, prov1 = true;
	string str;
	vector<vector<int>> graf;
	vector<SP*> masSP;
	ifstream inputFile;
	_getch();
	do
	{
		system("cls");
		cout << setw(17) << "�������� �����." << endl;
		cout << "1.������� ���� ��������� �������." << endl;
		cout << "2.������ ���� � ������." << endl;
		cout << "3.����������� ���� �� �����(input.txt)." << endl;
		cout << "4.�����" << endl;
		cout << "�������� ��������:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			graf.clear();
			masSP.clear();
			do
			{
				cout << "������ ���������� ������ � �����:";
				cin >> ver;

				if (ver < 1) cout << "������������ ����� �������! ��������� �������." << endl << endl;
				else prov1 = false;			
			} while (prov1);

			graf.resize(ver);
			for (int i = 0; i < ver; i++)
			{
				graf[i].resize(ver);
			}
			for (int i = 0; i < ver; i++)
			{
				for (int j = i; j < ver; j++)
				{
					if (i == j) graf[i][j] = 0;
					else
					{
						graf[i][j] = rand() % 2;
						graf[j][i] = graf[i][j];
					}
				}
			}
			cout << "������� ��������� ��� �����:" << endl;
			print(graf);
			cout << endl;
			masSP.resize(ver);
			GeneratSpisok(ver, masSP, graf);
			PrintSpisok(ver,masSP);
			_getch();
			menu(graf);
			break;
		case 2:
			system("cls");
			graf.clear();
			masSP.clear();
			do
			{
				cout << "������ ���������� ������ � �����:";
				cin >> ver;

				if (ver < 1) cout << "������������ ����� �������! ��������� �������." << endl << endl;
				else prov1 = false;
			} while (prov1);

			graf.resize(ver);
			for (int i = 0; i < ver; i++)
			{
				graf[i].resize(ver);
			}
			for (int i = 0; i < ver; i++)
			{
				for (int j = i; j < ver; j++)
				{
					if (i == j) graf[i][j] = 0;
					else
					{
						do
						{
							cout << "������� ��������(1 ��� 0) ��� �������� " << i << "X" << j << ":";
							cin >> graf[i][j];
							if (graf[i][j] == 1 || graf[i][j] == 0) prov = false;
							else cout << "�������� ����! ��������� �������." << endl;
						} while (prov);
						graf[j][i] = graf[i][j];
					}
				}
			}
			cout << "������� ��������� ��� �����:" << endl;
			print(graf);
			cout << endl;
			masSP.resize(ver);
			GeneratSpisok(ver, masSP, graf);
			PrintSpisok(ver, masSP);
			_getch();
			menu(graf);
			break;
		case 3:
			system("cls");
			graf.clear();
			masSP.clear();
			inputFile.open("input.txt");
			if (!inputFile.is_open())
			{
				cout << "������ �������� �����! ���������  �������, �������� ����. ������� ����� �������..." << endl;
				_getch();
				break;
			}
			//�������� ����� �� ������� ������
			if (inputFile.peek() == EOF)
			{
				cout << "���� ����! ���������  �������, ������� ������ � ����. ������� ����� �������..." << endl;
				_getch();
				break;
			}

			while (getline(inputFile, str)) //���� ���� ������. � ������� getline ��������� ������ ����
			{
				vector<int> znach1;
				for (char znach2 : str)
				{
					if (znach2 == '0' || znach2 == '1' || znach2 == ' ')
					{
						if (znach2 == '0' || znach2 == '1')
							znach1.push_back(znach2 - '0');//������ ����� ��� ����� �������
					}
					else
					{
						cout << "������ ������ �� �����! ���������  �������, �������� ������ � �����." << endl << "������, ��� ���� ����������������� � ������������." << endl << "������� ����� �������...";
						_getch();
						goto EndCase3;
					}			
				}	
				graf.push_back(znach1);//����� ������� ������������ � ������ �������
			}
			inputFile.close();
			cout << "���� ������� ����������!" << endl;
			cout << "������� ��������� ��� �����:" << endl;
			print(graf);
			ver = graf.size();
			cout << endl;
			masSP.resize(ver);
			GeneratSpisok(ver, masSP, graf);
			PrintSpisok(ver, masSP);
			_getch();
			menu(graf);
			break;
		EndCase3:
			inputFile.close();
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
}