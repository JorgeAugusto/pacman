
#ifndef snake_h
#define snake_h

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2_image/SDL_image.h>
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

typedef struct		s_ghost
{
	t_pos			ghostPos;
	t_pos			ghostMove;
	SDL_Surface		*ghostImage;
	SDL_Texture		*ghostTexture;
	SDL_Rect			ghostRect;
	int				ghostMapPreviousValue;
	int				id;
}					t_ghost;

typedef struct		s_pacman
{
	t_sdl			sdl;
	t_pos			pac;
	t_pos			pacMove;
	SDL_Surface		*pacImage;
	SDL_Surface		*pacImageUp;
	SDL_Surface		*pacImageDown;
	SDL_Surface		*pacImageLeft;
	SDL_Surface		*pacImageRight;
	SDL_Texture		*pacTexture;
	SDL_Rect		pacRect;
	int				pacmanLives;
	
	t_ghost			red;
	t_ghost			blue;
	t_ghost			pink;
	t_ghost			yellow;
	

	SDL_Surface		*buttonImage;
	SDL_Texture		*buttonTexture;
	SDL_Rect		buttonRect;

	int				eat;
	SDL_Surface		*ghostEatImage;
	SDL_Texture		*ghostEatTexture;

	int				stop;
	int				pause;
	int				score;
	SDL_Surface		*messageSurface;
	SDL_Rect			messageRect;
	SDL_Texture		*mssageTexture;

}					t_pacman;

void				sdlInit(t_pacman *pacman);
void				sdlDestroy(t_pacman *pacman);
void				sdlRenderClear(t_pacman *pacman);
void				drawMap(t_pacman *pacman);
void				putPacman(t_pacman *pacman);
void				putScore(t_pacman *pacman);
void				setLivesLevel(t_pacman *pacman);
void				putGhost(t_pacman *pacman, t_ghost *ghost);
void				putTextMessage(t_pacman *pacman, char *str);
void				intro(t_pacman *pacman, int *introOff);
void				setDefaultPosition(t_pacman *pacman);
void				checkPosition(t_pacman *pacman);
#endif
