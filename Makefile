
NAME = pacman

CC = gcc

CFLAGS =  -F. -Wall -Werror -Wextra

SDL_FLAGS = -framework SDL2 -framework SDL2_ttf -framework SDL2_image

OBJ = main.o putRedGhost.o drawMap.o putBlueGhost.o putText.o initSdl.o putPacman.o putYellowGhost.o intro.o putPinkGhost.o

HEADER = pacman.h

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC)  $^ $(CFLAGS) $(SDL_FLAGS) -o $@

clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

sdl2:
	cp -r SDL2_ttf.framework ~/Library/Frameworks/
	cp -r SDL2_image.framework ~/Library/Frameworks/
	cp -r SDL2.framework ~/Library/Frameworks/

