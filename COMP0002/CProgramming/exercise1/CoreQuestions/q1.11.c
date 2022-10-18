// Draw sine wave

#include "graphics.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(void)
{
    int i = 0;
    double rad = PI/180;
    int y1,y2;

    while (i<=360)
    {
        y1 = (int)((sin(i*rad))*100);
        y2 = (int)((sin((i+1)*rad))*100);
        drawLine(100+i,150-y1,100+i+1,150-y2);
        i = i + 1;
    }

    return(0);
}