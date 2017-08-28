#include "pacman.h"

void putGhostYellow(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			lenClosest = INT_MAX;
	int			lenClosestFarest = 0;
	
	pacman->ghostYellowMove = (t_pos){0, 0};
	map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 0] = tmpPos;
	
	if (map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] != 2 &&
		map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] != 5 &&
		map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] != 6 &&
		map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] != 7)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2) + pow(pacman->ghostYellow.y + 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostYellowMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2) + pow(pacman->ghostYellow.y + 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostYellowMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0];
		}
	}
	
	if (map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] != 2 &&
		map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] != 5 &&
		map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] != 6 &&
		map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] != 7)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2) + pow(pacman->ghostYellow.y - 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostYellowMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2) + pow(pacman->ghostYellow.y - 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostYellowMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0];
		}
	}
	
	if (map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] != 2 &&
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] != 5 &&
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] != 6 &&
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] != 7)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostYellow.x + 1 - pacman->pac.x,2) + pow(pacman->ghostYellow.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostYellowMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostYellow.x + 1 - pacman->pac.x,2) + pow(pacman->ghostYellow.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostYellowMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1];
		}
	}
	
	if (map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] != 2 &&
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] != 5 &&
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] != 6 &&
		map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] != 7)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - 1 - pacman->pac.x,2) + pow(pacman->ghostYellow.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			pacman->ghostYellowMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(pacman->ghostYellow.x - 1 - pacman->pac.x,2) + pow(pacman->ghostYellow.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			pacman->ghostYellowMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1];
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
	pacman->ghostYellow.x += pacman->ghostYellowMove.x;
	pacman->ghostYellow.y += pacman->ghostYellowMove.y;
	map[pacman->ghostYellow.y][pacman->ghostYellow.x] = 8;
	pacman->ghostYellowRect = (SDL_Rect){pacman->ghostYellow.x * 30, pacman->ghostYellow.y * 30, 30, 30};
}


