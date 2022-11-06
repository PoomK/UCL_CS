// If turn right and cannot move forward, then it will go the other direction
// Stick to right hand side unless cannot then will turn left
#include <stdio.h>
#include "graphics.h"

// Declare global variables and constants
const int width = 560;
const int height = 560;
const int moveDistance = 40;
const int waitTime = 150;
int triangleX[3], triangleY[3], direction, currentXGrid, currentYGrid, forwardValue;

// 2D array for the maze
int grid[12][12] = {
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,1,0,0,0,1,0,1,1,1},
    {1,1,0,1,0,1,0,1,0,0,0,1},
    {1,1,0,1,0,0,0,0,0,1,1,1},
    {1,1,0,1,0,1,1,1,0,1,0,1},
    {1,1,0,0,0,1,1,0,0,0,0,1},
    {1,1,0,1,0,1,0,0,1,0,1,1},
    {1,0,0,1,0,1,0,1,1,0,1,1},
    {1,0,1,1,0,1,1,1,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,0,1,1},
    {1,1,0,1,1,1,1,0,0,1,1,1},
    {1,1,1,1,1,1,1,1,2,1,1,1}
};

// Function to draw the maze
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
        int count = 0;
        forwardValue = checkForward(currentXGrid, currentYGrid, direction);

        while (forwardValue == 0) {

            forward(triangleX, triangleY, direction);

            // Will check right side of robot. If open, it will break out of look and move
            right(triangleX, triangleY, direction);
            if (direction == 4) {
                direction = 1;
            } else {
                direction += 1;
            }
            if (checkForward(currentXGrid, currentYGrid, direction) == 0 || checkForward(currentXGrid, currentYGrid, direction) == 2) {
                break;
            } else {
                count += 1;
            }

            // Turn left and check if free, if yes then break
            left(triangleX, triangleY, direction);
            if (direction == 1) {
                direction = 4;
            } else {
                direction -= 1;
            }
            if (checkForward(currentXGrid, currentYGrid, direction) == 0 || checkForward(currentXGrid, currentYGrid, direction) == 2) {
                break;
            } else {
                count += 1;
            }

            // Turn left again and check if free, if yes then break
            left(triangleX, triangleY, direction);
            if (direction == 1) {
                direction = 4;
            } else {
                direction -= 1;
            }
            if (checkForward(currentXGrid, currentYGrid, direction) == 0 || checkForward(currentXGrid, currentYGrid, direction) == 2) {
                break;
            } else {
                count += 1;
            }

            right(triangleX, triangleY, direction);
            if (direction == 4) {
                direction = 1;
            } else {
                direction += 1;
            }

            // This loop will run if dead end is reached. The dead end will be marked as 1 so the robot will not return back. The robot will also u-turn so that it will face the other way and continue moving
            if (count == 3) {
                printf("Marked dead end\n");
                grid[currentYGrid][currentXGrid] = 1;
                right(triangleX, triangleY, direction);
                if (direction == 4) {
                    direction = 1;
                } else {
                    direction += 1;
                }
                right(triangleX, triangleY, direction);
                if (direction == 4) {
                    direction = 1;
                } else {
                    direction += 1;
                }
            }
        }
        if (checkForward(currentXGrid, currentYGrid, direction) == 2) {
            forward(triangleX, triangleY, direction);
            printf("Reached end point!!!\n");
            break;
        }
    }
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}