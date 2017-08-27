
#include "pacman.h"

void putPacman(t_pacman *pacman)
{
	extern int map[H][W];
	
	if (map[pacman->pac.y + pacman->pacMove.y][pacman->pac.x + pacman->pacMove.x] != 2)
	{
		map[pacman->pac.y][pacman->pac.x] = 0;
		pacman->pac.x += pacman->pacMove.x;
		pacman->pac.y += pacman->pacMove.y;
		
		if(pacman->pac.x == 0 && pacman->pac.y == 10)
			pacman->pac = (t_pos){18, 10};
		else if(pacman->pac.x == 18 && pacman->pac.y == 10)
			pacman->pac = (t_pos){0, 10};
			
		if (map[pacman->pac.y][pacman->pac.x] == 1)
		{
			pacman->score += 10;
			printf("score %d\n\n", pacman->score);
		}
		else if (map[pacman->pac.y][pacman->pac.x] == 4)
		{
			pacman->score += 50;
			printf("score %d\n\n", pacman->score);
		}
		map[pacman->pac.y][pacman->pac.x] = 3;
	}
}
