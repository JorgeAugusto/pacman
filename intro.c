#include "pacman.h"

void intro(t_pacman *pacman, int *introOff)
{
	int i;
	i = 0;

	SDL_Rect  rect;
	rect = (SDL_Rect) {0, 300, 30, 30};
	while(i < 7)
	{
		putTextMessage(pacman, "PACMAN");
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
		SDL_RenderPresent(pacman->sdl.renderer);
		rect.x -= 120;
		sdlRenderClear(pacman);
		SDL_Delay(250);
		i++;
	}
	SDL_RenderPresent(pacman->sdl.renderer);
	*introOff = 1;
}
