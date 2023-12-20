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

//создание списка смежности
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

//вывод списка смежности
void PrintSpisok(int ver, vector<SP*>& masSP)
{
	for (int i = 0; i < ver; i++)
	{
		if (masSP[i] == NULL)
		{
			cout << "Вершина " << i + 1 << " не имеет смежных";
		}
		else
		{
			cout << "Вершина " << i + 1 << " смежна с:";
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

//вывод матрицы смежности для графа
void print(const vector<vector<int>>& graf)
{
	for (const auto& znach1 : graf)//auto-автомотически определяет тип
	{
		for (int znach2 : znach1)
		{
			cout << setw(3) << znach2;
		}
		cout << endl;
	}
}

//функция раскрашивания
void paintGraph(vector<vector<int>>& graf, vector<int> colors, int ver, vector<SP*>& masSP)
{
	ofstream outputFile;
	vector<pair<int, int>> degrees;//вектор пар(степень, номер)
	for (int i = 0; i < ver; i++)
	{
		int degree = 0;
		for (int j = 0; j < ver; j++)
		{
			degree += graf[i][j];
		}
		degrees.push_back(make_pair(degree, i));//заносим степень и номер
	}	
	sort(degrees.rbegin(), degrees.rend());//сортируем вектор по степени(от наибольшей до минимальной)
	
	colors.assign(ver, 0);//заполняем вектор цветов нулями

	int r = 1; //начальный цвет	
	for(int k = 0; k<ver; k++)
	{
		int u = degrees[k].second;//заносим индекс вершины

		//проверка цветов смежных вершин
		vector<bool> usedCol(r + 1, false);
		for (int j = 0; j < ver; ++j) 
		{
			if (graf[u][j] && colors[j] > 0) 
			{
				usedCol[colors[j]] = true;
			}
		}
		
		//находим минимальный допустимый цвет
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
		cout << "Вершина " << i + 1 << " окрашена в цвет: " << colors[i] << endl;
	}
	
	//открытие файла
	outputFile.open("rez.txt" , ios::out);
	if (!outputFile.is_open())
	{
		cout << "Ошибка открытия файла!Данные не были записаны в файл rez.txt. Повторите  попытку,исправив файл. Нажмите любую клавишу..." << endl;
		_getch();
		return;
	}

	//запись графа в файл
	for (const auto& znach1 : graf)
	{
		for (int znach2 : znach1)
		{
			outputFile << setw(3) << znach2;
		}
		outputFile << endl;
	}
	outputFile << endl;

	//запись списка смежности в файл
	for (int i = 0; i < ver; i++)
	{
		if (masSP[i] == NULL)
		{
			outputFile << "Вершина " << i + 1 << " не имеет смежных" << endl;
		}
		else {
			outputFile << "Вершина " << i + 1 << " смежна с: ";
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

	//запись окраски графа в файл
	for (int i = 0; i < ver; ++i)
	{
		outputFile << "Вершина " << i + 1 << " окрашена в цвет: " << colors[i] << endl;
	}
	outputFile.close();
	cout << endl << "Данные успешно записаны в файл rez.txt.";
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
		cout << setw(10) << "Меню." << endl;
		cout << "1.Просмотр графа." << endl;
		cout << "2.Раскрасить граф." << endl;
		cout << "3.Записать граф в файл(input.txt) для дальнейшего использования." << endl;
		cout << "4.Вернуться к созданию графа." << endl;
		cout << "5.Выход." << endl;
		cout << "Выберите действие:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Матрица смежности для графа:" << endl;
			print(graf);
			cout << endl;
			masSP.resize(ver);
			GeneratSpisok(ver, masSP, graf);
			PrintSpisok(ver, masSP);
			_getch();
			break;
		case 2:
			system("cls");
			cout << "Матрица смежности для графа:" << endl;
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
				cout << "Ошибка открытия файла! Повторите  попытку, исправив файл. Нажмите любую клавишу..." << endl;
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
			cout << "Граф успешно записан в файл." << endl << "Нажмите любую клавишу...";
			_getch();
			break;
		case 4:
			return;
		case 5:
			system("cls");
			cout << "До свидания!";
			exit(0);
		default:
			cout << endl;
			cout << "Неверный выбор! Повторите попытку.";
			cout << endl;
			break;
		}
	} while (choice != 5);
}

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	cout << "\n" << setw(90) << "Курсовая работа" << endl << setw(105) << "Тема: реализация алгоритма раскрашивания графа" << setw(90) << endl << "\n\n\n" << setw(105) << "Выполнил: ст. гр. 22ВВВ1" << endl << setw(104) << "Николаев А.А.";
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
		cout << setw(17) << "Создание графа." << endl;
		cout << "1.Создать граф случайным образом." << endl;
		cout << "2.Задать граф в ручную." << endl;
		cout << "3.Скопировать граф из файла(input.txt)." << endl;
		cout << "4.Выход" << endl;
		cout << "Выберите действие:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			graf.clear();
			masSP.clear();
			do
			{
				cout << "Ведите количество вершин в графе:";
				cin >> ver;

				if (ver < 1) cout << "Некорректный номер вершины! Повторите попытку." << endl << endl;
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
			cout << "Матрица смежности для графа:" << endl;
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
				cout << "Ведите количество вершин в графе:";
				cin >> ver;

				if (ver < 1) cout << "Некорректный номер вершины! Повторите попытку." << endl << endl;
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
							cout << "Введите значение(1 или 0) для элемента " << i << "X" << j << ":";
							cin >> graf[i][j];
							if (graf[i][j] == 1 || graf[i][j] == 0) prov = false;
							else cout << "Неверный ввод! Повторите попытку." << endl;
						} while (prov);
						graf[j][i] = graf[i][j];
					}
				}
			}
			cout << "Матрица смежности для графа:" << endl;
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
				cout << "Ошибка открытия файла! Повторите  попытку, исправив файл. Нажмите любую клавишу..." << endl;
				_getch();
				break;
			}
			//проверка файла на наличие данных
			if (inputFile.peek() == EOF)
			{
				cout << "Файл пуст! Повторите  попытку, добавив данные в файл. Нажмите любую клавишу..." << endl;
				_getch();
				break;
			}

			while (getline(inputFile, str)) //пока есть строки. с помощью getline построчно читаем файл
			{
				vector<int> znach1;
				for (char znach2 : str)
				{
					if (znach2 == '0' || znach2 == '1' || znach2 == ' ')
					{
						if (znach2 == '0' || znach2 == '1')
							znach1.push_back(znach2 - '0');//запись связи для одной вершины
					}
					else
					{
						cout << "Ошибка чтения из файла! Повторите  попытку, исправив данные в файле." << endl << "Учтите, что граф неориентированный и невзвешенный." << endl << "Нажмите любую клавишу...";
						_getch();
						goto EndCase3;
					}			
				}	
				graf.push_back(znach1);//связи вершины записываются в строку матрицы
			}
			inputFile.close();
			cout << "Граф успешно скопирован!" << endl;
			cout << "Матрица смежности для графа:" << endl;
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
			cout << "До свидания!";
			break;
		default:
			cout << endl;
			cout << "Неверный выбор! Повторите попытку.";
			cout << endl;
			break;
		}
	} while (choice != 4);
}