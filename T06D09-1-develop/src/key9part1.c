/*
Изменить программу src/key9part1.c так, чтобы она принимала на вход длину массива и массив целых чисел. В
качестве выхода она должна вывести в stdout сумму четных элементов массива и новый сформированный массив из
элементов старого, на которые делится нацело подсчитанная ранее сумма. Уменьшать декомпозицию нельзя - функции
можно только добавлять при необходимости, но не убирать. Использовать stdlib.h нельзя. Передача массива в
функцию только по указателю. Максимальный размер входного массива - 10. В случае ошибки или отсутствии четных
элементов выводить "n/a". */

#include <stdio.h>

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n = 10, data[n], data_new[n];
    if (input(data, &n)) {
        int number = sum_numbers(data, n);
        int k = find_numbers(data, n, number, data_new);
        printf("%d\n", number);
        output(data_new, k);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    int booleans = 1;
    if (scanf("%d%c", length, &check) == 2 && check == '\n') {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (p - buffer + 1 == *length) {
                if (scanf("%d%c", p, &check) != 2 || check != '\n') {
                    booleans = 0;
                }
            } else {
                if (scanf("%d%c", p, &check) != 2 || check != ' ') {
                    booleans = 0;
                }
            }
        }
    }
    return booleans;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        if (p - buffer + 1 < length) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}
/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int cnt = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && (number % buffer[i] == 0)) {
            numbers[cnt] = buffer[i];
            cnt++;
        }
    }
    return cnt;
}
