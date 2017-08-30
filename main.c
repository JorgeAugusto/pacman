
#include "pacman.h"

	// set game map
int map[22][19] = {
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

void			setDefaultPosition(t_pacman *pacman)
{
	pacman->pac = (t_pos){17, 20};
	pacman->red.ghostPos = (t_pos){6, 8};
	pacman->yellow.ghostPos = (t_pos){10, 10};
	pacman->blue.ghostPos = (t_pos){1, 4};
	pacman->pink.ghostPos = (t_pos){16, 4};
	
	pacman->red.ghostMapPreviousValue = 0;
	pacman->yellow.ghostMapPreviousValue = 0;
	pacman->blue.ghostMapPreviousValue = (map[4][1] == 1) ? 1 : 0;
	pacman->pink.ghostMapPreviousValue = (map[4][16] == 1) ? 1 : 0;
	
	pacman->pacMove = (t_pos){-1, 0};
}

static void	initDefault(t_pacman *pacman, int *stop)
{
	// read textures and set beginning positions of ghosts/pacman
	*stop = 0;
	pacman->pause = 0;
	pacman->score = 0;
	pacman->eat = 0;
	
	setDefaultPosition(pacman);
	pacman->pacmanLives = 3;
	
	pacman->red.id = 5;
	pacman->blue.id = 6;
	pacman->pink.id = 7;
	pacman->yellow.id = 8;
	
	pacman->pacImage = IMG_Load("image/pacman.png");
	pacman->pacImageUp = IMG_Load("image/pacmanUp.png");
	pacman->pacImageDown = IMG_Load("image/pacmanDown.png");
	pacman->pacImageLeft = IMG_Load("image/pacmanLeft.png");
	pacman->pacImageRight = IMG_Load("image/pacmanRight.png");
	pacman->pacTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pacImageLeft);
	
	pacman->red.ghostImage = IMG_Load("image/red.png");
	pacman->red.ghostTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->red.ghostImage);
	
	pacman->blue.ghostImage = IMG_Load("image/blue.png");
	pacman->blue.ghostTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->blue.ghostImage);
	
	pacman->yellow.ghostImage = IMG_Load("image/yellow.png");
	pacman->yellow.ghostTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->yellow.ghostImage);
	
	pacman->pink.ghostImage = IMG_Load("image/pink.png");
	pacman->pink.ghostTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->pink.ghostImage);
	
	pacman->ghostEatImage = IMG_Load("image/ghost.png");
	pacman->ghostEatTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->ghostEatImage);
	
	pacman->buttonImage = IMG_Load("image/button.png");
	pacman->buttonTexture = SDL_CreateTextureFromSurface(pacman->sdl.renderer, pacman->buttonImage);
}

int main(void)
{
	int			stop;
	t_pacman	*pacman;
	static int	ghostOffset = 0;
	int			introOff = 0;

	pacman = (t_pacman *)malloc(sizeof(t_pacman));
	sdlInit(pacman);
	initDefault(pacman, &stop);
	
	while (!stop)
	{
		while (SDL_PollEvent(&(pacman->sdl.e)))
		{
			if (pacman->sdl.e.type == SDL_QUIT || pacman->sdl.e.key.keysym.sym == SDLK_ESCAPE)
				stop = 1;
			else if (pacman->sdl.e.type == SDL_KEYUP)
			{
				if (pacman->sdl.e.key.keysym.sym == SDLK_SPACE)
				{
					putTextMessage(pacman, "Pause");
					pacman->pause = (pacman->pause == 1) ? 0 : 1;
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
		if (introOff == 0)
			intro(pacman, &introOff);
		
		if (pacman->pause == 0)
		{
			sdlRenderClear(pacman);
			putPacman(pacman);
			drawMap(pacman);
			if ((ghostOffset = (ghostOffset == 1) ? 0 : 1 ) % 2)
			{
				putGhost(pacman, &pacman->red);
				putGhost(pacman, &pacman->yellow);
				putGhost(pacman, &pacman->blue);
				putGhost(pacman, &pacman->pink);
			}
			checkPosition(pacman);
			SDL_RenderPresent(pacman->sdl.renderer);
			SDL_Delay(250);
		}
		
	}
	sdlDestroy(pacman);
	return 0;
}
