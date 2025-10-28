#include "text.h"

void    OpenStatus(t_Player *Player)
{
    printf("이름 : %s\n", Player->Name);
    printf("직업 : %s\n", Player->Job);
    printf("레벨 : %d\n", Player->Lv);
    printf("경험치 : %d\n", Player->Exp);
    printf("최대 체력 : %d\n", Player->Hp);
    printf("현재 체력 : %d\n", Player->MaxHp);
}

void    Game(t_Game *g)
{
    int Input = 0;
    while (1)
    {
        printf("(1)던전 (2)내정보 (3)상점 (4)저장 (5)나가기\n");
        scanf("%d", &Input);
        switch(Input)
        {
            case DonGeon:
            {
                InDonGeon(&g->Player);
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
            default :
                return ;
        }
    }
}