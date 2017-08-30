
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
			pacman->red.ghostMapPreviousValue = 0;
			pacman->red.ghostPos = (t_pos){9, 10};
			pacman->red.ghostMove = (t_pos){0, 0};
			pacman->score += 200;
		}
		else if (map[pacman->pac.y][pacman->pac.x] == 6 && pacman->eat != 0)
		{
			pacman->blue.ghostPos = (t_pos){1, 4};
			pacman->blue.ghostMapPreviousValue = (map[4][1] == 1) ? 1 : 0;
			pacman->blue.ghostMove = (t_pos){0, 0};
			pacman->score += 200;
		}
		else if (map[pacman->pac.y][pacman->pac.x] == 7 && pacman->eat != 0)
		{
			pacman->pink.ghostMapPreviousValue = (map[4][16] == 1) ? 1 : 0;
			pacman->pink.ghostPos = (t_pos){16, 4};
			pacman->pink.ghostMove = (t_pos){0, 0};
			pacman->score += 200;
		}
		else if (map[pacman->pac.y][pacman->pac.x] == 8 && pacman->eat != 0)
		{
			pacman->yellow.ghostMapPreviousValue = 0;
			pacman->yellow.ghostPos = (t_pos){10, 10};
			pacman->yellow.ghostMove = (t_pos){0, 0};
			pacman->score += 200;
		}
		map[pacman->pac.y][pacman->pac.x] = 3;
	}
	if (pacman->eat != 0)
		pacman->eat--;
}
