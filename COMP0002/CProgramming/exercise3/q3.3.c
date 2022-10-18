#include <stdio.h>

int main(void) {
    long int number, orderedNumber, reversedNumber;
    int remainder;

    printf("Enter number to check if palindromic: ");
    scanf("%ld", &number);
    orderedNumber = number;

    reversedNumber = 0;

    while (number != 0) {
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }

    if (orderedNumber == reversedNumber) {
        printf("Number is a palindrome \n");
    } else {
        printf("Number is not a palidnrome \n");
    }

    return 0;
}