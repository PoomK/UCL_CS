#include <stdio.h>

int main(void) {
    int row, column;
    for (row = 1 ; row <= 8 ; row++) {
        if (row == 1) {
            for (column = 1 ; column <= 7 ; column++) {
                printf("*");
            }
        } else if (row == 8) {
            for (column = 1 ; column <= 7 ; column++) {
                printf("#");
            }
        } else if (row == 2) {
            for (column = 1 ; column <= 7 ; column++) {
                if (column == 1) {
                    printf("#");
                } else if (column == 2 || column == 7) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        } else if (row == 7) {
            for (column = 1 ; column <= 7 ; column++) {
                if (column == 7) {
                    printf("*");
                } else if (column == 1 || column == 6) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
        } else {
            for (column = 1 ; column <= 7 ; column++) {
                if (column == 1) {
                    printf("#");
                } else if (column == 7) {
                    printf("*");
                } else if (column == row - 1) {
                    printf("#");
                } else if (column == row) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}