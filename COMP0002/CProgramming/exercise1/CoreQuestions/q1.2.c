// Written by Pittawas (Poom) Kijoran 3/10/2022
// This program displays my name, dept. name and building

#include <stdio.h>
#include <string.h>

int main(void)
{
    char myName[] = "Poom";
    char name[] = "Dept. of Computer Science";
    char address[] = "Malet Place Engineering Building";
    printf("Hello, my name is %s\n", myName);
    printf("I am from the %s\n", name);
    printf("Address: %s\n", address);

    int index = strlen(myName) - 1;
    while (index > -1)
    {
    printf("%c", myName[index]);
    index = index - 1;
    }
    printf("\n");
    return 0;
}