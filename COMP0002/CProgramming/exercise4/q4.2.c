#include <stdio.h>
#include "graphics.h"
#include <stdlib.h>
#include <time.h>

const int width = 400;
const int height = 400;
const int circleSize = 30;
const int moveDistance = 1;
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
    int x = 40, y = 60, running = 1, randomX = 1, randomY = 1;
    do
    {
        update(x,y);
        x += moveDistance * randomX;
        y += moveDistance * randomY;
        sleep(waitTime);
    } while (x >= 0 && y >= 0 && x <= 370 && y <= 370);
    while (running == 1) {
        if (x <= 0) {
            printf("x hit left boundary\n");
            randomX = rand() % (3 + 1 - 1) + 1;
            if (randomY > 0) {
                //Moving down
                randomY = rand() % (3 + 1 - 1) + 1;
            } else {
                //Moving up
                randomY = rand() % (-1 + 1 - (-3)) + (-3);
            }
        } else if (y <= 0) {
            printf("x hit top boundary\n");
            randomY = rand() % (3 + 1 - 1) + 1;
            if (randomX < 0) {
                //Moving left
                randomX = rand() % (-1 + 1 - (-3)) + (-3);
            } else {
                //Moving right
                randomX = rand() % (3 + 1 - 1) + 1;
            }
        } else if (x >= 370) {
            printf("x hit right boundary\n");
            randomX = rand() % (-1 + 1 - (-3)) + (-3);
            if (randomY > 0) {
                //Moving down
                randomY = rand() % (3 + 1 - 1) + 1;
            } else {
                //Moving up
                randomY = rand() % (-1 + 1 - (-3)) + (-3);
            }
        } else if (y >= 370) {
            printf("x hit bottom boundary\n");
            randomY = rand() % (-1 + 1 - (-3)) + (-3);
            if (randomX < 0) {
                //Moving left
                randomX = rand() % (-1 + 1 - (-3)) + (-3);
            } else {
                //Moving right
                randomX = rand() % (3 + 1 - 1) + 1;
            }
        }
        do
        {
            update(x,y);
            x += moveDistance * randomX;
            y += moveDistance * randomY;
            sleep(waitTime);
        } while (x >= 0 && y >= 0 && x <= 370 && y <= 370);
        //break;
    }
}

int main(void) {
    srand(time(0));
    setWindowSize(width, height);
    drawBackground();
    move();
}