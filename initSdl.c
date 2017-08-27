
#include "pacman.h"

void	sdlInit(t_pacman *pacman)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_JPG);
	pacman->sdl.window = SDL_CreateWindow("Pacman", 300, 300, WID, HEIG,
			SDL_WINDOW_OPENGL);
	pacman->sdl.renderer = SDL_CreateRenderer(pacman->sdl.window, -1,
			SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(pacman->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(pacman->sdl.renderer);
}

void	sdlDestroy(t_pacman *pacman)
{
	SDL_DestroyRenderer(pacman->sdl.renderer);
	SDL_DestroyWindow(pacman->sdl.window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void	sdlRenderClear(t_pacman *pacman)
{
	SDL_SetRenderDrawColor(pacman->sdl.renderer, 0, 0, 0, 255);
	SDL_RenderClear(pacman->sdl.renderer);
}
