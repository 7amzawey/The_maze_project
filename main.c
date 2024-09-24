#include "main.h" // Include the maze generation header

int main(void) {
    SDL_Window *win = SDL_CreateWindow("Maze",
                    SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED,
                    640, 640, SDL_WINDOW_SHOWN); // Changed window size to match the map size

    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    generateMaze(); // Generate the maze

    int px = 80;
    int py = 80;

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            move_player(&px, &py, event);
        }

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        draw_map(rend);
        draw_player(rend, px, py);

        SDL_RenderPresent(rend);
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
