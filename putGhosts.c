
#include "pacman.h"

void putGhostRed(t_pacman *pacman)
{

	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			len = 5000;

//	if (tmpPos == 3)
//		exit(0);
	map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 0] = tmpPos;
	
	
	if (map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2)
						+ pow(pacman->ghostRed.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove.x = 0;
			pacman->ghostRedMove.y = 1;
		}
		tmpPos = map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0];
	}
	
	if (map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2)
						+ pow(pacman->ghostRed.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove.x = 0;
			pacman->ghostRedMove.y = -1;
		}
		tmpPos = map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0];
	}
	
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostRed.x + 1 - pacman->pac.x,2)
						+ pow(pacman->ghostRed.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove.x = 1;
			pacman->ghostRedMove.y = 0;
		}
		tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1];
	}
	
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostRed.x - 1 - pacman->pac.x,2)
						+ pow(pacman->ghostRed.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove.x = -1;
			pacman->ghostRedMove.y = 0;
		}
		tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1];
	}
	
	pacman->ghostRed.x += pacman->ghostRedMove.x;
	pacman->ghostRed.y += pacman->ghostRedMove.y;
	
	map[pacman->ghostRed.y][pacman->ghostRed.x] = 5;
	
	
	
	

	
//	if (map[pacman->pac.y + pacman->pacMove.y][pacman->pac.x + pacman->pacMove.x] != 2)
//	{
//		map[pacman->pac.y][pacman->pac.x] = 0;
//		pacman->pac.x += pacman->pacMove.x;
//		pacman->pac.y += pacman->pacMove.y;
//		
//		if(pacman->pac.x == 0 && pacman->pac.y == 10)
//			pacman->pac = (t_pos){18, 10};
//		else if(pacman->pac.x == 18 && pacman->pac.y == 10)
//			pacman->pac = (t_pos){0, 10};
//		
//		if (map[pacman->pac.y][pacman->pac.x] == 1)
//		{
//			pacman->score += 10;
//			printf("score %d\n\n", pacman->score);
//		}
//		else if (map[pacman->pac.y][pacman->pac.x] == 4)
//		{
//			pacman->score += 50;
//			printf("score %d\n\n", pacman->score);
//		}
//		map[pacman->pac.y][pacman->pac.x] = 3;
//	}
}
