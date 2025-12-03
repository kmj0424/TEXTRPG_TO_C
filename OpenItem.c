#include "text.h"

void    OpenItem(t_Player *Player)
{
	int Input;

	while (1)
	{
		printf("아이템: 체력포션(%d개), 마나포션(%d개)\n", Player->Inv.HpPotion, Player->Inv.MpPotion);
		printf("(1)체력포션 사용 (2)마나포션 사용 (3)나가기\n");
		if (scanf("%d", &Input) != 1)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("다시 입력\n");
			continue;
		}
		switch(Input)
		{
			case 1:
			{
				if (Player->Inv.HpPotion <= 0)
					printf("체력포션 없음\n");
				else
				{
					Player->Inv.HpPotion -= 1;
					Player->Hp += 50;
					if (Player->Hp >= Player->MaxHp)
						Player->Hp = Player->MaxHp;
					printf("현재 HP : %d", Player->Hp);
				}
				break;
			}
			case 2:
			{
				if (Player->Inv.MpPotion <= 0)
					printf("마나포션 없음\n");
				else
				{
					Player->Inv.MpPotion -= 1;
					Player->Mp += 50;
					if (Player->Mp >= Player->MaxMp)
						Player->Mp = Player->MaxMp;
					printf("현재 MP : %d", Player->Mp);
				}
				break;
			}
			case 3:
				return ;
			default:
			{
				printf("다시 입력\n");
				break;
			}
		}
	}
}
