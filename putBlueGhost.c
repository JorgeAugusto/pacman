#include "pacman.h"

void putGhostBlue(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			len = 5000;
	int			len2 = 0;
	
	pacman->ghostBlueMove = (t_pos){0, 0};
	
	
	map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 0] = tmpPos;
	
	if (map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] == 0 ||
		map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] == 1 ||
		map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] == 3 ||
		map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y + 1 - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostBlueMove = (t_pos) {0, 1};
				tmpPos = map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0];
			}
	}
	
	if (map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] == 0 ||
		map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] == 1 ||
		map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] == 3 ||
		map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y - 1 - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostBlueMove = (t_pos) {0, -1};
				tmpPos = map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0];
			}
	}
	
	if (map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] == 0 ||
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] == 1 ||
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] == 3 ||
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostBlue.x + 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostBlue.x + 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostBlueMove = (t_pos) {1, 0};
				tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1];
			}
	}
	
	if (map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] == 0 ||
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] == 1 ||
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] == 3 ||
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostBlueMove = (t_pos) {-1, 0};
				tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1];
			}
	}
	if (tmpPos == 3)
	{
		putTextMessage(pacman, "You lose");
		SDL_RenderPresent(pacman->sdl.renderer);
		SDL_Delay(1500);
		exit(0);
	}
	
	pacman->ghostBlue.x += pacman->ghostBlueMove.x;
	pacman->ghostBlue.y += pacman->ghostBlueMove.y;
	
	map[pacman->ghostBlue.y][pacman->ghostBlue.x] = 6;
	pacman->ghostBlueRect = (SDL_Rect){pacman->ghostBlue.x * 30, pacman->ghostBlue.y * 30, 30, 30};
}

