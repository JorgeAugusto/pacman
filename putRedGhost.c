#include "pacman.h"

void putGhostRed(t_pacman *pacman)
{
	
	extern int	map[H][W];
	int			tmp;
	int			lenClosest = INT_MAX;
	int			lenClosestFarest = 0;
	
	pacman->ghostRedMove = (t_pos){0, 0};
	map[pacman->ghostRed.y][pacman->ghostRed.x] = pacman->ghostRedMapPreviousValue;
	
	//check move down
	if (map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 2 &&
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 7 &&
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 6 &&
		map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y + 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostRedMove = (t_pos) {0, 1};
			pacman->ghostRedMapPreviousValue = map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y + 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostRedMove = (t_pos) {0, 1};
			pacman->ghostRedMapPreviousValue = map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0];
		}
	}
	//check move up
	if (map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 2 &&
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 7 &&
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 6 &&
		map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y - 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostRedMove = (t_pos) {0, -1};
			pacman->ghostRedMapPreviousValue = map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y - 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostRedMove = (t_pos) {0, -1};
			pacman->ghostRedMapPreviousValue = map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0];
		}
	}
	//check move left
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 2 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 7 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 6 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x + 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostRedMove = (t_pos) {1, 0};
			pacman->ghostRedMapPreviousValue = map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x + 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostRedMove = (t_pos) {1, 0};
			pacman->ghostRedMapPreviousValue = map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1];
		}
	}
	//check move right
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 2 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 7 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 6 &&
		map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 8)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostRed.x - 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostRedMove = (t_pos) {-1, 0};
			pacman->ghostRedMapPreviousValue = map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostRed.x - 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostRedMove = (t_pos) {-1, 0};
			pacman->ghostRedMapPreviousValue = map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1];
		}
	}
	
	if (pacman->ghostRedMapPreviousValue == 3)
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
		pacman->pac = (t_pos){17, 20};
		pacman->pacMove = (t_pos){-1, 0};
		pacman->ghostRed = (t_pos){6, 8};
		pacman->ghostYellow = (t_pos){10, 10};
		pacman->ghostBlue = (t_pos){1, 4};
		pacman->ghostPink = (t_pos){16, 4};
		putTextMessage(pacman, "GET READY");
		sdlRenderClear(pacman);
		SDL_Delay(1500);
		pacman->ghostRedMapPreviousValue = 0;
		return ;
	}
	pacman->ghostRed.x += pacman->ghostRedMove.x;
	pacman->ghostRed.y += pacman->ghostRedMove.y;
	map[pacman->ghostRed.y][pacman->ghostRed.x] = 5;
	pacman->ghostRedRect = (SDL_Rect){pacman->ghostRed.x * 30, pacman->ghostRed.y * 30, 30, 30};
}


