#include "text.h"

void    ActPurchase(t_Player *Player)
{
	int Input;

	while (1)
	{
		printf("(1)체력포션 : 100G, (2)마나포션 : 100G (3)나가기\n");
		if (scanf("%d", &Input) != 1)
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			printf("다시 입력\n");
			continue;
		}
		if (Player->Gold < 100 && Input != 3)
		{
			printf("Gold 부족\n");
			return ;
		}
		switch (Input)
		{
			case 1:
			{
				Player->Gold -= 100;
				Player->Inv.HpPotion += 1;
				break;
			}
			case 2:
			{
				Player->Gold -= 100;
				Player->Inv.MpPotion += 1;
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

void    InMarket(t_Player *Player)
{
	int Input;

	printf("(1)구매 (2)나가기\n");
	if (scanf("%d", &Input) != 1)
	{
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		printf("다시 입력\n");
		return ;
	}
	switch (Input)
	{
		case 1:
		{
			ActPurchase(Player);
			break;
		}
		default:
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			return ;
		}
	}
}
