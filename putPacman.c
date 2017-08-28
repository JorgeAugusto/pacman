
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
			pacman->score += 10;
		else if (map[pacman->pac.y][pacman->pac.x] == 4)
		{
			pacman->score += 50;
			pacman->eat = 28;
		}
		else if (map[pacman->pac.y][pacman->pac.x] == 5 && pacman->eat != 0)
		{
			pacman->ghostRed = (t_pos){9, 10};
			pacman->ghostRedMove = (t_pos){0, 0};
			pacman->score += 200;
		}
		else if (map[pacman->pac.y][pacman->pac.x] == 6 && pacman->eat != 0)
		{
			pacman->ghostBlue = (t_pos){1, 4};
			pacman->ghostBlueMove = (t_pos){0, 0};
			pacman->score += 200;
		}
		else if (map[pacman->pac.y][pacman->pac.x] == 7 && pacman->eat != 0)
		{
			pacman->ghostPink = (t_pos){16, 4};
			pacman->ghostPinkMove = (t_pos){0, 0};
			pacman->score += 200;
		}
		else if (map[pacman->pac.y][pacman->pac.x] == 8 && pacman->eat != 0)
		{
			pacman->ghostYellow = (t_pos){10, 10};
			pacman->ghostYellowMove = (t_pos){0, 0};
			pacman->score += 200;
		}
		map[pacman->pac.y][pacman->pac.x] = 3;
	}
}
