// Use do loop to display 13 times table

#include <stdio.h>

int main(void)
{
    int n = 1;
    int ans;
    do
    {
        ans = n * 13;
        printf("%i * 13 = %i\n",n,ans);
    } while (++n<11);
    
    return 0;
}