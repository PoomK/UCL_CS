#include <stdio.h>
#include "graphics.h"

/*
TO DO:
- Create array for path e.g. what action it takes
- Everytime it moves forward, robot will need to check all directions DONE and check if more
  than one exit, if yes then mark x and enter coords into array
    - Create function to check all directions
- if dead end, then move to previous x and go out different exit
- Create function to show that robot has already passed
- Create struct for stack and pop and push functions
*/

// Declare global variables and constants
const int width = 560;
const int height = 560;
const int moveDistance = 40;
const int waitTime = 40;
int triangleX[3], triangleY[3], direction, currentXGrid, currentYGrid, forwardValue;
char pathArray[100];


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

// Function to check all directions, return 0 if only 1 exit, return 1 if more than one exit, return 2 if dead end
// !!! Need to add to node array if more than 1 exit
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
    }
    if (count == 1) {
        printf("1 exit\n");
    } else if (count > 1) {
        printf("More than 1 exit\n");
    } else if (count == 0) {
        printf("Dead end\n");
    }
}

// Function to reverse the robot back to previous point with more than 1 exit
void reverseRobot(int triangleX[3], int triangleY[3], int direction) {
    for (int a=1; a<=2; a++) {
        right(triangleX, triangleY, direction);
        if (direction == 4) {
            direction = 1;
        } else {
            direction += 1;
        }
    }
}

// Function to show robot has already passed

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
            forward(triangleX, triangleY, direction);
            forwardValue = checkForward(currentXGrid, currentYGrid, direction);
            sleep(waitTime);
        }
        if (forwardValue == 2) {
            forward(triangleX, triangleY, direction);
            printf("Reached end point!!!\n");
            break;
        }
        printf("Hit wall\n");

        //Turn right and check if can move forward, if can't, then turn left twice to check other direction
        right(triangleX, triangleY, direction);
        sleep(waitTime);
        if (direction == 4) {
            direction = 1;
        } else {
            direction += 1;
        }
        forwardValue = checkForward(currentXGrid, currentYGrid, direction);
        if (forwardValue == 1) {
            left(triangleX, triangleY, direction);
            sleep(waitTime);
            if (direction == 1) {
                direction = 4;
            } else {
                direction -= 1;
            }
            left(triangleX, triangleY, direction);
            sleep(waitTime);
            if (direction == 1) {
                direction = 4;
            } else {
                direction -= 1;
            }
        }

        // If dead end then call reverse until reaches the previous point in node array
    }
}

int main(void) {
    setWindowSize(width, height);
    drawBackground();
    move();
}