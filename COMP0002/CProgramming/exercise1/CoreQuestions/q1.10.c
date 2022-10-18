// Create a program to draw a bar chart with labels

#include "graphics.h"

int main(void)
{
    drawLine(50,50,50,250);
    drawLine(50,250,350,250);
    drawLine(50,100,45,100);
    drawLine(50,150,45,150);
    drawLine(50,200,45,200);
    drawLine(50,250,45,250);
    setColour(blue);
    fillRect(50,190,50,60);
    setColour(green);
    fillRect(100,120,50,130);
    setColour(red);
    fillRect(150,130,50,120);
    setColour(yellow);
    fillRect(200,150,50,100);
    setRGBColour(255,20,147);
    fillRect(250,120,50,130);
    setColour(black);
    drawString("150",10,105);
    drawString("100",10,155);
    drawString("50",10,205);
    drawString("0",10,255);
    drawString("CDs",55,265);
    drawString("DVDs",105,265);
    drawString("Books",155,265);
    drawString("Clothes",205,265);
    drawString("Shoes",255,265);
    return 0;
}