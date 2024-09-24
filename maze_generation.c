#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

extern int map[WIDTH][HEIGHT]; // Declare the map array

// Function for random values
void chooseRandomSidePoint(int *x, int *y) {
    int side = rand() % 4;
    switch (side) {
        case 0: // Top side
            *x = 0;
            *y = rand() % HEIGHT;
            break;
        case 1: // Right side
            *x = rand() % WIDTH;
            *y = HEIGHT - 1;
            break;
        case 2: // Bottom side
            *x = WIDTH - 1;
            *y = rand() % HEIGHT;
            break;
        case 3: // Left side
            *x = rand() % WIDTH;
            *y = 0;
            break;
    }
}

// Recursive function to carve the maze
void carveMaze(int x, int y) {
    map[x][y] = 0; // Mark as path

    int directions[4] = {0, 1, 2, 3}; // 0: up, 1: right, 2: down, 3: left
    // Shuffle directions
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[r];
        directions[r] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x, ny = y;
        switch (directions[i]) {
            case 0: ny -= 2; break; // Up
            case 1: nx += 2; break; // Right
            case 2: ny += 2; break; // Down
            case 3: nx -= 2; break; // Left
        }

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && map[nx][ny] == 1) {
		map[(x + nx) / 2][(y + ny) / 2] = 0;
		map[nx][ny] = 0;
		carveMaze(nx, ny);
	}

    }
}
void createExit() {
            int x, y;
            chooseRandomSidePoint(&x, &y);
            map[x][y] = 0;
    }
// Function to initialize and generate the maze
void generateMaze() {
	srand(time(NULL)); // Seed the random number generator
			  // Initialize the map with walls
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (x == 0 || x == WIDTH - 1 || y == 9 || y < HEIGHT - 1) {
				map[x][y] = 1;
			}
			else {
				map[x][y] = 1;
			}
		 }
	}
    createExit();
    int start_x, start_y;
    chooseRandomSidePoint(&start_x, &start_y);
    map[start_x][start_y] = 0;
    carveMaze(start_x, start_y);
}
