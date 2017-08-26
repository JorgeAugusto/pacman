int map[22][19]={
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2},
	{2,0,2,2,0,2,2,2,0,2,0,2,2,2,0,2,2,0,2},
	{2,0,2,2,0,2,2,2,0,2,0,2,2,2,0,2,2,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,0,2,2,0,2,0,2,2,2,2,2,0,2,0,2,2,0,2},
	{2,0,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2},
	{2,2,2,2,0,2,2,2,0,2,0,2,2,2,0,2,2,2,2},
	{0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,2,0,0,0},
	{2,2,2,2,0,2,0,2,2,0,2,2,0,2,0,2,2,2,2},
	{0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0},
	{2,2,2,2,0,2,0,2,2,2,2,2,0,2,0,2,2,2,2},
	{0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,2,0,0,0},
	{2,2,2,2,0,2,0,2,2,2,2,2,0,2,0,2,2,2,2},
	{2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2},
	{2,0,2,2,0,2,2,2,0,2,0,2,2,2,0,2,2,0,2},
	{2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2},
	{2,2,0,2,0,2,0,2,2,2,2,2,0,2,0,2,0,2,2},
	{2,0,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,2},
	{2,0,2,2,2,2,2,2,0,2,0,2,2,2,2,2,2,0,2},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};

#include "pacman.h"

int main(void)
{
	int			stop;
	t_pacman	*pacman;
	
	stop = 0;
	pacman = (t_pacman *)malloc(sizeof(pacman));
	sdlInit(pacman);
	drawMap(pacman);
	

	

	
//	for(int i = 0; i < 22; i++)
//	{
//		for(int j = 0; j < 19; j++)
//		{
//			printf("%d, ", map[i][j]);
//		}
//		printf("\n");
//
//	}

	
	
	
	
	

	
	
	
	while (!stop)
	{
		while (SDL_PollEvent(&(pacman->sdl.e)))
		{
			if (pacman->sdl.e.type == SDL_QUIT ||
				pacman->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				stop = 1;
			else if (pacman->sdl.e.type == SDL_KEYUP)
			{
				if (pacman->sdl.e.key.keysym.sym == SDLK_SPACE)
				{
					map[4][4] = 3;
					drawMap(pacman);
				}
//				else if (map->sdl.e.key.keysym.sym == SDLK_RIGHT)
//					map->move = (t_pos){1, 0, 0};
//				else if (map->sdl.e.key.keysym.sym == SDLK_LEFT)
//					map->move = (t_pos){-1, 0, 0};
//				else if (map->sdl.e.key.keysym.sym == SDLK_UP)
//					map->move = (t_pos){0, -1, 0};
//				else if (map->sdl.e.key.keysym.sym == SDLK_DOWN)
//					map->move = (t_pos){0, 1, 0};
			}
		}
	}
	
	
	
	
	
	

	sdlDestroy(pacman);
	return 0;
}
