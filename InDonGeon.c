#include "text.h"

int	RandNum(int i, int j)
{
	srand(time(NULL));
	return ((rand() % (i - j + 1)) + j);
}

void    MonSet(t_Monster *Monster, t_Player *Player)
{
    Monster->Job = "Monster";
    Monster->Hp = Player->MaxHp / 2;
    Monster->MaxHp = Monster->Hp;
    Monster->MaxAtt = Player->MaxAtt / 2;
    Monster->MinAtt = Player->MinAtt / 2;
    Monster->Gold = 50;
    Monster->Item = RandNum(4, 1);
}

int    FightMon(t_Player *Player, t_Monster *Monster)
{
	int	m_att;
	int p_att;

	printf("몬스터 : %d, 플레이어 : %d\n", Monster->Hp, Player->Hp);
	m_att = RandNum(Monster->MaxAtt, Monster->MinAtt);
	p_att = RandNum(Player->MaxAtt, Player->MinAtt);
	printf("몬스터에게 %d의 피해를 받음\n", m_att);
	Player->Hp -= m_att;
	if (Player->Hp <= 0)
		return 1;
	printf("몬스터에게 %d의 피해를 입힘\n", p_att);
	Monster->Hp -= p_att;
	printf("몬스터 : %d, 플레이어 : %d\n", Monster->Hp, Player->Hp);
	if (Monster->Hp <= 0)
	{
		Player->Exp += 80;
		if (Player->Exp >= 100 * Player->Lv)
		{
			Player->Exp -= 100 * Player->Lv;
			Player->Lv += 1;
			Player->MaxAtt *= 2;
            Player->MinAtt *= 2;
			Monster->MaxAtt *= 2;
            Monster->MinAtt *= 2;
			Player->Hp = Player->MaxHp * Player->Lv;
            Player->MaxHp = Player->Hp;
		}
		Monster->Hp = Monster->MaxHp * Player->Lv;
        Monster->MaxHp = Monster->Hp;
	}
}

void    InDonGeon(t_Player *Player)
{
    int Input;
    t_Monster Monster;

    MonSet(&Monster, Player);
    while (1)
    {
        OpenStatus(Player);
        printf("(1)공격 (2)아이템 (3)나가기\n");
        scanf("%d", &Input);
        if (Input == 1)
        {
            FightMon(Player, &Monster);
        }
        if (Input == 2)
        {
            OpenItem(Player);
        }
        else
            return ;
    }
}
