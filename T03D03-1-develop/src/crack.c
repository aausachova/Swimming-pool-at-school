#include <stdio.h>

int main(void) {
    float x, y;
    printf("Координаты: ");
    if (scanf("%f %f", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }
    float radius = x * x + y * y;
    if (radius <= 5.0) {
        printf("GOTCHA\n");
    } else {
        printf("MISS\n");
    }

    return 0;
}