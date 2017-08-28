
#include "pacman.h"

void	putScore(t_pacman *pacman)
{
	char buf[50] = {0};
	
	strcat(buf, "Score ");
	SDL_itoa(pacman->score, buf + 6, 10);
	
	pacman->sdl.font = TTF_OpenFont("arcadeclassic/ARCADECLASSIC.TTF", 22);
	pacman->sdl.surfaceScore = TTF_RenderText_Solid(pacman->sdl.font, buf,
													(SDL_Color){255, 255, 255, 255});
	pacman->sdl.textureScore = SDL_CreateTextureFromSurface(pacman->sdl.renderer,
															pacman->sdl.surfaceScore);
	pacman->sdl.rectScore.x = 5;
	pacman->sdl.rectScore.y = HEIG - 30;
	pacman->sdl.rectScore.w = 200;
	pacman->sdl.rectScore.h = 30;
	
	SDL_RenderCopy(pacman->sdl.renderer, pacman->sdl.textureScore, NULL, &(pacman->sdl.rectScore));
}

void	putTextMessage(t_pacman *pacman, char *str)
{
	
	pacman->sdl.font = TTF_OpenFont("arcadeclassic/ARCADECLASSIC.TTF", 22);
	pacman->messageSurface = TTF_RenderText_Solid(pacman->sdl.font, str, (SDL_Color){255, 255, 255, 255});
	pacman->mssageTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->messageSurface);
	pacman->messageRect.x = 185;
	pacman->messageRect.y = (HEIG - 30)/2;
	pacman->messageRect.w = 200;
	pacman->messageRect.h = 30;
	SDL_RenderCopy(pacman->sdl.renderer, pacman->mssageTexture, NULL, &(pacman->messageRect));
	SDL_RenderPresent(pacman->sdl.renderer);
}

void	setLivesLevel(t_pacman *pacman)
{
	SDL_Rect	rect;
	int			i;

	i = 0;
	rect = (SDL_Rect) {WID - 90, HEIG - 30, 30, 30};
	while(i < pacman->pacmanLives)
	{
		pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImageRight);
		SDL_RenderCopy(pacman->sdl.renderer, pacman->pacTexture, NULL, &(rect));
		rect.x +=30;
		i++;
	}
}
