#include "pacman.h"

void putGhostRed(t_pacman *pacman, t_ghost *red)
{
	
	extern int	map[H][W];
	int			tmp;
	int			lenClosest = INT_MAX;
	int			lenClosestFarest = 0;
	
	red->ghostMove = (t_pos){0, 0};
	map[red->ghostPos.y][red->ghostPos.x] = red->ghostMapPreviousValue;
	
	//check move down
	if (map[red->ghostPos.y + 1][red->ghostPos.x + 0] == 0 ||
		map[red->ghostPos.y + 1][red->ghostPos.x + 0] == 1 ||
		map[red->ghostPos.y + 1][red->ghostPos.x + 0] == 3 ||
		map[red->ghostPos.y + 1][red->ghostPos.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(red->ghostPos.x - pacman->pac.x,2) + pow(red->ghostPos.y + 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			red->ghostMove = (t_pos) {0, 1};
			red->ghostMapPreviousValue = map[red->ghostPos.y + 1][red->ghostPos.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(red->ghostPos.x - pacman->pac.x,2) + pow(red->ghostPos.y + 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			red->ghostMove = (t_pos) {0, 1};
			red->ghostMapPreviousValue = map[red->ghostPos.y + 1][red->ghostPos.x + 0];
		}
	}
	//check move up
	if (map[red->ghostPos.y - 1][red->ghostPos.x + 0] == 0 ||
		map[red->ghostPos.y - 1][red->ghostPos.x + 0] == 1 ||
		map[red->ghostPos.y - 1][red->ghostPos.x + 0] == 3 ||
		map[red->ghostPos.y - 1][red->ghostPos.x + 0] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(red->ghostPos.x - pacman->pac.x,2) + pow(red->ghostPos.y - 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			red->ghostMove = (t_pos) {0, -1};
			red->ghostMapPreviousValue = map[red->ghostPos.y - 1][red->ghostPos.x + 0];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(red->ghostPos.x - pacman->pac.x,2) + pow(red->ghostPos.y - 1 - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			red->ghostMove = (t_pos) {0, -1};
			red->ghostMapPreviousValue = map[red->ghostPos.y - 1][red->ghostPos.x + 0];
		}
	}
	//check move left
	if (map[red->ghostPos.y + 0][red->ghostPos.x + 1] == 0 ||
		map[red->ghostPos.y + 0][red->ghostPos.x + 1] == 1 ||
		map[red->ghostPos.y + 0][red->ghostPos.x + 1] == 3 ||
		map[red->ghostPos.y + 0][red->ghostPos.x + 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(red->ghostPos.x + 1 - pacman->pac.x,2) + pow(red->ghostPos.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			red->ghostMove = (t_pos) {1, 0};
			red->ghostMapPreviousValue = map[red->ghostPos.y + 0][red->ghostPos.x + 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(red->ghostPos.x + 1 - pacman->pac.x,2) + pow(red->ghostPos.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			red->ghostMove = (t_pos) {1, 0};
			red->ghostMapPreviousValue = map[red->ghostPos.y + 0][red->ghostPos.x + 1];
		}
	}
	//check move right
	if (map[red->ghostPos.y + 0][red->ghostPos.x - 1] == 0 ||
		map[red->ghostPos.y + 0][red->ghostPos.x - 1] == 1 ||
		map[red->ghostPos.y + 0][red->ghostPos.x - 1] == 3 ||
		map[red->ghostPos.y + 0][red->ghostPos.x - 1] == 4)
	{
		if (pacman->eat == 0 && (tmp = sqrt(pow(red->ghostPos.x - 1 - pacman->pac.x,2) + pow(red->ghostPos.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = tmp;
			red->ghostMove = (t_pos) {-1, 0};
			red->ghostMapPreviousValue = map[red->ghostPos.y + 0][red->ghostPos.x - 1];
		}
		else if (pacman->eat != 0 && (tmp = sqrt(pow(red->ghostPos.x - 1 - pacman->pac.x,2) + pow(red->ghostPos.y - pacman->pac.y,2))) > lenClosestFarest)
		{
			lenClosestFarest = tmp;
			red->ghostMove = (t_pos) {-1, 0};
			red->ghostMapPreviousValue = map[red->ghostPos.y + 0][red->ghostPos.x - 1];
		}
	}
	
	if (red->ghostMapPreviousValue == 3)
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
		red->ghostMapPreviousValue = 0;
		return ;
	}
	red->ghostPos.x += red->ghostMove.x;
	red->ghostPos.y += red->ghostMove.y;
	map[red->ghostPos.y][red->ghostPos.x] = red->id;
	red->ghostRect = (SDL_Rect){red->ghostPos.x * 30, red->ghostPos.y * 30, 30, 30};
}


