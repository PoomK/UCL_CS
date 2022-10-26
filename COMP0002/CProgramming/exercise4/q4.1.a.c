#include <stdio.h>
#include "graphics.h"
#include <stdlib.h>

const int width = 400;
const int height = 400;
const int squareSize = 50;
const int moveDistance = 5;
const int waitTime = 25;

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
    int y = 100;
    int i = 1;
    while(i == 1) {
        for (int n = 0; n < 30; n++) {
            update(x,y);
            x += moveDistance;
            sleep(waitTime);
        }
        for (int n = 0; n < 30; n++) {
            update(x,y);
            y += moveDistance;
            sleep(waitTime);
        }
        for (int n = 0; n < 30; n++) {
            update(x,y);
            x -= moveDistance;
            sleep(waitTime);
        }
        for (int n = 0; n < 30; n++) {
            update(x,y);
            y -= moveDistance;
            sleep(waitTime);
        }
    }
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}