#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

struct node
{
	char inf[256]; // полезная информация
	struct node* next; // ссылка на следующий элемент
	int prir;
};

int start = 1;
struct node* head = NULL, * last = NULL, * f = NULL;
int dlinna = 0;

struct node* get_struct(int pr, char s[256])
{
	struct node* p = NULL;

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) // выделяем память под новый элемент списка
	{
		printf(" Ошибка при распределении памяти\n");
		exit(1);
	}
	 if (*s == 0)
	{
		printf("Запись не была произведена\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->next = NULL;
	p->prir = pr;
	return p; // возвращаем указатель на созданный элемент
}

void queue(struct node** head, struct node** last, char s[256])
{
	struct node* temp = get_struct(0,s);

	if (*head == NULL && temp != NULL)
	{
		*head = temp;
		*last = temp;
	}
	else if (*head != NULL && temp != NULL)
	{
		(*last)->next = temp;
		*last = temp;
	}
}

void ueue(struct node** head, char s[256])
{
	struct node* temp = get_struct(0,s);

	if (temp != NULL)
	{
		temp->next = *head;
		*head = temp;
	}

}

void prioritet(struct node** head, int pr, char s[256])
{
	struct node* prom = *head;

	struct node* temp = get_struct(pr,s);
 
	if (*head == NULL || (*head)->prir > pr)
	{
		temp->next = *head;
		*head = temp;
	}
	else 
	{
		while (prom->next != NULL && prom->next->prir <= pr)
		{
			prom = prom->next;
		}
		temp->next = prom->next;
		prom->next = temp;
	}
}

void free_queue(struct node* head)
{
	struct node* current = head;
	struct node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

// Удаление элемента по содержимому. 
void del(char* name)
{
	struct node *struc = head; // указатель, проходящий по списку установлен на начало списка
	struct node *prev = NULL;// указатель на предшествующий удаляемому элемент
	int flag = 0; // индикатор отсутствия удаляемого элемента в списке
	if (head == NULL) // если голова списка равна NULL, то список пуст
	{
		printf("Список пуст");
		return;
	}
	if (strcmp(name, struc->inf) == 0) // если удаляемый элемент - первый
	{
		flag = 1;
		head = struc->next; // установливаем голову на следующий элемент
		free(struc); // удаляем первый элемент
		struc = head; // устанавливаем указатель для продолжения поиска
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}
	while (struc) // проход по списку и поиск удаляемого элемента
	{
		if (strcmp(name, struc->inf) == 0) // если нашли, то
		{	
			flag = 1; // выставляем индикатор
			if (struc->next) // если найденный элемент не последний в списке
			{
				prev->next = struc->next; // меняем указатели
				free(struc); // удаляем элемент
				struc = prev->next; // устанавливаем указатель для продолжения поиска

			}
			else // если найденный элемент последний в списке
			{
				prev->next = NULL; // обнуляем указатель предшествующего элемента
				free(struc); // удаляем элемент
				return;
			}
		}
		else // если не нашли, то
		{
			prev = struc; // устанавливаем указатели для продолжения поиска
			struc = struc->next;
		}
	}
	if (flag == 0) // если флаг = 0, значит нужный элемент не найден
	{
		printf("Элемент не найден\n");
		return;
	}
}

void delit(struct node** head)
{
	if (*head == NULL)
	{
		printf("Очередь пуста\n");
		return;
	}
	struct node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

void delitt(struct node** head)
{
	if (*head == NULL)
	{
		printf("стек пуст\n");
		return;
	}
	 struct node* temp = *head;
	 *head = (*head)->next;
	free(temp);


}

void main()
{
	int f = 0,cs = 0;
	int i = 0, j=0;
	char s[256];
	SetConsoleCP(1251);//Установка языка
	SetConsoleOutputCP(1251);

	while (f != 4)
	{
		system("cls");
		printf("Выберите номер действия, которое хотите выполнить:\n");
		printf("1) Приоритетная очередь.\n");
		printf("2) Очередь.\n");
		printf("3) Стек.\n");
		printf("4) Выход.\n");
		scanf("%d", &f);

		switch (f)
		{
		case 1:
		{
			system("cls");
			int pr = NULL;
			printf("* - окончание записи данных в приоритетную очередь\n");
			

			while (start)
			{
				do
				{
					printf("\nВведите приоритет обьекта №%d:", j + 1);
				    scanf("%d", &pr);
					cs = 0;
					if (pr<0)
					{
						printf(" Ошибка при записи приоритета\n");
						cs = 1;
					}
				}while (cs);

				printf("Введите название элемента №%d:", j + 1);
				scanf(" %s", &s);
				if (*s == '*')
				{
					printf("\nПостроение очереди окончено\n\n");
					start = 0;
				}
				else prioritet(&head, pr, s);
				j++;
			}

			printf("\n|  №  |  Элемент  |   Приоритет  |\n");
			printf("+-----+-----------+--------------+\n");

			struct node* current = head;
			while (current != NULL)
			{
				i++;
				printf("|%-5d|%-11s|%-14d|\n", i, current->inf, current->prir);
				printf("+-----+-----------+--------------+\n");
				current = current->next;
			}	
			_getch();

			int d;
			char k[256];
			int gg = 1;
			
			struct node* rent = NULL;
			
			int hh = 1;
			do
			 {
				printf("\nДля удаления введите 1: ");
				scanf("%d", &d);

				if (d != 1)
				{
					break;
				}
				 printf("Введите элемент:");
				 scanf("%s", &k);
				 del(k);
			
			i = 0;
			
			
			node* rent = head;
			while (rent != NULL)
			{
				i++;
				printf("|%-5d|%-11s|%-14d|\n", i, rent->inf, rent->prir);
				printf("+-----+-----------+--------------+\n");
				rent = rent->next;
			}
			_getch();
			} while (1);

			

			struct node* ent = NULL;
			do {

				printf("\nДля добавления элемента введите 2: ");
				scanf("%d", &d);
				if (d != 2)
				{
					break;
				}
					do
					{
						printf("\nВведите приоритет обьекта :");
						scanf("%d", &pr);
						cs = 0;
						if (pr < 0)
						{
							printf(" Ошибка при записи приоритета\n");
							cs = 1;
						}
					} while (cs);

					printf("Введите название элемента:");
					scanf(" %s", &s);
					prioritet(&head, pr, s);
				

				i = 0;
			 node* ent = head;
				while (ent != NULL)
				{
					i++;
					printf("|%-5d|%-11s|%-14d|\n", i, ent->inf, ent->prir);
					printf("+-----+-----------+--------------+\n");
					ent = ent->next;
				}
				_getch();
			} while (1);

			return;
		}
		case 2:
		{
			system("cls"); 
			printf("\n* - окончание записи данных в очередь\n");

			while (start)
			{
				
				printf("\nВведите название элемента №%d:", j + 1);
				scanf(" %s", &s);
				if (*s == '*')
				{
					printf("\nПостроение очереди окончено\n\n");
					start = 0;
				}
				else queue(&head, &last, s);
				j++;
			}

			printf("\n|  №  |  Элемент  |\n");
			printf("+-----+-----------+\n");

			struct node* urrent = head;
			while (urrent != NULL)
			{
				i++;
				printf("|%-5d|%-11s|\n", i, urrent->inf);
				printf("+-----+-----------+\n");
				urrent = urrent->next;
			}
			_getch();
			
			struct node* nt = NULL;
			int p;
			char k[256];
			do
			{
				printf("\nДля удаления введите 1: ");
				scanf("%d", &p);

				if (p != 1)
				{
					break;
				}
				delit(&head);

				i = 0;
				node* nt = head;
				while (nt != NULL)
				{
					i++;
					printf("|%-5d|%-11s|%-14d|\n", i, nt->inf, nt->prir);
					printf("+-----+-----------+--------------+\n");
					nt = nt->next;
				}
				_getch();
			} while (1);

			return;
		}
		case 3:
		{
			system("cls");
			printf("* - окончание записи данных в стек\n");

			while (start)
			{

				printf("\nВведите название элемента №%d:", j + 1);
				scanf(" %s", &s);
				if (*s == '*')
				{
					printf("\nПостроение очереди окончено\n\n");
					start = 0;
				}
				else ueue(&head, s);
				j++;
			}
			int q;
			q = j;
			printf("\n|  №  |  Элемент  |\n");
			printf("+-----+-----------+\n");
			struct node* rrent = head;
			while (rrent != NULL)
			{
				j--;
				printf("|%-5d|%-11s|\n", j, rrent->inf);
				printf("+-----+-----------+\n");
				rrent = rrent->next;
			}
			_getch();

			struct node* t = head;
			int p;
			char k[256];
			do
			{
				printf("\nДля удаления введите 1: ");
				scanf("%d", &p);

				if (p != 1)
				{
					break;
				}
				delitt(&head);
				
				i = q - 1;
				q--;
				node* t = head;
				while (t != NULL)
				{
					i--;
					printf("|%-5d|%-11s|\n", i, t->inf);
					printf("+-----+-----------+\n");
					t = t->next;
				}
				_getch();
			} while (1);
			return;
		}
		case 4:
		{
			system("cls");
			printf("ВЫХОД\n");
			return;
		default:
			printf("Неверный выбор\n");
			return;
		}
		}
	}
}