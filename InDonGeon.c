#include "text.h"

int	RandNum(int i, int j)
{
	srand(time(NULL));
	return ((rand() % (i - j + 1)) + j);
}

void    InDonGeon(t_Game *g)
{
    int Input;
    printf("(1)Easy (2)Normal (3)Hard\n");
    scanf("%d", &Input);
    switch(Input)
    {
        case 1:
        {
            EasyDon(g);
            break;
        }
        case 2:
        {
            NormalDon(g);
            break;
        }
        case 3:
        {
            HardDon(g);
            break;
        }
        default :
            break;
    }
}
