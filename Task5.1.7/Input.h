//
// Created by zhenya on 29.03.18.
//
#include <stdio.h>
#ifndef TASK5_1_7_INPUT_H
#define TASK5_1_7_INPUT_H

int inputIntegers() // проверка на корректный ввод целых чисел
{
    char str[1000];
    int number = 0;
    do {
        _Bool incorrectInput = 0;
        gets(str);
        int ifNegative = 0;

        if (str[0] =='-')
            ifNegative = 1;

        for (int i = ifNegative; str[i]; i++)
            if (str[i] < '0' || str[i] > '9')
            {
                incorrectInput = 1;
                break;
            }

        if (str[ifNegative] == '0' && str[ifNegative + 1] != '\0')
            incorrectInput = 1;
        if (incorrectInput)
        {
            puts("\nError. Invalid input");
            continue;
        }

        for (int i = ifNegative; str[i]; i++)
            number = number * 10 + (str[i] - '0');
        if (ifNegative)
            number *= -1;
        break;
    }while(1);
    return number;
}


#endif //TASK5_1_7_INPUT_H
