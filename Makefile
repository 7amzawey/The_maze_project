CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
LDFLAGS = -lSDL2
SRC = main.c
OBJ = $(SRC:.c=.o)
EXEC = game

all: $(OBJ)
    $(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

clean:
    rm -f $(OBJ) $(EXEC)
