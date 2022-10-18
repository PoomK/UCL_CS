#include <stdio.h>

int main(void)
{
    int row, column;
    for (row = 0 ; row < 4 ; row++)
    {
        if (row == 0 || row == 3) {
            for (column = 0 ; column < 5 ; column++)
            {
                printf("*");
            }
        } else {
            for (column = 0 ; column < 5 ; column ++)
            {
                if (column == 0 || column == 4) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
        }
    return 0;
}