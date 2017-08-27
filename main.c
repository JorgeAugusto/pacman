int map[22][19]={
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
	{2,4,2,2,1,2,2,2,1,2,1,2,2,2,1,2,2,4,2},
	{2,1,2,2,1,2,2,2,1,2,1,2,2,2,1,2,2,1,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{2,1,2,2,1,2,1,2,2,2,2,2,1,2,1,2,2,1,2},
	{2,1,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,2},
	{2,2,2,2,1,2,2,2,0,2,0,2,2,2,1,2,2,2,2},
	{0,0,0,2,1,2,0,0,0,0,0,0,0,2,1,2,0,0,0},
	{2,2,2,2,1,2,0,2,2,0,2,2,0,2,1,2,2,2,2},
	{0,0,0,0,1,0,0,2,0,0,0,2,0,0,1,0,0,0,0},
	{2,2,2,2,1,2,0,2,2,2,2,2,0,2,1,2,2,2,2},
	{0,0,0,2,1,2,0,0,0,0,0,0,0,2,1,2,0,0,0},
	{2,2,2,2,1,2,0,2,2,2,2,2,0,2,1,2,2,2,2},
	{2,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,2},
	{2,1,2,2,1,2,2,2,1,2,1,2,2,2,1,2,2,1,2},
	{2,4,1,2,1,1,1,1,1,1,1,1,1,1,1,2,1,4,2},
	{2,2,1,2,1,2,1,2,2,2,2,2,1,2,1,2,1,2,2},
	{2,1,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,2},
	{2,1,2,2,2,2,2,2,1,2,1,2,2,2,2,2,2,1,2},
	{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};

#include "pacman.h"

static void	initDefault(t_pacman *pacman, int *stop)
{
	*stop = 0;
	pacman->score = 0;
	pacman->pacMove = (t_pos){0, 0};
	pacman->pac = (t_pos){17, 20};
	
	pacman->ghostRed = (t_pos){10, 10};
}

int main(void)
{
	int			stop;
	t_pacman		*pacman;
	static int	ghost = 0;
	
	pacman = (t_pacman *)malloc(sizeof(t_pacman));
	
	sdlInit(pacman);
	initDefault(pacman, &stop);
	putPacman(pacman);
	drawMap(pacman);
	
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
				else if (pacman->sdl.e.key.keysym.sym == SDLK_UP)
					pacman->pacMove = (t_pos){0, -1};
				else if (pacman->sdl.e.key.keysym.sym == SDLK_DOWN)
					pacman->pacMove = (t_pos){0, 1};
				else if (pacman->sdl.e.key.keysym.sym == SDLK_RIGHT)
					pacman->pacMove = (t_pos){1, 0};
				else if (pacman->sdl.e.key.keysym.sym == SDLK_LEFT)
					pacman->pacMove = (t_pos){-1, 0};
			}
		}
		sdlRenderClear(pacman);
		putPacman(pacman);
		drawMap(pacman);
		if (ghost++ % 2)
			putGhostRed(pacman);
		
		
		SDL_RenderPresent(pacman->sdl.renderer);
		SDL_Delay(250);
		
//		for(int i = 0; i < 22; i++)
//		{
//			for(int j = 0; j < 19; j++)
//			{
//				printf("%d, ", map[i][j]);
//			}
//			printf("\n");
//			
//		}
//		printf("\n\n");
	}
	
	

	

//	sdlDestroy(pacman);
	return 0;
}
