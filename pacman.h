
#ifndef snake_h
#define snake_h

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>
# define WID 19*30
# define HEIG 22*30+30
# define W WID / 30
# define H HEIG / 30

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer		*renderer;
	SDL_Event		e;
	TTF_Font			*font;
	SDL_Surface		*surfaceScore;
	SDL_Rect			rectScore;
	SDL_Texture		*textureScore;
	
}					t_sdl;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_pacman
{
	t_sdl			sdl;
	t_pos			pac;
	t_pos			pacMove;
	
	t_pos			ghostRed;
	t_pos			ghostRedMove;
	
	
	int				stop;
	int				score;

	
}					t_pacman;

void				sdlInit(t_pacman *pacman);
void				sdlDestroy(t_pacman *pacman);
void				sdlRenderClear(t_pacman *pacman);
void				drawMap(t_pacman *pacman);
void				putPacman(t_pacman *pacman);
void				drawCircle(t_pacman *pacman, t_pos center, int radius);

void				putText(t_pacman *pacman);
void				putGhostRed(t_pacman *pacman);

//int map[H][W];

#endif
