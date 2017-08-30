
NAME = pacman

CC = gcc

CFLAGS =  -F. -Wall -Werror -Wextra

SDL_FLAGS = -framework SDL2 -framework SDL2_ttf -framework SDL2_image

OBJ = checkPosition.o initSdl.o main.o putPacman.o drawMap.o intro.o putGhost.o putText.o

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

