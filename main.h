#ifndef MAIN_H
#define MAIN_H
#define TILE_SIZE 64
#include <SDL2/SDL.h>
#include <stdio.h>

void generateMaze();
void draw_map(SDL_Renderer* rend);
int is_walkable(int x, int y);
void move_player(int* px, int* py, SDL_Event event);
void draw_player(SDL_Renderer* rend, int px, int py);
void createExit();

#endif // MAZE_GENERATION_H
