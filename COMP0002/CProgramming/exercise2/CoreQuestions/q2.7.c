#include <stdio.h>

int main(void)
{
    int row, column;
    for (row = 1 ; row < 8 ; row++)
    {
        if (row == 1 || row == 7)
        {
            for (column = 1 ; column < 9 ; column++)
            {
                printf("*");
            }
        } else if (row == 2 || row == 6) {
            for (column = 1 ; column < 9 ; column++)
            {
                if (column == 1 || column == 8) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        } else if (row == 3 || row == 5) {
            for (column = 1 ; column < 9 ; column++)
            {
                if (column == 1 || column == 8) {
                    printf("*");
                } else if (column == 2 || column == 7) {
                    printf(" ");
                } else {
                    printf("#");
                }
            }
        } else {
            for (column = 1 ; column < 9 ; column++)
            {
                if (column == 1 || column == 8) {
                    printf("*");
                } else if (column == 3 || column == 6) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}