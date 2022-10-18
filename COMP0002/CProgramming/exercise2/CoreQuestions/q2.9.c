#include <stdio.h>

int main(void)
{
    int row, column;
    for (row = 1 ; row < 10 ; row++) {
        if (row == 1 || row == 9) {
            printf("*");
        } else if (row >= 2 && row <= 5) {
            for (column = 1 ; column < 6 ; column++) {
                if (column == 1) {
                    printf("*");
                } else if (column == row) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        } else {
            for (column = 1 ; column < 6 ; column++) {
                if (column == 1) {
                    printf("*");
                } else if (column == 10 - row) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}