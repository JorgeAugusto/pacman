
#include "pacman.h"

void putGhostRed(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 0;
	int			tmp;
	int			len = 5000;
	
	//	if (tmpPos == 3)
	//		exit(0);
	map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 0] = tmpPos;
	
	
	if (map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostRed.y + 1][pacman->ghostRed.x + 0];
		}
	}
	
	if (map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostRed.x - pacman->pac.x,2) + pow(pacman->ghostRed.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostRed.y - 1][pacman->ghostRed.x + 0];
		}
	}
	
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostRed.x + 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostRedMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostRed.y + 0][pacman->ghostRed.x + 1];
		}
	}
	
	if (map[pacman->ghostRed.y + 0][pacman->ghostRed.x - 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostRed.x - 1 - pacman->pac.x,2) + pow(pacman->ghostRed.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
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



void putGhostBlue(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 1;
	int			tmp;
	int			len = 5000;
	
	//	if (tmpPos == 3)
	//		exit(0);
	map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 0] = tmpPos;
	
	
	if (map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostBlue.y + 1][pacman->ghostBlue.x + 0];
		}
	}
	
	if (map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostBlue.x - pacman->pac.x,2) + pow(pacman->ghostBlue.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostBlue.y - 1][pacman->ghostBlue.x + 0];
		}
	}
	
	if (map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostBlue.x + 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostBlueMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x + 1];
		}
	}
	
	if (map[pacman->ghostBlue.y + 0][pacman->ghostBlue.x - 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostBlue.x - 1 - pacman->pac.x,2) + pow(pacman->ghostBlue.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
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

void putGhostPink(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 1;
	int			tmp;
	int			len = 5000;
	
	//	if (tmpPos == 3)
	//		exit(0);
	map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 0] = tmpPos;
	
	
	if (map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2) + pow(pacman->ghostPink.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostPinkMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostPink.y + 1][pacman->ghostPink.x + 0];
		}
	}
	
	if (map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostPink.x - pacman->pac.x,2)
						+ pow(pacman->ghostPink.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostPinkMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostPink.y - 1][pacman->ghostPink.x + 0];
		}
	}
	
	if (map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostPink.x + 1 - pacman->pac.x,2)
						+ pow(pacman->ghostPink.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostPinkMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostPink.y + 0][pacman->ghostPink.x + 1];
		}
	}
	
	if (map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostPink.x - 1 - pacman->pac.x,2)
						+ pow(pacman->ghostPink.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostPinkMove = (t_pos) {-1, 0};
			tmpPos = map[pacman->ghostPink.y + 0][pacman->ghostPink.x - 1];
		}
	}
	if (tmpPos == 3)
	{
		putTextMessage(pacman, "You lose");
		SDL_RenderPresent(pacman->sdl.renderer);
		SDL_Delay(1500);
		exit(0);
	}
	pacman->ghostPink.x += pacman->ghostPinkMove.x;
	pacman->ghostPink.y += pacman->ghostPinkMove.y;
	
	map[pacman->ghostPink.y][pacman->ghostPink.x] = 7;
	
	pacman->ghostPinkRect = (SDL_Rect){pacman->ghostPink.x * 30, pacman->ghostPink.y * 30, 30, 30};
	
}

void putGhostYellow(t_pacman *pacman)
{
	
	extern int	map[H][W];
	static int	tmpPos = 1;
	int			tmp;
	int			len = 5000;
	
	//	if (tmpPos == 3)
	//		exit(0);
	map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 0] = tmpPos;
	
	
	if (map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2)
						+ pow(pacman->ghostYellow.y + 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostYellowMove = (t_pos) {0, 1};
			tmpPos = map[pacman->ghostYellow.y + 1][pacman->ghostYellow.x + 0];
		}
	}
	
	if (map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostYellow.x - pacman->pac.x,2)
						+ pow(pacman->ghostYellow.y - 1 - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostYellowMove = (t_pos) {0, -1};
			tmpPos = map[pacman->ghostYellow.y - 1][pacman->ghostYellow.x + 0];
		}
	}
	
	if (map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostYellow.x + 1 - pacman->pac.x,2)
						+ pow(pacman->ghostYellow.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
			pacman->ghostYellowMove = (t_pos) {1, 0};
			tmpPos = map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x + 1];
		}
	}
	
	if (map[pacman->ghostYellow.y + 0][pacman->ghostYellow.x - 1] != 2)
	{
		if ((tmp = sqrt(pow(pacman->ghostYellow.x - 1 - pacman->pac.x,2)
						+ pow(pacman->ghostYellow.y - pacman->pac.y,2))) < len)
		{
			len = tmp;
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

