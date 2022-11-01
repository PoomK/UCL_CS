#include <stdio.h>
#include "graphics.h"

// Maybe create array for the path, if dead end, then move back to previous place with more than 1 option
// Maybe array of previous actions and make it go opposite

// Declare global variables and constants
const int width = 520;
const int height = 520;
const int moveDistance = 40;
const int waitTime = 40;
int triangleX[3], triangleY[3], direction, currentXGrid, currentYGrid, forwardValue;

//  Function to draw the maze
void drawBackground() {
    background();
    int i, j;
    //Grid for the maze (1 for black or 0 for white or 2 for grey)
    int gridBack[11][11] = {
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
            if (gridBack[i][j] == 1) {
                setColour(black);
            } else if (gridBack[i][j] == 0) {
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

void update(int triangleX[3], int triangleY[3]) {
    clear();
    //Draw shape
    fillPolygon(3,triangleX,triangleY);
}

// Function for moving the robot forward, depending on the direction it is facing
void forward(int triangleX[3], int triangleY[3], int direction) {
    int i;
    if (direction == 1) { // Facing north
        for (i = 0; i <= 2; i++) {
            triangleY[i] -= 40;
        }
        currentYGrid -= 1;
    } else if (direction == 2) { // Facing east
        for (i = 0; i <= 2; i++) {
            triangleX[i] += 40;
        }
        currentXGrid += 1;
    } else if (direction == 3) { // Facing south
        for (i = 0; i <= 2; i++) {
            triangleY[i] += 40;
        }
        currentYGrid += 1;
    } else { // Facing west
        for (i = 0; i <= 2; i++) {
            triangleX[i] -= 40;
        }
        currentXGrid -= 1;
    }
    update(triangleX, triangleY);
}

void right(int triangleX[3], int triangleY[3], int direction) {
    int i;
    if (direction == 1) { // Facing north
        triangleY[0] -= 40;
        triangleX[1] -= 40;
        triangleX[2] += 20;
        triangleY[2] += 20;
    } else if (direction == 2) { // Facing east
        triangleX[0] += 40;
        triangleY[1] -= 40;
        triangleX[2] -= 20;
        triangleY[2] += 20;
    } else if (direction == 3) { // Facing south
        triangleY[0] += 40;
        triangleX[1] += 40;
        triangleX[2] -= 20;
        triangleY[2] -= 20;
    } else { // Facing west
        triangleX[0] -= 40;
        triangleY[1] += 40;
        triangleX[2] += 20;
        triangleY[2] -= 20;
    }
    update(triangleX, triangleY);
    printf("Turned right\n");
}

void left(int triangleX[3], int triangleY[3], int direction) {
    int i;
    if (direction == 1) { // Facing north
        triangleX[0] += 40;
        triangleY[1] -= 40;
        triangleX[2] -= 20;
        triangleY[2] += 20;
    } else if (direction == 2) { // Facing east
        triangleY[0] += 40;
        triangleX[1] += 40;
        triangleX[2] -= 20;
        triangleY[2] -= 20;
    } else if (direction == 3) { // Facing south
        triangleX[0] -= 40;
        triangleY[1] += 40;
        triangleX[2] += 20;
        triangleY[2] -= 20;
    } else { // Facing west
        triangleY[0] -= 40;
        triangleX[1] -= 40;
        triangleX[2] += 20;
        triangleY[2] += 20;
    }
    update(triangleX, triangleY);
    printf("Turned left\n");
}

/*
int atMarker() {
    int atMarkerEnd;
    //Use grid posiition to check whether grid position in front is 2
    return atMarkerEnd;
}
*/

// Return 0 if can move forward, return 1 if wall ahead, return 2 if end point ahead
int checkForward(int currentXGrid, int currentYGrid, int direction) {
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
    if (direction == 1) { // Facing north
        return grid[currentYGrid-1][currentXGrid];
    } else if (direction == 2) { // Facing east
        return grid[currentYGrid][currentXGrid + 1];
    } else if (direction == 3) { // Facing south
        return grid[currentYGrid + 1][currentXGrid];
    } else { // Facing west
        return grid[currentYGrid][currentXGrid - 1];
    }
}

void move() {
    int a;
    int running = 1;
    foreground();

    //Direction is to show which direction robot is moving
    //(1 = north, 2 = east, 3 = south, 4 = west)
    direction = 2;
    setColour(green);

    //Set start position of robot and draw the starting robot
    int triangleX[3] = {40,40,80};
    int triangleY[3] = {80,120,100};
    currentXGrid = 0;
    currentYGrid = 1;
    update(triangleX, triangleY);

    canMoveForward(currentXGrid, currentYGrid, direction);

    //Code to move robot forward until hit wall or end point
    forwardValue = checkForward(currentXGrid, currentYGrid, direction);
    //Keep moving forward until cannot move forward
    while (forwardValue == 0) {
        forward(triangleX, triangleY, direction);
        forwardValue = checkForward(currentXGrid, currentYGrid, direction);
        sleep(waitTime);
    }
    if (forwardValue == 2) {
        forward(triangleX, triangleY, direction);
        printf("Reached end point!!!\n");
        break;
    }

    //Code to turn right
    right(triangleX, triangleY, direction);
    sleep(waitTime);
    if (direction == 4) {
        direction = 1;
    } else {
        direction += 1;
    }

    //Code to turn left
    left(triangleX, triangleY, direction);
    sleep(waitTime);
    if (direction == 1) {
        direction = 4;
    } else {
        direction -= 1;
    }
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}