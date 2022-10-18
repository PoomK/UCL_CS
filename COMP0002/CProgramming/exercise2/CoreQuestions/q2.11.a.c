// Print squares of the numbers from 1 to 100

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    for (i = 1 ; i <= 100 ; i++) {
        int sqrNum = pow(i,2);
        printf("%d\n",sqrNum);
    }
}