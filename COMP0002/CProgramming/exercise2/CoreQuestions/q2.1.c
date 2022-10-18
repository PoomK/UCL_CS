// Use while loop to display 13 times table

#include <stdio.h>

int main(void)
{
    int n = 1;
    int ans;
    while (n<11)
    {
        ans = n * 13;
        printf("%i * 13 = %i\n",n,ans);
        n += 1;
    }
    return 0;
}