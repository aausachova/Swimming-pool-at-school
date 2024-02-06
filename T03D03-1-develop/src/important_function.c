#include <math.h>
#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf", &a);
    b = 7e-3 * pow(a, 4) + ((22.8 * cbrt(a) - 1e3) * a + 3) / (a * a / 2) - a * pow(10 + a, 2.0 / a) - 1.0;

    printf("%.1lf\n", b);
}