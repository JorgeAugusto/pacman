
#ifndef snake_h
#define snake_h

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# define WID 19*30
# define HEIG 22*30
# define W WID / 30
# define H HEIG / 30

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;
}					t_sdl;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_pacman
{
	t_sdl			sdl;
	
	
	int				stop;

	
}					t_pacman;

void				sdlInit(t_pacman *pacman);
void				sdlDestroy(t_pacman *pacman);
void				sdlRenderClear(t_pacman *pacman);
void				drawMap(t_pacman *pacman);

//int map[H][W];

#endif
