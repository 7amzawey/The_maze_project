#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#define WIDTH 21 // Must be odd to ensure no double walls
#define HEIGHT 21 // Must be odd

int map[WIDTH][HEIGHT]; // Declare the map array

// Direction vectors: up, right, down, left
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

// Check if a cell is within bounds and can be carved
bool isValid(int x, int y) {
    return x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1;
}

// Recursive function to carve the maze
void carveMaze(int x, int y) {
    map[x][y] = 0; // Mark current cell as path

    // Randomly shuffle directions
    int directions[] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[r];
        directions[r] = temp;
    }

    // Carve the maze in random order
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[directions[i]] * 2;
        int ny = y + dy[directions[i]] * 2;

        // Check if the neighboring cell is within bounds and is a wall
        if (isValid(nx, ny) && map[nx][ny] == 1) {
            // Remove the wall between the current cell and the neighbor
            map[x + dx[directions[i]]][y + dy[directions[i]]] = 0;
            // Recurse to the neighboring cell
            carveMaze(nx, ny);
        }
    }
}

// Function to initialize and generate the maze
void generateMaze() {
    srand(time(NULL)); // Seed random number generator

    // Fill the maze with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            map[x][y] = 1; // Set all cells as walls
        }
    }

    // Start carving from a random cell inside the maze (1,1)
    int start_x = 1;
    int start_y = 1;
    carveMaze(start_x, start_y);

    // Create one random exit on the outer edge
    map[WIDTH - 2][HEIGHT - 2] = 0; // You can randomize this as well

    // Ensure the start is a path
    map[start_x][start_y] = 0;
}

// Function to print the maze for debugging
void printMaze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (map[x][y] == 1) {
                printf("#"); // Wall
            } else {
                printf(" "); // Path
            }
        }
        printf("\n");
    }
}

int main() {
    generateMaze();
    printMaze(); // Output the maze to the console
    return 0;
}

