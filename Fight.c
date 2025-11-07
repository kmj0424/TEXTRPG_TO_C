#include "text.h"

int	SkillChoice(t_Player *Player)
{
	int	Input;

	printf("스킬선택 : skill_1(1), passive(2)");
	scanf("%d", &Input);
	switch(Input)
	{
		case 1:
			return (Player->SkillAtt = Player->MaxAtt * 1.2);
		default :
			break;
	}
	return (RandNum(Player->MaxAtt, Player->MinAtt));
}

int    FightMon(t_Player *Player, t_Monster *Monster)
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
		Player->Exp += 80;
		if (Player->Exp >= 100 * Player->Lv)
		{
			Player->Exp -= 100 * Player->Lv;
			Player->Lv += 1;
			Player->MaxAtt *= 1.5;
            Player->MinAtt *= 1.5;
			Monster->MaxAtt *= 1.5;
            Monster->MinAtt *= 1.5;
			Player->Hp = Player->MaxHp * Player->Lv;
            Player->MaxHp = Player->Hp;
		}
		Monster->Hp = Monster->MaxHp * Player->Lv;
        Monster->MaxHp = Monster->Hp;
	}
}
