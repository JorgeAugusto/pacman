
#include "pacman.h"


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
	
	pacman->ghostRedRect.x = pacman->ghostRed.x * 30;
	pacman->ghostRedRect.y = pacman->ghostRed.y * 30;
	pacman->ghostRedRect.w = 30;
	pacman->ghostRedRect.h = 30;
	

	
	
}



void putGhostBlue(t_pacman *pacman)
{

	extern int	map[H][W];
	static int	tmpPos = 1;
	int			tmp;
	int			len = 5000;

//	if (tmpPos == 3)
//		exit(0);
	map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 0] = tmpPos;
	
	
	if (map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2)
						+ pow(pacman->ghostBlue.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove.x = 0;
			pacman->ghostBlueMove.y = 1;
		}
		tmpPos = map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0];
	}
	
	if (map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2)
						+ pow(pacman->ghostBlue.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove.x = 0;
			pacman->ghostBlueMove.y = -1;
		}
		tmpPos = map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0];
	}
	
	if (map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostBlue.x + 1 - pacman->pac.x,2)
						+ pow(pacman->ghostBlue.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove.x = 1;
			pacman->ghostBlueMove.y = 0;
		}
		tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1];
	}
	
	if (map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostBlue.x - 1 - pacman->pac.x,2)
						+ pow(pacman->ghostBlue.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove.x = -1;
			pacman->ghostBlueMove.y = 0;
		}
		tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1];
	}
	
	pacman->ghostBlue.x += pacman->ghostBlueMove.x;
	pacman->ghostBlue.y += pacman->ghostBlueMove.y;
	
	map[pacman->ghostBlue.y][pacman->ghostBlue.x] = 6;
	
	pacman->ghostBlueRect.x = pacman->ghostBlue.x * 30;
	pacman->ghostBlueRect.y = pacman->ghostBlue.y * 30;
	pacman->ghostBlueRect.w = 30;
	pacman->ghostBlueRect.h = 30;

}
