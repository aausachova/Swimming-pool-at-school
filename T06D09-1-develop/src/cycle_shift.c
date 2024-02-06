/* Создать программу src/cycle_shift.c, ожидающую на вход число n, массив A из n целых чисел и число c, на
которое все элементы массива должны сдвинутся влево циклично. При этом, при отрицательном значении c сдвиг
должен произойти вправо по массиву. В качестве вывода ожидается измененный массив. Необходимо придерживаться
предлагаемой декомпозиции, как и в прошлых квестах. Использовать stdlib.h нельзя. Передача массива в функцию
только по указателю. Максимальный размер входного массива - 10. В случае ошибки выводить "n/a". */

#include <stdio.h>

int input(int *a, int *n);
void cycle_sort(int *a, int n, int c);
void output(int *a, int n);

int main() {
    int n, data[100];
    if (input(data, &n)) {
        int c;
        scanf("%d", &c);
        cycle_sort(data, n, c);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char check;
    if (scanf("%d", n) == 1 && scanf("%c", &check) && check == '\n' && *n >= 1) {
        for (int *p = a; p - a < *n; p++) {
            if (p - a + 1 == *n) {
                if (scanf("%d%c", p, &check) != 2 || check != '\n') {
                    return 0;
                }
            } else {
                if (scanf("%d%c", p, &check) != 2 || check != ' ') {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p - a + 1 < n) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}

void cycle_sort(int *a, int n, int c) {
    if (c == 0) {
        return;
    }
    if (c < 0) {
        c = -c;
        while (c > 0) {
            int sort = a[n - 1];
            for (int i = n - 1; i > 0; i--) {
                a[i] = a[i - 1];
            }
            a[0] = sort;
            c--;
        }
    } else {
        while (c > 0) {
            int sort = a[0];
            for (int i = 0; i < n - 1; i++) {
                a[i] = a[i + 1];
            }
            a[n - 1] = sort;
            c--;
        }
    }
}