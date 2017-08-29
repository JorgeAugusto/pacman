#include "pacman.h"

void putGhostPink(t_pacman *pacman)
{
	
	extern int	map[H][W];
	int			tmp;
	int			lenClosest = INT_MAX;
	int			lenClosestFarest = 0;
	
	pacman->ghostPinkMove = (t_pos){0, 0};
	map[pacman->ghostPink.y][pacman->ghostPink.x] = pacman->ghostPinkMapPreviousValue;
	
	//check move down
	if (map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] != 2 &&
		map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] != 5 &&
		map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] != 6 &&
		map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y + 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostPinkMove = (t_pos) {0, 1};
			pacman->ghostPinkMapPreviousValue = map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y + 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostPinkMove = (t_pos) {0, 1};
			pacman->ghostPinkMapPreviousValue = map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0];
		}
	}
	//check move up
	if (map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] != 2 &&
		map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] != 5 &&
		map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] != 6 &&
		map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y - 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostPinkMove = (t_pos) {0, -1};
			pacman->ghostPinkMapPreviousValue = map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y - 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostPinkMove = (t_pos) {0, -1};
			pacman->ghostPinkMapPreviousValue = map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0];
		}
	}
	//check move left
	if (map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] != 2 &&
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] != 5 &&
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] != 6 &&
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostPink.x + 1 - pacman->pac.x,2) + pow(pacman->ghostPink.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostPinkMove = (t_pos) {1, 0};
			pacman->ghostPinkMapPreviousValue = map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostPink.x + 1 - pacman->pac.x,2) + pow(pacman->ghostPink.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostPinkMove = (t_pos) {1, 0};
			pacman->ghostPinkMapPreviousValue = map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1];
		}
	}
	//check move right
	if (map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] != 2 &&
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] != 5 &&
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] != 6 &&
		map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostPink.x - 1 - pacman->pac.x,2) + pow(pacman->ghostPink.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostPinkMove = (t_pos) {-1, 0};
			pacman->ghostPinkMapPreviousValue = map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostPink.x - 1 - pacman->pac.x,2) + pow(pacman->ghostPink.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostPinkMove = (t_pos) {-1, 0};
			pacman->ghostPinkMapPreviousValue = map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1];
		}
	}
	
	if (pacman->ghostBlueMapPreviousValue == 3)
	{
		//if U eated by ghost
		pacman->pacmanLives--;
		if (pacman->pacmanLives == 0)
		{
			putTextMessage(pacman, "You lose");
			SDL_Delay(1500);
			exit(0);
		}
		map[pacman->pac.y][pacman->pac.x] = 0;
		setDefaultPosition(pacman);
		pacman->pacMove = (t_pos){-1, 0};
		putTextMessage(pacman, "GET READY");
		sdlRenderClear(pacman);
		SDL_Delay(1500);
		pacman->ghostBlueMapPreviousValue = 0;
		return ;
	}
	pacman->ghostPink.x += pacman->ghostPinkMove.x;
	pacman->ghostPink.y += pacman->ghostPinkMove.y;
	map[pacman->ghostPink.y][pacman->ghostPink.x] = 7;
	pacman->ghostPinkRect = (SDL_Rect){pacman->ghostPink.x * 30, pacman->ghostPink.y * 30, 30, 30};
}
