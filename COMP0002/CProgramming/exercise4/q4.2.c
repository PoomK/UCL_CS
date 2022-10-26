#include <stdio.h>
#include "graphics.h"
#include <stdlib.h>
#include <time.h>

const int width = 400;
const int height = 400;
const int circleSize = 30;
const int moveDistance = 3;
const int waitTime = 10;

void drawBackground() {
    background();
    int i, j;
    //Grid for the background (1 for black or 0 for white)
    int grid[10][10] = {
        {1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1}
        };
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            if (grid[i][j] == 1) {
                setColour(black);
            } else {
                setColour(white);
            }
            fillRect(i*40, j*40, 40, 40);
        }
    }
}

void update(int x, int y) {
    clear();
    fillOval(x, y, circleSize, circleSize);
}

void move() {
    foreground();
    setColour(red);
    int x = 40, y = 60, running = 1, randomX, randomY;
    do
    {
        update(x,y);
        x += moveDistance;
        y += moveDistance;
        sleep(waitTime);
    } while (x >= 0 && y >= 0 && x <= 370 && y <= 370);
    if (x <= 0) {
        printf("x hit left\n");
    } else if (y <= 0) {
        printf("x hit top\n");
    } else if (x >= 370) {
        printf("x hit right\n");
    } else if (y >= 370) {
        printf("x hit bottom\n");
    }
    printf("Hit boundary");
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}