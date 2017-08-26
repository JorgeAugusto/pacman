
#include "pacman.h"

void putPacman(t_pacman *pacman)
{
	extern int map[H][W];
	
	if (map[pacman->pac.y + pacman->move.y][pacman->pac.x + pacman->move.x] != 2)
	{
		map[pacman->pac.y][pacman->pac.x] = 0;
		pacman->pac.x += pacman->move.x;
		pacman->pac.y += pacman->move.y;
		map[pacman->pac.y][pacman->pac.x] = 3;
	}
}
