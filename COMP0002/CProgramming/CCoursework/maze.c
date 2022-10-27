#include <stdio.h>
#include "graphics.h"

// Declare global variables and constants
const int width = 520;
const int height = 520;
const int moveDistance = 40;
const int waitTime = 40;
int triangleX[3], triangleY[3], grid[11][11];
int currentXPos, currentYPos;
//Create global variables for current grid positions

//  Function to draw the maze
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
    int triangleXUpdate[3] = {x1,x2,x3};
    int triangleYUpdate[3] = {y1,y2,y3};
    fillPolygon(3,triangleXUpdate,triangleYUpdate);
}

//Maybe take this out as there is no need
void getCurrentPos(int triangleX[3], int triangleY[3]) {
    currentXPos = (triangleX[0] + triangleX[1] + triangleX[2])/3;
    currentYPos = (triangleY[0] + triangleY[1] + triangleY[2])/3;
    printf("Current position of robot: (%d, %d)\n", currentXPos, currentYPos);
}

// Function for moving the robot forward, depending on the direction it is facing
// !!! Need to add the current position in grid
void forward(int triangleX[3], int triangleY[3], int direction) {
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
}

void right(int triangleX[3], int triangleY[3], int direction) {
    //Use same structure as forward (check which direction it is facing)
}

/*void left(int triangleX[3], int triangleY[3], int direction) {
    //Use same structure as forward (check which direction it is facing)
}

int atMarket() {
    int atMarketEnd;
    // Make sure to check current pos /3 will get decimal and need to round up
    // Or just use current grid position
    return atMarketEnd;
}

int canMoveForward() {
    int canMoveForwardYN;
    //Check if position ahead is wall or not, if wall, then return false, if no wall then return true
    return canMoveForwardYN;
}*/

void move() {
    int a;
    foreground();
    //Direction is to show which direction robot is moving
    //(1 = north, 2 = east, 3 = south, 4 = west)
    int direction = 2;
    setColour(green);
    //Set start position of robot and draw the starting robot
    int triangleX[3] = {40,40,80};
    int triangleY[3] = {80,120,100};
    getCurrentPos(triangleX, triangleY);
    update(triangleX[0],triangleY[0],triangleX[1],triangleY[1],triangleX[2],triangleY[2]);
    
    //Keep moving forward until hit wall

    //Code to move forward by one block
    forward(triangleX, triangleY, direction);
    update(triangleX[0],triangleY[0],triangleX[1],triangleY[1],triangleX[2],triangleY[2]);
    sleep(waitTime);
    getCurrentPos(triangleX, triangleY);
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}