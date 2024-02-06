/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, const int *n);
double variance(int *a, const int *n);
int even(int *a, const int *n, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) && n >= 1) {
        even(data, &n, mean(data, &n), variance(data, &n));
        printf("%d", even(data, &n, mean(data, &n), variance(data, &n)));
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char check;
    if (scanf("%d", n) == 1 && scanf("%c", &check) && check == '\n' && *n <= 30) {
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

int even(int *a, const int *n, double mean_v, double variance_v) {
    for (int *p = a; p - a < *n; p++) {
        if (*p % 2 == 0 && (*p != 0 && *p >= mean_v && *p <= mean_v + 3 * sqrt(variance_v))) {
            return *p;
        }
    }
    return 0;
}