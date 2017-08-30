
#include "pacman.h"

void		checkPosition(t_pacman *pacman)
{
	extern int	map[H][W];
	
	// check if ghost and pacman on same position on map
	if ((pacman->red.ghostPos.x == pacman->pac.x && pacman->red.ghostPos.y == pacman->pac.y) ||
		(pacman->blue.ghostPos.x == pacman->pac.x && pacman->blue.ghostPos.y == pacman->pac.y) ||
		(pacman->yellow.ghostPos.x == pacman->pac.x && pacman->yellow.ghostPos.y == pacman->pac.y) ||
		(pacman->pink.ghostPos.x == pacman->pac.x && pacman->pink.ghostPos.y == pacman->pac.y) )
	{
		pacman->pacmanLives--;
		if (pacman->pacmanLives == 0)
		{
			putTextMessage(pacman, "You lose");
			SDL_Delay(1500);
			exit(0);
		}
		
		// put to map previous value
		map[pacman->red.ghostPos.y][pacman->red.ghostPos.x] = pacman->red.ghostMapPreviousValue;
		map[pacman->blue.ghostPos.y][pacman->blue.ghostPos.x] = pacman->blue.ghostMapPreviousValue;
		map[pacman->pink.ghostPos.y][pacman->pink.ghostPos.x] = pacman->pink.ghostMapPreviousValue;
		map[pacman->yellow.ghostPos.y][pacman->yellow.ghostPos.x] = pacman->yellow.ghostMapPreviousValue;
		
		map[pacman->pac.y][pacman->pac.x] = 0;
		setDefaultPosition(pacman);
		
		putTextMessage(pacman, "Get Ready!");
		SDL_Delay(1500);
		sdlRenderClear(pacman);
	}

}
