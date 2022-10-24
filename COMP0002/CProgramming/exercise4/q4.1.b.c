#include <stdio.h>
#include "graphics.h"

const int width = 400;
const int height = 400;
const int squareSize = 50;
const int moveDistance = 1;
const int waitTime = 10;

void drawBackground() {
    background();
    //Draw green donut in the background
    setColour(green);
    fillArc(100,100,200,200,0,360);
    setColour(white);
    fillArc(130,130,140,140,9,360);
}

void update(int x, int y) {
    clear();
    fillRect(x, y, squareSize, squareSize);
}

void move() {
    foreground();
    setColour(blue);
    int x = 100;
    int y = 175;
    for (int n = 0; n < 20; n++) {
        update(x,y);
        x += moveDistance;
        y -= moveDistance * 3;
        sleep(waitTime);
    }
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}