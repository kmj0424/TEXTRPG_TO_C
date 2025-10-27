#include "text.h"

int main()
{
	t_Player Player;

	int	Input;
    printf("(1)새게임 (2)불러오기 (3)나가기\n");
	scanf("%d", &Input);
	if (Input == New)
	{
		NewSet(&Player);
	}
	if (Input == Fetch)
	{
		FetchSet(&Player);
	}
	if (Input == Exit)
		;// free();
	return 0;
};