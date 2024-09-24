#include "main.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

extern int map[WIDTH][HEIGHT]; // Declare the map array

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y) {
	return x > 0 && x < WIDTH - 1 && y > 0 && y < HEIGHT - 1;
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
		int nx = x + dx[directions[i]] * 2;
		int ny = y + dy[directions[i]] * 2;
	
	if (isValid(nx, ny) && map[nx][ny] == 1) {
		map[x + dx[directions[i]]][y + dy[directions[i]]] = 0;
		carveMaze(nx, ny);
	}
	}
}
// Function to initialize and generate the maze
void generateMaze() {
	srand(time(NULL)); // Seed the random number generator
			  // Initialize the map with walls
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			map[x][y] = 1;
		 }
	}
	int start_x = 1, start_y = 1;

	map[start_x][start_y] = 0;

	carveMaze(start_x, start_y);
}
