// Use for loop to display 13 times table

#include <stdio.h>

int main(void)
{
    int n = 0;
    int ans;
    for (n=1; n<11; n++)
    {
        ans = n * 13;
        printf("%i * 13 = %i\n",n,ans);
    }
    return 0;
}