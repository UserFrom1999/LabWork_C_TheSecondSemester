#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

#include "Input.h"

typedef struct node
{
    unsigned short int bit;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list
{
    int size;
    Node *head, *end;
} List;

// прототипы функций для работы с двунаправленным списком

void insert(unsigned short int, int, List*); // вставка значения в указанную позицию в указанный список
void push_back(unsigned short int, List*); // вставка значения в конец указанного списока
void delete(unsigned short int, List*); // удаляет первое вхождение числа из указанного списка
void deleteAt(int, List *); // удаляет элемент, расположенный под указанным индексом, из указанного списка
void display(List); // выводит указанный список от головы к хвосту (от начала)
void displayReverse(List); // выводит указанный список от хвоста к голове (от конца)
void clear(List*); // удаляет все элементы в указанном списке

// прототипы функций для решения задачи

void exponentiation(List*); // возведение введёного числа в указанную степень
void setNumber(int, List*); // записывает указанное число в список
void multiplication(List*, List, int); // перемножает два числа, выраженных списками

int main() {

    List list;
    list.size = 0;
    list.end = list.head = NULL;
    char answer[100];
    do {
        clear(&list);
        exponentiation(&list);
        puts("\nIf you would like to continue - enter \"yes\"");
        gets(answer);
    } while (!strcmp(answer, "yes"));
    return 0;
}

// функции для решения задачи

void exponentiation(List* list) // exponentiation - (с англ.) возведение в степень (вводит числа для возведения и само возведение (бинарное)
{
    int degree, base, notationBase;
    _Bool ifNegative = 0;
    do {
        puts("Enter the base of notation (2 <= base && base <= 10): ");
        notationBase = inputIntegers();
        if (2 <= notationBase && notationBase <= 10)
            break;
        puts("Error. Invalid input");
    } while(1);
    do {
        _Bool allOkey = 1;
        puts("Enter the number (base) which will be exponented : ");
        base = inputIntegers();

        if (allOkey)
            break;
        puts("Error. Invalid input");
    } while(1);

    puts("Enter the degree (> 0): " );
    do {
        degree = inputIntegers();
        if (degree > 0)
            break;
        puts("Error. Invalid input. Degree > 0");
    } while(1);

    if (base <  0 && (degree & 1))
    {
        ifNegative = 1;
        base *= -1;
    }

    setNumber(base, list);

    List answer;
    answer.head = answer.end = NULL;
    answer.size = 0;
    setNumber(1, &answer);

    while (degree) // бинарное возведение в степень
    {
        if (degree & 1)
        {
            multiplication(&answer, *list, notationBase);
            degree--;
        }
        else
        {
            multiplication(list, *list, notationBase);
            degree >>= 1;
        }
    }
    puts("\nAnswer: ");
    if (ifNegative)
        printf("-");
    displayReverse(answer); // вывод списка с конца
    clear(&answer);
}

void setNumber(int number, List* list) // записывает в список число (number)
{
    if (number == 0)
        push_back(number, list);
    int bit, degree = 1;
    bit = number % 10;
    while (bit)
    {

        push_back(bit, list);
        bit = (number % (int)pow(10., degree + 1)) / (int)pow(10., degree);
        degree++;
    }
}

void normalizeToNotationBase(List *list, int notationBase)
{
    Node *pointer = list->head;
    int remainder = 0;
    while (pointer)
    {
        pointer->bit += remainder;
        remainder = pointer->bit / notationBase;
        pointer->bit %= notationBase;
        pointer = pointer->next;
    }
    while (remainder)
    {
        push_back(remainder % notationBase, list);
        remainder /= notationBase;
    }
}

void multiplication(List *firstMultipling, List secondMultipling, int notationBase)
{
    List answer;
    answer.size = 0;
    answer.head = answer.end = NULL;
    Node *pointerToAnswer = NULL;
    Node *tempPointerToAnswer = NULL;
    while (secondMultipling.head)
    {
        Node* beMultipling = firstMultipling->head;
        if (!pointerToAnswer)
            tempPointerToAnswer = NULL;
        else
            tempPointerToAnswer = pointerToAnswer->next;
        while (beMultipling)
        {
            if (tempPointerToAnswer) {
                tempPointerToAnswer->bit += beMultipling->bit * secondMultipling.head->bit;
                tempPointerToAnswer = tempPointerToAnswer->next;
            }
            else
                push_back(beMultipling->bit * secondMultipling.head->bit, &answer);
            beMultipling = beMultipling->next;
        }
        if (!pointerToAnswer)
            pointerToAnswer = answer.head;
        else
            pointerToAnswer = pointerToAnswer->next;
        secondMultipling.head = secondMultipling.head->next;
    }

    normalizeToNotationBase(&answer, notationBase);
    clear(firstMultipling);
    *firstMultipling = answer;
}

void push_back(unsigned short int value, List* list)
{
    Node *add = (Node*)malloc(sizeof(Node));
    add->bit = value;
    add->prev = add->next = NULL;
    if (list->end == NULL)
    {
        list->end = list->head = add;
        list->size++;
    }
    else
    {
        list->end->next = add;
        add->prev = list->end;
        list->end = add;
        list->size++;
    }
}

void deleteAt(int index, List* list)
{
    if (list->size - 1 < index || index < 0)
        return;
    Node* del = list->head;

    for (int i = 0; i < index; i++)
        del = del->next;

    if (del == NULL)
        return;

    if (del == list->head)
    {
        list->head = list->head->next;
        if (list->head != NULL)
            list->head->prev = NULL;
    }
    else if (del == list->end)
    {
        list->end = list->end->prev;
        if (list->end != NULL)
            list->end->next = NULL;
    }
    else
    {
        del->prev->next = del->next;
        del->next->prev = del->prev;
    }
    free(del);
    list->size--;
}

void displayReverse(List list)
{
    Node *out = list.end;
    for(; out; out = out->prev)
        printf("%d", out->bit);
}

void clear(List* list)
{
    while (list->head != NULL)
        deleteAt(0, list);
    list->head = list->end = NULL;
}