#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int InputIntegers()
{
    char str[1000];
    int number = 0;
    do {
        _Bool incorrectInput = 0;
        //fsdputs("Enter the number: ");
        gets(str);

        //checking letters

        for (int i = 0; str[i]; i++)
            if (str[i] < '0' || str[i] > '9')
            {
                incorrectInput = 1;
                break;
            }

        //checking NULL and Null and 12354 in order to 0133 is invalid input

        if (str[0] == '0') incorrectInput = 1;
        if (incorrectInput)
        {
            puts("\nError. Invalid input");
            continue;
        }
        //translate in number

        for (int i = 0; str[i]; i++)
            number = number * 10 + (str[i] - '0');
        break;
    }while(1);
    return number;
}

int main() {
    const int lengthString = 80;
    int amountStrings;

    puts("Enter the amount of strings: ");
    amountStrings = InputIntegers();
    printf("\nAmount %d\n", amountStrings);

    char **inputText = (char**)malloc(amountStrings * sizeof(char));
    for (int i = 0; i < amountStrings; i++)
        inputText[i] = (char* )calloc(lengthString, sizeof(char));

    puts("\nInput your text:\n\n ");

    for (int i = 0; i < amountStrings; i++)
    {
        printf("%d    ", i + 1);
        fgets(inputText[i], lengthString, stdin);
        fflush(stdin);
        //gets(inputText[i]);
    }
    puts("Output \n");

    for (int i = 0; i < amountStrings; i++)
    {
        printf("%d    ", i + 1);
        printf("%s", inputText[i]);
    }

    return 0;
}