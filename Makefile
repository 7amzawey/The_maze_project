CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_image -lm

maze: main.o maze_generation.o draw_map.o
	$(CC) $(CFLAGS) -o maze main.o maze_generation.o draw_map.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

draw_map.o: draw_map.c
	$(CC) $(CFLAGS) -c draw_map.c

maze_generation.o: maze_generation.c
	$(CC) $(CFLAGS) -c maze_generation.c
clean:
	rm -f maze main.o maze_generation.o draw_map.o

