#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree
{
    int number;
    struct tree* right;
    struct tree* left;
    struct tree* parent;
} Tree;

void insert(int number, Tree** root) // функция, которая вставляет число в дерево
{
    if (*root == NULL) {
        Tree* adding = (Tree*)malloc(sizeof(Tree));
        adding->number = number;
        adding->right = adding->left = NULL;
        *root = adding;
        if ((*root)->parent != NULL)
        {
            if ((*root)->parent->right->number == adding->number)
                (*root)->parent->right = adding;
            else
                (*root)->parent->left = adding;
        }
    }
    else
    {
        if (number < (*root)->number)
            insert(number, &(*root)->left);
        else
            insert(number, &(*root)->right);
    }
}

void displayAscending(Tree *root) // вывод дерево по возрастанию
{
    if (root != NULL)
    {
        displayAscending(root->left);
        printf("\n%d", root->number);
        displayAscending(root->right);
    }
}

void displayDescending(Tree *root) // вывод дерева по убыванию
{
    if (root != NULL)
    {
        displayDescending(root->right);
        printf("\n%d", root->number);
        displayDescending(root->left);
    }
}

void deleteTree(Tree** root) // удаление дерева
{
    if (*root != NULL)
    {
        deleteTree(&(*root)->right);
        deleteTree(&(*root)->left);
        free(*root);
        *root = NULL;
    }
}

void solution(Tree ** root) // решение поставленной задачи
{
    const int STRING_SIZE = 200;
    char *string = (char*)malloc(STRING_SIZE * sizeof(char));
    puts("Enter the string: ");
    gets(string);
    int numberLength;
    while (*string) {
        numberLength = 0;

        if (*string == '-') {
            numberLength = 1;
            string++;
        }

        while ('0' <= *string && *string <= '9')
        {
            numberLength++;
            string++;
        }

        if (numberLength) {
            insert(atoi(string - numberLength), root);
            string--;
        }

        string++;
    }
    puts("By ascending: ");
    displayAscending(*root);
    puts("\nBy descending: ");
    displayDescending(*root);

}

int main() {
    char toContinue[50];
    Tree* root = NULL;
    puts("\n\tHello user\n");
    do {
        deleteTree(&root);
        solution(&root);
        puts("\nTo continue - enter \"yes\"");
        gets(toContinue);
    } while (!strcmp(toContinue, "yes"));

    return 0;
}





