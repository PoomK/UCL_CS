#include <stdio.h>
#include "graphics.h"

const int width = 520;
const int height = 520;
const int moveDistance = 40;
const int waitTime = 20;

void drawBackground() {
    background();
    int i, j;
    //Grid for the maze (1 for black or 0 for white or 2 for grey)
    int grid[11][11] = {
        {1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,1,0,1,0,1},
        {1,0,1,1,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,0,0,1,0,1},
        {1,0,1,0,1,1,1,1,1,0,1},
        {1,0,1,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,0,1},
        {1,0,0,0,1,0,1,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,2,1}
        };
    for (i = 0; i <= 10; i++) {
        for (j = 0; j <= 10; j++) {
            if (grid[i][j] == 1) {
                setColour(black);
            } else if (grid[i][j] == 0) {
                setColour(white);
            } else {
                setColour(gray);
            }
            fillRect(j*40+40, i*40+40, 40, 40);
            setColour(black);
            drawRect(j*40+40, i*40+40, 40, 40);
        }
    }
}

void update(int x1, int y1, int x2, int y2, int x3, int y3) {
    clear();
    //Draw shape
    int triangleX[3] = {x1,x2,x3};
    int triangleY[3] = {y1,y2,y3};
    fillPolygon(3,triangleX,triangleY);
}

// Function for moving the robot forward, depending on the direction it is facing
int forward(int triangleX[3], int triangleY[3], int direction) {
    int i;
    if (direction == 1) { // Facing north
        for (i = 0; i <= 2; i++) {
            triangleY[i] -= 40;
        }
    } else if (direction == 2) { // Facing east
        for (i = 0; i <= 2; i++) {
            triangleX[i] += 40;
        }
    } else if (direction == 3) { // Facing south
        for (i = 0; i <= 2; i++) {
            triangleY[i] += 40;
        }
    } else { // Facing west
        for (i = 0; i <= 2; i++) {
            triangleX[i] -= 40;
        }
    }
    return triangleX, triangleY;
}

void left() {
    return 0;
}

void right() {
    return 0;
}

int atMarket() {
    int atMarketEnd;
    return atMarketEnd;
}

int canMoveForward() {
    int canMoveForwardYN;
    return canMoveForwardYN;
}

void move() {
    foreground();
    //Direction is to show which direction robot is moving
    //(1 = north, 2 = east, 3 = south, 4 = west)
    int direction = 2;
    setColour(green);
    update(40,80,40,120,80,100);
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}