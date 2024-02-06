#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FIELD_SIZE_X 80
#define FIELD_SIZE_Y 25

#define TRUE 1
#define FALSE 0

int **init();
void polish_notation();
void finish(int **matrix);

void draw_field();



int main() {
	return 0;
}

int **init() {
    int **data = allocate_matrix(FIELD_SIZE_Y, FIELD_SIZE_X);
	return data;
}

void finish(int **matrix) {
    printf("Ended. Closing application...\n");
    free(matrix);
}

int **allocate_matrix(int rows, int cols) {
    int **matrix = malloc(rows * cols * sizeof(int) + rows * sizeof(int *));
    int *pointer = (int *)(matrix + rows);
    for (int row = 0; row < rows; row++) {
        matrix[row] = pointer + row * cols;
    }
    for (int i = 0; i < rows * cols - 1; i++) matrix[i / cols][i % cols] = 0;
    return matrix;
}

void draw_field(int **currentStep) {
    char vert_border = '|';
    char horiz_border = '-';
    char dead = ' ';
    char alive = '*';

    for (int y = 0; y <= (FIELD_SIZE_Y + 1); y++) {
        for (int x = 0; x <= (FIELD_SIZE_X + 1); x++) {
            if (y == 0 || y == (FIELD_SIZE_Y + 1))
                printw("%c", horiz_border);
            else if (x == 0 || x == (FIELD_SIZE_X + 1))
                printw("%c", vert_border);
            else if (currentStep[y - 1][x - 1])
                printw("%c", alive);
            else
                printw("%c", dead);
        }
        printf("\n");
    }
}
