#include "pacman.h"

void putGhostRed(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			lenClosest = INT_MAX;
	int			lenClosestFarest = 0;
	
	pacman->ghostRedMove = (t_pos){0, 0};
	map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 0] = tmpPos;
	
	if (map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 2 &&
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 7 &&
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 6 &&
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y + 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostRedMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y + 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostRedMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0];
		}
	}
	
	if (map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 2 &&
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 7 &&
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 6 &&
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y - 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostRedMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y - 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostRedMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0];
		}
	}
	
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 2 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 7 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 6 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x + 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostRedMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x + 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostRedMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1];
		}
	}
	
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 2 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 7 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 6 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostRedMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostRedMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1];
		}
	}
	if (tmpPos == 3)
	{
		pacman->pacmanLives--;
		map[pacman->pac.y][pacman->pac.x] = 0;
		pacman->pac = (t_pos){17, 20};
		pacman->pacMove = (t_pos){-1, 0};
		tmpPos = 0;
	}
	pacman->ghostRed.x += pacman->ghostRedMove.x;
	pacman->ghostRed.y += pacman->ghostRedMove.y;
	map[pacman->ghostRed.y][pacman->ghostRed.x] = 5;
	pacman->ghostRedRect = (SDL_Rect){pacman->ghostRed.x * 30, pacman->ghostRed.y * 30, 30, 30};
}


