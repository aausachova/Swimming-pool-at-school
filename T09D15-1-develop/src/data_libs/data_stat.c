#include "data_stat.h"

#include <math.h>

double max(double *data, int n) {
    double max;
    max = *(data + 0);
    for (double *p = data; p - data < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

double min(double *data, int n) {
    double min;
    min = *(data + 0);
    for (double *p = data; p - data < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

double mean(double *data, int n) {
    double sum = 0;
    for (double *p = data; p - data < n; p++) {
        sum += (*p);
    }

    return sum / (n);
}

double variance(double *data, int n) {
    double sum = 0;
    for (double *p = data; p - data < n; p++) {
        sum += pow((*p) - mean(data, n), 2);
    }

    return sum / (n);
}
