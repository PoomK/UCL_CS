#include <stdio.h>

int main(void) {
    int n;
    int check = 1;

    while (check == 1) {
        printf("Enter a positive integer number: ");
        scanf("%d", &n);
        if (n >= 0) {
            break;
        } else {
            printf("Input is not a valid number\n");
        }
    }

    int count = 0;
    int i = 2;
    int j = n;
    while(i <= j/2) {
        if(j%i == 0) {
            count++;
            break;
        }
        i++;	
    }	
    if(count == 0 && j != 1 ) {
        printf("%d is a prime number\n", j);
    } else {
        printf("%d is not a prime number\n", j);
    }

    return 0;
}