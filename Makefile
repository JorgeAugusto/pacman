
NAME = pacman

CC = gcc

CFLAGS =  -F. -Wall -Werror -Wextra

SDL_FLAGS = -framework SDL2 -framework SDL2_ttf -framework SDL2_image

OBJ = drawCircle.o main.o putRedGhost.o drawMap.o putBlueGhost.o putText.o initSdl.o putPacman.o putYellowGhost.o intro.o putPinkGhost.o

HEADER = pacman.h

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC)  $^ $(CFLAGS) $(SDL_FLAGS) -o $@

clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all
