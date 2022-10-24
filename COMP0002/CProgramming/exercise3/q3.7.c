#include <stdio.h>

int main()
{
    int a, b, checka = 1, checkb = 1;

    while (checka == 1) {
        printf("Enter lower range: ");
        scanf("%d", &a);
        if (a >= 0) {
            break;
        } else {
            printf("Input is not a valid number\n");
        }
    }

    while (checkb == 1) {
        printf("Enter upper range: ");
        scanf("%d", &b);
        if (b >= 0) {
            break;
        } else {
            printf("Input is not a valid number\n");
        }
    }

    int previousPrime;
    
    int i, j = a, count;

    while(j <= b) {
        count = 0;
        i = 2;
        while(i <= j/2) {
            if(j%i == 0) {
                count++;
                break;
            }
            i++;	
        }
        previousPrime = 2;
        if(count == 0 && j != 1 ) {
            if (j-previousPrime<=2) {
                printf("%d and %d\n",previousPrime, j);
            }
            previousPrime = j;
        }
        j++; 
    }
    return 0;
}