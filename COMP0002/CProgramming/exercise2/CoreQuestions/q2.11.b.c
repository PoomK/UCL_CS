// Print the squares of the even numbers between 1 and 101

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;
    for (i = 1 ; i <= 101 ; i++) {
        if (i%2==0) {
            int sqrNum = pow(i,2);
            printf("%d\n",sqrNum);
        }
    }
}