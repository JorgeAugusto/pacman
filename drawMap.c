
#include "pacman.h"

void	drawMap(t_pacman *pacman)
{
	extern int	map[H][W];
	int			winFlag = 0;

	SDL_Rect  rect;
	rect = (SDL_Rect) {0, 0, 30, 30};
	for (int y = 0; y < 22; y++)
	{
		rect.x = 0;
		for (int x = 0; x < 19; x++)
		{
			if (map[y][x] == 0) // empty place
			{
				SDL_SetRenderDrawColor(pacman->sdl.renderer, 0, 0, 0, 255);
				SDL_RenderFillRect(pacman->sdl.renderer, &rect);
				SDL_RenderDrawRect(pacman->sdl.renderer, &rect);
				
			}
			else if (map[y][x] == 1) // coin
			{
				SDL_SetRenderDrawColor(pacman->sdl.renderer, 255, 255, 255, 255);
				SDL_RenderDrawPoint(pacman->sdl.renderer, rect.x + 30/2, rect.y + 30/2);
				SDL_RenderDrawPoint(pacman->sdl.renderer, rect.x + 30/2, rect.y + 32/2);
				SDL_RenderDrawPoint(pacman->sdl.renderer, rect.x + 32/2, rect.y + 32/2);
				winFlag = 1;
			}
			else if (map[y][x] == 4) // big coin
			{
				pacman->buttonRect = (SDL_Rect){rect.x + 5, rect.y + 5, 20, 20};
				SDL_RenderCopy(pacman->sdl.renderer, pacman->buttonTexture, NULL, &(pacman->buttonRect));
				winFlag = 1;
			}
			else if (map[y][x] == 2) // wall
			{
				SDL_SetRenderDrawColor(pacman->sdl.renderer, 23, 23, 110, 255);
				SDL_RenderFillRect(pacman->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(pacman->sdl.renderer, 50, 50, 50, 255);
				SDL_RenderDrawRect(pacman->sdl.renderer, &rect);
			}
			else if (map[y][x] == 3) //pacman
			{
				pacman->pacRect = (SDL_Rect){rect.x, rect.y, 30, 30};
				if (pacman->pacMove.x == 0 && pacman->pacMove.y == 1)
					pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImageDown);
				else if (pacman->pacMove.x == 0 && pacman->pacMove.y == -1)
					pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImageUp);
				else if (pacman->pacMove.x == 1 && pacman->pacMove.y == 0)
					pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImageRight);
				else if (pacman->pacMove.x == -1 && pacman->pacMove.y == 0)
					pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImageLeft);
				if ((x % 2 && y % 2) || (x % 2 == 0 && y % 2 == 0))
					pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImage);
				SDL_RenderCopy(pacman->sdl.renderer, pacman->pacTexture, NULL, &(pacman->pacRect));
			}
			else if (map[y][x] == 5) //red ghost
				SDL_RenderCopy(pacman->sdl.renderer, (pacman->eat == 0) ? pacman->ghostRedTexture : pacman->ghostEatTexture, NULL, &(pacman->ghostRedRect));
			else if (map[y][x] == 6) //blue ghost
				SDL_RenderCopy(pacman->sdl.renderer, (pacman->eat == 0) ? pacman->ghostBlueTexture : pacman->ghostEatTexture, NULL, &(pacman->ghostBlueRect));
			else if (map[y][x] == 7) //pink ghost
				SDL_RenderCopy(pacman->sdl.renderer, (pacman->eat == 0) ? pacman->ghostPinkTexture : pacman->ghostEatTexture, NULL, &(pacman->ghostPinkRect));
			else if (map[y][x] == 8) //yellow ghost
				SDL_RenderCopy(pacman->sdl.renderer, (pacman->eat == 0) ? pacman->ghostYellowTexture : pacman->ghostEatTexture, NULL, &(pacman->ghostYellowRect));
			rect.x += 30;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		rect.y += 30;
	}
	putScore(pacman);
	setLivesLevel(pacman);
	if (winFlag == 0)
	{
		putTextMessage(pacman, "YOU WIN!");
		SDL_Delay(2500);
		exit(0);
	}
}
