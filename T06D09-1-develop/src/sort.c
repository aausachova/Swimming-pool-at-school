//Создать программу src/sort.c, ожидающую на вход в stdin массив длиной 10 из целых чисел
// и выводящую этот же массив, но уже отсортированный по возрастанию. Необходимо выделить
// функции чтения, сортировки и вывода массива отдельно. Алгоритм сортировки можно использовать
// любой. Использовать stdlib.h нельзя. Передача массива в функцию только по указателю.
//В случае ошибки выводить "n/a".

#include <math.h>
#include <stdio.h>

int input(int *a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n = 10, data[n];
    if (input(data, &n) == 1) {
        sort(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

// int input(int *a, int n) {
//     //char check;
//     for (int *p = a; p - a < n; p++) {
//         if (p - a + 1 == n) {
//             if (scanf("%d%c", p, &check) != 2 || check != '\n') {
//                 return 0;
//             }
//         } else {
//             if (scanf("%d%c", p, &check) != 2 || check != ' ') {
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }

int input(int *a, int *n) {
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", a + i) != 1) {
            return 1;
        }
    }
    return 1;
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

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int cnt = a[j];
                a[j] = a[j + 1];
                a[j + 1] = cnt;
            }
        }
    }
}
