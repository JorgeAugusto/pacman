#include "pacman.h"

void intro(t_pacman *pacman, int *introOff)
{
	int			i;
	SDL_Rect	rect;
	i = 0;

	rect = (SDL_Rect) {0, 300, 30, 30};
	sdlRenderClear(pacman);
	while(i < 7)
	{
		rect.x += 30;
		SDL_RenderCopy(pacman->sdl.renderer, pacman->ghostYellowTexture, NULL, &(rect));
		rect.x += 30;
		SDL_RenderCopy(pacman->sdl.renderer, pacman->ghostPinkTexture, NULL, &(rect));
		rect.x += 30;
		SDL_RenderCopy(pacman->sdl.renderer,  pacman->ghostBlueTexture, NULL, &(rect));
		rect.x += 30;
		SDL_RenderCopy(pacman->sdl.renderer, pacman->ghostRedTexture , NULL, &(rect));
		rect.x += 60;
		pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImageRight);
		if (i % 2)
			pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImage);
		
		SDL_RenderCopy(pacman->sdl.renderer, pacman->pacTexture, NULL, &(rect));
		rect.x -= 120;
		putTextMessage(pacman, "PACMAN");
		sdlRenderClear(pacman);
		SDL_Delay(250);
		i++;
	}
	SDL_RenderPresent(pacman->sdl.renderer);
	*introOff = 1;
}
