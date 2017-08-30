#include "pacman.h"

void putGhost(t_pacman *pacman, t_ghost *ghost)
{
	
	extern int	map[H][W];
	int			lenCurrent;
	int			lenClosest = INT_MAX;
	int			lenFarest = 0;
	int			mapValue;
	
	ghost->ghostMove = (t_pos){0, 0};
	map[ghost->ghostPos.y][ghost->ghostPos.x] = ghost->ghostMapPreviousValue;
	
	//check move down
	mapValue = map[ghost->ghostPos.y + 1][ghost->ghostPos.x];
	if (mapValue == 0 || mapValue == 1 || mapValue == 3 || mapValue == 4)
	{
		if (pacman->eat == 0 && (lenCurrent = sqrt(pow(ghost->ghostPos.x - pacman->pac.x,2) + pow(ghost->ghostPos.y + 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = lenCurrent;
			ghost->ghostMove = (t_pos) {0, 1};
			ghost->ghostMapPreviousValue = map[ghost->ghostPos.y + 1][ghost->ghostPos.x + 0];
		}
		else if (pacman->eat != 0 && (lenCurrent = sqrt(pow(ghost->ghostPos.x - pacman->pac.x,2) + pow(ghost->ghostPos.y + 1 - pacman->pac.y,2))) > lenFarest)
		{
			lenFarest = lenCurrent;
			ghost->ghostMove = (t_pos) {0, 1};
			ghost->ghostMapPreviousValue = map[ghost->ghostPos.y + 1][ghost->ghostPos.x + 0];
		}
	}
	//check move up
	mapValue = map[ghost->ghostPos.y - 1][ghost->ghostPos.x];
	if (mapValue == 0 || mapValue == 1 || mapValue == 3 || mapValue == 4)
	{
		if (pacman->eat == 0 && (lenCurrent = sqrt(pow(ghost->ghostPos.x - pacman->pac.x,2) + pow(ghost->ghostPos.y - 1 - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = lenCurrent;
			ghost->ghostMove = (t_pos) {0, -1};
			ghost->ghostMapPreviousValue = map[ghost->ghostPos.y - 1][ghost->ghostPos.x + 0];
		}
		else if (pacman->eat != 0 && (lenCurrent = sqrt(pow(ghost->ghostPos.x - pacman->pac.x,2) + pow(ghost->ghostPos.y - 1 - pacman->pac.y,2))) > lenFarest)
		{
			lenFarest = lenCurrent;
			ghost->ghostMove = (t_pos) {0, -1};
			ghost->ghostMapPreviousValue = map[ghost->ghostPos.y - 1][ghost->ghostPos.x + 0];
		}
	}
	//check move left
	mapValue = map[ghost->ghostPos.y][ghost->ghostPos.x + 1];
	if (mapValue == 0 || mapValue == 1 || mapValue == 3 || mapValue == 4)
	{
		if (pacman->eat == 0 && (lenCurrent = sqrt(pow(ghost->ghostPos.x + 1 - pacman->pac.x,2) + pow(ghost->ghostPos.y - pacman->pac.y,2))) < lenClosest)
		{
			lenClosest = lenCurrent;
			ghost->ghostMove = (t_pos) {1, 0};
			ghost->ghostMapPreviousValue = map[ghost->ghostPos.y + 0][ghost->ghostPos.x + 1];
		}
		else if (pacman->eat != 0 && (lenCurrent = sqrt(pow(ghost->ghostPos.x + 1 - pacman->pac.x,2) + pow(ghost->ghostPos.y - pacman->pac.y,2))) > lenFarest)
		{
			lenFarest = lenCurrent;
			ghost->ghostMove = (t_pos) {1, 0};
			ghost->ghostMapPreviousValue = map[ghost->ghostPos.y + 0][ghost->ghostPos.x + 1];
		}
	}
	//check move right
	mapValue = map[ghost->ghostPos.y][ghost->ghostPos.x - 1];
	if (mapValue == 0 || mapValue == 1 || mapValue == 3 || mapValue == 4)
	{
		if (pacman->eat == 0 && (lenCurrent = sqrt(pow(ghost->ghostPos.x - 1 - pacman->pac.x,2) + pow(ghost->ghostPos.y - pacman->pac.y,2))) < lenClosest)
		{
			ghost->ghostMove = (t_pos) {-1, 0};
			ghost->ghostMapPreviousValue = map[ghost->ghostPos.y + 0][ghost->ghostPos.x - 1];
		}
		else if (pacman->eat != 0 && (lenCurrent = sqrt(pow(ghost->ghostPos.x - 1 - pacman->pac.x,2) + pow(ghost->ghostPos.y - pacman->pac.y,2))) > lenFarest)
		{
			ghost->ghostMove = (t_pos) {-1, 0};
			ghost->ghostMapPreviousValue = map[ghost->ghostPos.y + 0][ghost->ghostPos.x - 1];
		}
	}
	ghost->ghostPos.x += ghost->ghostMove.x;
	ghost->ghostPos.y += ghost->ghostMove.y;
	map[ghost->ghostPos.y][ghost->ghostPos.x] = ghost->id;
	ghost->ghostRect = (SDL_Rect){ghost->ghostPos.x * 30, ghost->ghostPos.y * 30, 30, 30};
}
