
#include "pacman.h"

void	drawCircle(t_pacman *pacman, t_pos center, int radius)
{

	for (int w = 0; w < radius * 2; w++)
	{
		for (int h = 0; h < radius * 2; h++)
		{
			int dx = radius - w; // horizontal offset
			int dy = radius - h; // vertical offset
			if ((dx*dx + dy*dy) <= (radius * radius))
			{
				SDL_RenderDrawPoint(pacman->sdl.renderer, center.x + dx, center.y + dy);
			}
		}
	}
}

