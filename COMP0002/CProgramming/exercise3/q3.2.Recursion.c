#include <stdio.h>

int power_recursion(int n1, int n2);

int power_recursion(int a, int b) {
    if (b != 0)
        return (a * power_recursion(a, b - 1));
    else
        return 1;
}

int main(void) {
    int x, y, z;

    printf("Enter base: ");
    scanf("%d", &x);
    printf("Enter power: ");
    scanf("%d", &y);

    z = power_recursion(x,y);
    printf("Answer: %d \n", z);
}