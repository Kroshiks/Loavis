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

int start = 1;
struct node* head = NULL, * last = NULL, * f = NULL;
int dlinna = 0;

struct node* get_struct(int pr, char s[256])
{
	struct node* p = NULL;

	if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) // �������� ������ ��� ����� ������� ������
	{
		printf(" ������ ��� ������������� ������\n");
		exit(1);
	}
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

// �������� �������� �� �����������. 
void del(char* name)
{
	struct node *struc = head; // ���������, ���������� �� ������ ���������� �� ������������
	struct node *prev = NULL;// ��������� �� �������������� ���������� �������
	int flag = 0; // ��������� ���������� ���������� �������� � ������
	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����");
		return;
	}
	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc); // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}
	while (struc) // ������ �� ������ � ����� ���������� ��������
	{
		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
		{	
			flag = 1; // ���������� ���������
			if (struc->next) // ���� ��������� ������� �� ��������� � ������
			{
				prev->next = struc->next; // ������ ���������
				free(struc); // ������� �������
				struc = prev->next; // ������������� ��������� ��� �����������������

			}
			else // ���� ��������� ������� ��������� � ������
			{
				prev->next = NULL; // �������� ��������� ��������������� ��������
				free(struc); // ������� �������
				return;
			}
		}
		else // ���� �� �����, ��
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}
	if (flag == 0) // ���� ���� = 0, ������ ������ ������� �� ������
	{
		printf("������� �� ������\n");
		return;
	}
}

void main()
{
	int f = 0,cs = 0;
	int i = 0, j=0;
	char s[256];
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
			printf("* - ��������� ������ ������ � ������������ �������\n");
			

			while (start)
			{
				do
				{
					printf("\n������� ��������� ������� �%d:", j + 1);
				    scanf("%d", &pr);
					cs = 0;
					if (pr<0)
					{
						printf(" ������ ��� ������ ����������\n");
						cs = 1;
					}
				}while (cs);

				printf("������� �������� �������� �%d:", j + 1);
				scanf(" %s", &s);
				if (*s == '*')
				{
					printf("\n���������� ������� ��������\n\n");
					start = 0;
				}
				else prioritet(&head, pr, s);
				j++;
			}

			printf("\n|  �  |  �������  |   ���������  |\n");
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
			
			printf("\n��� �������� ������� 1: ");
			scanf("%d",&d);
			 
			if(d==1)
			 {
				 printf("������� �������:");
				 scanf("%s", &k);
				 del(k);
			 }
			 else return;
			
			i = 0;
			struct node* rent = head;

			while (rent != NULL)
			{
				i++;
				printf("|%-5d|%-11s|%-14d|\n", i, rent->inf, rent->prir);
				printf("+-----+-----------+--------------+\n");
				rent = rent->next;
			}
			_getch();
			return;
		}
		case 2:
		{
			system("cls"); 
			printf("\n* - ��������� ������ ������ � �������\n");

			while (start)
			{
				
				printf("\n������� �������� �������� �%d:", j + 1);
				scanf(" %s", &s);
				if (*s == '*')
				{
					printf("\n���������� ������� ��������\n\n");
					start = 0;
				}
				else queue(&head, &last, s);
				j++;
			}

			printf("\n|  �  |  �������  |\n");
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
			return;
		}
		case 3:
		{
			system("cls");
			printf("* - ��������� ������ ������ � ����\n");

			while (start)
			{

				printf("\n������� �������� �������� �%d:", j + 1);
				scanf(" %s", &s);
				if (*s == '*')
				{
					printf("\n���������� ������� ��������\n\n");
					start = 0;
				}
				else ueue(&head, s);
				j++;
			}

			printf("\n|  �  |  �������  |\n");
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
			return;
		}
		case 4:
		{
			system("cls");
			printf("�����\n");
			return;
		default:
			printf("�������� �����\n");
			return;
		}
		}
	}
}