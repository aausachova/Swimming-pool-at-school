#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read_data(int n, int m, int data[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &data[i][j]);
        }
    }
}

void print_data(int n, int m, int data[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int n, int m, int data1[n][m], int data2[n][m]) {
    int result[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = data1[i][j] + data2[i][j];
        }
    }
    print_data(n, m, result);
}

void multiply_matrices(int n1, int m1, int data1[n1][m1], int n2, int m2, int data2[n2][m2]) {
    if (m1 != n2) {
        printf("n/a\n");
        return;
    }

    int result[n1][m2];
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                result[i][j] += data1[i][k] * data2[k][j];
            }
        }
    }
    print_data(n1, m2, result);
}

void transpose_data(int n, int m, int data[n][m]) {
    int result[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][i] = data[i][j];
        }
    }
    print_data(m, n, result);
}

int main() {
    int check;
    scanf("%d", &check);

    int n1, m1;
    scanf("%d %d", &n1, &m1);
    int data1[n1][m1];
    read_data(n1, m1, data1);

    if (check == 1) {
        int n2, m2;
        scanf("%d %d", &n2, &m2);
        int data2[n2][m2];
        read_data(n2, m2, data2);

        if (n1 != n2 || m1 != m2) {
            printf("n/a");
            return 0;
        }

        add_matrices(n1, m1, data1, data2);
    } else if (check == 2) {
        int n2, m2;
        scanf("%d %d", &n2, &m2);
        int data2[n2][m2];
        read_data(n2, m2, data2);

        multiply_matrices(n1, m1, data1, n2, m2, data2);
    } else if (check == 3) {
        transpose_data(n1, m1, data1);
    } else {
        printf("n/a");
    }

    return 0;
}