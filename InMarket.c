#include "text.h"

void	ActPurchase(t_Player *Player)
{
	int	Input;

	while (1)
	{
		printf("(1)체력포션 : 100G, (2)마나포션 : 100G (3)나가기\n");
		scanf("%d", &Input);
		if (Player->Gold < 100)
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
			}
			case 2:
			{
				Player->Gold -= 100;
				Player->Inv.MpPotion += 1;
			}
			default:
				return ;
		}
	}
}

void    InMarket(t_Player *Player)
{
	int Input;

	printf("(1)구매 (2)나가기\n");
	scanf("%d", &Input);
	switch (Input)
	{
		case 1:
		{
			ActPurchase(Player);
			break;
		}
		default:
			break;
	}
}