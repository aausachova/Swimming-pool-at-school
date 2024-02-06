#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, const int *n);
int max(int *a, const int *n);
int min(int *a, const int *n);
double mean(int *a, const int *n);
double variance(int *a, const int *n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) && n >= 1) {
        output(data, &n);
        output_result(max(data, &n), min(data, &n), mean(data, &n), variance(data, &n));
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

int max(int *a, const int *n) {
    int max;
    max = *(a + 0);
    for (int *p = a; p - a < *n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, const int *n) {
    int min;
    min = *(a + 0);
    for (int *p = a; p - a < *n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

double mean(int *a, const int *n) {
    double sum = 0;
    for (int *p = a; p - a < *n; p++) {
        sum += (*p);
    }

    return sum / (*n);
}

double variance(int *a, const int *n) {
    double sum = 0;
    for (int *p = a; p - a < *n; p++) {
        sum += pow((*p) - mean(a, n), 2);
    }

    return sum / (*n);
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("\n%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}
