#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iter = atoi(av[3]);

	if (width < 0 || height < 0 || iter < 0)
		return 1;
	int x = 1, y = 1, pen = 0;
	int trip[2][height + 2][width + 2];
	char c;

	for (int l = 0; l < 2; l++)
		for(int s = 0; s < height; s++)
			for(int d = 0; d < width; d++)
				trip[l][s][d] = 0;
	while (read(0, &c, 1) > 0) 
	{
		if (c == 'w' && y > 1)
			y--;
		else if (c == 's' && y < height)
			y++;
		else if (c == 'd' && x < width)
			x++;
		else if (c == 'a' && x > 1)
			x--;
		else if (c == 'x')
			pen = !pen;
		if (pen)
			trip[0][y][x] = 1;
	}
	for(int i = 0; i < iter; i++)
	{
		int t1 = i % 2;
		int t2 = (i + 1) % 2;
		for(int idx = 0; idx <= height; idx++)
		{
			for(int sub = 0; sub <= width; sub++)
			{
				int n = 0;
				for (int dy = -1; dy <= height; dy++) 
				{
					for (int dx = -1; dx <= width; dx++)
					{
						if (dx != 0 || dy != 0)
							trip[t1][idx][sub] = 1;
					}
				}
			}
		}
	}
}