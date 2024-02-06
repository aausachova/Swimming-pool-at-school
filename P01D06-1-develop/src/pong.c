#include <stdio.h>

void draw_field(int ball_x, int ball_y, int p1_score, int p2_score, int left_racket_x, int right_racket_x);
int move_racket(char input, int racket_x);
void print_winner(int p1_score, int p2_score);

int main() {
    int p1_score = 0, p2_score = 0;
    int ball_x = 13, ball_y = 40;
    int ball_step_x = 1, ball_step_y = 1;
    int left_racket_x = 13, right_racket_x = 13;
    int winner = 0;

    while (!winner) {
        char input;
        draw_field(ball_x, ball_y, p1_score, p2_score, left_racket_x, right_racket_x);
        input = getchar();
        while (getchar() != '\n')
            ;
        if ((input == 'z' || input == 'Z' || input == 'a' || input == 'A' || input == 'k' || input == 'K' ||
             input == 'm' || input == 'M' || input == ' ')) {
            if (input == 'z' || input == 'Z' || input == 'a' || input == 'A') {
                left_racket_x = move_racket(input, left_racket_x);
            }
            if (input == 'k' || input == 'K' || input == 'm' || input == 'M') {
                right_racket_x = move_racket(input, right_racket_x);
            }
            ball_x += ball_step_x;
            ball_y += ball_step_y;
            if (ball_x == 24 || ball_x == 1) {
                ball_step_x = -ball_step_x;
            }
            if (ball_y == 80 || ball_y == 1) {
                ball_x = 13;
                ball_y = 40;
            }
            if ((ball_y == 5) &&
                (ball_x == left_racket_x || ball_x == left_racket_x + 1 || ball_x == left_racket_x - 1)) {
                ball_step_y = -ball_step_y;
            }
            if ((ball_y == 75) &&
                (ball_x == right_racket_x || ball_x == right_racket_x - 1 || ball_x == right_racket_x - 2)) {
                ball_step_y = -ball_step_y;
            }
            if (ball_y == 2) {
                p2_score += 1;
            } else if (ball_y == 79) {
                p1_score += 1;
            }
        }
        winner = (p1_score == 2 || p2_score == 21) ? 1 : 0;
    }
    print_winner(p1_score, p2_score);
    return 0;
}

void draw_field(int ball_x, int ball_y, int p1_score, int p2_score, int left_racket_x, int right_racket_x) {
    int field_height = 25;
    int field_width = 80;
    char vert_border = '|';
    char horiz_border = '-';
    char space = ' ';
    char racket = '|';
    char ball = 'o';
    printf("\033[H\033[J");
    for (int i = 0; i <= field_height; i++) {
        for (int j = 0; j <= field_width; j++) {
            if ((i == 0) || (i == 25)) {
                printf("%c", horiz_border);
            } else if ((i == ball_x) && (j == ball_y)) {
                printf("%c", ball);
            } else if ((i == 3) && (j == 20)) {
                printf("%d", p1_score);
            } else if ((i == 3) && (j == 60)) {
                printf("%d", p2_score);
            } else if ((j == 0) || (j == 80)) {
                printf("%c", vert_border);
            } else if (j == 76) {
                if (i == right_racket_x || i == right_racket_x + 1 || i == right_racket_x - 1) {
                    printf("%c", racket);
                } else {
                    printf("%c", space);
                }
            } else if (j == 4) {
                if (i == left_racket_x || i == left_racket_x + 1 || i == left_racket_x - 1) {
                    printf("%c", racket);
                } else {
                    printf("%c", space);
                }
            } else {
                printf("%c", space);
            }
        }
        printf("\n");
    }
}

int move_racket(char input, int racket_x) {
    if ((input == 'z' || input == 'Z' || input == 'm' || input == 'M')) {
        racket_x++;
    }
    if ((input == 'a' || input == 'A' || input == 'k' || input == 'K')) {
        racket_x--;
    }
    if (racket_x == 1) {
        racket_x += 1;
    } else if (racket_x == 24) {
        racket_x -= 1;
    }
    return (racket_x);
}

void print_winner(int p1_score, int p2_score) {
    printf("\033[H\033[J");
    if (p1_score == 2) {
        printf("First player won!");
    } else if (p2_score == 21) {
        printf("Second player won!");
    }
}