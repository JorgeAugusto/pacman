#include "pacman.h"

void putGhostRed(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			len = 5000;
	int			len2 = 0;
	
	pacman->ghostRedMove = (t_pos){0, 0};

	
	map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 0] = tmpPos;
	
	if (map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] == 0 ||
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] == 1 ||
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] == 3 ||
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y + 1 - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostRedMove = (t_pos) {0, 1};
				tmpPos = map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0];
			}
	}
	
	if (map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] == 0 ||
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] == 1 ||
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] == 3 ||
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y - 1 - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostRedMove = (t_pos) {0, -1};
				tmpPos = map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0];
			}
	}
	
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] == 0 ||
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] == 1 ||
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] == 3 ||
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x + 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x + 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostRedMove = (t_pos) {1, 0};
				tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1];
			}
	}
	
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] == 0 ||
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] == 1 ||
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] == 3 ||
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostRedMove = (t_pos) {-1, 0};
				tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1];
			}
	}
	if (tmpPos == 3)
	{
		putTextMessage(pacman, "You lose");
		SDL_RenderPresent(pacman->sdl.renderer);
		SDL_Delay(1500);
		exit(0);
	}
	
	pacman->ghostRed.x += pacman->ghostRedMove.x;
	pacman->ghostRed.y += pacman->ghostRedMove.y;
	
	map[pacman->ghostRed.y][pacman->ghostRed.x] = 5;
	pacman->ghostRedRect = (SDL_Rect){pacman->ghostRed.x * 30, pacman->ghostRed.y * 30, 30, 30};
}
