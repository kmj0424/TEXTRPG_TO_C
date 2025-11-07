#include "text.h"

void    OpenItem(t_Player *Player)
{
	int	Input;
	int	HpSignal;
	int	MpSignal;

	printf("아이템 : 체력포션(%d), 마나포션(%d)\n", Player->Inv.HpPotion, Player->Inv.MpPotion);
	while (1)
	{
		printf("(1)체력포션사용 (2)마나포션사용 (3)나가기\n");
		scanf("%d", &Input);
		switch(Input)
		{
			case 1:
			{
				if (Player->Inv.HpPotion <= 0)
					break;
				Player->Inv.HpPotion -= 1;
				Player->Hp += 50;
				break;
			}
			case 2:
			{
				if (Player->Inv.MpPotion <= 0)
					break;
				Player->Inv.MpPotion -= 1;
				Player->Mp += 50;
				break;
			}
			default:
				return ;
		}
	}
}