#include "text.h"

void    HardDon(t_Game *g)
{
	int Input;

	Monset(&g->Monster, "Hard");
	while (1)
	{
		OpenStatus(&g->Player);
		printf("(1)공격 (2)아이템 (3)나가기\n");
		scanf("%d", &Input);
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
			default:
				return ;
		}
	}
}
