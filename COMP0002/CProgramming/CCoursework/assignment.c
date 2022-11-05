#include <stdio.h>
#include "graphics.h"

// Global constants and variables
const int width = 560;
const int height = 560;
const int moveDistance = 40;
const int waitTime = 500;
int triangleX[3], triangleY[3], direction, currentXGrid, currentYGrid, forwardValue;
char stepArr[1000]; // Array to store steps taken
int xNodes[100] = {}, yNodes[100] = {}; // Arrays to store the x and y values of the nodes
int currentCount = -1, nodeCount = -1, deadEndYN;

// 2D array for the maze
int grid[12][12] = {
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,1,0,0,0,1,0,1,1,1},
    {1,1,0,1,0,1,0,1,0,0,0,1},
    {1,1,0,1,0,0,0,0,0,1,1,1},
    {1,1,0,1,0,1,1,1,0,1,0,1},
    {1,1,0,0,0,1,1,0,0,0,0,1},
    {1,1,0,1,0,0,0,0,1,0,1,1},
    {1,0,0,1,0,1,0,1,1,0,1,1},
    {1,0,1,1,0,1,1,1,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,0,1,1},
    {1,1,0,1,1,1,1,0,0,1,1,1},
    {1,1,1,1,1,1,1,1,2,1,1,1}
};

//  Function to draw the maze
void drawBackground() {
    background();
    int i, j;
    //Grid for the maze (1 for black or 0 for white or 2 for grey)
    for (i = 0; i <= 11; i++) {
        for (j = 0; j <= 11; j++) {
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

void update(int triangleX[3], int triangleY[3]) {
    clear();
    //Draw shape
    fillPolygon(3,triangleX,triangleY);
}

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
    sleep(waitTime);
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
    sleep(waitTime);
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
    sleep(waitTime);
}

// Return 0 if can move forward, return 1 if wall ahead, return 2 if end point ahead
int checkForward(int currentXGrid, int currentYGrid, int direction) {
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

void checkAllDirections(int currentXGrid, int currentYGrid, int direction) {
    int count = 0;
    for (int i=1; i <= 4; i++) {
        if (checkForward(currentXGrid, currentYGrid, direction) == 0) {
            count += 1;
        }
        right(triangleX, triangleY, direction);
        if (direction == 4) {
            direction = 1;
        } else {
            direction += 1;
        }
        sleep(waitTime);
    }
    if (count == 1) {
        //printf("1 exit\n");
    } else if (count > 1) {
        //printf("More than 1 exit\n");
        nodeCount += 1;
        xNodes[nodeCount] = currentXGrid;
        yNodes[nodeCount] = currentYGrid;
        printf("Added node at %d,%d\n", currentXGrid, currentYGrid);
        printf("Previous node: %d, %d\n", xNodes[nodeCount], yNodes[nodeCount]);
    } else if (count == 0) {
        printf("Detected dead end\n");
        deadEndYN = 1;
    }
}

// Add 3 into grid to show that robot already passed
void addPath(int currentXGrid, int currentYGrid){
    grid[currentYGrid][currentXGrid] = 3;
}

void move() {
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
    checkForward(currentXGrid, currentYGrid, direction);

    while (running == 1) {
        forwardValue = checkForward(currentXGrid, currentYGrid, direction);
        //Keep moving forward until cannot move forward
        while (forwardValue == 0) {
            checkAllDirections(currentXGrid, currentYGrid, direction);
            addPath(currentXGrid, currentYGrid);
            forward(triangleX, triangleY, direction);
            forwardValue = checkForward(currentXGrid, currentYGrid, direction);
            sleep(waitTime);
        }
        if (forwardValue == 2) {
            forward(triangleX, triangleY, direction);
            printf("Reached end point!!!\n");
            break;
        }
        printf("\n");
        //printf("Hit wall\n");

        // If dead end then reverse to previous node
        /*checkAllDirections(currentXGrid, currentYGrid, direction);
        if (deadEndYN == 1) {
            reverseRobot(triangleX, triangleY, direction);
        }*/

        //Turn right and check if can move forward, if can't, then turn left twice to check other direction
        right(triangleX, triangleY, direction);
        sleep(waitTime);
        if (direction == 4) {
            direction = 1;
        } else {
            direction += 1;
        }
    }
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}