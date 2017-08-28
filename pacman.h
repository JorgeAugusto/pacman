
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
	
	t_pos			ghostRed;
	t_pos			ghostRedMove;
	SDL_Surface		*ghostRedImage;
	SDL_Texture		*ghostRedTexture;
	SDL_Rect			ghostRedRect;
	
	t_pos			ghostBlue;
	t_pos			ghostBlueMove;
	SDL_Surface		*ghostBlueImage;
	SDL_Texture		*ghostBlueTexture;
	SDL_Rect			ghostBlueRect;
	
	t_pos			ghostYellow;
	t_pos			ghostYellowMove;
	SDL_Surface		*ghostYellowImage;
	SDL_Texture		*ghostYellowTexture;
	SDL_Rect			ghostYellowRect;
	
	t_pos			ghostPink;
	t_pos			ghostPinkMove;
	SDL_Surface		*ghostPinkImage;
	SDL_Texture		*ghostPinkTexture;
	SDL_Rect			ghostPinkRect;
	

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
void				putGhostRed(t_pacman *pacman);
void				putGhostBlue(t_pacman *pacman);
void				putGhostYellow(t_pacman *pacman);
void				putGhostPink(t_pacman *pacman);
void				putTextMessage(t_pacman *pacman, char *str);
void				intro(t_pacman *pacman, int *introOff);
#endif
