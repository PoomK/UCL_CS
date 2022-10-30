#include <stdio.h>
#include "graphics.h"

// Maybe create array for the path, if dead end, then move back to previous place with more than 1 option
// Maybe array of previous actions and make it go opposite

// Declare global variables and constants
const int width = 520;
const int height = 520;
const int moveDistance = 40;
const int waitTime = 40;
int triangleX[3], triangleY[3], grid[11][11], direction, currentXGrid, currentYGrid, canMoveForwardYN;

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
    printf("Turned left\n");
}

/*
int atMarker() {
    int atMarkerEnd;
    //Use grid posiition to check whether grid position in front is 2
    return atMarkerEnd;
}
*/

// Return 0 if can move forward, return 1 if wall ahead
int canMoveForward(int currentXGrid, int currentYGrid, int direction) {
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
    printf("grid at 9,4: %d\n", grid[9][4]);
    printf("grid at 9,5: %d\n", grid[9][5]);
    printf("grid at 9,6: %d\n", grid[9][6]);
    printf("grid at 9,7: %d\n", grid[9][7]);
    if (direction == 1) { // Facing north
        return grid[currentXGrid][currentYGrid-1];
    } else if (direction == 2) { // Facing east
        return grid[currentXGrid + 1][currentYGrid];
    } else if (direction == 3) { // Facing south
        printf("%d\n",grid[currentXGrid][currentYGrid + 1]);
        return grid[currentXGrid][currentYGrid + 1];
    } else { // Facing west
        return grid[currentXGrid - 1][currentYGrid];
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

    while (running == 1) {
        canMoveForwardYN = canMoveForward(currentXGrid, currentYGrid, direction);
        printf("%d\n", canMoveForwardYN);
        //Keep moving forward until cannot move forward
        while (canMoveForwardYN == 0) {
            forward(triangleX, triangleY, direction);
            update(triangleX, triangleY);
            canMoveForwardYN = canMoveForward(currentXGrid, currentYGrid, direction);
            sleep(waitTime);
        }
        printf("Hit wall\n");
        //Turn right
        right(triangleX, triangleY, direction);
        update(triangleX, triangleY);
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