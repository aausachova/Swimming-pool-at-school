#include <stdio.h>

int main(void) {
    int a, b;

    if ((scanf("%d", &a) != 1) | (scanf("%d", &b) != 1)) {
        printf("n/a\n");
        return 1;
    }

    printf("%d %d %d", a + b, a - b, a * b);

    if (b != 0) {
        printf("%d\n", a / b);
    } else {
        printf("n/a\n");
    }

    return 0;
}