#include <stdio.h>
#include "graphics.h"
#include <stdlib.h>
#include <time.h>

// Declare global variables and constants
const int width = 560;
const int height = 560;

// Set start position
int currentI = 0, currentJ = 1;

// Create grid for the maze
int grid[12][12] = {
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1}
};

// Function to draw main path of the maze including the finish line
void generateMaze() {
    int randomVal = 0, randomNode = 0, running = 1, nodeCount = 0;
    grid[currentJ][currentI] = 0;
    currentI += 1;
    grid[currentJ][currentI] = 0;
    currentI += 1;
    grid[currentJ][currentI] = 0;
    currentJ += 1;
    grid[currentJ][currentI] = 0;
    while (grid[currentI][currentJ + 1] != 0 || grid[currentI+1][currentJ] != 0) {
        randomVal = rand() % (100 + 1 - 1) + 1;
        if (randomVal >= 50) {
            currentJ += 1;
        } else {
            currentI += 1;
        }
        if (currentI == 11 || currentJ == 11) {
            grid[currentJ][currentI] = 2;
            break;
        } else {
            grid[currentJ][currentI] = 0;
        }
    }
}

// Function to draw the traps
void drawTraps() {
    int junctionI = 0, junctionJ = 0, randomVal = 0;
    junctionI = rand() % (10 + 1 - 1) + 1;
    junctionJ = rand() % (10 + 1 - 1) + 1;
    for (int i=0; i<= 50; i++) {
        junctionI = rand() % (10 + 1 - 1) + 1;
        junctionJ = rand() % (10 + 1 - 1) + 1;
        grid[junctionJ][junctionI] = 0;
    }
}

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

int main(void) {
    srand(time(0)); // Seed for random generator
    setWindowSize(width, height);
    generateMaze();
    drawTraps();
    drawBackground();
}