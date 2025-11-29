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

void    InDonGeon(t_Game *g)
{
	int Input = 0;

	while (1)
	{
		printf("(1)Easy (2)Normal (3)Hard (4)Exit\n");
		scanf("%d", &Input);
		switch(Input)
		{
			case 1:
			{
				EasyDon(g);
				break;
			}
			case 2:
			{
				NormalDon(g);
				break;
			}
			case 3:
			{
				HardDon(g);
				break;
			}
			case 4:
				return ;
			default :
			{
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
				printf("다시 입력\n");
				break;
			}
		}
	}
}
