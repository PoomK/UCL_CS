#include <stdio.h>

int multiply_sequence(x,y) {
    int i, z = 1;
    for (i = x; i <= y; i++) {
        z = z * i;
    }
    return z;
}

int main(void) {
    int a, b, c;

    printf("Enter start number of the sequence: ");
    scanf("%d", &a);
    printf("Enter end number of sequence: ");
    scanf("%d", &b);

    c = multiply_sequence(a,b);
    printf("Result: %d \n", c);

    return 0;
}