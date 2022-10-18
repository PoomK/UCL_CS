#include <stdio.h>

int main(void)
{
    int n = 1;
    while (n < 11)
    {
        printf("%i: Hello\n",n);
        n = n + 1;
    }
    return 0;
}