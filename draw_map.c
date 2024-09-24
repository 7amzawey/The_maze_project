#include "main.h"
/**
 * draw_map - draws the grids map
 * @rend: the Renderer that draws the grids map
 */

int map[WIDTH][HEIGHT];

void draw_map(SDL_Renderer* rend) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			SDL_Rect tile;
			tile.x = j * TILE_SIZE;
			tile.y = i * TILE_SIZE;
			tile.w = TILE_SIZE;
			tile.h = TILE_SIZE;

		if (map[i][j] == 1) {
			SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
			SDL_RenderFillRect(rend, &tile);
		}

		else {
			SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
			SDL_RenderFillRect(rend, &tile);
		}

		SDL_SetRenderDrawColor(rend, 100, 100, 100, 225);
		SDL_RenderDrawRect(rend, &tile);
		}
	}
}

/**
 * draw_player - draw a player for the maze.
 * @rend: the Renderer.
 * @px: the x cordinate.
 * @py: the y cordinate.
 */

void draw_player(SDL_Renderer* rend, int px, int py) {
	SDL_Rect player;
	player.w = 16;
	player.h = 8;
	player.x = px;
	player.y = py;
	SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
	SDL_RenderFillRect(rend, &player);
	SDL_RenderDrawLine(rend, px + 8, py, px + 8, py + 16);
}


/**
 * is_walkable - checks where the next place is walkable or not.
 *@x: is the x position.
 *@y: is the y position.
 */
int is_walkable(int x, int y) {
	int tx_left = x / TILE_SIZE;
	int tx_right = (x + 15) / TILE_SIZE;
	int ty_top = y / TILE_SIZE;
	int ty_bottom = (y + 7) / TILE_SIZE;
	return (tx_left >= 0 && tx_right < WIDTH && ty_top >= 0 && ty_bottom < HEIGHT &&
			map[ty_top][tx_left] == 0 && map[ty_top][tx_right] == 0 &&
	    		map[ty_bottom][tx_left] == 0 && map[ty_bottom][tx_right] == 0);
}

void move_player(int* px, int* py, SDL_Event event) {
	int new_x = *px;
	int new_y = *py;

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_UP:
				new_y -= 4;
				break;
			case SDLK_DOWN:
				new_y += 4;
				break;
			case SDLK_LEFT:
				new_x -= 4;
				break;
			case SDLK_RIGHT:
				new_x += 4;
				break;
		}
		if (is_walkable(new_x, new_y)) {
			*px = new_x;
			*py = new_y;
		}
	}
}
