#include <stdio.h>

int main(void) {
    int hours, minutes;
    printf("Enter time in 24 hour format (XX:XX): ");
    scanf("%d:%d", &hours, &minutes);
    if (hours<=12) {
        printf("%d.%d am\n", hours, minutes);
    } else {
        hours = hours - 12;
        printf("%d.%d pm\n", hours, minutes);
    }
    return 0;
}