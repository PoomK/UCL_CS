#include <stdio.h>

int main(void)
{
    int row;
    for (row = 0 ; row < 6 ; row++)
    {
        int column;
        for (column = 0 ; column < 7 ; column++)
        {
            if (column <= row) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}