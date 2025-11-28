#include "text.h"

int	SkillChoice(t_Player *Player)
{
	int	Input;

	printf("스킬선택 : (1)skill_1, (2)passive\n");
	scanf("%d", &Input);
	switch(Input)
	{
		case 1:
		{
			if (Player->Mp < 50)
			{
				printf("마나 부족(auto passive skill)\n");
				return (RandNum(Player->MaxAtt, Player->MinAtt));
			}
			Player->Mp -= 50;
			return (Player->SkillAtt = Player->MaxAtt * 1.2);
		}
		default :
			break;
	}
	return (RandNum(Player->MaxAtt, Player->MinAtt));
}

void	Monset(t_Monster *Monster, char *MonLv)
{
	if (strcmp(MonLv, "Easy") == 0)
	{
		strncpy(Monster->Job, "Easy", sizeof(Monster->Job));
		Monster->Job[sizeof(Monster->Job)-1] = '\0';
		Monster->MaxHp = 30;
		Monster->Hp = Monster->MaxHp;
		Monster->MaxAtt = 30;
		Monster->MinAtt = 20;
		Monster->Gold = 50;	
	}
	else if (strcmp(MonLv, "Normal") == 0)
	{
		strncpy(Monster->Job, "Normal", sizeof(Monster->Job));
		Monster->Job[sizeof(Monster->Job)-1] = '\0';
		Monster->MaxHp = 100;
		Monster->Hp = Monster->MaxHp;
		Monster->MaxAtt = 120;
		Monster->MinAtt = 80;
		Monster->Gold = 75;
	}
	else if (strcmp(MonLv, "Hard") == 0)
	{
		strncpy(Monster->Job, "Hard", sizeof(Monster->Job));
		Monster->Job[sizeof(Monster->Job)-1] = '\0';
		Monster->MaxHp = 300;
		Monster->Hp = Monster->MaxHp;
		Monster->MaxAtt = 330;
		Monster->MinAtt = 300;
		Monster->Gold = 100;
	}
}

int	FightMon(t_Player *Player, t_Monster *Monster)
{
	int	m_att;
	int p_att;

	printf("몬스터 : %d, 플레이어 : %d\n", Monster->Hp, Player->Hp);
	m_att = RandNum(Monster->MaxAtt, Monster->MinAtt);
	p_att = SkillChoice(Player);
	printf("몬스터에게 %d의 피해를 받음\n", m_att);
	Player->Hp -= m_att;
	if (Player->Hp <= 0)
		return 1;
	printf("몬스터에게 %d의 피해를 입힘\n", p_att);
	Monster->Hp -= p_att;
	printf("몬스터 : %d, 플레이어 : %d\n", Monster->Hp, Player->Hp);
	if (Monster->Hp <= 0)
	{
		Monset(Monster, Monster->Job);
		Player->Exp += 80;
		Player->Gold += 50;
		if (Player->Exp >= 100 * Player->Lv)
		{
			Player->Exp -= 100 * Player->Lv;
			Player->Lv += 1;
			Player->MaxAtt *= 1.2;
            Player->MinAtt *= 1.2;
			Player->MaxHp *= 1.2;
			Player->MaxMp *= 1.2;
			Player->Hp = Player->MaxHp;
            Player->Mp = Player->MaxMp;
		}
	}
	return 0;
}
