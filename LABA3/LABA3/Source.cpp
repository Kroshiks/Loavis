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

struct Queue {
	struct node* front, * rear;
};

struct node* head = NULL, * last = NULL, * f = NULL;
int dlinna = 0;

struct node* get_struct(int pr)
{
	struct node* p = NULL;
	char s[256];

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) // выделяем память под новый элемент списка
	{
		printf(" Ошибка при распределении памяти\n");
		exit(1);
	}
	scanf(" %s", &s);
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

void queue(struct Queue* q)
{
	struct node* temp = get_struct(0);
	
	if (q->rear == NULL) 
	{
		q->front = q->rear = temp;
		return;
	}

	// Добавляем новый узел в конец очереди и обновляем указатель на последний элемент
	q->rear->next = temp;
	q->rear = temp;
}

void prioritet(struct node** head, int pr)
{
	struct node* prom = *head;

	struct node* temp = get_struct(pr);

	if (*head == NULL || (*head)->prir < pr)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		while (prom->next != NULL && prom->next->prir >= pr)
		{
			prom = prom->next;
		}
		temp->next = prom->next;
		prom->next = temp;
	}
}

void main()
{
	int f=0;
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

			printf("Введите количество элементов в списке:");
			scanf("%d", &dlinna);

			for (int i = 0; i < dlinna; i++)
			{
				printf("\nВведите приоритет обьекта №%d:", i + 1);
				scanf("%d", &pr);
				printf("Введите название объекта №%d:", i + 1);
				prioritet(&head, pr);
			}

			struct node* current = head;
			while (current != NULL)
			{
				printf("Элемент %s (приоритет %d)\n", current->inf, current->prir);
				current = current->next;
			}
			_getch();
			break;
		}
		case 2:
		{
			system("cls");

		

			printf("Введите количество элементов в очереди:");
			scanf("%d", &dlinna);

			for (int i = 0; i < dlinna; i++)
			{
				printf("\nВведите название объекта №%d:", i + 1);
				queue(q);
			}

			
			struct node* current = q->front;
			while (current != NULL)
			{
				printf("Элемент %s\n", current->inf);
				current = current->next;
			}
			_getch();
			break;
		}
		case 3:
		{
			system("cls");
			
			break;
		}
		case 0:
		{
			system("cls");
			printf("ВЫХОД\n");
			break;
		default:
			printf("Неверный выбор\n");
			break;
		}
		}
	}
}
