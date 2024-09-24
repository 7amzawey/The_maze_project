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

    int directions[] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[r];
        directions[r] = temp;
    }
    for (int i = 0; i < 4; i++) {
        extern int nx = x + dx[directions[i]] * 2;
        extern int ny = y + dy[directions[i]] * 2;

        if (isValid(nx, ny) && map[nx][ny] == 1) {
           
        	map[x + dx[directions[i]]][y + dy[directions[i]]] = 0;
                carveMaze(nx, ny);
		
        }
    }
  map[nx][ny] = 2;  
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
    

    // Ensure the start is a path
    map[start_x][start_y] = 0;
}
// Function to print the maze for debugging
void printMaze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (map[x][y] == 1) {
                printf("#"); // Wall
            } else if (map[x][y] == 0){
                printf(" "); // Path
            } else {
		    printf("$");
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

