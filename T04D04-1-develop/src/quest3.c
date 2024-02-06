#include <stdio.h>

int fibbanachi(int number) {
    if (number <= 2) {
        return 1;
    } else {
        return fibbanachi(number - 1) + fibbanachi(number - 2);
    }
}

int main(void) {
    int number;
    char c;

    if ((scanf("%d", &number) == 1) && (scanf("%c", &c)) && (c == '\n')) {
        printf("%d", fibbanachi(number));
    } else {
        printf("n/a");
    }
}