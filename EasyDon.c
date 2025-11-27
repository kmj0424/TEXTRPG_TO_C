#include "text.h"

static void	MonSet(t_Monster *Monster, t_Player *Player)
{
    strcpy(Monster->Job, "Easy");
    Monster->MaxHp = 30;
    Monster->Hp = Monster->MaxHp;
    Monster->MaxAtt = 30;
    Monster->MinAtt = 20;
    Monster->Gold = 50;
    // Monster->Item = RandNum(4, 1);
}

void    EasyDon(t_Game *g)
{
	int Input;

	MonSet(&g->Monster, &g->Player);
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
				return;
		}
	}
}
