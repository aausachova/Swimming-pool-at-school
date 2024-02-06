// //Создать программу src/sort.c, ожидающую на вход в stdin массив длиной 10 из целых чисел
// // и выводящую этот же массив, но уже отсортированный по возрастанию. Необходимо выделить
// // функции чтения, сортировки и вывода массива отдельно. Алгоритм сортировки можно использовать
// // любой. Использовать stdlib.h нельзя. Передача массива в функцию только по указателю.
// //В случае ошибки выводить "n/a".

#include <math.h>
#include <stdio.h>

int input(int *a, int n);
void output(int *a, int n);
void psort(int *a, int n);
void qsort(int *a, int n, int low, int high);

int main() {
    int n = 10, data[10], data1[10], data2[10];
    if (input(data, n) && n >= 1) {
        for (int i = 0; i < n; i++) {
            data1[i] = data[i];
            data2[i] = data[i];
        }
        int f = 0;
        int l = n - 1;

        psort(data1, n);
        output(data1, n);
        printf("\n");
        qsort(data2, n, f, l);
        output(data2, n);

    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int n) {
    char c;
    for (int *p = a; p - a < n; p++) {
        if (p - a + 1 == n) {
            if (scanf("%d%c", p, &c) != 2 || c != '\n') {
                return 0;
            }

        } else {
            if (scanf("%d%c", p, &c) != 2 || c != ' ') {
                return 0;
            }
        }
    }
    return 1;

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

void psort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void qsort(int *a, int n, int low, int high) {
    int i = low, j = high;
    int tmp, x;

    x = a[(low + (high - low) / 2)];
    do {
        while (a[i] < x) {
            i++;
        }
        while (a[j] > x) {
            j--;
        }
        if (i <= j) {
            if (a[i] > a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            if (j > 0) {
                j--;
            }
        }
    } while (i <= j);

    if (i < high) {
        qsort(a, n, i, high);
    }
    if (j > low) {
        qsort(a, n, low, j);
    }
}