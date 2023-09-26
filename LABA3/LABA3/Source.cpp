#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

struct node
{
	char inf[256]; // �������� ����������
	struct node* next; // ������ �� ��������� �������
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

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) // �������� ������ ��� ����� ������� ������
	{
		printf(" ������ ��� ������������� ������\n");
		exit(1);
	}
	scanf(" %s", &s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);
	p->next = NULL;
	p->prir = pr;
	return p; // ���������� ��������� �� ��������� �������
}

void queue(struct Queue* q)
{
	struct node* temp = get_struct(0);
	
	if (q->rear == NULL) 
	{
		q->front = q->rear = temp;
		return;
	}

	// ��������� ����� ���� � ����� ������� � ��������� ��������� �� ��������� �������
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
	SetConsoleCP(1251);//��������� �����
	SetConsoleOutputCP(1251);

	

	while (f != 4)
	{
		system("cls");
		printf("�������� ����� ��������, ������� ������ ���������:\n");
		printf("1) ������������ �������.\n");
		printf("2) �������.\n");
		printf("3) ����.\n");
		printf("4) �����.\n");
		scanf("%d", &f);
		
		switch (f)
		{
		case 1:
		{
			system("cls");
			int pr = NULL;

			printf("������� ���������� ��������� � ������:");
			scanf("%d", &dlinna);

			for (int i = 0; i < dlinna; i++)
			{
				printf("\n������� ��������� ������� �%d:", i + 1);
				scanf("%d", &pr);
				printf("������� �������� ������� �%d:", i + 1);
				prioritet(&head, pr);
			}

			struct node* current = head;
			while (current != NULL)
			{
				printf("������� %s (��������� %d)\n", current->inf, current->prir);
				current = current->next;
			}
			_getch();
			break;
		}
		case 2:
		{
			system("cls");

		

			printf("������� ���������� ��������� � �������:");
			scanf("%d", &dlinna);

			for (int i = 0; i < dlinna; i++)
			{
				printf("\n������� �������� ������� �%d:", i + 1);
				queue(q);
			}

			
			struct node* current = q->front;
			while (current != NULL)
			{
				printf("������� %s\n", current->inf);
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
			printf("�����\n");
			break;
		default:
			printf("�������� �����\n");
			break;
		}
		}
	}
}
