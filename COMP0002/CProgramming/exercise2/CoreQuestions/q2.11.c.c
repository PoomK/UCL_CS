// Print the prime numbers between 1 and 100

#include <stdio.h>

int main()
{
    int i, j = 1, count; 
    while(j <= 100) {
        count = 0;
        i = 2;
        while(i <= j/2) {
            if(j%i == 0) {
                count++;
                break;
            }
            i++;	
        }	
        if(count == 0 && j != 1 ) {
            printf("%d\n", j);
        }
        j++; 
    }
    return 0;
}