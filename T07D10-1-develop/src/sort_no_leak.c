#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *n);
void output(int *a, int n);
void sort(int *a, int n);
void proverka(int *data);
int main() {
    int n;
    if (scanf("%d", &n) == 1 && (n == 0)) {
        printf("n/a");
        return 1;
    }

    int *data = (int *)malloc(n * sizeof(int));
    proverka(data);
    if (input(data, &n) == 1) {
        sort(data, n);
        output(data, n);
        free(data);
    } else {
        printf("n/a");
        free(data);
    }
    return 0;
}

void proverka(int *data) {
    if (data == NULL) {
        printf("n/a");
        exit(1);
    }
}

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
