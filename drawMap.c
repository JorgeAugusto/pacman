
#include "pacman.h"

void	drawMap(t_pacman *pacman)
{
	extern int map[H][W];
	

	
	SDL_Rect  rect;
	rect = (SDL_Rect) {0, 0, 30, 30};
	for (int y = 0; y < 22; y++)
	{
		rect.x = 0;
		for (int x = 0; x < 19; x++)
		{
			if (map[y][x] == 0)
			{
				SDL_SetRenderDrawColor(pacman->sdl.renderer, 0, 0, 0, 255);
				SDL_RenderFillRect(pacman->sdl.renderer, &rect);
				
			}
			else if (map[y][x] == 2)
			{
				SDL_SetRenderDrawColor(pacman->sdl.renderer, 23, 23, 110, 255);
				SDL_RenderFillRect(pacman->sdl.renderer, &rect);
				SDL_SetRenderDrawColor(pacman->sdl.renderer, 50, 50, 50, 255);
			}
			else if (map[y][x] == 3)
			{
				SDL_SetRenderDrawColor(pacman->sdl.renderer, 255, 255, 0, 255);
				SDL_RenderFillRect(pacman->sdl.renderer, &rect);

			}
			
			SDL_RenderDrawRect(pacman->sdl.renderer, &rect);
			rect.x += 30;
			rect = (SDL_Rect) {rect.x, rect.y, rect.h, rect.w};
		}
		rect.y += 30;
	}
	SDL_RenderPresent(pacman->sdl.renderer);

}



