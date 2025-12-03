#include "text.h"

void    NormalDun(t_Game *g)
{
	int Input;

	Monset(&g->Monster, "Normal");
	while (1)
	{
		OpenStatus(&g->Player);
		printf("(1)공격 (2)아이템 (3)뒤로\n");
		if (scanf("%d", &Input) != 1)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("다시 입력\n");
			continue;
		}
		switch (Input)
		{
			case 1:
			{
				if (FightMon(&g->Player, &g->Monster) != 0)
				{
					g->Player.PlayerState = 1;
					return ;
				}
				break;
			}
			case 2:
			{
				OpenItem(&g->Player);
				break;
			}
			case 3:
				return ;
			default:
			{
				printf("다시 입력\n");
				break;
			}
		}
	}
}
