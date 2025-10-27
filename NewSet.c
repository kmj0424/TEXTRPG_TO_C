#include "text.h"

void    Init(t_Player *Player)
{
	memset(Player, 0, sizeof(t_Player));
	Player->Lv = 1;
}

void	NewSet(t_Player *Player)
{
	int	Input;
	Init(Player);
	printf("닉네임 생성 : \n");
	scanf("%s", Player->Name);
	printf("직업 선택 : 전사(1), 마법사(2), 암살자(3)\n");
	scanf("%d", &Input);
	if (Input == Fighter)
	{
		strcpy(Player->Job, "전사");
		Player->Hp = 100;
		Player->MaxHp = 100;
		Player->MaxAtt = 55;
		Player->MinAtt = 45;
	}
	if (Input == Mage)
	{
		strcpy(Player->Job, "마법사");
		Player->Hp = 90;
		Player->MaxHp = 90;
		Player->MaxAtt = 50;
		Player->MinAtt = 40;
	}
	if (Input == Assassin)
	{
		strcpy(Player->Job, "암살자");
		Player->Hp = 80;
		Player->MaxHp = 80;
		Player->MaxAtt = 55;
		Player->MinAtt = 45;
	}
	printf("새 정보를 저장합니다.\n");
	OpenStatus(Player);
	Save(Player);
	Game(Player);
}