#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, b, c;
    double d, s, area, perimeter;

    printf("Enter length of the first side of the triangle: ");
    scanf("%d", &a);
    printf("Enter legnth of the second side of the triangle: ");
    scanf("%d",&b);
    printf("Enter length of the third side of the traingle: ");
    scanf("%d", &c);
    printf("\n");

    perimeter = a + b + c;
    s = 0.5*perimeter;

    if ((s-a<=0)||(s-b<=0)||(s-c<=0)) {
        printf("Input values do not represent a triangle \n");
    } else {
        printf("Perimeter: %f \n", perimeter);
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("Area: %f \n", area);
    }

    return 0;
}