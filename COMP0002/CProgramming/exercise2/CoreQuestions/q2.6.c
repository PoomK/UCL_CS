#include <stdio.h>

int main(void)
{
    int row, column;
    for (row = 1 ; row < 10 ; row++)
    {
        if (row <= 5)
        {
            for (column = 1 ; column < 10 ; column++)
            {
                if (column >= row && column <= row + 4)
                {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        } else {
            for (column = 1 ; column < 10 ; column++)
            {
                if (column >= 10 - row && column <= 14 - row)
                {
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