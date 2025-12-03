#include "text.h"

int	RandNum(int Max, int Min)
{
	static int seeded = 0;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = 1;
	}
	return ((rand() % (Max - Min + 1)) + Min);
}

void    InDungeon(t_Game *g)
{
	int Input = 0;

	while (1)
	{
		printf("(1)Easy (2)Normal (3)Hard (4)Exit\n");
		if (scanf("%d", &Input) != 1)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("다시 입력\n");
			continue;
		}
		switch(Input)
		{
			case 1:
			{
				EasyDun(g);
				break;
			}
			case 2:
			{
				NormalDun(g);
				break;
			}
			case 3:
			{
				HardDun(g);
				break;
			}
			case 4:
				return ;
			default :
			{
				printf("다시 입력\n");
				break;
			}
		}
	}
}
