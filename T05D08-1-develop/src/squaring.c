#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, const int *n);
void squaring(int *a, const int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) && n >= 1) {
        squaring(data, &n);
        output(data, &n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char check;
    if (scanf("%d", n) == 1 && scanf("%c", &check) && check == '\n' && *n <= 10) {
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

void output(int *a, const int *n) {
    for (int *p = a; p - a < *n; p++) {
        if (p - a + 1 < *n) {
            printf("%d ", *p);
        } else {
            printf("%d", *p);
        }
    }
}

void squaring(int *a, const int *n) {
    for (int *p = a; p - a < *n; p++) {
        *p = (*p) * (*p);
    }
}
