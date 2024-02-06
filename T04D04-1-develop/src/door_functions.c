#include <math.h>
#include <stdio.h>

int main(void) {
    double y2;
    double y3;
    double y4;
    double sh;
    double x;

    sh = (M_PI * 2) / 41;
    x = -M_PI;
    for (int s = 0; s < 42; s++) {
        y4 = 1 / (pow(x, 2));
        y3 = (pow(1, 3)) / (pow(1, 2) + pow(x, 2));
        y2 = sqrt(sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1, 2));

        if (y2 >= 0) {
            printf("%.7lf | %.7lf | %.7lf | %.7lf\n", x, y3, y2, y4);
        } else {
            printf("%.7lf | %.7lf | - | %.7lf\n", x, y3, y4);
        }
        x += sh;
    }
}