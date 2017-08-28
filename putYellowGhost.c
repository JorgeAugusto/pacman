#include "pacman.h"

void putGhostYellow(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			len = 5000;
	int			len2 = 0;
	
	pacman->ghostYellowMove = (t_pos){0, 0};
	
	
	map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 0] = tmpPos;
	
	if (map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] == 0 ||
		map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] == 1 ||
		map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] == 3 ||
		map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2) + pow(pacman->ghostYellow.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostYellowMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2) + pow(pacman->ghostYellow.y + 1 - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostYellowMove = (t_pos) {0, 1};
				tmpPos = map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0];
			}
	}
	
	if (map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] == 0 ||
		map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] == 1 ||
		map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] == 3 ||
		map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2) + pow(pacman->ghostYellow.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostYellowMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2) + pow(pacman->ghostYellow.y - 1 - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostYellowMove = (t_pos) {0, -1};
				tmpPos = map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0];
			}
	}
	
	if (map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] == 0 ||
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] == 1 ||
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] == 3 ||
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostYellow.x + 1 - pacman->pac.x,2) + pow(pacman->ghostYellow.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostYellowMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostYellow.x + 1 - pacman->pac.x,2) + pow(pacman->ghostYellow.y - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostYellowMove = (t_pos) {1, 0};
				tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1];
			}
	}
	
	if (map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] == 0 ||
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] == 1 ||
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] == 3 ||
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - 1 - pacman->pac.x,2) + pow(pacman->ghostYellow.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostYellowMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1];
		}
		else
			if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - 1 - pacman->pac.x,2) + pow(pacman->ghostYellow.y - pacman->pac.y,2))) > len2)
			{
				len2 = tmp;
				pacman->ghostYellowMove = (t_pos) {-1, 0};
				tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1];
			}
	}
	if (tmpPos == 3)
	{
		putTextMessage(pacman, "You lose");
		SDL_RenderPresent(pacman->sdl.renderer);
		SDL_Delay(1500);
		exit(0);
	}
	
	pacman->ghostYellow.x += pacman->ghostYellowMove.x;
	pacman->ghostYellow.y += pacman->ghostYellowMove.y;
	
	map[pacman->ghostYellow.y][pacman->ghostYellow.x] = 8;
	pacman->ghostYellowRect = (SDL_Rect){pacman->ghostYellow.x * 30, pacman->ghostYellow.y * 30, 30, 30};
}
