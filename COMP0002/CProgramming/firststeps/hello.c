#include <stdio.h>

int main(void)
{
    printf("Hello world!\n");

    int counter = 0;
    while (counter < 10)
    {
        printf("%i\n", counter);
        counter = counter + 1;
    }
    return 0;
}