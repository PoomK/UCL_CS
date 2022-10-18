// Draw fractal shape (Koch Snowflake) using a recursive algorithm

#include "graphics.h"

void drawTriangle()
{
    int a [] = {0,3,6};
    int b [] = {0,3,0};
    drawPolygon(3,a,b);
}

int main()
{
    drawTriangle();
    return 0;
}