#include <stdio.h>

void max(int a, int b) {
    if (a > b) {
        printf("%d\n", a);
    } else {
        printf("%d\n", b);
    }
}

int main(void) {
    int a, b;

    if ((scanf("%d", &a) != 1) | (scanf("%d", &b) != 1)) {
        printf("n/a\n");
        return 1;
    }

    max(a, b);
    return 0;
}