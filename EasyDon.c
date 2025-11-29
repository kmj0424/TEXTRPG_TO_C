#include "text.h"

void    EasyDon(t_Game *g)
{
	int Input;

	Monset(&g->Monster, "Easy");
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
			case 3:
				return ;
			default:
			{
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
				printf("다시 입력\n");
				break;
			}
		}
	}
}
