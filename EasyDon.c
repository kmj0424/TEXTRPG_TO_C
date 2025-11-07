#include "text.h"

static void	MonSet(t_Monster *Monster, t_Player *Player)
{
    Monster->Job = "Easy";
    Monster->Hp = Player->MaxHp / 2;
    Monster->MaxHp = Monster->Hp;
    Monster->MaxAtt = Player->MaxAtt / 2;
    Monster->MinAtt = Player->MinAtt / 2;
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
				FightMon();
				break;
			}
			case 2:
			{
				OpenItem();
				break;
			}
			else
				return ;
		}
	}
}