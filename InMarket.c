#include "text.h"

void	ActPurchase(t_Player *Player)
{
	Printf("(1)체력포션\n");
}

void    InMarket(t_Player *Player)
{
	int Input;

	printf("(1)구매 (2)나가기");
	scanf("%d", &Input);
	switch (Input)
	{
		case Purchase:
		{        
			ActPurchase(Player);
			break;
		}
		// case Sale:
		// {
		// 	ActSale(Player);
		// 	break;
		// }
		default:
			break;
	}
}