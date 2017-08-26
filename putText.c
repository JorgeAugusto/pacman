

#include "pacman.h"

void	putText(t_pacman *pacman)
{
	char buf[50] ={0};
	
	strcat(buf, "Score ");
	SDL_itoa(pacman->score, buf + 6, 10);
	
	pacman->sdl.font = TTF_OpenFont("arcadeclassic/ARCADECLASSIC.TTF", 22);
	pacman->sdl.surfaceScore = TTF_RenderText_Solid(pacman->sdl.font, buf,
													(SDL_Color){255, 255, 255});
	pacman->sdl.textureScore = SDL_CreateTextureFromSurface(pacman->sdl.renderer,
													 pacman->sdl.surfaceScore);
	pacman->sdl.rectScore.x = 5;
	pacman->sdl.rectScore.y = 22*30;
	pacman->sdl.rectScore.w = 200;
	pacman->sdl.rectScore.h = 30;
	
	SDL_RenderCopy(pacman->sdl.renderer, pacman->sdl.textureScore, NULL, &(pacman->sdl.rectScore));
}


	
