#include "text.h"

void    Init(t_Player *Player)
{
	memset(Player, 0, sizeof(t_Player));
	Player->Lv = 1;
}

void    NewSet(t_Game *g)
{
	int Input;
	char Name[35];

	Init(&g->Player);
	printf("캐릭터 이름 입력(최대 30자): \n");
	scanf("%30s%*[^\n]%*c", Name);
	strncpy(g->Player.Name, Name, sizeof(g->Player.Name) - 1);
	g->Player.Name[sizeof(g->Player.Name) - 1] = '\0';
	while (1)
	{
		printf("직업 선택 : (1)전사, (2)마법사, (3)암살자\n");
		if (scanf("%d", &Input) != 1)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("다시 입력\n");
			continue;
		}
		switch (Input)
		{
			case Fighter:
			{
				strcpy(g->Player.Job, "전사");
				g->Player.Hp = 100;
				g->Player.MaxHp = 100;
				g->Player.MaxAtt = 55;
				g->Player.MinAtt = 45;
				g->Player.Mp = 100;
				g->Player.MaxMp = 100;
				return ;
			}
			case Mage:
			{
				strcpy(g->Player.Job, "마법사");
				g->Player.Hp = 90;
				g->Player.MaxHp = 90;
				g->Player.MaxAtt = 50;
				g->Player.MinAtt = 40;
				g->Player.Mp = 100;
				g->Player.MaxMp = 100;
				return ;
			}
			case Assassin:
			{
				strcpy(g->Player.Job, "암살자");
				g->Player.Hp = 80;
				g->Player.MaxHp = 80;
				g->Player.MaxAtt = 55;
				g->Player.MinAtt = 45;
				g->Player.Mp = 100;
				g->Player.MaxMp = 100;
				return ;
			}
			default:
			{
				printf("다시 입력\n");
				break;
			}
		}
	}
}
