#include "text.h"

static void	MonSet(t_Monster *Monster, t_Player *Player)
{
    strcpy(Monster->Job, "Normal");
    Monster->Hp = 100;
    Monster->MaxHp = Monster->Hp;
    Monster->MaxAtt = 120;
    Monster->MinAtt = 80;
    Monster->Gold = 75;
    // Monster->Item = RandNum(4, 1);
}

void    NormalDon(t_Game *g)
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
				return ;
		}
	}
}
