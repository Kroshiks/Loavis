#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* CreateTree(Tree* root, int data)
{
    if (root == NULL)
    {
        root = (Tree*)malloc(sizeof(Tree));
        if (root == NULL)
        {
            printf("Ошибка выделения памяти");
            exit(0);
        }

        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    
    if (data < root->data)
    {
        root->left = CreateTree(root->left, data);
    }
    else if (data >= root->data)
    {
        root->right = CreateTree(root->right, data);
    }
    else
    {
        printf("Нельзя добавить уже существующий элемент!\n");
        free(CreateTree(0, data));
        return root;
    }

    return root;
}

//Функция для подсчета вхождений элемента в дерево
int counter(Tree* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1 + counter(root->left, data) + counter(root->right, data);
    }
    else if (data < root->data) {
        return counter(root->left, data);
    }
    else {
        return counter(root->right, data);
    }
}

// Функция вывода дерева на экран 
void print_tree(Tree* root, int level)
{
    if (root == NULL)
    {
        return;
    }

    print_tree(root->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        printf(" ");
    }

    printf("%d\n", root->data);

    print_tree(root->left, level + 1);
}

int main()
{
    SetConsoleCP(1251);//Установка языка
    SetConsoleOutputCP(1251);
    int data, start = 1;
    Tree* root = NULL;
    int f = 0, element,input;
  
	do
	{
        printf("      МЕНЮ\n");
		printf("1) Построить дерево.\n");
		printf("2) Найти элемент\n");
		printf("3) Выход.\n");
        printf("\nВыберите номер действия, которое хотите выполнить: ");
		scanf("%d", &f);

		switch (f)
		{
		case 1:
		{
			system("cls");

            printf("-1 - окончание построения дерева\n");

            while (start)
            {
                printf("Введите число: ");
                scanf("%d", &data);

                if (data == -1)
                {
                    printf("\nПостроение дерева окончено\n\n");
                    start = 0;
                }
                
                else root = CreateTree(root, data);     
            }

            print_tree(root, 0);
            printf("\n");
			break;
		}
		case 2:
		{
            printf("\nВведите элемент, которое хотите найти: ");
            scanf("%d", &element);

            input = counter(root, element);
            printf("Количество вхождений элемента %d = %d\n", element, input);
            printf("\n");
			break;
		}
		case 3:
		{
			system("cls");
			printf("ВЫХОД\n");
			return 0;
		default:
			printf("Неверный выбор\n");
			return 0;
		}
		}
    } while (f != 4);

    return 0;
}