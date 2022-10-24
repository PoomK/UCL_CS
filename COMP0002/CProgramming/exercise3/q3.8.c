//Print all strong numbers for a specific range

#include <stdio.h>

int factorial(n) {
    int x=1, fact=1;
    while(x<=n) {
        fact = fact * x;
        x++;
    }
    return fact;
}

int main()
{
    int a, b, checka = 1, checkb = 1, i, digit, ten, hundred, tempNum;

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

    for (i = a; i <= b; i++) {
        int currentNum = i;
        digit = i % 10;
        tempNum = i / 10;
        ten = i % 10;
        tempNum = i / 10;
        hundred = i % 10;
        tempNum = i / 10;

        int sum = factorial(digit) + factorial(ten) + factorial(hundred);

        if (currentNum == sum) {
            printf("%d\n", currentNum);
        }
    }
}