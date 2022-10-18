#include <stdio.h>

int main(void)
{
    int row, column;
    for (row = 1 ; row < 7 ; row++) {
        if (row % 2 == 1) {
            for (column = 1 ; column < 7 ; column++) {
                if (column % 2 == 1) {
                    printf("*");
                } else {
                    printf("#");
                }
            }
        } else {
            for (column = 1 ; column < 7 ; column ++) {
                if (column % 2 == 1) {
                    printf("#");
                } else {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
}