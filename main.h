#ifndef MAIN_H
#define MAIN_H
#define TILE_SIZE 32 
#define WIDTH 21
#define HEIGHT 21
#include <SDL2/SDL.h>
#include <stdio.h>

void generateMaze();
void draw_map(SDL_Renderer* rend);
int is_walkable(int x, int y);
void move_player(int* px, int* py, int* angle, SDL_Event event);
void draw_player(SDL_Renderer* rend, SDL_Texture* player_texture,  int px, int py, int angle);
void createExit();

#endif // MAZE_GENERATION_H
