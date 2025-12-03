#include "text.h"

void    OpenStatus(t_Player *Player)
{
	printf("이름 : %s\n", Player->Name);
	printf("직업 : %s\n", Player->Job);
	printf("레벨 : %d\n", Player->Lv);
	printf("경험치 : %d\n", Player->Exp);
	printf("체력 : %d/%d\n", Player->Hp, Player->MaxHp);
	printf("마나 : %d/%d\n", Player->Mp, Player->MaxMp);
	printf("골드 : %d\n", Player->Gold);
}

void    Game(t_Game *g)
{
	int Input;
	while (1)
	{
		if (g->Player.PlayerState == 1)
		{
			printf("플레이어 리스폰\n");
			g->Player.Hp = g->Player.MaxHp / 2;
			g->Player.Mp = g->Player.MaxMp / 2;
			g->Player.Exp = 0;
			g->Player.PlayerState = 0;
		}
		printf("(1)던전 (2)내 정보 (3)상점 (4)저장 (5)종료\n");
		if (scanf("%d", &Input) != 1)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("다시 입력\n");
			continue;
		}
		switch(Input)
		{
			case Dungeon:
			{
				InDungeon(g);
				break;
			}
			case MyInfo:
			{
				OpenStatus(&g->Player);
				break;
			}
			case Market:
			{
				InMarket(&g->Player);
				break;
			}
			case SavePoint:
			{
				Save(g);
				break;
			}
			case Back:
				return ;
			default :
			{
				printf("다시 입력\n");
				break;
			}
		}
	}
}
