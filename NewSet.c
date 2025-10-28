#include "text.h"

void    Init(t_Player *Player)
{
	memset(Player, 0, sizeof(t_Player));
	Player->Lv = 1;
}

void	NewSet(t_Game *g)
{
	int	Input;
	Init(&g->Player);
	printf("닉네임 생성 : \n");
	scanf("%s", &g->Player.Name);
	printf("직업 선택 : 전사(1), 마법사(2), 암살자(3)\n");
	scanf("%d", &Input);
	if (Input == Fighter)
	{
		strcpy(g->Player.Job, "전사");
		g->Player.Hp = 100;
		g->Player.MaxHp = 100;
		g->Player.MaxAtt = 55;
		g->Player.MinAtt = 45;
	}
	if (Input == Mage)
	{
		strcpy(g->Player.Job, "마법사");
		g->Player.Hp = 90;
		g->Player.MaxHp = 90;
		g->Player.MaxAtt = 50;
		g->Player.MinAtt = 40;
	}
	if (Input == Assassin)
	{
		strcpy(g->Player.Job, "암살자");
		g->Player.Hp = 80;
		g->Player.MaxHp = 80;
		g->Player.MaxAtt = 55;
		g->Player.MinAtt = 45;
	}
	printf("새 정보를 저장합니다.\n");
	OpenStatus(&g->Player);
	Save(g);
	Game(g);
}