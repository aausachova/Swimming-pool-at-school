/*  Изменить программу src/key9part2.c так, чтобы она вернула результат сложения и разности двух очень больших
чисел, переданных программе на вход в виде массивов. Максимальная длина числа - 100 элементов типа int.
Вводимые целые числа представляют собой десятичные цифры. В случае если вычитаемое больше уменьшаемого, в
разности выводится "n/a". Необходимо придерживаться декомпозиции, как и в прошлых квестах. Использовать
stdlib.h нельзя. Передача массива в функцию только по указателю. В случае ошибки выводить "n/a".*/

#include <stdio.h>

#define LEN 100

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result);
void sub(const int *buff1, int len1, const int *buff2, int len2, int *result);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

int main() {
    int buff1[LEN], buff2[LEN], result[LEN];
    int len1, len2;
    if (scanf("%d", &len1) != 1 || len1 <= 0 || len1 > LEN) {
        printf("n/a");
        return 1;
    }
    for (int i = 0; i < len1; i++) {
        if (scanf("%d", &buff1[i]) != 1 || buff1[i] > 9) {
            printf("n/a");
            return 1;
        }
    }
    if (scanf("%d", &len2) != 1 || len2 <= 0 || len2 > LEN) {
        printf("n/a");
        return 1;
    }
    for (int i = 0; i < len2; i++) {
        if (scanf("%d", &buff2[i]) != 1 || buff2[i] > 9) {
            printf("n/a");
            return 1;
        }
    }
    sum(buff1, len1, buff2, len2, result);
    for (int i = result[0]; i >= 1; i--) {
        printf("%d", result[i]);
    }
    printf("\n");
    sub(buff1, len1, buff2, len2, result);
    if (result[0] == -1) {
        printf("n/a\n");
    } else {
        for (int i = result[0]; i >= 1; i--) {
            printf("%d", result[i]);
        }
        printf("\n");
    }
    return 0;
}

void sum(const int *buff1, int len1, const int *buff2, int len2, int *result) {
    int carry = 0;
    int i = 0;
    while ((i < len1 && i < len2) || carry > 0) {
        if (i < len1) {
            carry += buff1[i];
        }
        if (i < len2) {
            carry += buff2[i];
        }
        result[i] = carry % 10;
        carry /= 10;
        i++;
    }
    result[0] = i - 1;
}

void sub(const int *buff1, int len1, const int *buff2, int len2, int *result) {
    if (len1 < len2) {
        result[0] = -1;
        return;
    }
    int borrow = 0;
    int i = 0;
    while (i < len1 || borrow > 0) {
        if (i < len1) {
            borrow += buff1[i];
        }
        if (i < len2) {
            borrow -= buff2[i];
        }
        if (borrow < 0) {
            result[0] = -1;
            return;
        }
        result[i] = borrow % 10;
        borrow /= 10;
        i++;
    }
    while (i > 1 && result[i - 1] == 0) {
        i--;
    }
    result[0] = i - 1;
}