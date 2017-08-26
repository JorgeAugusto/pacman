
#include "pacman.h"

void putPacman(t_pacman *pacman)
{
	extern int map[H][W];
	
	if (map[pacman->pac.y + pacman->move.y][pacman->pac.x + pacman->move.x] != 2)
	{
		map[pacman->pac.y][pacman->pac.x] = 0;
		pacman->pac.x += pacman->move.x;
		pacman->pac.y += pacman->move.y;
		
		if(pacman->pac.x == 0 && pacman->pac.y == 10)
			pacman->pac = (t_pos){18, 10};
		else if(pacman->pac.x == 18 && pacman->pac.y == 10)
			pacman->pac = (t_pos){0, 10};
			
		if (map[pacman->pac.y][pacman->pac.x] == 1)
		{
			pacman->score += 100;
			printf("score %d\n\n", pacman->score);
		}
		map[pacman->pac.y][pacman->pac.x] = 3;
	}
}
