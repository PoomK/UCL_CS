#include <stdio.h>

int power_loop(a,b) {
    int i;
    int c = 1;
    for (i = 1; i <= b; i++) {
        c = a * c;
    }
    return c;
}

int main(void) {
    int x, y, z;

    printf("Enter base: ");
    scanf("%d", &x);
    printf("Enter power: ");
    scanf("%d", &y);

    z = power_loop(x,y);
    printf("Answer: %d \n", z);
}