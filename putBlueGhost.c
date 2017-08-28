#include "pacman.h"

void putGhostBlue(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			lenClosest = INT_MAX;
	int			lenClosestFarest = 0;
	
	pacman->ghostBlueMove = (t_pos){0, 0};
	map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 0] = tmpPos;
	
	if (map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] != 2 &&
		map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] != 5 &&
		map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] != 7 &&
		map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y + 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostBlueMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y + 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostBlueMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0];
		}
	}
	
	if (map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] != 2 &&
		map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] != 5 &&
		map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] != 7 &&
		map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y - 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostBlueMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y - 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostBlueMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0];
		}
	}
	
	if (map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] != 2 &&
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] != 5 &&
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] != 7 &&
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostBlue.x + 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostBlueMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostBlue.x + 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostBlueMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1];
		}
	}
	
	if (map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] != 2 &&
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] != 5 &&
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] != 7 &&
		map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostBlueMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostBlue.x - 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostBlueMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1];
		}
	}
	if (tmpPos == 3)
	{
		pacman->pacmanLives--;
		if (pacman->pacmanLives == 0)
		{
			putTextMessage(pacman, "You lose");
			SDL_Delay(1500);
			exit(0);
		}
		map[pacman->pac.y][pacman->pac.x] = 0;
		pacman->pac = (t_pos){17, 20};
		pacman->pacMove = (t_pos){-1, 0};
		pacman->ghostRed = (t_pos){6, 8};
		pacman->ghostYellow = (t_pos){10, 10};
		pacman->ghostBlue = (t_pos){1, 4};
		pacman->ghostPink = (t_pos){16, 4};
		putTextMessage(pacman, "GET READY");
		sdlRenderClear(pacman);
		SDL_Delay(1500);
		tmpPos = 0;
		return ;
	}
	pacman->ghostBlue.x += pacman->ghostBlueMove.x;
	pacman->ghostBlue.y += pacman->ghostBlueMove.y;
	map[pacman->ghostBlue.y][pacman->ghostBlue.x] = 6;
	pacman->ghostBlueRect = (SDL_Rect){pacman->ghostBlue.x * 30, pacman->ghostBlue.y * 30, 30, 30};
}

