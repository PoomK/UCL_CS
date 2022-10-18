#include <stdio.h>

const char* verbalise_num(number) {
    char numberStr[] = "";
    char numberArr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int check = 1;

    while (check == 1) {
        
    }
}

int main(void) {
    int n;
    int check = 1;

    while (check == 1) {
        printf("Enter number between 0 and 999: ");
        scanf("%d", &n);
        if (n >= 0 && n <= 999) {
            break;
        } else {
            printf("Number is not in the valid range\n");
        }
    }

    return 0;
}