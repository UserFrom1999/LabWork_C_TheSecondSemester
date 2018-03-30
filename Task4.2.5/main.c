#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct list
{
    int amountRepeat;
    char *word;
    struct list* next;
} List;

/*
char* toLower(char *someString) // переводит все символы в строке в нижний регистр
{
    for (int i = 0; someString[i]; i++)
        someString[i] = (char)tolower(someString[i]);

    return someString;
}
*/

char* toLower(char* some)
{
    char* out = some;
    for (; *some; some++) {
        *some = (char)tolower(*some);
    }
    return out;
}

_Bool checkRepeat(char *word, List *head) // проверяет, есть ли данное слово уже в спис
{
    List* new = head;
    for (; new != NULL; new = new->next)
        if (!strcmp(toLower(word), toLower(new->word))) // в случаи различного написания слов (если первая буква зглавная, или всё слово заглавными)
        {
            new->amountRepeat++;
            return 0;
        }

    return 1;
}

List* add(char *word, List** add) // добавляет элемент в начало списка
{
    if (word == NULL)
        return add;
    if(checkRepeat(word, (*add)))
    {
        List *new = (List*)malloc(sizeof(List));
        new->word = (char*)realloc(new->word, sizeof(word));
        strcpy(new->word, word);
        new->amountRepeat = 1;
        new->next = *add;
        *add = new;
    }
    return add;
}

void delete(List del, List **head)
{
    List *find = *head;
    if (!strcmp(find->word, del.word))
    {
        *head = (*head)->next;
        free(find->word);
        free(find);
    }
    else
    {
        for (; strcmp(del.word, find->next->word); find = find->next);
        List *edit = find->next;
        find->next = find->next->next;
        free(edit->word);
        free(edit);
    }
}

void display(List *head) // вывод список в консоль
{
    List* out = head;
    for (; out != NULL; out = out->next)
        printf("\nWord: %s\nAmount of repeat: %d", out->word, out->amountRepeat);
}

List maxRepeat(List *head) // находит в списке слово с наибольшим количеством повторов
{
    List *maxItem = head;
    //int max = head->amountRepeat;
    head = head->next;
    for (; head != NULL; head = head->next) {
        if (head->amountRepeat > maxItem->amountRepeat)
            maxItem = head;
    }

    itemOut(*maxItem);
    return *maxItem;
}

void itemOut(List item) // выводит данный элемент списка
{
    puts("");
    printf("Amount of repeat: %d\nWord: ", item.amountRepeat);
    puts(item.word);
}

void maxUseItems(List *head) // выводит двадцать элементов, наиболее часто встречающихся в тексте
{
    puts("\n\n20 most used words and frecuency of their usage:");
    for (int i = 0; i < 20; i++)
        delete(maxRepeat(head), &head);
}

void readFromFile(List **head) // производится считывание из файла, обработка строк (вычленение слов) и запись в структуру данных
{
    const char fileName[] = "TextFile.txt";
    FILE *file = fopen(fileName, "r+");

    if (file == NULL)
    {
        puts("Error. Cannot open file");
        exit(0);
    }

    const int maxSize = 1000;
    char tString[maxSize];

    while (fgets(tString, maxSize, file) != NULL)
    {
        char *word = strtok(tString, " .,?!:…\n\"");
        add(word, head);
        while (word != NULL)
        {
            puts(word);
            word = strtok(NULL, " .,?!:…\n\"");
            add(word, head);
        }
    }
    fclose(file);
    puts("End of processing");
    display(*head);
}

int main() {
    List *head = NULL;
    readFromFile(&head);
    maxUseItems(head);

    return 0;
}